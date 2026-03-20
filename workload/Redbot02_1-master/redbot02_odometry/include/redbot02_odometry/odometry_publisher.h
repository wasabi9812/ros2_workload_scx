#ifndef __REDBOT02_ODOMETRY_H__
#define __REDBOT02_ODOMETRY_H__

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TransformStamped.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <string>
#include <boost/thread/thread.hpp>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int16MultiArray.h>

namespace Redbot
{

struct RobotState
{
  double x;
  double y;
  double z;
  double roll;
  double pitch;
  double yaw;
};

class ToOdom
{

private:
  ros::NodeHandle nh;
  ros::NodeHandle pnh;
  
  ros::Publisher odom_pub_;
  ros::Subscriber enc_vel_sub_;
  tf::TransformBroadcaster odom_tf_broadcaster_;
  
  boost::thread read_thread;

  int read_rate;

  geometry_msgs::Twist enc_vel;
  nav_msgs::Odometry odom;
  geometry_msgs::TransformStamped odom_tf;

  std::string robot_name;

  double current_time, last_time;
  double dx, dy, dyaw, dt;
  double enc_vel_gain, enc_wvel_gain;
  RobotState *robot_state;
  void init();
  void setParam();
  void encVelToOdomTF();
  void readThread(int rate);
  void encVelCallback(const geometry_msgs::TwistConstPtr& msgs);
  void setPublisher();
	void setSubscriber();
  std::mutex enc_vel_mutex;

public:
  ros::Rate loop_rate;
  ToOdom();
  ~ToOdom();
};

};

#endif