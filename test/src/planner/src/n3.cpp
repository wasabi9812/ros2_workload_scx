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

class PlannerNode : public rclcpp::Node
{
public:
  PlannerNode()
  : Node("n3"), received_count_(0)
  {
    this->declare_parameter<std::string>("input_topic", "/preprocessed");
    this->declare_parameter<std::string>("output_topic", "/planned");
    this->declare_parameter<int>("qos_depth", 10);
    this->declare_parameter<int>("compute_iterations", 16);
    this->declare_parameter<int>("touch_bytes", 2048);
    this->declare_parameter<int>("patch_bytes", 64);
    this->declare_parameter<bool>("verify_shape", true);
    this->declare_parameter<int>("log_every_n", 50);

    input_topic_ = this->get_parameter("input_topic").as_string();
    output_topic_ = this->get_parameter("output_topic").as_string();
    qos_depth_ = this->get_parameter("qos_depth").as_int();
    compute_iterations_ = this->get_parameter("compute_iterations").as_int();
    touch_bytes_ = this->get_parameter("touch_bytes").as_int();
    patch_bytes_ = this->get_parameter("patch_bytes").as_int();
    verify_shape_ = this->get_parameter("verify_shape").as_bool();
    log_every_n_ = this->get_parameter("log_every_n").as_int();

    if (qos_depth_ < 1) {
      throw std::invalid_argument("qos_depth must be >= 1");
    }

    if (compute_iterations_ < 1) {
      throw std::invalid_argument("compute_iterations must be >= 1");
    }

    if (touch_bytes_ < 1) {
      throw std::invalid_argument("touch_bytes must be >= 1");
    }

    if (patch_bytes_ < 0) {
      throw std::invalid_argument("patch_bytes must be >= 0");
    }

    if (log_every_n_ < 0) {
      throw std::invalid_argument("log_every_n must be >= 0");
    }

    publisher_ = this->create_publisher<sensor::msg::WorkloadMsg>(output_topic_, qos_depth_);
    subscription_ = this->create_subscription<sensor::msg::WorkloadMsg>(
      input_topic_,
      qos_depth_,
      std::bind(&PlannerNode::on_message, this, std::placeholders::_1));

    RCLCPP_INFO(
      this->get_logger(),
      "[n3] input=%s output=%s qos=%d compute_iterations=%d touch_bytes=%d patch_bytes=%d verify_shape=%s log_every_n=%d",
      input_topic_.c_str(),
      output_topic_.c_str(),
      qos_depth_,
      compute_iterations_,
      touch_bytes_,
      patch_bytes_,
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

  std::uint32_t heavy_checksum(const WorkloadMsg & msg, std::size_t touch_count) const
  {
    std::uint32_t acc = 0x9e3779b9U;

    for (int iter = 0; iter < compute_iterations_; ++iter) {
      for (std::size_t i = 0; i < touch_count; ++i) {
        const std::uint32_t value = static_cast<std::uint32_t>(msg.payload[i]);
        acc += value + static_cast<std::uint32_t>(i + iter);
        acc ^= (acc << 7);
        acc ^= (acc >> 9);
        acc += (value << (i % 3U));
      }
    }

    return acc;
  }

  void patch_payload(WorkloadMsg & msg, std::uint32_t checksum) const
  {
    const std::size_t patch_count = std::min<std::size_t>(
      static_cast<std::size_t>(patch_bytes_),
      msg.payload.size());

    for (std::size_t i = 0; i < patch_count; ++i) {
      const std::uint8_t mix = static_cast<std::uint8_t>((checksum >> ((i % 4U) * 8U)) & 0xffU);
      msg.payload[i] = static_cast<std::uint8_t>(msg.payload[i] ^ mix ^ static_cast<std::uint8_t>(i));
    }
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

    auto out_msg = *msg;
    const std::size_t touch_count = std::min<std::size_t>(
      static_cast<std::size_t>(touch_bytes_),
      out_msg.payload.size());
    const auto checksum = heavy_checksum(out_msg, touch_count);
    patch_payload(out_msg, checksum);

    if (log_every_n_ > 0 && (received_count_ % static_cast<std::uint64_t>(log_every_n_) == 0U)) {
      RCLCPP_INFO(
        this->get_logger(),
        "seq=%lu payload=%zu touch=%zu checksum=%u",
        out_msg.seq,
        out_msg.payload.size(),
        touch_count,
        checksum);
    }

    publisher_->publish(out_msg);
  }

  std::string input_topic_;
  std::string output_topic_;
  int qos_depth_;
  int compute_iterations_;
  int touch_bytes_;
  int patch_bytes_;
  bool verify_shape_;
  int log_every_n_;
  std::uint64_t received_count_;

  rclcpp::Publisher<WorkloadMsg>::SharedPtr publisher_;
  rclcpp::Subscription<WorkloadMsg>::SharedPtr subscription_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PlannerNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
