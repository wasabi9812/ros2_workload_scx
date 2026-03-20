#include "redbot02_core/redbot02_core.h"

Redbot::Core::Core():pnh("~")
{
    setParam();
    setPublisher();
    setSubscriber();
    Init();
}

Redbot::Core::~Core()
{
    driver->shutdown();
    driver.reset();
}

void Redbot::Core::Init()
{
    driver = std::make_shared<can::ThreadedSocketCANInterface>();
    if (!driver -> init(can_device, 0))
    {
        ROS_FATAL("[redbot_core] Failed to initialize can_device at %s", can_device.c_str());
    } 

    else
    {
        ROS_INFO("[redbot_core] Successfully connected to %s.", can_device.c_str());
        driver->recover();
    }
    frame_listener = driver->createMsgListenerM(this,&Redbot::Core::canCallback);

    // settingMotor();
    // startMotor();
    //timer= nh.createTimer(ros::Duration(1.0),&Redbot::Core::timerCallback,this);
}


void Redbot::Core::setParam()
{
    pnh.param("wheel_radius",wheel_radius,0.114);
    pnh.param("distance_wheels",distance_wheels,0.404);
    pnh.param("gear_ratio",gear_ratio,0.03);
    pnh.param("can_device",can_device,std::string("can0"));
    pnh.param("id_rpm",id_rpm,1);
    pnh.param("id_enc",id_enc,1);
    pnh.param("mode",mode,1);
    pnh.param("endcoder_resolution",endcoder_resolution,4096);
    pnh.param("pole_number",pole_number,4);
    pnh.param("can_hz",can_hz,10.0);
    pnh.param("max_rpm",max_rpm,200);
    pnh.param("break_option",break_option,1);
    pnh.param("rated_current",rated_current,8.0);
    pnh.param("max_current",max_current,16.0);
    pnh.param("hall_offset",hall_offset,240);
    pnh.param("Main1",Main1,0x1A1B101);
    pnh.param("Conveyor",Conveyor,0x1A1B103);
    pnh.param("Sub_Conveyor",Sub_Conveyor,0x1B1A103);
    pnh.param("Sub",Sub,0x1B1A101);
    pnh.param("enc_vel_gain",enc_vel_gain,0.9);
    pnh.param("enc_wvel_gain",enc_wvel_gain,0.93);

    motor = new Motor{0,};
    error = new Error{0,};
    conveyor = new ConveyorInfo{0,};
}

void::Redbot::Core::setPublisher()
{
    // When use casebot_core, It is not used.
    //enc_vel_pub_ = nh.advertise<geometry_msgs::Twist>("enc_vel",10);
}

void::Redbot::Core::setSubscriber()
{
    // When use casebot_core, It is not used.
    // cmd_vel_sub_ = nh.subscribe<geometry_msgs::Twist>("cmd_vel", 1, &Redbot::Core::cmdVelCallback, this);
    con_status_sub_ = nh.subscribe<std_msgs::UInt8MultiArray>("con_status", 1, &Redbot::Core::conveyorCallback, this);
}

bool Redbot::Core::sendCan(int id,char *data)
{
    can::Frame can_msgs;
    can_msgs.id = id;
    
    can_msgs.is_rtr = false;
    can_msgs.is_extended = true;
    can_msgs.is_error = false;
    can_msgs.dlc = 8;

    // set can data 
    for(int index=0;index<8;index++)
    can_msgs.data[index] = data[index];

#if CANSEND_DEBUGMODE
    ROS_INFO("[redbot02_core] <can> send ID : %d Data : %d %d %d %d %d %d %d %d",
    can_msgs.id,can_msgs.data[0],can_msgs.data[1],can_msgs.data[2],can_msgs.data[3],
    can_msgs.data[4],can_msgs.data[5],can_msgs.data[6],can_msgs.data[7]);
#endif
    // send can data
    bool res = driver->send(can_msgs);
    // recover can
    if (!res)
    {
        ROS_ERROR("[redbot02_core] Failed to send message");
        driver->recover();
    }
    return res;

return false;
}

