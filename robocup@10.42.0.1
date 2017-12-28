#!/usr/bin/env python2.7

from svg_ros.srv import *
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from math import radians
import roslib
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan


# System Libraries
#import os
#import time
#import sys
#import serial
class sensor_service():
	
	def __init__(self):
	
	    
	    s = rospy.Service('get_laser',GetLaserServ, self.handle_sensor)
	    service_1 = rospy.Service("over_sensor",OverSrv,self.handle_over);
	    rospy.Subscriber('scan',LaserScan,self.update_value)
	    print "Ready laser_module"
	   
	    rospy.spin()

	
	#Initializaction of Hokuyo
	num_points = 650
	PI = 3.1415926535
	range_laser = 240
	complete_range = range_laser * PI / 180
	K1 = num_points / complete_range
	#K1 = complete_range / num_points
	ranges=[]
	
	
	def update_value(self,msg):
	    
	    print "suscrito"
	    #print msg.ranges[0] 
	    self.ranges=msg.ranges
	   # print ranges[0]
	
	def handle_over(self,req):
	
	        ovr = req.over_flg
	        #print "Handle Over flg ",str(ovr)
	
	        if (ovr):
	                #ROS_INFO("base_node received over signal")
	                flg_read=1
	                flg_ENVIRONMENT=1
	                req.over_flg = 0
	
	
	def handle_sensor(self,req):
		
		sensors = range(700)
		num_sensors=req.num_sensors
		ranges=req.range
		offset = self.complete_range / 2
		init_angle= offset + req.init_angle
		inc_angle = ranges / num_sensors
		theta = init_angle
		k = 1
		laser=[]
		#print self.ranges[0]
	
	        #print "Sensor node num ",str(num_sensors)," ranges ",str(ranges)," init_angle ",str(init_angle)
		s = "( sensor laser "+str(num_sensors)+" "+str(ranges)+" "+str(init_angle)+" )"
	
		# it reads the laser data from Hokuyo
		
		laser = self.ranges
		print laser[0]
		print 'Lase:'
		print len(laser)
		for j in range (0,num_sensors):
			
			print 
			index = int( self.K1 * theta) 
			#print index
			sensors[j] = float(laser[index]) 
	
			k = k + 1
			theta = k*inc_angle + init_angle
	                #print "laser[",str(index) +"] ",str(laser[index])
	
	        #print "Returning ",str(sensors)
		return GetLaserServResponse(s,sensors)
	
	
	
	
	
	
	
if __name__ == '__main__':
    try:
    	rospy.init_node('laser_module')
        
        n=sensor_service()
    except rospy.ROSInterruptException:
        pass
	
	