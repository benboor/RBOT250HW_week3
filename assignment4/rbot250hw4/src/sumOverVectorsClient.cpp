#include "ros/ros.h"
#include "rbot250hw4/sumOverVectors.h"
#include <cstdlib>
#include "std_msgs.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sum_over_vectors_client");

  ROS_INFO("usage: sum over Vectors linear angular");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<rbot250hw4::sumOverVectors>("sum_over_vectors");
  rbot250hw4::sumOverVectors srv;
  srv.request.linear = atoll(argv[1]);
  srv.request.angular = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %f", (double)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service sum_over_vectors");
    return 1;
  }

  return 0;
}
