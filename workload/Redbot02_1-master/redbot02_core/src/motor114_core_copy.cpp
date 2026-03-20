#include "motor114_core/motor114_core.h"

Motor114::Core::Core():pnh("~")
{
    setParam();
    setPublisher();
    setSubscriber();
    Init();
}

Motor114::Core::~Core()
{
    driver->shutdown();
    driver.reset();
}

void Motor114::Core::Init()
{
    driver = std::make_shared<can::ThreadedSocketCANInterface>();
    if (!driver -> init(can_device, 0))
    {
        ROS_FATAL("[motor114_core] Failed to initialize can_device at %s", can_device.c_str());
    } 

    else
    {
        ROS_INFO("[motor114_core] Successfully connected to %s.", can_device.c_str());
        driver->recover();
    }
    frame_listener = driver->createMsgListenerM(this,&Motor114::Core::canCallback);
    settingMotor();
    startMotor();
    timer= nh.createTimer(ros::Duration(1.0),&Motor114::Core::timerCallback,this);
}

void Motor114::Core::settingMotor()
{
    clearError();
    encoderSet((int16_t)endcoder_resolution);
    poleSet((int16_t)pole_number);
    ratedCurrent(rated_current);
    maxCurrent(max_current);
    hallOffset(hall_offset);
    breakOption(break_option);
    save();

}

void Motor114::Core::startMotor()
{
    moterEnable();
    veloctyMode();
    synchronousMode();
}

void Motor114::Core::setParam()
{
    pnh.param("wheel_radius",wheel_radius,0.10);
    pnh.param("distance_wheels",distance_wheels,0.45);
    pnh.param("gear_ratio",gear_ratio,1.0);
    pnh.param("can_device",can_device,std::string("can0"));
    pnh.param("id",id,1537);
    pnh.param("mode",mode,1);
    pnh.param("endcoder_resolution",endcoder_resolution,4096);
    pnh.param("pole_number",pole_number,20);
    pnh.param("can_hz",can_hz,10.0);
    pnh.param("max_rpm",max_rpm,200);
    pnh.param("break_option",break_option,1);
    pnh.param("rated_current",rated_current,8.0);
    pnh.param("max_current",max_current,16.0);
    pnh.param("hall_offset",hall_offset,240);

    motor = new Motor{0,};
    error = new Error{0,};
}

void::Motor114::Core::setPublisher()
{

}

void::Motor114::Core::setSubscriber()
{
    cmd_vel_sub_ = nh.subscribe<geometry_msgs::Twist>("cmd_vel", 1, &Motor114::Core::cmdVelCallback, this);
}

bool Motor114::Core::sendCan(int id,char *data)
{
    can::Frame can_msgs;
    can_msgs.id = id;
    can_msgs.is_rtr = false;
    can_msgs.is_extended = false;
    can_msgs.is_error = false;
    can_msgs.dlc = 8;

    // set can data 
    for(int index=0;index<8;index++)
    can_msgs.data[index] = data[index];

#if CANSEND_DEBUGMODE
    ROS_INFO("[motor114_core] <can> send ID : %d Data : %d %d %d %d %d %d %d %d",
    can_msgs.id,can_msgs.data[0],can_msgs.data[1],can_msgs.data[2],can_msgs.data[3],
    can_msgs.data[4],can_msgs.data[5],can_msgs.data[6],can_msgs.data[7]);
#endif
    // send can data
    bool res = driver->send(can_msgs);
    // recover can
    if (!res)
    {
        ROS_ERROR("[motor114_core] Failed to send message");
        driver->recover();
    }
    return res;

return false;
}

void Motor114::Core::cmdVelCallback(const geometry_msgs::TwistConstPtr& msgs)
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

    int16_t left = -1*(round((60/(2*Math_PI*wheel_radius)) * (cmd_vel.linear.x + (distance_wheels/2)*cmd_vel.angular.z) / gear_ratio));
    int16_t right = (round((60/(2*Math_PI*wheel_radius)) * (cmd_vel.linear.x - (distance_wheels/2)*cmd_vel.angular.z) / gear_ratio));

    ROS_INFO("send rpm left: %d right: %d",left,right);

    //set msgs
    buf[index++] = 0x23;
    buf[index++] = 0xff;
    buf[index++] = 0x60;
    buf[index++] = 0x03;
    buf[index++] = (left & 0xff);
    buf[index++] = (left>>8) & 0xff;
    buf[index++] = right & 0xff;
    buf[index] = (right>>8) & 0xff;
    // send can msgs ID 0x6f 
    sendCan(id,buf);
}

