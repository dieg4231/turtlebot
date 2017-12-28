      /********************************
     *        Node to manage          *
    *            inputs              *
   *           from GUI             *
  *         to other nodes         *
 *                                *
*********************************/
#include "ros/ros.h"
#include "svg_ros/InputsSrv.h"
#include "../utilities/structures.h"
#include "../utilities/constants.h"
#include "svg_ros/InputsPlannerSrv.h"
#include "svg_ros/OverSrv.h"
#include "svg_ros/ReadySrv.h"
#define LARGEST_DISTANCE_SENSORS 5.0 // 5.0 meters

//Global variable to manage inputs
Inputs inputsT;
int flgGUI = 1;
int flgEND = 1;
int count = 0;


int ready_gui()
{

        static int flg = 1;
        static ros::NodeHandle n;
        static ros::ServiceClient client;
        svg_ros::ReadySrv srv;

        printf("Ready GUI\n");
        if(flg == 1){
                client = n.serviceClient<svg_ros::ReadySrv> ("inputs_ready"); // connecting to service ReadySrv:inputs_ready
                flg = 0;
        }

        srv.request.ready = 1;

        if (client.call(srv))
        {
                ROS_INFO("GUI data is available");
        	srv.request.ready = 1;
        }
        else
        {
          ROS_ERROR("Failed to call service ReadySRV");
        return 1;
        }

        return 0;
}

//initialize inputs in case there's no real input
void initialize(Inputs * inputs){
	inputs->xo=.10;
	inputs->yo=.10;
	inputs->angle_robot=0.0;
	inputs->xd=0.750;
	inputs->yd=1.60;
	strcpy(inputs->sensor,"laser");
	inputs->num_sensors=8;
	


	inputs->theta_sensor=-0.2;
	inputs->range_sensor=0.4;
	strcpy(inputs->environment,"room");
	strcpy(inputs->path,"../data/");
	inputs->radio_robot=RADIO_ROBOT;
	inputs->Mag_Advance=MAG_ADVANCE;
	inputs->max_angle=TURN_ANGLE;
	inputs->number_steps= LIMIT_SIM;
	inputs->selection = 1;
	inputs->largest_value = LARGEST_DISTANCE_SENSORS;
        inputs->flgGUI = flgGUI;
        inputs->flg_noise = 1;
}



// callback where GUI sends inputs
bool get_data_GUI(svg_ros::InputsSrv::Request &req, svg_ros::InputsSrv::Response &res)
{
	res.success=1;//flag to assure communication

	
	inputsT.xo=req.origin_x;
	inputsT.yo=req.origin_y;
	inputsT.angle_robot=req.origin_angRob;
	inputsT.xd=req.dest_x;
	inputsT.yd=req.dest_y;
	strcpy(inputsT.sensor,(req.sensorBool).c_str());
	inputsT.num_sensors=req.num_sensorsInt;
	inputsT.theta_sensor=req.angle_sensor_orig;
	inputsT.range_sensor=req.range_angleRob;
	inputsT.radio_robot=req.radiusRob;
	inputsT.Mag_Advance=req.advance;
	inputsT.max_angle=req.max_angle;
	inputsT.number_steps= req.num_steps;
	inputsT.selection = req.select;
	inputsT.largest_value = req.largest_sensor;
	strcpy(inputsT.path,(req.pathNAme).c_str());
	strcpy(inputsT.environment,(req.fileNAme).c_str());
	inputsT.flg_noise = req.flg_noise;


	//ROS_INFO("geting inputs from GUI: x=%f y=%f",(float)req.origin_x,(float)req.origin_y);
	//printf("flg_noise %d\n",inputsT.flg_noise);
	//ROS_INFO("sending back response: success %i",(int)res.success);

	//ready_gui();

	flgGUI = 0;
	return true;

}


//callback: Nodes will receive input data
bool send_data_nodes(svg_ros::InputsPlannerSrv::Request &req, svg_ros::InputsPlannerSrv::Response &res)
{

	//printf("send_data_node\n");
	res.origin_x = inputsT.xo;
	res.origin_y = inputsT.yo;
	res.origin_angRob = inputsT.angle_robot;
	res.dest_x = inputsT.xd;
	res.dest_y = inputsT.yd;
	res.sensorBool = inputsT.sensor;
	res.num_sensorsInt = inputsT.num_sensors;
	res.angle_sensor_orig = inputsT.theta_sensor;
	res.range_angleRob = inputsT.range_sensor;
	res.radiusRob = inputsT.radio_robot;
	res.advance = inputsT.Mag_Advance;
	res.max_angle = inputsT.max_angle;
	res.num_steps = inputsT.number_steps;
	res.select = inputsT.selection;
	res.largest_sensor = inputsT.largest_value;
	res.pathNAme = inputsT.path;
	res.fileNAme = inputsT.environment;
	res.flg_noise = inputsT.flg_noise;

	//ROS_INFO("sending back inputs: [ %f %f ]", (float)res.origin_x, (float)res.origin_y);

	res.flgGUI = flgGUI;
	//send to nodes when GUI input has been send
	/*
	if(!flgGUI){
		ROS_INFO("sending back inputs: [ %f %f ]", (float)res.origin_x, (float)res.origin_y);
		ROS_INFO("sending back count %i",count);
		count ++;
		if(count <= 1){
			//change state to wait for inputs
			flgGUI = 1;
			count = 0;

		}
		
	}

	res.flgGUI = flgGUI;
	*/

	return true;

}



// callback that checks if motion planner has ended
bool over_inputs(svg_ros::OverSrv::Request &req, svg_ros::OverSrv::Response &res)
{

 res.answer=1;//flag to assure communication	
 flgEND = req.over_flg;
 flgGUI = 1;
 //printf("Ready again to receive data from GUI\n");

 return true;
}

//callback: Confirm end to GUI
bool confirm_end(svg_ros::OverSrv::Request &req, svg_ros::OverSrv::Response &res)
{

	res.answer = flgEND;

	//send to nodes when GUI input has been send
	if(!flgEND){
			//change state to wait for state
			flgEND = 1;		
	}
	return true;
}



int main(int argc, char **argv)
{

	ros::init(argc, argv, "inputs_Server");
	initialize(&inputsT);
	ros::NodeHandle n;


	//dos servidores, uno para escuchar inputs del gui, otro para enviar inputs a los otros nodos
	ros::ServiceServer service = n.advertiseService("sendInputs", get_data_GUI);
	ros::ServiceServer service2 = n.advertiseService("receiveInputs",send_data_nodes);
	//dos servidores, uno para verificar si ha terminado, otro para indicarselo a la GUI
	ros::ServiceServer service4 = n.advertiseService("over_inputs", over_inputs);
	//ros::ServiceServer service5 = n.advertiseService("confirm_end",confirm_end);
	ROS_INFO("Ready to manage inputs from the GUI");

	ros::spin();
	return 0;
}
