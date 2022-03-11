# Linefollowing
This is the lab resources for SUSTech EE346.

# Usage

## 1. Clone the source code
  cd ~/catkin_ws
  git clone git@github.com:zhaojieting/Linefollowing.git
  
## 2. Catkin make the linefollowing package
  catkin_make

## 3. Launch the gazebo map
   source ~/catkin_ws/devel/setup.bash
   roslaunch linefollowing line_following.launch
## 4. Run linefollowing node
   #Open a new terminal
   cd ~/catkin_ws
   source devel/setup.bash
   rosrun linefollowing linefollowing
