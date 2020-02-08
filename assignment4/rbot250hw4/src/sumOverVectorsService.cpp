#include "ros/ros.h"
#include "rbot250hw4/sumOverVectors.h"

bool sum(rbot250hw4::sumOverVectors::Request  &req,
         rbot250hw4::sumOverVectors::Response &res)
{
  res.sum = req.angular.x + req.angular.y + req.angular.z + req.linear.x + req.linear.y + req.linear.z;

  /**there may be an issue with the type of the request. THere may (likely) needs to be a type
  conversion because of the twist type containing two vectors of doubles **/
  ROS_INFO("request: angular=%f, linear=%f", (double)req.angular, (double)req.b);
  ROS_INFO("sending back response: [%f]", (double)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sumOverVectorsServer");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("sumOverVectors", sum);
  ROS_INFO("Ready to sum linear and angular");
  ros::spin();

  return 0;
}