void Motor114::Core::veloctyMode()
{
    char buf[8];
    int index = 0;

    //set msgs
    buf[index++] = 0x2f;
    buf[index++] = 0x60;
    buf[index++] = 0x60;
    buf[index++] = 0x00;
    buf[index++] = 0x03;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index] = 0x00;
    // send can msgs ID 0x6f 
    sendCan(id,buf);
    ros::Duration(1/can_hz).sleep();

}

void Motor114::Core::synchronousMode()
{
    char buf[8];
    int index = 0;

    //set msgs
    buf[index++] = 0x2b;
    buf[index++] = 0x0f;
    buf[index++] = 0x20;
    buf[index++] = 0x00;
    buf[index++] = 0x01;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index] = 0x00;
    // send can msgs ID 0x6f 
    sendCan(id,buf);
    ros::Duration(1/can_hz).sleep();

}

void Motor114::Core::AsynchronousMode()
{
    char buf[8];
    int index = 0;

    //set msgs
    buf[index++] = 0x2b;
    buf[index++] = 0x0f;
    buf[index++] = 0x20;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index] = 0x00;
    // send can msgs ID 0x6f 
    sendCan(id,buf);
    ros::Duration(1/can_hz).sleep();
  
}

void Motor114::Core::moterEnable()
{
    char buf[8];
    int index = 0;
    char seq[4] = {0x00,0x06,0x07,0x0f};
    //set msgs 
    for(int i =0;i<4;i++)
    {
        buf[index++] = 0x2b;
        buf[index++] = 0x40;
        buf[index++] = 0x60;
        buf[index++] = 0x00;
        buf[index++] = seq[i];
        buf[index++] = 0x00;
        buf[index++] = 0x00;
        buf[index] = 0x00;
        index = 0;
        sendCan(id,buf);
        ros::Duration(1/can_hz).sleep();
    }
    // send can msgs ID 0x6f 
    
}

void Motor114::Core::encoderSet(int16_t enc)
{
    char buf[8];
    int index = 0;
    for(int i=0;i<2;i++)
    {
        buf[index++] = 0x2b;
        buf[index++] = 0x0e;
        buf[index++] = 0x20;
        buf[index++] = i+1;
        buf[index++] = (enc & 0xff);
        buf[index++] = (enc>>8) & 0xff;
        buf[index++] = 0x00;
        buf[index] = 0x00;
        index = 0;
        sendCan(id,buf);
        ros::Duration(1/can_hz).sleep();
    }
}

void Motor114::Core::poleSet(int16_t pole)
{
    char buf[8];
    int index = 0;
    for(int i=0;i<2;i++)
    {
        buf[index++] = 0x2b;
        buf[index++] = 0x0c;
        buf[index++] = 0x20;
        buf[index++] = i+1;
        buf[index++] = (pole & 0xff);
        buf[index++] = (pole>>8) & 0xff;
        buf[index++] = 0x00;
        buf[index] = 0x00;
        index = 0;
        sendCan(id,buf);
        ros::Duration(1/can_hz).sleep();
    }
}

void Motor114::Core::save()
{
    char buf[8];
    int index = 0;
    buf[index++] = 0x2b;
    buf[index++] = 0x10;
    buf[index++] = 0x20;
    buf[index++] = 0x00;
    buf[index++] = 0x01;
    buf[index++] =  0x00;
    buf[index++] = 0x00;
    buf[index] = 0x00;
    index = 0;
    sendCan(id,buf);
    ros::Duration(1/can_hz).sleep();

}

void Motor114::Core::breakOption(int option)
{
    char buf[8];
    int index = 0;
    buf[index++] = 0x2b;
    buf[index++] = 0x07;
    buf[index++] = 0x20;
    buf[index++] = 0x00;
    buf[index++] = (char)option;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index] = 0x00;
    index = 0;
    sendCan(id,buf);
    ros::Duration(1/can_hz).sleep();
}

void Motor114::Core::maxRPM(int16_t rpm)
{
    char buf[8];
    int index = 0;
    buf[index++] = 0x2b;
    buf[index++] = 0x08;
    buf[index++] = 0x20;
    buf[index++] = 0x00;
    buf[index++] = (rpm & 0xff);
    buf[index++] = (rpm>>8) & 0xff;
    buf[index++] = 0x00;
    buf[index] = 0x00;
    sendCan(id,buf);
    ros::Duration(1/can_hz).sleep();
}

void Motor114::Core::ratedCurrent(double current)
{
    char buf[8];
    for(int i=0;i<2;i++)
    {
        int index = 0;
        buf[index++] = 0x2b;
        buf[index++] = 0x14;
        buf[index++] = 0x20;
        buf[index++] = i+1;
        buf[index++] = (int)(current*10);
        buf[index++] = 0x00;
        buf[index++] = 0x00;
        buf[index] = 0x00;
        sendCan(id,buf);
        ros::Duration(1/can_hz).sleep();
    }
}

