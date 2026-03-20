#ifndef __Redbot_CORE_H__
#define __Redbot_CORE_H__

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TransformStamped.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Int16.h>
#include <std_msgs/UInt8MultiArray.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Bool.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Range.h>
#include <tf/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <socketcan_interface/string.h>
#include <socketcan_interface/threading.h>
#include <socketcan_interface/socketcan.h>
#include <can_msgs/Frame.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/LaserScan.h>
#include <string>
#include <queue>
#include <mutex>
#include <vector>
#include <boost/thread/thread.hpp>

#define Math_PI 3.14159
#define SIGNIFICANT_FIGURES 100

namespace Redbot
{

typedef struct 
{
	double enc_l;
	double enc_r;
}Motor;

typedef struct 
{
	int right;
	int left;
}Error;

typedef struct
{
	uint8_t con_status;
	uint8_t carry_status;
	uint8_t loading_status;
	uint8_t unloading_status;
}ConveyorInfo;

class Core
{
private:
	ros::NodeHandle nh;
	ros::NodeHandle pnh;

	ros::Publisher enc_vel_pub_;
	ros::Subscriber cmd_vel_sub_;
	ros::Subscriber con_status_sub_;
	ros::Timer timer;
	ros::Timer alarm;

	ros::Time current_time;
	ros::Time last_time;
	ros::Duration alarm_time;

	std_msgs::UInt8MultiArray con_status;

	geometry_msgs::Twist cmd_vel;
	geometry_msgs::Twist enc_vel;
	boost::thread alarm_thread;

	double wheel_radius;
	double distance_wheels;
	double gear_ratio;
	double enc_vel_gain;
	double enc_wvel_gain;
	std::string can_device;
	int id_enc;
	int id_rpm;
	int mode;
	int endcoder_resolution;
	int pole_number;
	int max_rpm;
	int break_option;
	double rated_current;
	double max_current;
	double can_hz;
	int hall_offset;

	int32_t Main1;
	int32_t Main2;
	int32_t Conveyor;
	int32_t Sub_Conveyor;
	int32_t Sub;
	int32_t Motordriver;
	
	Motor *motor;
	Error *error;
	ConveyorInfo *conveyor;
	can::ThreadedSocketCANInterfaceSharedPtr driver;
	can::FrameListenerConstSharedPtr frame_listener;     

	void cmdVelCallback(const geometry_msgs::TwistConstPtr& msgs);

	void conveyorCallback(const std_msgs::UInt8MultiArrayConstPtr& msgs);
	void subconveyorCallback(const can::Frame& msgs);

	void canCallback(const can::Frame& msgs);
	void encCallback(const can::Frame& msgs);
	void errorCallback(const can::Frame& msgs);

	void hallCallback(const can::Frame& msgs);

	void timerCallback(const ros::TimerEvent& event);
	void alarmCallback(const ros::TimerEvent& event);

	void SendState();
	void alarmThread(int rate);
	void SendEmergencyStop();

	void Init();
	void setParam();
	void setPublisher();
	void setSubscriber();

	void settingMotor();
	void startMotor();
	void veloctyMode();
	void synchronousMode();
	void AsynchronousMode();
	void moterEnable();
	void save();

	bool sendCan(int id,char *data);

public:
	Core();
	~Core();

	void spin();

	geometry_msgs::Twist parse();
};

};

#endif