# Linefollowing
This is the lab resources for SUSTech EE346.

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

 ![image](https://github.com/591774192/MerlandTrade/blob/master/%E6%A2%85%E5%85%B0%E5%95%86%E8%B4%B8%E6%88%AA%E5%9B%BE.png)
