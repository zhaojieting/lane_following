cmake_minimum_required(VERSION 2.8.3)
project(linefollowing)

add_definitions(-std=c++11)
set(OpenCV_DIR ${/home/test/Downloads/opencv-3.4.13}/share/OpenCV)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS cv_bridge roscpp rospy std_msgs genmsg geometry_msgs)
find_package(OpenCV REQUIRED)

## Declare ROS messages and services
##add_message_files(FILES pos.msg)

## Generate added messages and services
##generate_messages(DEPENDENCIES std_msgs)

catkin_package()


## Executables
include_directories(include ${catkin_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(linefollowing src/linefollowing.cpp)
target_link_libraries(linefollowing ${catkin_LIBRARIES} ${OpenCV_LIBS})
add_dependencies(linefollowing linefollowing_gencpp)
