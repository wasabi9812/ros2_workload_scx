#include <chrono>
#include <algorithm>
#include <cstdint>
#include <functional>
#include <memory>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor/msg/workload_msg.hpp"

class SensorSource : public rclcpp::Node
{
public:
  SensorSource()
  : Node("n1"), seq_(0)
  {
    this->declare_parameter<std::string>("topic_name", "/sensor_input");
    this->declare_parameter<double>("rate_hz", 50.0);
    this->declare_parameter<std::string>("profile", "lidar_2d");
    this->declare_parameter<std::string>("encoding", "range32");
    this->declare_parameter<std::string>("fill_mode", "seq_pattern");
    this->declare_parameter<int>("width", 720);
    this->declare_parameter<int>("height", 1);
    this->declare_parameter<int>("element_size", 4);
    this->declare_parameter<int>("payload_bytes", 0);

    topic_name_ = this->get_parameter("topic_name").as_string();
    rate_hz_ = this->get_parameter("rate_hz").as_double();
    profile_ = this->get_parameter("profile").as_string();
    encoding_ = this->get_parameter("encoding").as_string();
    fill_mode_ = this->get_parameter("fill_mode").as_string();
    width_ = this->get_parameter("width").as_int();
    height_ = this->get_parameter("height").as_int();
    element_size_ = this->get_parameter("element_size").as_int();
    payload_bytes_ = this->get_parameter("payload_bytes").as_int();

    if (rate_hz_ <= 0.0) {
      throw std::invalid_argument("rate_hz must be > 0");
    }

    if (width_ < 1) {
      throw std::invalid_argument("width must be >= 1");
    }

    if (height_ < 1) {
      throw std::invalid_argument("height must be >= 1");
    }

    if (element_size_ < 1) {
      throw std::invalid_argument("element_size must be >= 1");
    }

    if (payload_bytes_ < 0) {
      throw std::invalid_argument("payload_bytes must be >= 0");
    }

    payload_size_ = resolve_payload_size();
    seed_payload_.resize(payload_size_);
    fill_payload(seed_payload_);

    publisher_ = this->create_publisher<sensor::msg::WorkloadMsg>(topic_name_, 10);

    auto period = std::chrono::duration<double>(1.0 / rate_hz_);
    timer_ = this->create_wall_timer(
      std::chrono::duration_cast<std::chrono::nanoseconds>(period),
      std::bind(&SensorSource::on_timer, this));

    RCLCPP_INFO(
      this->get_logger(),
      "[n1] topic=%s rate=%.2fHz profile=%s encoding=%s shape=%dx%d elem=%d payload=%zu fill=%s",
      topic_name_.c_str(),
      rate_hz_,
      profile_.c_str(),
      encoding_.c_str(),
      width_,
      height_,
      element_size_,
      payload_size_,
      fill_mode_.c_str());
  }

private:
  std::size_t resolve_payload_size() const
  {
    if (payload_bytes_ > 0) {
      return static_cast<std::size_t>(payload_bytes_);
    }

    const auto max_size = static_cast<std::uint64_t>(std::numeric_limits<std::size_t>::max());
    const std::uint64_t computed_size =
      static_cast<std::uint64_t>(width_) *
      static_cast<std::uint64_t>(height_) *
      static_cast<std::uint64_t>(element_size_);

    if (computed_size == 0 || computed_size > max_size) {
      throw std::invalid_argument("computed payload size is invalid");
    }

    return static_cast<std::size_t>(computed_size);
  }

  void fill_payload(std::vector<uint8_t> & payload)
  {
    if (fill_mode_ == "zero") {
      std::fill(payload.begin(), payload.end(), 0);
      return;
    }

    if (fill_mode_ == "checkerboard") {
      for (std::size_t i = 0; i < payload.size(); ++i) {
        payload[i] = (i % 2 == 0) ? 0x00 : 0xFF;
      }
      return;
    }

    for (std::size_t i = 0; i < payload.size(); ++i) {
      payload[i] = static_cast<uint8_t>(i % 256);
    }
  }

  void publish_one()
  {
    sensor::msg::WorkloadMsg msg;

    msg.seq = seq_++;
    msg.profile = profile_;
    msg.encoding = encoding_;
    msg.width = static_cast<uint32_t>(width_);
    msg.height = static_cast<uint32_t>(height_);
    msg.element_size = static_cast<uint32_t>(element_size_);
    msg.payload = seed_payload_;

    if (fill_mode_ == "seq_pattern") {
      const uint8_t offset = static_cast<uint8_t>(msg.seq % 256);
      for (auto & value : msg.payload) {
        value = static_cast<uint8_t>(value + offset);
      }
    }

    publisher_->publish(msg);
  }

  void on_timer()
  {
    publish_one();
  }

  uint64_t seq_;

  std::string topic_name_;
  std::string profile_;
  std::string encoding_;
  std::string fill_mode_;
  double rate_hz_;
  int width_;
  int height_;
  int element_size_;
  int payload_bytes_;
  std::size_t payload_size_;
  std::vector<uint8_t> seed_payload_;

  rclcpp::Publisher<sensor::msg::WorkloadMsg>::SharedPtr publisher_;
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
