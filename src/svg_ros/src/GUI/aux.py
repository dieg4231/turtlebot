#!/usr/bin/env python
from svg_ros.srv import *
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from math import *
import roslib
from nav_msgs.msg import Odometry


#Global variables
base_distance_x0=0
base_distance_y0=0
base_angle_0=0
base_distance_x1=0
base_distance_y1=0
base_angle_1=0
flag=0
    
def update_value(msg):
    global base_distance_x1
    global base_distance_y1
    global base_angle_1
    base_distance_x1=msg.pose.pose.position.x 
    base_distance_y1=msg.pose.pose.position.y 
    base_angle_1=msg.pose.pose.orientation.w 

    print "x: "+str(base_distance_x1)
    print "y: "+str(base_distance_y1)
    print "Ang: "+str(   acos(base_angle_1)*2   )
    #print msg.pose.pose

def move_robot(req):
    print req.param
    global flag
    flag=0 
    global base_distance_x1
    global base_distance_y1
    global base_angle_1

    global base_distance_x0
    global base_distance_y0
    global base_angle_0

    r = rospy.Rate(10)
    angle=req.param.split()
    angle=(float)(angle[2])
    distance=req.param.split()
    distance=(float)(distance[1])

#   print angle
#   print distance
    angle=(int)((angle*57.2958)/.9)
    distance=(int)(distance/.04)
#   print angle
#   print distance

    cmd_vel = rospy.Publisher('cmd_vel_mux/input/navi', Twist, queue_size=10)
    
    move_cmd = Twist()
    if distance<0:
        move_cmd.linear.x =-0.2
    else:
        move_cmd.linear.x =0.2#0.4 

    turn_cmd = Twist()
    turn_cmd.linear.x = 0


    r = rospy.Rate(100)
    if angle<0:
        turn_cmd.angular.z =radians(-90)
        angle*=-1
    else :
        turn_cmd.angular.z =radians(90)

    if angle!=0:
        rospy.loginfo("Turning")
        for x in range(0,angle):
            cmd_vel.publish(turn_cmd)
            r.sleep()

        turn_cmd.angular.z =0
        cmd_vel.publish(move_cmd)
    
    base_distance_x0=base_distance_x1
    base_distance_y0=base_distance_y1
    base_angle_0=base_angle_1

    r = rospy.Rate(5)
    
    rospy.loginfo("Going Straight")
    if distance<=0:
        for x in range(0,abs(distance)): #Resolucion .02m
            cmd_vel.publish(move_cmd)
            r.sleep()
        flag=0
    elif distance<=.15:
        for x in range(0,abs(distance)): #Resolucion .02m
            cmd_vel.publish(move_cmd)
            r.sleep()
        flag=0
    else:
        print 'siiiiiiiiiiiiiiiiiiiisisisissi'
        flag=1
    

    if distance<=0:
        move_cmd.linear.x =0
        cmd_vel.publish(move_cmd)
    
    rospy.loginfo("Finished")

    print 'Distancia: '
    print ( ((base_distance_x1-base_distance_x0)**2) + ((base_distance_y1-base_distance_y0)**2) )**1/2
    #print 'Angulo: '
    #print base_angle_1

    
    return  req.param



def mv_turtle():
    
    

    rospy.init_node('AUX')

    rospy.Subscriber('odom',Odometry,update_value)
    print "Ready to move turtle bot."
    rospy.Rate(2)
    rospy.spin()



if __name__ == '__main__':
    try:
        mv_turtle()
    except rospy.ROSInterruptException:
        pass