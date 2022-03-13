# lane following
This is the lab resources for SUSTech EE346.

Reference: https://github.com/sinyeopgo/ROS-2-simulation

https://www.youtube.com/watch?v=0FveGFwQruk
# Usage

## 1. Clone the source code
  cd ~/catkin_ws/src
  
  git clone git@github.com:zhaojieting/lane_following.git
  
## 2. Catkin make the lane following package
  cd ..
  
  catkin_make

## 3. Copy course models to ~/.gazebo/models
   export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:~/catkin_ws/src/lane_following/models
   
## 4. Launch the gazebo map
   source ~/catkin_ws/devel/setup.bash
   
   roslaunch lane_following lane_following.launch 
## 5. Run lane following c++ node( open a new terminal)
   
   cd ~/catkin_ws  
   
   source devel/setup.bash
   
   rosrun lane_following lane_following
## 6. Run lane following python node
   
   cd ~/catkin_ws/src/lane_following/scripts/
   
   chmod +x lane_following.py
   
   cd ~/catkin_ws
   
   source devel/setup.bash
   
   rosrun lane_following lane_following.py

 ![image](https://github.com/zhaojieting/linefollowing/blob/main/data/demo.png)
