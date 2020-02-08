# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 2.8.3)
project(RBOT250hw4)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
add_message_files(FILES Twist.msg)
add_service_files(FILES sumOverVectors.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

## Build service client and server
# %Tag(SRVCLIENT)%
add_executable(sumOverVectorsServer src/sumOverVectorsServer.cpp)
target_link_libraries(sumOverVectorsServer ${catkin_LIBRARIES})
add_dependencies(sumOverVectorsServer RBOT250hw4_gencpp)

add_executable(sumOverVectorsClient src/sumOverVectorsClient.cpp)
target_link_libraries(sumOverVectorsClient ${catkin_LIBRARIES})
add_dependencies(sumOverVectorsClient RBOT250hw4_gencpp)

sumOverVectorsServer

# %EndTag(SRVCLIENT)%

# %EndTag(FULLTEXT)%