// When use casebot_core, It is not used.
/*
void Redbot::Core::cmdVelCallback(const geometry_msgs::TwistConstPtr& msgs)
{

    char buf[8];
    int index = 0;
    //save cmd_vel msg
    this->cmd_vel.linear.x=msgs->linear.x;
    this->cmd_vel.linear.y=msgs->linear.y;
    this->cmd_vel.linear.z=msgs->linear.z;
    this->cmd_vel.angular.x=msgs->angular.x;
    this->cmd_vel.angular.y=msgs->angular.y;
    this->cmd_vel.angular.z=msgs->angular.z;

    // int16_t left = -1*(round((60/(2*Math_PI*wheel_radius)) * (cmd_vel.linear.x + (distance_wheels/2)*cmd_vel.angular.z) / gear_ratio));
    // int16_t right = (round((60/(2*Math_PI*wheel_radius)) * (cmd_vel.linear.x - (distance_wheels/2)*cmd_vel.angular.z) / gear_ratio));

    // ROS_INFO("send rpm left: %d right: %d",left,right);

    int16_t cmd_vel_x = cmd_vel.linear.x * SIGNIFICANT_FIGURES;  // 유효숫자
    int16_t cmd_vel_z = cmd_vel.angular.z * SIGNIFICANT_FIGURES;
    ROS_INFO("send cmd_vel linear: %d angular: %d", cmd_vel_x, cmd_vel_z);


    //set msgs
    buf[index++] = (cmd_vel_x & 0xff);              // cmd_vx 하위 00010100 [0]         data[0] | (data[1] << 8) = 00000000 00010100
    buf[index++] = (cmd_vel_x >> 8) & 0xff;         // cmd_vx 상위 00000000 [1]
    buf[index++] = 0x00;                            // X
    buf[index++] = 0x00;                            // X
    buf[index++] = (cmd_vel_z & 0xff);              // cmd_w 하위
    buf[index++] = (cmd_vel_z >> 8) & 0xff;         // cmd_w 상위
    buf[index++] = 0x00;                            // X
    buf[index] = 0x00;                              // X
    // send can msgs ID 0x6f 
    sendCan(Main1,buf);
    //ROS_INFO("send rpm linear: %f angular: %f", cmd_vel.linear.x,cmd_vel.angular.z);
}
*/
void Redbot::Core::conveyorCallback(const std_msgs::UInt8MultiArrayConstPtr& msgs)
{

    char buf[8];
    int index = 0;

    conveyor->con_status = msgs->data[0];

    buf[index++] = conveyor->con_status;              // 0:stop 1:action         data[0] | (data[1] << 8) = 00000000 00010100
    buf[index++] = 0x00;                // X
    buf[index++] = 0x00;                // 0:foward 1:backward               // X
    buf[index++] = 0x00;
    buf[index++] = 0x00;  
    buf[index++] = 0x00;  
    buf[index++] = 0x00;  
    buf[index] = 0x00;     

    sendCan(Conveyor,buf);
}

void Redbot::Core::subconveyorCallback(const can::Frame& msgs)
{
    conveyor->carry_status = msgs.data[0];
}
///////////////////////////////////////////////////////////////////////////////////

void Redbot::Core::canCallback(const can::Frame& msgs)
{
    // When use casebot_core, It is not used.
    // if(msgs.id == Sub) 
    //     encCallback(msgs);
    if(msgs.id == Sub_Conveyor)
        subconveyorCallback(msgs);
}

// When use casebot_core, It is not used.
/*
void Redbot::Core::encCallback(const can::Frame& msgs)
{ 
    int16_t enc_vx, enc_w;

    enc_vx = (int16_t)msgs.data[0] | ((int16_t)msgs.data[1]<<8);
    enc_w = (int16_t)msgs.data[4] | ((int16_t)msgs.data[5]<<8);

    //ROS_INFO("enc_vel_gain: %f", enc_vel_gain);

    enc_vel.linear.x = (double) enc_vx / SIGNIFICANT_FIGURES * enc_vel_gain;
    enc_vel.angular.z = (double) -enc_w / SIGNIFICANT_FIGURES * enc_wvel_gain;
    enc_vel_pub_.publish(enc_vel);

    // ROS_INFO("send enc_vel linear: %f angular: %f", enc_vel.linear.x, enc_vel.angular.z);
}
*/

/*
// 하위로부터 rpm 값 수신 , 추후에는 계산된 twist 값 수신
void Redbot::Core::encCallback(const can::Frame& msgs)
{ 
    int16_t enc_l, enc_r;

    // 왼쪽 모터의 rpm 값 수신
    enc_l = (int16_t)msgs.data[4] | ((int16_t)msgs.data[5]<<8);

    // 오른쪽 모터의 rpm 값 수신
    enc_r = (int16_t)msgs.data[6] | ((int16_t)msgs.data[7]<<8);
    
    ROS_INFO("POSI_L: %f POSI_R: %f",motor->enc_l, motor->enc_r);
    
    // ToTwist (추후 kinematics가 하위에 추가되면 삭제할 예정)
    double left = (double) enc_l * gear_ratio;
    double right = (double) enc_r * gear_ratio;

    right = (left+right)*(Math_PI*wheel_radius/60);
    left = (-left+right)*((Math_PI*wheel_radius)/(30*distance_wheels));
    ROS_INFO("rrrrr%f %f",right,left);

    geometry_msgs::Twist enc_vel;
    
    enc_vel.linear.x = right + left;
    enc_vel.angular.z = (right - left) / (30*distance_wheels);
    // ROS_INFO("receive enc %f %f", motor->enc_vel.linear.x, motor->enc_vel.angular.z);

    enc_vel_pub_.publish(enc_vel);
}
*/
// geometry_msgs::Twist Redbot::Core::parse()
// {

// }


// 하위로부터 hall sensor 값 (encoder 값) 콜백 XXXXXX 수신할 필요 없음 rpm 수신!!! gear_ratio !!!
// void Redbot::Core::hallCallback(const can::Frame& msgs)
// { 
//     long enc_l, enc_r;

//     // 왼쪽 모터의 포지션 값 수신
//     if(msgs.data[3] == 0){
//         enc_l = (int32_t)msgs.data[4] | (int32_t)msgs.data[5]<<8 | (int32_t)msgs.data[6]<<16 | ((int32_t)msgs.data[7]<< 32 );
//         motor->enc_l = enc_l;
//     }
//     // 오른쪽 모터의 포지션 값 수신
//     if(msgs.data[3] == 1){
//         enc_r = (int32_t)msgs.data[4] | (int32_t)msgs.data[5]<<8 | (int32_t)msgs.data[6]<<16 | ((int32_t)msgs.data[7]<< 32 );
//         motor->enc_r = enc_r;
//     }
    
//     ROS_INFO("POSI_L: %f POSI_R: %f",motor->enc_l, motor->enc_r);
// }