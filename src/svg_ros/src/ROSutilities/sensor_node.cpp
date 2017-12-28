/********************************************************
*      Sensor node		    			*
*                                			*
*      Using the simulator:	   			*
*  	rosrun svg_ros sensor_node -selection 1 	*
*                                			*
*      Using the real data:	   			*
*  	rosrun svg_ros sensor_node -selection 0 	*
*                                			*
*                         Jesus Savage   		*
*                         FI-UNAM, 2017			*
*                                			*
*********************************************************/

#include <time.h>
#include <sys/time.h>
#include "ros/ros.h"
#include "../utilities/structures.h"
#include "../utilities/constants.h"
#include "../simulator/simulation.h"
#include "../utilities/inputs.h"
#include "svg_ros/SensorSrv.h"
#include "svg_ros/OverSrv.h"
#include "svg_ros/GetLaserServ.h"
#include "svg_ros/OverSrv.h"
#include "../ROSutilities/receiveInputs.h"
#include "../utilities/random.h"
#include "../utilities/utilities.h"
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


//callback that reads the environment and simulates sensor data
//updates sensor[] accordingly to the world, the robot's coords, and the robot's orientation
bool get_coords(svg_ros::SensorSrv::Request &req, svg_ros::SensorSrv::Response &res)
{
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
	// Function in ~/catkin_ws/src/svg_ros/src/simulator/simulation.h
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

        //ROS_INFO("sensor response: [ %s ]", line );

        return true;
}



//communication with robot's laser sensor
int ROS_get_laser(std::string s, int num_sensors, float range, float init_angle, float * sensors){
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<svg_ros::GetLaserServ> ("get_laser");
  svg_ros::GetLaserServ srv;
  int i;

  srv.request.param=s;
  srv.request.num_sensors=num_sensors;
  srv.request.range=range;
  srv.request.init_angle=init_angle;

  if (client.call(srv))
  {
    //ROS_INFO("success: %s", srv.response.answer.c_str());
    //std::cout << srv.response.answer.c_str() << std::endl;
  }
  else
  {
    ROS_ERROR("Failed to call service get_laser");
    printf("Failed to call service get_laser");
    return 1;
  }

  //printf("Num. sensors %d range %f init_angle %f \n",num_sensors,range,init_angle);
  //printf("ROS_get_laser %s\n",srv.response.answer.c_str());

  for(i=0;i<num_sensors;i++){

    sensors[i] = srv.response.sensors[i];   
    //printf("get_laser sensors[%d]  %f\n",i,srv.response.sensors[i]);


  }

  return 0;
}


//callback that reads laser sensor data
bool get_laser(svg_ros::SensorSrv::Request &req, svg_ros::SensorSrv::Response &res)
{
	int j;
	char line[MAX_NUM_CHARACTERS*500];
	char tmp[MAX_NUM_CHARACTERS];
 	char param[20];
	float sensors[700];


	if(flg_read)
	{
		
		int r = 1;
		while(r)
			r=receiveInputs(&inputsT,"receiveInputs");
	}
	flg_read=0;

	sprintf(line,"( sensor laser %d %f %f ",inputsT.num_sensors,inputsT.range_sensor,inputsT.theta_sensor);
 	ROS_get_laser(line,inputsT.num_sensors,inputsT.range_sensor,inputsT.theta_sensor,sensors);


	for(j=0;j<inputsT.num_sensors;j++){
		sprintf(tmp,"%2.2f ",sensors[j]);
		res.sensors[j]=sensors[j];
		//printf("res.sensors[%d]  %f\n",j,res.sensors[j]);
		strcat(line,tmp);
	}
	strcat(line,")");
	std::string s=line;
	res.sensor = s.c_str();

	res.flag=1;
  	res.region=0;
  	res.x=0;
	res.y=0;
  	res.theta=0;

  	res.num_sensors=inputsT.num_sensors;

	//ROS_INFO("sensor response: [ %s ]", line );

	return true;
}


// it selects simulated sensors
void sensor_func(){

	ros::NodeHandle n;

	ros::ServiceServer service = n.advertiseService("send_position", get_coords);
        printf("Using simulated laser data\n");

	ros::ServiceServer service1 = n.advertiseService("over_sensor",over);

	ROS_INFO("Sensors node started");
	ros::spin();

}


// it selects real sensors
void sensor_func_1(){

        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("send_position", get_laser);
        printf("Using real laser data\n");

        ros::ServiceServer service1 = n.advertiseService("over_sensor",over);

        ROS_INFO("Sensors node started");
        ros::spin();

}



// Main program
int main(int argc, char *argv[])
{

 int num_steps;

 // it gets line inputs, function in file ~/catkin_ws/src/svg_ros/src/utilities/inputs.h
 get_inputs(argc,argv,&inputsT);

 // it inits ROS environment
 ros::init(argc, argv, "sensor_module");


 if(inputsT.selection == 0)
	// it selects real sensors
 	sensor_func_1();
 else
	// it selects simulated sensors
 	sensor_func();

 return 0;

}