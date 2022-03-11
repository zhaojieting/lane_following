#include "linefollowing.hpp"
#include <geometry_msgs/Twist.h>
#include <memory>
#include <time.h>
#include <ros/ros.h>

Linefollowing::Linefollowing(){
  ros::NodeHandle nh;
  img_sub = nh.subscribe("/camera/image", 10, &Linefollowing::subs_callback, this);
  cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);
  ros::Rate loop_rate(10);
  while(ros::ok())
  {
      geometry_msgs::Twist cmd_vel;
      cmd_vel.linear.x = 0.3;
      cmd_vel.angular.z = (error*90.0/160)/15;
      cmd_vel_pub_.publish(cmd_vel);

      ros::spinOnce();
      loop_rate.sleep();
  }
}

void Linefollowing::subs_callback(const sensor_msgs::ImageConstPtr& msg) {
  frame = cv_bridge::toCvShare(msg, "bgr8")->image;
  gray = cv_bridge::toCvShare(msg, "mono8")->image;

  gray = gray + 100 - mean(gray)[0];
  threshold(gray, gray, 160, 255, THRESH_BINARY);

  dst = gray(Rect(30, gray.rows * 2/3, 290, gray.rows *1/ 3));
  
  Mat labels, stats, centroids;
  int cnt = connectedComponentsWithStats(dst, labels, stats, centroids);
  if (cnt > 1) {
    for (int i = 1; i < cnt; i++) {
      double* p = centroids.ptr<double>(i);
      ptdistance[0] = abs(p[0] - prevpt1.x);
      ptdistance[1] = abs(p[0] - prevpt2.x);
      cout<<i<<":"<<p[0]<<endl;
      mindistance1.push_back(ptdistance[0]);
      mindistance2.push_back(ptdistance[1]);
    }

    threshdistance[0] = *min_element(mindistance1.begin(), mindistance1.end());
    threshdistance[1] = *min_element(mindistance2.begin(), mindistance2.end());

    minlb[0] = min_element(mindistance1.begin(), mindistance1.end()) - mindistance1.begin();
    minlb[1] = min_element(mindistance2.begin(), mindistance2.end()) - mindistance2.begin();

    cpt[0] = Point2d(centroids.at<double>(minlb[0] + 1, 0), centroids.at<double>(minlb[0] + 1, 1));
    cpt[1] = Point2d(centroids.at<double>(minlb[1] + 1, 0), centroids.at<double>(minlb[1] + 1, 1));

    if (threshdistance[0] > 100) cpt[0] = prevpt1;
    if (threshdistance[1] > 100) cpt[1] = prevpt2;

    mindistance1.clear();
    mindistance2.clear();
  }
  else {
    cpt[0] = prevpt1;
    cpt[1] = prevpt2;
  }

  prevpt1 = cpt[0];
  prevpt2 = cpt[1];

  fpt.x = (cpt[0].x + cpt[1].x) / 2;
  fpt.y = (cpt[0].y + cpt[1].y) / 2 + gray.rows / 3 * 2;
  cvtColor(dst, dst, COLOR_GRAY2BGR);

  circle(frame, fpt, 2, Scalar(0, 0, 255), 2);
  circle(dst, cpt[0], 2, Scalar(0, 0, 255), 2);
  circle(dst, cpt[1], 2, Scalar(255, 0, 0), 2);

  error = (dst.cols) / 2 - fpt.x;

  imshow("camera",frame);
  imshow("gray",dst);
  waitKey(1);
}


int main(int argc, char **argv) {
  ros::init(argc, argv, "linefollowing");
  Linefollowing lf;
  return 0;
}