void Motor114::Core::maxCurrent(double current)
{
    char buf[8];
    for(int i=0;i<2;i++)
    {
        int index = 0;
        buf[index++] = 0x2b;
        buf[index++] = 0x15;
        buf[index++] = 0x20;
        buf[index++] = i+1;
        buf[index++] = (int)(current*10);
        buf[index++] = 0x00;
        buf[index++] = 0x00;
        buf[index] = 0x00;
        sendCan(id,buf);
        ros::Duration(1/can_hz).sleep();
    }
}

void Motor114::Core::hallOffset(int16_t dgree)
{
    char buf[8];
    for(int i=0;i<2;i++)
    {
        int index = 0;
        buf[index++] = 0x2b;
        buf[index++] = 0x11;
        buf[index++] = 0x20;
        buf[index++] = i+1;
        buf[index++] = (dgree & 0xff);
        buf[index++] = (dgree>>8) & 0xff;
        buf[index++] = 0x00;
        buf[index] = 0x00;
        sendCan(id,buf);
        ros::Duration(1/can_hz).sleep();
    }
}


void Motor114::Core::reqEnc()
{
    char buf[8];
    int index = 0;
    buf[index++] = 0x40;
    buf[index++] = 0x6c;
    buf[index++] = 0x60;
    buf[index++] = 0x03;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index] = 0x00;
    sendCan(id,buf);
    ros::Duration(1/can_hz).sleep();
}

void Motor114::Core::clearError()
{
    char buf[8];
    int index = 0;
    buf[index++] = 0x2b;
    buf[index++] = 0x40;
    buf[index++] = 0x60;
    buf[index++] = 0x00;
    buf[index++] = 0x80;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index] = 0x00;
    sendCan(id,buf);
    ros::Duration(1/can_hz).sleep();
}

void Motor114::Core::reqState()
{
    char buf[8];
    int index = 0;
    buf[index++] = 0x40;
    buf[index++] = 0x3f;
    buf[index++] = 0x60;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index++] = 0x00;
    buf[index] = 0x00;
    sendCan(id,buf);
    ros::Duration(1/can_hz).sleep();
}


void Motor114::Core::canCallback(const can::Frame& msgs)
{
    
    switch(msgs.id)
    {
        case 0x701:
            startMotor();
            break;

        case 0x581:
            if(msgs.data[1] == 0x6c && msgs.data[2] == 0x60)
                encCallback(msgs);
            if(msgs.data[1] == 0x3f && msgs.data[2] == 0x60)
                errorCallback(msgs);
            break;  
    }
}

void Motor114::Core::encCallback(const can::Frame& msgs)
{
    int16_t rrpm,lrpm;
    lrpm = (int16_t)msgs.data[4] | ((int16_t)msgs.data[5]<<8);
    rrpm = (int16_t)msgs.data[6] | ((int16_t)msgs.data[7]<<8);
    motor->lrpm = (-lrpm) / 10.0;
    motor->rrpm = (rrpm) / 10.0;

    ROS_INFO("LRPM: %f RRPM: %f",motor->lrpm,motor->rrpm);
}

void Motor114::Core::errorCallback(const can::Frame& msgs)
{
    error->left = (int16_t)msgs.data[4] | ((int16_t)msgs.data[5]<<8);
    error->right = (int16_t)msgs.data[6] | ((int16_t)msgs.data[7]<<8);
    errorPrint();
}

void Motor114::Core::errorPrint()
{
    if(error->right == 0x01 || error->left == 0x01)
        ROS_INFO("OVER VOLTAGE");
    else if(error->right == 0x02 || error->left == 0x02)
        ROS_INFO("UNDER VOLTAGE");
    else if(error->right == 0x0100 || error->left == 0x0100)
        ROS_INFO("EEPROM ERROR");   
    else if(error->right == 0x04 || error->left == 0x04)
        ROS_INFO("OVER CURRENT");   
    else if(error->right == 0x08 || error->left == 0x08)
        ROS_INFO("OVER LOAD");   
    else if(error->right == 0x10 || error->left == 0x10)
        ROS_INFO("CURRENT OUT OF RANGE");   
    else if(error->right == 0x20 || error->left == 0x20)
        ROS_INFO("ECODER OUT OF RANGE");  
    else if(error->right == 0x40 || error->left == 0x40)
        ROS_INFO("VELOCITY OUT OF RANGE");
    else if(error->right == 0x80 || error->left == 0x80)
        ROS_INFO("REFERENCE VOLTAGE ERROR");
    if(!(error->right == 0x00 && error->left == 0x00))
    {
        clearError();
        startMotor();
    }
}

void Motor114::Core::timerCallback(const ros::TimerEvent& event)
{
    reqEnc();
    reqState();
}

