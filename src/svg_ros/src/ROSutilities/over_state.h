#include "ros/ros.h"
#include "svg_ros/OverSrv.h"
#include <cstdlib>

int over_light()
{

	static int flg = 1;
  	static ros::NodeHandle n;
  	static ros::ServiceClient client;
	svg_ros::OverSrv srv;

  	//printf("over light\n");
  	if(flg == 1){
        	client = n.serviceClient<svg_ros::OverSrv> ("over_light"); // connecting to service OverSrv:over_light
       		 flg = 0;
  	}

	srv.request.over_flg = 1;

	if (client.call(srv))
	{
		//ROS_INFO("LIGHT Program is over");
	}
	else
	{
	  	ROS_ERROR("Failed to call LIGHT service over_light");
		return 1;
	}

	return 0;
}




int over_sensor()
{

        static int flg = 1;
        static ros::NodeHandle n;
        static ros::ServiceClient client;
        svg_ros::OverSrv srv;

        //printf("over sensor\n");
        if(flg == 1){
                client = n.serviceClient<svg_ros::OverSrv> ("over_sensor"); // connecting to service OverSrv:send_destination
                flg = 0;
        }

	srv.request.over_flg = 1;

	if (client.call(srv))
	{
		//ROS_INFO("SENSOR Program is over");
	}
	else
	{
	  ROS_ERROR("Failed to call SENSOR service over_sensor");
	return 1;
	}

	return 0;
}



int over_base()
{

        static int flg = 1;
        static ros::NodeHandle n;
        static ros::ServiceClient client;
        svg_ros::OverSrv srv;

        //printf("over base\n");
        if(flg == 1){
                client = n.serviceClient<svg_ros::OverSrv> ("over_base"); // connecting to service OverSrv:over_base
                flg = 0;
        }

        srv.request.over_flg = 1;

        if (client.call(srv))
        {
                //ROS_INFO("Base Program is over");
        }
        else
        {
          ROS_ERROR("Failed to call BASE service over_base");
        return 1;
        }

        return 0;
}



int over_inputs()
{
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<svg_ros::OverSrv> ("over_inputs");
	svg_ros::OverSrv srv;

	srv.request.over_flg = 0;

	if (client.call(srv))
	{
		//ROS_INFO("Inputs Program's over");
	
	}
	else
	{
	  ROS_ERROR("Failed to call inputs service over_inputs");
	return 1;
	}

	return 0;
}



int over_gui()
{
        ros::NodeHandle n;
        ros::ServiceClient client = n.serviceClient<svg_ros::OverSrv> ("over_gui");

        svg_ros::OverSrv srv;

        srv.request.over_flg = 0;


	//printf("over gui\n");

        if (client.call(srv))
        {
                //ROS_INFO("GUI Program's over");

        }
        else
        {
          ROS_ERROR("Failed to call gui service over_gui");
        return 1;
        }

        return 0;
}


int over(){
	int s1 = over_light();
	int s2 = over_sensor();
	int s3 = over_inputs();
	int s4 = over_gui();
	int s5 = over_base();

	return s1|s2|s3|s4|s5;

}

