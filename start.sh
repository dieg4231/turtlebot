#!/bin/bash
#Script to start the ros simulations 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros inputs" &
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros training" &
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros light_node" & 
#xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros sensor_node " & 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros base_node " &
xterm -hold -e ". ~/catkin_ws/devel/setup.bash &&  roscd svg_ros/src/data/ && rosrun svg_ros sensor_node -selection 1 " &


xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros GUI_ROS.py" & 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros GUI_HAPI.py" &

xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros mv_turtle.py"  &

#sudo xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/ROSutilities/ &&  python sensor_node.py " &


xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/data/ && rosrun svg_ros motion_planner_ROS" #&

#XXXXXX


#xterm -hold -e ". ~/catkin_ws/devel/setup.bash && 
#export TURTLEBOT_BASE=create && 
#export TURTLEBOT_STACKS=circles &&
#sudo chmod +777 /dev/ttyUSB0 && 
#export TURTLEBOT_SERIAL_PORT=/dev/ttyUSB0 &&
#roslaunch turtlebot_bringup minimal.launch --screen" 
