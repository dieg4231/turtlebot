      /*********************************
     * Light Tower simulation node    *
    *                                *
   *                                *
  *                                *
 *                                *
*********************************/

#include <time.h>
#include <sys/time.h>
#include "ros/ros.h"
#include "../utilities/structures.h"
#include "../utilities/constants.h"
#include "../simulator/simulation.h"
#include "../utilities/inputs.h"
#include "svg_ros/LightSrv.h"
#include "svg_ros/OverSrv.h"
#include "../ROSutilities/receiveInputs.h"
#define LARGEST_DISTANCE_SENSORS 5.0 // 5.0 meters
#define MAX_NUM_CHARACTERS 1500


//Global variables to handle inputs and flags

Inputs inputsT; //get inputs from GUI
int flg_dest=0; // check this flag later
int flg_read=1;
int ovr = 0;

#define K_GOAL CNT_GOAL*MAG_ADVANCE
#define K_INTENSITY  1.00*K_GOAL


//quantize value functions:


float get_angle(float ang,float c,float d,float X,float Y){
        float x,y;

        x=c-X;
        y=d-Y;
        if((x == 0) && (y == 0)) return(0);
        if(fabs(x)<0.0001)      return((float) ((y<0.0f)? 3*PI/2  : PI/2) - ang );
        else{
                if(x>=0.0f&&y>=0.0f) return( (float)(atan(y/x)-ang) );
                else if(x< 0.0f&&y>=0.0f) return( (float)(atan(y/x)+PI-ang) );
                else if(x< 0.0f&&y<0.0f) return( (float)(atan(y/x)+PI-ang) );
                else return( (float)(atan(y/x)+2*PI-ang));
        }
}

float magnitude(coord vector){

        float magnitude;

        magnitude=(float)sqrt((vector.xc*vector.xc)+(vector.yc*vector.yc));
        //printf("magnitude: %f\n",magnitude);
        return(magnitude);
}




coord dif_vectors(coord vector1,coord vector2){

        coord dif;

        dif.xc=vector1.xc-vector2.xc;
        dif.yc=vector1.yc-vector2.yc;
        return(dif);
}




int quantize_destination(coord coord_robot,coord coord_dest){

	int value=0;
	float angle;
	coord dif;
	float theta;

	theta=coord_robot.anglec;
	//printf("pose x %f y %f theta %f\ndest x %f y %f\n",coord_robot.xc,coord_robot.yc,theta,coord_dest.xc,coord_dest.yc);

	dif=dif_vectors(coord_robot,coord_dest);

	angle=get_angle(0,0,0,dif.xc,dif.yc);
	//angle=get_angle(0,0,0,coord_dest.xc,coord_dest.yc);
	//printf("angle %f\n",angle);
	angle=angle - theta;
	if(angle < 0) angle = 2*PI + angle;
	//printf("angle %f\n",angle);


	if( angle < PI / 2) value = 3;
	else if ( angle < PI ) value = 1;
	else if( angle < 3*PI/2) value = 0;
	else value = 2;

	return value;
}


int quantize_intensity(coord coord_robot,coord coord_dest){

	int value=0;
	coord attraction_force;
	float mag;

	attraction_force=dif_vectors(coord_robot,coord_dest);
	mag=magnitude(attraction_force);
	//printf("distance destination %f threshold %f\n",mag,K_INTENSITY);


	if(mag > K_INTENSITY){
	    value = 0;
	}
	else{
	     value = 1;
	}

	return value;
}


// callback that checks if motion_planner is over
bool over(svg_ros::OverSrv::Request &req, svg_ros::OverSrv::Response &res)
{
	ovr = req.over_flg;
	if (ovr)
	{
		//ROS_INFO("Light node: motion planner it's over");
		flg_read=1;
		flg_dest=0; //check this later
	}
	req.over_flg = 0;
}


//callback that sends destination coordinates and quantized values to motion_planner
bool send_destination(svg_ros::LightSrv::Request &req, svg_ros::LightSrv::Response &res)
{
	//sends quantized intensity and quantized attraction from coordinates
	int a;
	int b;
	coord coord_robot, coord_dest; 


	if(flg_read)
	{
		
		//ROS_INFO("Light waiting for destination");
		int r = 1;
		while(r)
			r=receiveInputs(&inputsT,"receiveInputs");

		//printf("Get destination from GUI");
		ROS_INFO("Light tower, destination set to: %f,%f",inputsT.xd,inputsT.yd);
	}
	flg_read=0;

	coord_robot.xc=req.coord_x;
	coord_robot.yc=req.coord_y;
	coord_robot.anglec=req.coord_ang;
	coord_dest.xc=inputsT.xd;
	coord_dest.yc=inputsT.yd;

	a=quantize_intensity(coord_robot,coord_dest);
	b=quantize_destination(coord_robot,coord_dest);
	//printf("intensity:%d, destination:%d\n",a,b);
		
	res.quantized_attraction=b;
	res.quantized_intensity=a;

	return true;
}


void light_func(){

	ros::NodeHandle n;
	std::string inputs_node_name= "receiveInputs";

	ROS_INFO("Light tower simulation node started");
	
	ros::ServiceServer service = n.advertiseService("send_destination", send_destination);
	ros::ServiceServer service1 = n.advertiseService("over_light",over);
	ros::spin();
}


// Main program
int main(int argc, char *argv[])
{


 int num_steps;
 ros::init(argc, argv, "light_module");

 /* it gets line inputs */
 get_inputs(argc,argv,&inputsT);

 light_func();

 return 0;

}
