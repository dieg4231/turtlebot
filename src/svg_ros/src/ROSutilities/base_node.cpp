      /*********************************
     *      Base simulation node      *
    *                                *
   *    base_node.cpp               *
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
#include "../utilities/utilities.h"
#include "svg_ros/SensorSrv.h"
#include "svg_ros/OverSrv.h"
#include "svg_ros/ReadySrv.h"
#include "../ROSutilities/receiveInputs.h"
#include "../utilities/random.h"
#define LARGEST_DISTANCE_SENSORS 5.0 // 5.0 meters
#define MAX_NUM_CHARACTERS 1500

//Global Variables
Inputs inputsT;
int flg_ENVIRONMENT=1;
int flg_read=1;
int ovr = 0;
coord coord_robot_sim;




// callback that checks if motion_planner is over
bool over(svg_ros::OverSrv::Request &req, svg_ros::OverSrv::Response &res)
{
	ovr = req.over_flg;
	if (ovr)
	{
		//ROS_INFO("base_node received over signal");
		flg_read=1;
		flg_ENVIRONMENT=1;
	}
	req.over_flg = 0;
}



// it will move the robot the desire angle and distance
void  mvrobot_sim(AdvanceAngle *DistTheta,coord coord_robot ){
 int flg=0;
 float new_xmv,new_ymv,new_thetamv;
 float xc,yc;
 float speed;
 coord new_coord;
 float xmv,ymv,thetamv;
 float distance, angle1;

 xmv=coord_robot.xc;
 ymv=coord_robot.yc;
 thetamv=coord_robot.anglec;

 angle1 = DistTheta->angle;
 //printf("angle1 %f\n",angle1);
 distance = DistTheta->distance;

 if(angle1 > 5.75f) angle1=- (angle1 - 5.75f) ;

 new_thetamv = thetamv + angle1;
 if(new_thetamv > 6.2832) new_thetamv = new_thetamv - (float) 6.2832;
 else if(new_thetamv < -0.0) new_thetamv = new_thetamv + (float) 6.2832;

 new_xmv = xmv + (float) distance*(float)cos((float) (new_thetamv));
 new_ymv = ymv + (float) distance*(float)sin((float) (new_thetamv));

 // it checks if the robot new position is inside an obstacle
 flg = shs_distance_obstacle(xmv,ymv,new_xmv,new_ymv,.5);
 //printf("check inside %d x:%.3f, y:%.3f,  rad:%.3f\n",flg,new_xmv,new_ymv,new_thetamv);

 if(flg==1){
        DistTheta->angle=0;
	DistTheta->distance=0;
        //printf("The robot remains with the previous position\n");
 }

 //printf("mv x:%f, y:%f,  rad:%f\n",coord_robot->xc,coord_robot->yc,coord_robot->anglec);


}


//Callback that reads the environment to check if the robot collids with an obstacle
//bool get_environment(svg_ros::MVServ::Request &req, svg_ros::MVServ::Response &res)
bool get_environment(svg_ros::MVServ::Request &req, svg_ros::MVServ::Response &res)
{
	//updates sensor[] accordingly to the world, the robot's coords, and the robot's orientation
	char world_file[250];
        char line[MAX_NUM_CHARACTERS*30];

	
	if(flg_read)
	{
		
		int r = 1;
		while(r)
			r=receiveInputs(&inputsT,"receiveInputs");
	}
	flg_read=0;

	coord_robot_sim.xc=req.coord_x;
	coord_robot_sim.yc=req.coord_y;
	coord_robot_sim.anglec=req.coord_ang;

	//printf("sim_base node get_environment pose robot x %f y %f angle %f\n",coord_robot_sim.xc,coord_robot_sim.yc,coord_robot_sim.anglec);


	if(flg_ENVIRONMENT){
		//read_environment must be read when another environment is selected 
		sprintf(world_file,"%s%s.wrl",inputsT.path,inputsT.environment);
		//printf("Environment %s\n",world_file);
		read_environment(world_file,0);
		flg_ENVIRONMENT=0;
	}



	sprintf(line,"position x %f y %f angle %f",coord_robot_sim.xc,coord_robot_sim.yc,coord_robot_sim.anglec);
        std::string s=line;
        res.answer = s.c_str();


        //ROS_INFO("mv position response: [ %s ]", line );

	return true;
}




//callback that simulates the movement of the robot
bool mv_ROS(svg_ros::MVServ::Request &req, svg_ros::MVServ::Response &res)
{
        //updates sensor[] accordingly to the world, the robot's coords, and the robot's orientation
        coord coord_robot;
        char world_file[250];
        int j;
        Raw observations;
        int num_obs=1;
        char line[MAX_NUM_CHARACTERS*30];
        char command[MAX_NUM_CHARACTERS];
	float answer_distance, answer_angle;
	AdvanceAngle DistTheta;
	float noise_advance,noise_angle;
	int flg_noise=1;


        coord_robot.xc=coord_robot_sim.xc;
        coord_robot.yc=coord_robot_sim.yc;
        coord_robot.anglec=coord_robot_sim.anglec;

	strcpy(line,req.param.c_str());
	sscanf(line,"%s%f%f",command,&answer_distance,&answer_angle);
  	//printf("mv params line: %f %f\n", answer_distance,answer_angle);

	DistTheta.angle=answer_angle;
        DistTheta.distance=answer_distance;

	flg_noise = inputsT.flg_noise;
	//printf("flg_noise %d\n",flg_noise);


	if(flg_noise==1){
                get_random_advance_angle(&noise_advance,&noise_angle,inputsT.path);
                //printf("angle %f\n",DistTheta.angle);
                DistTheta.angle = DistTheta.angle + noise_angle;
                //printf("angle + noise %f\n",DistTheta.angle);
                //printf("distance %f\n",DistTheta.distance);
                DistTheta.distance = DistTheta.distance + noise_advance;
                //printf("distance + noise %f\n",DistTheta.distance);
        }


        mvrobot_sim(&DistTheta,coord_robot);

        sprintf(line,"mv %f %f",DistTheta.distance,DistTheta.angle);
        //sprintf(line,"mv 0.04 0.0");
	//printf("sim_base mv_ROS answer distance %f angle %f\n",DistTheta.distance,DistTheta.angle);
        std::string s=line;
        res.answer = s.c_str();

        //ROS_INFO("sim_base response: [ %s ]", line );

	usleep(1000);

        return true;
}



// Main program
void base_func(){

	ros::NodeHandle n;
	ros::ServiceServer service_0 = n.advertiseService("send_position_mv", get_environment);
	ros::ServiceServer service_1 = n.advertiseService("over_base",over);
	ros::ServiceServer service_2 = n.advertiseService("move_robot", mv_ROS);
	ROS_INFO("Mobile robot base simulation node started");
	ros::spin();

}


int main(int argc, char *argv[])
{

 int num_steps;
 ros::init(argc, argv, "base_module");
 //ros::init(argc, argv, "mv_server");

 /* it gets line inputs */
 get_inputs(argc,argv,&inputsT);

 base_func();

 return 0;

}
