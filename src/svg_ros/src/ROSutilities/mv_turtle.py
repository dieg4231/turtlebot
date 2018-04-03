#!/usr/bin/env python
from svg_ros.srv import *
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from math import radians

def move_robot(req):
    r = rospy.Rate(10)
    angle=req.param.split()
    angle=(float)(angle[2])
    distance=req.param.split()
    distance=(float)(distance[1])

    print angle
    print distance
    angle=(int)((angle*57.2958)/.9)
    distance=(int)(distance/.002)
    print angle
    print distance

    cmd_vel = rospy.Publisher('gazebo/cmd_vel', Twist, queue_size=10)
    
    #cmd_vel = rospy.Publisher('cmd_vel_mux/input/navi', Twist, queue_size=10)
    
    

    turn_cmd = Twist()
    turn_cmd.linear.x = 0


    #if abs(angle) <= .785375 :
    #   turn_cmd.angular.z =angle
    #   mv_angle=10
    #elif abs(angle) <= 1.5707 :
    #   turn_cmd.angular.z =angle/2
    #   mv_angle=20
    #else :
    #   turn_cmd.angular.z =angle/3
    #   mv_angle=30

    # 0.01 segundos
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
        turn_cmd.angular.z =radians(0)
        cmd_vel.publish(turn_cmd)
    
    

    move_cmd = Twist()
    if distance<0:


        move_cmd.linear.x =0.0 

        for x in range(0,50):
            cmd_vel.publish(move_cmd)
            r.sleep()

        move_cmd.linear.x =-0.2 
    else:
        move_cmd.linear.x =0.2

    rospy.loginfo("Going Straight")
    for x in range(0,abs(distance)): #Resolucion .02m
        cmd_vel.publish(move_cmd)
        r.sleep()


    
    rospy.loginfo("Finished")
    
    return  req.param

def mv_turtle():
    rospy.init_node('move_robot_turtle')
    s = rospy.Service('move_robot_turtle', MVServ,move_robot)
    print "Ready to move turtle bot."
    rospy.spin()



if __name__ == '__main__':
    try:
        mv_turtle()
    except:
        rospy.loginfo("node mv_turtle terminated.")
