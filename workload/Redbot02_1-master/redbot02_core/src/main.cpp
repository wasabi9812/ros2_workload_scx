#include "redbot02_core/redbot02_core.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "redbot02_core");
	ros::Time::init();
	Redbot::Core core;
  	ros::spin();
}

        
