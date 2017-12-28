      /********************************
     *        Node to manage          *
    *            inputs              *
   *           from GUI             *
  *         to other nodes         *
 *                                *
*********************************/
#include "ros/ros.h"
#include "svg_ros/MVServ.h"
#include "../utilities/structures.h"
#include "../utilities/constants.h"
#include "svg_ros/MVPlannerSrv.h"
#include "svg_ros/OverSrv.h"
#include "svg_ros/ReadySrv.h"
#include <string.h>

//Global variable to manage inputs
MV inputsT;
int flgGUI = 1;
int flgEND = 1;
int count = 0;
char nada[256];



//initialize inputs in case there's no real input
void initialize( MV * inputs){
	strcpy(inputs->param,nada);
	inputs->coord_x=.10;
	inputs->coord_y=.10;
	inputs->coord_ang=0.0;
}



// callback where GUI sends inputs
bool get_data_GUI(svg_ros::MVServ::Request &req, svg_ros::MVServ::Response &res)
{
	res.answer='1';//flag to assure communication

	
	//inputsT.param=req.param;

	strcpy(inputsT.param,(req.param).c_str());
	//strcpy(inputsT.param,nada);
	inputsT.coord_x=req.coord_x;
	inputsT.coord_y=req.coord_y;
	inputsT.coord_ang=req.coord_ang;


	flgGUI = 0;
	return true;

}


//callback: Nodes will receive input data
bool send_data_nodes(svg_ros::MVPlannerSrv::Request &req, svg_ros::MVPlannerSrv::Response &res)
{

	//printf("send_data_node\n");
	res.param=inputsT.param;
	res.coord_x = inputsT.coord_x;
	res.coord_y = inputsT.coord_y;
	res.coord_ang = inputsT.coord_ang;

	res.flgGUI = flgGUI;
	flgGUI=1;

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




int main(int argc, char **argv)
{

	ros::init(argc, argv, "inputs_ServerMV");
	initialize(&inputsT);
	ros::NodeHandle n;


	//dos servidores, uno para escuchar inputs del gui, otro para enviar inputs a los otros nodos
	ros::ServiceServer service = n.advertiseService("receptor", get_data_GUI);//Resive
	ros::ServiceServer service2 = n.advertiseService("enviador",send_data_nodes);
	//dos servidores, uno para verificar si ha terminado, otro para indicarselo a la GUI
	ros::ServiceServer service4 = n.advertiseService("over_inputsMV", over_inputs);
	ROS_INFO("XXXXXXXXXXXXXXX");

	ros::spin();
	return 0;
}
