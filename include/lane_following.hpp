#include <iostream>
#include <ros/ros.h>
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include <geometry_msgs/Twist.h>

using namespace cv;
using namespace std;

class Linefollowing{
private:
  ros::Subscriber img_sub;
  ros::Publisher cmd_vel_pub_;
  void subs_callback(const sensor_msgs::ImageConstPtr& msg);
  Mat frame , gray, dst;
  Point prevpt1 = Point(50, 60);
  Point prevpt2 = Point(250, 60);
  Point cpt[2];
  Point fpt;
  int minlb[2];
  double ptdistance[2];
  double threshdistance[2];
  vector<double> mindistance1;
  vector<double> mindistance2;
  int error;
public:
  Linefollowing();

};
