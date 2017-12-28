#!/usr/bin/env python
from svg_ros.srv import *
import rospy

def handle_add_two_ints(req):
    print "Returning [%s]"%(req.param)
    #rospy.set_param('answer','as as 1 2')
    return  req.param

def add_two_ints_server():
    rospy.init_node('add_two_ints_server')
    s = rospy.Service('move_robot_turtle', MVServ, handle_add_two_ints)
    print "Ready to add two ints."
    rospy.spin()

if __name__ == "__main__":
    add_two_ints_server()