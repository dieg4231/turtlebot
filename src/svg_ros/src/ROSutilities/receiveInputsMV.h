

#include "ros/ros.h"
#include "svg_ros/MVPlannerSrv.h"
#include <cstdlib>
#include <string.h>


int receiveInputsMV(MV *inp,std::string s)
{

 static int flg = 1;
 static ros::NodeHandle n;
 static ros::ServiceClient client;
 static svg_ros::MVPlannerSrv srv;

 if(flg == 1){
       	  client = n.serviceClient<svg_ros::MVPlannerSrv> (s);
       	  flg = 0;
 }


 if (client.call(srv)) {

	if(srv.response.flgGUI){
		return 1;
	}


	strcpy(inp->param,(srv.response.param).c_str());
	inp->coord_x=srv.response.coord_y;
	inp->coord_y=srv.response.coord_x;
	inp->coord_ang=srv.response.coord_ang;

	return 0;
 }
 else {
 	ROS_ERROR("Failed to call service receiveInputs");
	return 1;
 }

}




