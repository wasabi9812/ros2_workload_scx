#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor/msg/workload_msg.hpp"

class FanoutPublisherNode : public rclcpp::Node
{
public:
  FanoutPublisherNode()
  : Node("n5"), received_count_(0)
  {
    this->declare_parameter<std::string>("input_topic", "/preprocessed");
    this->declare_parameter<int>("qos_depth", 10);
    this->declare_parameter<bool>("enable_lidar", true);
    this->declare_parameter<bool>("enable_odom", true);
    this->declare_parameter<bool>("enable_camera", true);
    this->declare_parameter<bool>("enable_can", true);
    this->declare_parameter<std::string>("lidar_topic", "/fanout/lidar");
    this->declare_parameter<std::string>("odom_topic", "/fanout/odom");
    this->declare_parameter<std::string>("camera_topic", "/fanout/camera");
    this->declare_parameter<std::string>("can_topic", "/fanout/can");
    this->declare_parameter<int>("log_every_n", 100);

    input_topic_ = this->get_parameter("input_topic").as_string();
    qos_depth_ = this->get_parameter("qos_depth").as_int();
    enable_lidar_ = this->get_parameter("enable_lidar").as_bool();
    enable_odom_ = this->get_parameter("enable_odom").as_bool();
    enable_camera_ = this->get_parameter("enable_camera").as_bool();
    enable_can_ = this->get_parameter("enable_can").as_bool();
    lidar_topic_ = this->get_parameter("lidar_topic").as_string();
    odom_topic_ = this->get_parameter("odom_topic").as_string();
    camera_topic_ = this->get_parameter("camera_topic").as_string();
    can_topic_ = this->get_parameter("can_topic").as_string();
    log_every_n_ = this->get_parameter("log_every_n").as_int();

    if (qos_depth_ < 1) {
      throw std::invalid_argument("qos_depth must be >= 1");
    }

    if (log_every_n_ < 0) {
      throw std::invalid_argument("log_every_n must be >= 0");
    }

    if (enable_lidar_) {
      lidar_pub_ = this->create_publisher<sensor::msg::WorkloadMsg>(lidar_topic_, qos_depth_);
    }
    if (enable_odom_) {
      odom_pub_ = this->create_publisher<sensor::msg::WorkloadMsg>(odom_topic_, qos_depth_);
    }
    if (enable_camera_) {
      camera_pub_ = this->create_publisher<sensor::msg::WorkloadMsg>(camera_topic_, qos_depth_);
    }
    if (enable_can_) {
      can_pub_ = this->create_publisher<sensor::msg::WorkloadMsg>(can_topic_, qos_depth_);
    }

    subscription_ = this->create_subscription<sensor::msg::WorkloadMsg>(
      input_topic_,
      qos_depth_,
      std::bind(&FanoutPublisherNode::on_message, this, std::placeholders::_1));

    RCLCPP_INFO(
      this->get_logger(),
      "[n5] input=%s qos=%d lidar=%s odom=%s camera=%s can=%s log_every_n=%d",
      input_topic_.c_str(),
      qos_depth_,
      enable_lidar_ ? lidar_topic_.c_str() : "off",
      enable_odom_ ? odom_topic_.c_str() : "off",
      enable_camera_ ? camera_topic_.c_str() : "off",
      enable_can_ ? can_topic_.c_str() : "off",
      log_every_n_);
  }

private:
  using WorkloadMsg = sensor::msg::WorkloadMsg;

  void publish_branch(
    const rclcpp::Publisher<WorkloadMsg>::SharedPtr & publisher,
    const WorkloadMsg::SharedPtr & msg,
    const std::string & profile_name,
    const std::string & encoding_name)
  {
    if (!publisher) {
      return;
    }

    auto out_msg = *msg;
    out_msg.profile = profile_name;
    out_msg.encoding = encoding_name;
    publisher->publish(out_msg);
  }

  void on_message(const WorkloadMsg::SharedPtr msg)
  {
    ++received_count_;

    publish_branch(lidar_pub_, msg, "lidar", "range32");
    publish_branch(odom_pub_, msg, "odom", "pose32");
    publish_branch(camera_pub_, msg, "camera", "rgb8");
    publish_branch(can_pub_, msg, "can", "frame8");

    if (log_every_n_ > 0 && (received_count_ % static_cast<std::uint64_t>(log_every_n_) == 0U)) {
      RCLCPP_INFO(
        this->get_logger(),
        "seq=%lu published branches lidar=%s odom=%s camera=%s can=%s",
        msg->seq,
        enable_lidar_ ? "on" : "off",
        enable_odom_ ? "on" : "off",
        enable_camera_ ? "on" : "off",
        enable_can_ ? "on" : "off");
    }
  }

  std::string input_topic_;
  int qos_depth_;
  bool enable_lidar_;
  bool enable_odom_;
  bool enable_camera_;
  bool enable_can_;
  std::string lidar_topic_;
  std::string odom_topic_;
  std::string camera_topic_;
  std::string can_topic_;
  int log_every_n_;
  std::uint64_t received_count_;

  rclcpp::Publisher<WorkloadMsg>::SharedPtr lidar_pub_;
  rclcpp::Publisher<WorkloadMsg>::SharedPtr odom_pub_;
  rclcpp::Publisher<WorkloadMsg>::SharedPtr camera_pub_;
  rclcpp::Publisher<WorkloadMsg>::SharedPtr can_pub_;
  rclcpp::Subscription<WorkloadMsg>::SharedPtr subscription_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<FanoutPublisherNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
