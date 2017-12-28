#!/bin/bash
#Script to start the ros simulations 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros inputs" &
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros training" &
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros light_node" & 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros sensor_node" & 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros base_node" &
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros motion_planner_ROS" &

xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros GUI_ROS.py" & 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros GUI_HAPI.py" 