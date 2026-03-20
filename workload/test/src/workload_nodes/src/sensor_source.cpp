#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "workload_nodes/msg/workload_msg.hpp"

using namespace std::chrono_literals;

class SensorSource : public rclcpp::Node
{
public:
  SensorSource()
  : Node("sensor_source"), seq_(0)
  {
    // ===== parameters =====
    this->declare_parameter<std::string>("topic_name", "/sensor_input");
    this->declare_parameter<double>("rate_hz", 50.0);
    this->declare_parameter<int>("payload_bytes", 128);
    this->declare_parameter<bool>("burst_enable", false);
    this->declare_parameter<int>("burst_size", 1);
    this->declare_parameter<int>("source_id", 0);

    topic_name_   = this->get_parameter("topic_name").as_string();
    rate_hz_      = this->get_parameter("rate_hz").as_double();
    payload_bytes_= this->get_parameter("payload_bytes").as_int();
    burst_enable_ = this->get_parameter("burst_enable").as_bool();
    burst_size_   = this->get_parameter("burst_size").as_int();
    source_id_    = this->get_parameter("source_id").as_int();

    // ===== publisher =====
    publisher_ = this->create_publisher<workload_nodes::msg::WorkloadMsg>(topic_name_, 10);

    // ===== timer =====
    auto period = std::chrono::duration<double>(1.0 / rate_hz_);
    timer_ = this->create_wall_timer(
      std::chrono::duration_cast<std::chrono::nanoseconds>(period),
      std::bind(&SensorSource::on_timer, this));

    RCLCPP_INFO(
      this->get_logger(),
      "[sensor_source] topic=%s rate=%.2fHz payload=%d burst=%s size=%d source_id=%d",
      topic_name_.c_str(),
      rate_hz_,
      payload_bytes_,
      burst_enable_ ? "true" : "false",
      burst_size_,
      source_id_);
  }

private:
  void publish_one()
  {
    workload_nodes::msg::WorkloadMsg msg;

    msg.seq = seq_++;
    msg.t0_ns = this->now().nanoseconds();
    msg.source_id = static_cast<uint32_t>(source_id_);
    msg.payload_size = static_cast<uint32_t>(payload_bytes_);

    msg.payload.resize(payload_bytes_);
    for (int i = 0; i < payload_bytes_; ++i) {
      msg.payload[i] = static_cast<uint8_t>((msg.seq + i) % 256);
    }

    publisher_->publish(msg);
  }

  void on_timer()
  {
    int count = burst_enable_ ? burst_size_ : 1;

    for (int i = 0; i < count; ++i) {
      publish_one();
    }
  }

  // ===== variables =====
  uint64_t seq_;

  std::string topic_name_;
  double rate_hz_;
  int payload_bytes_;
  bool burst_enable_;
  int burst_size_;
  int source_id_;

  rclcpp::Publisher<workload_nodes::msg::WorkloadMsg>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SensorSource>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}