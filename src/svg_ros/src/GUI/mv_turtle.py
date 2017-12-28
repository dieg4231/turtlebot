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
    base_angle_1=acos(msg.pose.pose.orientation.w)*2  

def move_robot(req):
    print "Request: "+req.param
    global flag
    flag=0 
    global base_distance_x1
    global base_distance_y1
    global base_angle_1

    global base_distance_x0
    global base_distance_y0
    global base_angle_0

    #r = rospy.Rate(10)
    angle=req.param.split()
    angle=(float)(angle[2])
    distance=req.param.split()
    distance=(float)(distance[1])

    #angle=(int)((angle*57.2958)/.9)
    #distance=(int)(distance/.04)

    base_angle_0=base_angle_1

    cmd_vel = rospy.Publisher('cmd_vel_mux/input/navi', Twist, queue_size=10)
    move_cmd = Twist()

    turn_cmd = Twist()
    turn_cmd.linear.x = 0

    r = rospy.Rate(100)
  
    #rospy.loginfo("Turning")
    if angle!=0:
        if angle<0:
            turn_cmd.angular.z =radians(-45)
            angle_sig="-";
        else :
            angle_sig="";
            turn_cmd.angular.z =radians(45)
    
        while abs((base_angle_1)-(base_angle_0) )<=abs(angle): 
            #print str(base_angle_1)+"-"+str(base_angle_0)+"="+str(base_angle_1-base_angle_0)
            cmd_vel.publish(turn_cmd)
        #    r.sleep()
        #print "Final angle="+str(base_angle_1-base_angle_0)
        turn_cmd.angular.z =0
        cmd_vel.publish(turn_cmd)
        final_angle=abs(base_angle_1-base_angle_0)
    else:
        angle_sig=""
        final_angle=0


    
    base_distance_x0=base_distance_x1
    base_distance_y0=base_distance_y1
    





    move_cmd = Twist()
    if distance!=0:
        if distance<0:
            move_cmd.linear.x =-0.1
            distance_sig="-";
        else:
            move_cmd.linear.x =0.1
            distance_sig=""
        #rospy.loginfo("Going Straight")
        
        while sqrt(pow( (base_distance_x1-base_distance_x0),2)+pow((base_distance_y1-base_distance_y0),2))<=abs(distance): 
            #print "dis="+str(sqrt(pow( (base_distance_x1-base_distance_x0),2)+pow((base_distance_y1-base_distance_y0),2)))
            cmd_vel.publish(move_cmd)
            #r.sleep()
        #print "Final distance="+str(sqrt(pow( (base_distance_x1-base_distance_x0),2)+pow((base_distance_y1-base_distance_y0),2)))
        final_distance=sqrt(pow( (base_distance_x1-base_distance_x0),2)+pow((base_distance_y1-base_distance_y0),2))
    else:
        distance_sig=""
        final_distance=0


    #move_cmd.linear.x =0
    #cmd_vel.publish(move_cmd)
    print "     Response: mv "+distance_sig+str(final_distance)+" "+angle_sig+str(final_angle)
    return  "mv "+distance_sig+str(final_distance)+" "+angle_sig+str(final_angle)



def mv_turtle():
    
    

    rospy.init_node('move_robot_turtle')
    s = rospy.Service('move_robot_turtle', MVServ,move_robot)
    rospy.Subscriber('odom',Odometry,update_value)
    print "Ready to move turtle bot." 

    
    rospy.spin()



if __name__ == '__main__':
    try:
        mv_turtle()
    except rospy.ROSInterruptException:
        pass