#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"


void velMsgCallback(const geometry_msgs::Twist& msg){

    ROS_INFO("geometry_msgs/Vector3 linear float64 x: [%f]", msg.linear.x,
            "float64 x: [%f]", msg.linear.y,
            "float64 z: [%f]",  msg.linear.z);

    ROS_INFO("geometry_msgs/Vector3 angular float64 x: [%f]", msg.angular.x,
            "float64 x: [%f]", msg.angular.y,
            "float64 z: [%f]",  msg.angular.z);
}

int main(int argc, char **argv){

	ros::init(argc, argv, "kayaListener");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("kayaTwist", 1000, velMsgCallback);
	ros::spin();

	return 0;
}


