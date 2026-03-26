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

class FanoutSubscriberNodeHeavy : public rclcpp::Node
{
public:
  FanoutSubscriberNodeHeavy()
  : Node("n7"), total_received_(0)
  {
    this->declare_parameter<int>("qos_depth", 10);
    this->declare_parameter<bool>("enable_lidar", true);
    this->declare_parameter<bool>("enable_odom", true);
    this->declare_parameter<bool>("enable_camera", true);
    this->declare_parameter<bool>("enable_can", true);
    this->declare_parameter<std::string>("lidar_topic", "/fanout/lidar");
    this->declare_parameter<std::string>("odom_topic", "/fanout/odom");
    this->declare_parameter<std::string>("camera_topic", "/fanout/camera");
    this->declare_parameter<std::string>("can_topic", "/fanout/can");
    this->declare_parameter<bool>("verify_shape", true);
    this->declare_parameter<int>("compute_iterations", 12);
    this->declare_parameter<int>("touch_bytes", 1024);
    this->declare_parameter<std::string>("checksum_mode", "xor32");
    this->declare_parameter<int>("log_every_n", 100);

    qos_depth_ = this->get_parameter("qos_depth").as_int();
    enable_lidar_ = this->get_parameter("enable_lidar").as_bool();
    enable_odom_ = this->get_parameter("enable_odom").as_bool();
    enable_camera_ = this->get_parameter("enable_camera").as_bool();
    enable_can_ = this->get_parameter("enable_can").as_bool();
    lidar_topic_ = this->get_parameter("lidar_topic").as_string();
    odom_topic_ = this->get_parameter("odom_topic").as_string();
    camera_topic_ = this->get_parameter("camera_topic").as_string();
    can_topic_ = this->get_parameter("can_topic").as_string();
    verify_shape_ = this->get_parameter("verify_shape").as_bool();
    compute_iterations_ = this->get_parameter("compute_iterations").as_int();
    touch_bytes_ = this->get_parameter("touch_bytes").as_int();
    checksum_mode_ = this->get_parameter("checksum_mode").as_string();
    log_every_n_ = this->get_parameter("log_every_n").as_int();

    if (qos_depth_ < 1 || compute_iterations_ < 1 || touch_bytes_ < 1 || log_every_n_ < 0) {
      throw std::invalid_argument("invalid n7 parameter value");
    }

    if (checksum_mode_ != "byte_sum" && checksum_mode_ != "xor32") {
      throw std::invalid_argument("checksum_mode must be 'byte_sum' or 'xor32'");
    }

    if (enable_lidar_) {
      lidar_sub_ = this->create_subscription<sensor::msg::WorkloadMsg>(
        lidar_topic_, qos_depth_, [this](const WorkloadMsg::SharedPtr msg) { this->on_message("lidar", msg); });
    }
    if (enable_odom_) {
      odom_sub_ = this->create_subscription<sensor::msg::WorkloadMsg>(
        odom_topic_, qos_depth_, [this](const WorkloadMsg::SharedPtr msg) { this->on_message("odom", msg); });
    }
    if (enable_camera_) {
      camera_sub_ = this->create_subscription<sensor::msg::WorkloadMsg>(
        camera_topic_, qos_depth_, [this](const WorkloadMsg::SharedPtr msg) { this->on_message("camera", msg); });
    }
    if (enable_can_) {
      can_sub_ = this->create_subscription<sensor::msg::WorkloadMsg>(
        can_topic_, qos_depth_, [this](const WorkloadMsg::SharedPtr msg) { this->on_message("can", msg); });
    }

    RCLCPP_INFO(
      this->get_logger(),
      "[n7] qos=%d lidar=%s odom=%s camera=%s can=%s verify_shape=%s compute_iterations=%d touch_bytes=%d checksum=%s log_every_n=%d",
      qos_depth_,
      enable_lidar_ ? lidar_topic_.c_str() : "off",
      enable_odom_ ? odom_topic_.c_str() : "off",
      enable_camera_ ? camera_topic_.c_str() : "off",
      enable_can_ ? can_topic_.c_str() : "off",
      verify_shape_ ? "true" : "false",
      compute_iterations_,
      touch_bytes_,
      checksum_mode_.c_str(),
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

  std::uint32_t compute_checksum(const WorkloadMsg & msg, std::size_t touch_count) const
  {
    std::uint32_t acc = 0;
    for (int iter = 0; iter < compute_iterations_; ++iter) {
      for (std::size_t i = 0; i < touch_count; ++i) {
        const std::uint32_t value = static_cast<std::uint32_t>(msg.payload[i]);
        if (checksum_mode_ == "xor32") {
          acc ^= (value << ((i % 4U) * 8U));
          acc = (acc << 5) | (acc >> 27);
        } else {
          acc += value + static_cast<std::uint32_t>(iter + i);
        }
      }
    }
    return acc;
  }

  void on_message(const std::string & source_name, const WorkloadMsg::SharedPtr msg)
  {
    ++total_received_;

    if (verify_shape_) {
      const auto expected = expected_payload_size(*msg);
      if (expected != msg->payload.size()) {
        RCLCPP_WARN(
          this->get_logger(),
          "[%s] seq=%lu shape mismatch expected=%zu actual=%zu",
          source_name.c_str(),
          msg->seq,
          expected,
          msg->payload.size());
      }
    }

    const std::size_t touch_count = std::min<std::size_t>(static_cast<std::size_t>(touch_bytes_), msg->payload.size());
    const auto checksum = compute_checksum(*msg, touch_count);

    if (log_every_n_ > 0 && (total_received_ % static_cast<std::uint64_t>(log_every_n_) == 0U)) {
      RCLCPP_INFO(
        this->get_logger(),
        "[%s] seq=%lu profile=%s payload=%zu touch=%zu checksum=%u",
        source_name.c_str(),
        msg->seq,
        msg->profile.c_str(),
        msg->payload.size(),
        touch_count,
        checksum);
    }
  }

  int qos_depth_;
  bool enable_lidar_;
  bool enable_odom_;
  bool enable_camera_;
  bool enable_can_;
  std::string lidar_topic_;
  std::string odom_topic_;
  std::string camera_topic_;
  std::string can_topic_;
  bool verify_shape_;
  int compute_iterations_;
  int touch_bytes_;
  std::string checksum_mode_;
  int log_every_n_;
  std::uint64_t total_received_;

  rclcpp::Subscription<WorkloadMsg>::SharedPtr lidar_sub_;
  rclcpp::Subscription<WorkloadMsg>::SharedPtr odom_sub_;
  rclcpp::Subscription<WorkloadMsg>::SharedPtr camera_sub_;
  rclcpp::Subscription<WorkloadMsg>::SharedPtr can_sub_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<FanoutSubscriberNodeHeavy>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
