# Linefollowing
This is the lab resources for SUSTech EE346.

Reference: https://github.com/sinyeopgo/ROS-2-simulation

https://www.youtube.com/watch?v=0FveGFwQruk
# Usage

## 1. Clone the source code
  cd ~/catkin_ws/src
  
  git clone git@github.com:zhaojieting/Linefollowing.git
  
## 2. Catkin make the linefollowing package
  cd ..
  
  catkin_make

## 3. Launch the gazebo map
   source ~/catkin_ws/devel/setup.bash
   
   roslaunch linefollowing line_following.launch 
## 4. Run linefollowing node( open a new terminal)
   
   cd ~/catkin_ws  
   
   source devel/setup.bash
   
   rosrun linefollowing linefollowing

 ![image](https://github.com/zhaojieting/Linefollowing/blob/main/data/demo.png)
