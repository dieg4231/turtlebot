#!/bin/bash
xterm -hold -e ". ~/catkin_ws/devel/setup.bash &&
				sudo chmod a+rw /dev/ttyUSB0 && 
				export TURTLEBOT_BASE=create && 
				export TURTLEBOT_STACKS=circles && 
				export TURTLEBOT_SERIAL_PORT=/dev/ttyUSB0 &&
				roslaunch turtlebot_bringup minimal.launch --screen" &
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && rosrun turtlebot_node turtlebot_node "  &
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd svg_ros/src/ROSutilities/ && python sensor_node.py " &
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && rosrun svg_ros sensor_node -selection 0 "
