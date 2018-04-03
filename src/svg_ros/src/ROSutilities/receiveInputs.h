

#include "ros/ros.h"
#include "svg_ros/InputsPlannerSrv.h"
#include <cstdlib>


int receiveInputs(Inputs *inp,std::string s)
{

 static int flg = 1;
 static ros::NodeHandle n;
 static ros::ServiceClient client;
 static svg_ros::InputsPlannerSrv srv;

 if(flg == 1){
       	  client = n.serviceClient<svg_ros::InputsPlannerSrv> (s);
       	  flg = 0;
 }


 if (client.call(srv)) {

	if(srv.response.flgGUI){
		return 1;
	}

	inp->xo=srv.response.origin_x;
	inp->yo=srv.response.origin_y;
	inp->angle_robot=srv.response.origin_angRob;
	inp->xd=srv.response.dest_x;
	inp->yd=srv.response.dest_y;
	strcpy(inp->sensor,(srv.response.sensorBool).c_str());
	inp->num_sensors=srv.response.num_sensorsInt;
	inp->theta_sensor=srv.response.angle_sensor_orig;
	inp->range_sensor=srv.response.range_angleRob;
	inp->radio_robot=srv.response.radiusRob;
	inp->Mag_Advance=srv.response.advance;
	inp->max_angle=srv.response.max_angle;
	inp->number_steps= srv.response.num_steps;
	inp->selection = srv.response.select;
	inp->largest_value = srv.response.largest_sensor;
	strcpy(inp->path,(srv.response.pathNAme).c_str());
	strcpy(inp->environment,(srv.response.fileNAme).c_str());
	inp->flg_noise = srv.response.flg_noise;
	inp->flg_real_environment = srv.response.flg_real_environment;
	//printf("xinit %f yinit %f xdest %f ydest %f \n", 
			//(float)srv.response.origin_x, (float)srv.response.origin_y, (float)srv.response.dest_x, (float)srv.response.dest_y);
	//printf("flg_noise %d\n",srv.response.flg_noise);


	return 0;
 }
 else {
 	ROS_ERROR("Failed to call service receiveInputs");
	return 1;
 }

}




