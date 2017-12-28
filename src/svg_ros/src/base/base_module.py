#!/usr/bin/env python

###
# base_module.py
#
 

from svg_ros.srv import *
import rospy
# System Libraries
import os
import time
import sys

delay = 0.1

def handle_mv(req):
	
	#ss = range(2)

	s=req.param
	print "Base module receiving [%s]"%(s)
	s=s.split()
	s=s[0] + " " + s[1]+ " " + s[2]
	#s=s[0] + " 0.04 0.0"
	#time.sleep(delay)
	#ss[0] = s
	#ss[1] = 'dummy'
	print "Returning ",s
	return MVServResponse(s)



def handle_position(req):

	#ss = range(2)

	x=req.coord_x
	y=req.coord_y
	angle=req.coord_ang

        print "Base module position x ",str(x)," y ",str(y)," angle ",str(angle)

        s="position x "+str(x)+" y "+str(y)+" angle "+str(angle)
        #time.sleep(delay)
	#ss[0] =  'dummy' 
	#ss[1] = s 
        print "Returning ",s
	return MVServResponse(s)




def mv_server():
    rospy.init_node('mv_server')
    s = rospy.Service('move_robot', MVServ, handle_mv)
    s = rospy.Service('send_position_mv', MVServ, handle_position)
    print "Ready to move the robot."
    rospy.spin()

if __name__ == "__main__":
    mv_server()
