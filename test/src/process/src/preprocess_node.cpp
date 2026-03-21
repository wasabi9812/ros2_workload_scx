#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor/msg/workload_msg.hpp"

class PreprocessNode : public rclcpp::Node
{
public:
  PreprocessNode()
  : Node("preprocess_node"), received_count_(0)
  {
    this->declare_parameter<std::string>("input_topic", "/sensor_input");
    this->declare_parameter<std::string>("output_topic", "/preprocessed");
    this->declare_parameter<int>("qos_depth", 10);
    this->declare_parameter<std::string>("checksum_mode", "byte_sum");
    this->declare_parameter<bool>("verify_shape", true);
    this->declare_parameter<int>("log_every_n", 100);

    input_topic_ = this->get_parameter("input_topic").as_string();
    output_topic_ = this->get_parameter("output_topic").as_string();
    qos_depth_ = this->get_parameter("qos_depth").as_int();
    checksum_mode_ = this->get_parameter("checksum_mode").as_string();
    verify_shape_ = this->get_parameter("verify_shape").as_bool();
    log_every_n_ = this->get_parameter("log_every_n").as_int();

    if (qos_depth_ < 1) {
      throw std::invalid_argument("qos_depth must be >= 1");
    }

    if (log_every_n_ < 0) {
      throw std::invalid_argument("log_every_n must be >= 0");
    }

    if (checksum_mode_ != "byte_sum" && checksum_mode_ != "xor32") {
      throw std::invalid_argument("checksum_mode must be 'byte_sum' or 'xor32'");
    }

    publisher_ = this->create_publisher<sensor::msg::WorkloadMsg>(output_topic_, qos_depth_);
    subscription_ = this->create_subscription<sensor::msg::WorkloadMsg>(
      input_topic_,
      qos_depth_,
      std::bind(&PreprocessNode::on_message, this, std::placeholders::_1));

    RCLCPP_INFO(
      this->get_logger(),
      "[preprocess_node] input=%s output=%s qos=%d checksum=%s verify_shape=%s log_every_n=%d",
      input_topic_.c_str(),
      output_topic_.c_str(),
      qos_depth_,
      checksum_mode_.c_str(),
      verify_shape_ ? "true" : "false",
      log_every_n_);
  }

private:
  using WorkloadMsg = sensor::msg::WorkloadMsg;

  std::size_t expected_payload_size(const WorkloadMsg & msg) const
  {
    const auto max_size = static_cast<std::uint64_t>(std::numeric_limits<std::size_t>::max());
    const std::uint64_t expected_size =
      static_cast<std::uint64_t>(msg.width) *
      static_cast<std::uint64_t>(msg.height) *
      static_cast<std::uint64_t>(msg.element_size);

    if (expected_size > max_size) {
      throw std::overflow_error("expected payload size overflow");
    }

    return static_cast<std::size_t>(expected_size);
  }

  std::uint32_t compute_checksum(const WorkloadMsg & msg) const
  {
    if (checksum_mode_ == "xor32") {
      std::uint32_t checksum = 0;
      for (std::size_t i = 0; i < msg.payload.size(); ++i) {
        const std::uint32_t shift = static_cast<std::uint32_t>((i % 4U) * 8U);
        checksum ^= static_cast<std::uint32_t>(msg.payload[i]) << shift;
      }
      return checksum;
    }

    std::uint32_t checksum = 0;
    for (const auto value : msg.payload) {
      checksum += value;
    }
    return checksum;
  }

  void on_message(const WorkloadMsg::SharedPtr msg)
  {
    ++received_count_;

    if (verify_shape_) {
      const auto expected_size = expected_payload_size(*msg);
      if (expected_size != msg->payload.size()) {
        RCLCPP_WARN(
          this->get_logger(),
          "seq=%lu shape mismatch width=%u height=%u elem=%u expected=%zu actual=%zu",
          msg->seq,
          msg->width,
          msg->height,
          msg->element_size,
          expected_size,
          msg->payload.size());
      }
    }

    const auto checksum = compute_checksum(*msg);

    if (log_every_n_ > 0 && (received_count_ % static_cast<std::uint64_t>(log_every_n_) == 0U)) {
      RCLCPP_INFO(
        this->get_logger(),
        "seq=%lu profile=%s payload=%zu checksum=%u",
        msg->seq,
        msg->profile.c_str(),
        msg->payload.size(),
        checksum);
    }

    publisher_->publish(*msg);
  }

  std::string input_topic_;
  std::string output_topic_;
  std::string checksum_mode_;
  int qos_depth_;
  bool verify_shape_;
  int log_every_n_;
  std::uint64_t received_count_;

  rclcpp::Publisher<WorkloadMsg>::SharedPtr publisher_;
  rclcpp::Subscription<WorkloadMsg>::SharedPtr subscription_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PreprocessNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
