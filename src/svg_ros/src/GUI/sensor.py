#!/usr/bin/env python
from svg_ros.srv import *
import rospy


  #srv.request.coord_x=num_sensors;  //Numero de sensores
  #srv.request.coord_y=theta;   //Enpezando desde
  #srv.request.coord_ang=range;    //Rango


def handle_add_two_ints(req):
    print "Returning [hhhhh]"
    

    num_sensors=int(req.coord_x)
    resp=SensorSrvResponse()
    resp.num_sensors=num_sensors


    #sensado=90+req.theta*57.2958
    #incremento=req.range*57.2958/num_sensors

    for i in range( num_sensors ):
        resp.sensors[i]=.1
        
       # write"sense 20" sensado
      #  sensado=sensado+incremento;
     #   Response =read

    return  resp

def add_two_ints_server():
    rospy.init_node('add_two_ints_server')
    s = rospy.Service('sensor_robot_turtle', SensorSrv, handle_add_two_ints)
    print "Ready to sensor."
    rospy.spin()

if __name__ == "__main__":
    add_two_ints_server()