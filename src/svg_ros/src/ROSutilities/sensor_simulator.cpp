      /*********************************
     *      Sensor simulation node    *
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
#include "svg_ros/SensorSrv.h"
#include "svg_ros/OverSrv.h"
#include "../ROSutilities/receiveInputs.h"
#include "../utilities/random.h"
#define LARGEST_DISTANCE_SENSORS 5.0 // 5.0 meters
#define MAX_NUM_CHARACTERS 1500

//Global Variables
Inputs inputsT;
int flg_ENVIRONMENT=1;
int flg_read=1;
int ovr = 0;


// callback that checks if motion_planner is over
bool over(svg_ros::OverSrv::Request &req, svg_ros::OverSrv::Response &res)
{
	ovr = req.over_flg;
	if (ovr)
	{
		//ROS_INFO("sensor receive over signal");
		flg_ENVIRONMENT=1;
		flg_read=1;
	}
	req.over_flg = 0;

}


//callback that reads the environment and sensor data
bool get_coords(svg_ros::SensorSrv::Request &req, svg_ros::SensorSrv::Response &res)
{
	//updates sensor[] accordingly to the world, the robot's coords, and the robot's orientation
	coord coord_robot;
	char world_file[250];
	int j;
	Raw observations;
	int num_obs=1;
	char line[MAX_NUM_CHARACTERS*30];
	char tmp[MAX_NUM_CHARACTERS];
	int flg_noise=1;

	
	if(flg_read)
	{
		
		int r = 1;
		while(r)
			r=receiveInputs(&inputsT,"receiveInputs");
	}
	flg_read=0;

	coord_robot.xc=req.coord_x;
	coord_robot.yc=req.coord_y;
	coord_robot.anglec=req.coord_ang;


	//printf("sensor node pose robot x %f y %f angle %f\n",coord_robot.xc,coord_robot.yc,coord_robot.anglec);


	if(flg_ENVIRONMENT){
		//read_environment must be read once only
		sprintf(world_file,"%s%s.wrl",inputsT.path,inputsT.environment);
		//printf("Get inputs GUI: Environment %s\n",world_file);
		read_environment(world_file,0);
		flg_ENVIRONMENT=0;
	}

	//printf("type %d Pose robot %f %f %f \n",num_obs,coord_robot.xc,coord_robot.yc,coord_robot.anglec);
	get_sensor_values(coord_robot,inputsT.theta_sensor,inputsT.range_sensor,&observations,inputsT.num_sensors,inputsT.largest_value);
	sprintf(line,"( sensor laser %d %f %f ",inputsT.num_sensors,inputsT.range_sensor,inputsT.theta_sensor);

	flg_noise = inputsT.flg_noise;
	//printf("flg_noise %d\n",flg_noise);

	if(flg_noise==1) add_noise_obs(&observations,inputsT.num_sensors,inputsT.path);

	res.flag=observations.flag;
	res.region=observations.region;
	res.x=observations.x;
	res.y=observations.y;
	res.theta=observations.theta;
	res.num_sensors=inputsT.num_sensors;


	for(j=0;j<inputsT.num_sensors;j++){
		sprintf(tmp,"%2.2f ",observations.sensors[j]);
		res.sensors[j]=observations.sensors[j];
		strcat(line,tmp);
	}
	strcat(line,")");
	std::string s=line;
	res.sensor = s.c_str();

	//usleep(100000);

	//ROS_INFO("sensor response: [ %s ]", line );

	return true;
}


// Main program
void sensor_func(){

	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("send_position", get_coords);
	ros::ServiceServer service1 = n.advertiseService("over_sensor",over);
	ROS_INFO("Sensors simulation node started");
	ros::spin();



}


int main(int argc, char *argv[])
{

 int num_steps;
 ros::init(argc, argv, "sensor_module");

 /* it gets line inputs */
 get_inputs(argc,argv,&inputsT);

 sensor_func();

 return 0;

}
