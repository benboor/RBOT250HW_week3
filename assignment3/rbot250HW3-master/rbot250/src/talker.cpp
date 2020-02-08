#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv){

	ros::init(argc, argv, "kayaTalker");
	ros::NodeHandle n;

	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("kayaTwist", 1000);
	ros::Rate loop_rate(10);

	int count = 0;	
	while (ros::ok()){

		geometry_msgs::Twist msg;
		msg.linear.x = 1.2;
		msg.linear.y = 0;
		msg.linear.z = 0;
		msg.angular.x = 0;
		msg.angular.y = 0;
		msg.angular.z = 1.571;
 
	    pub.publish(msg);
	    ros::spinOnce();
	    loop_rate.sleep();
		++count;		

	}
	
	return 0;
}