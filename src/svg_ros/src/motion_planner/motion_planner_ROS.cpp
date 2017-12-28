/********************************************************************************
*                                                                               *
* motion_planner_ROS.cpp                                                        *
*  ===================                                                          *
*                                                                               *
*  Description:                                                                 *
*  It controls the movement of a robot using state machines.                    *
*  It uses a real robot or a simulated one.                                     *
*                                                                               *
*                               J. Savage                                       *
*                                                                               *
*                               FI-UNAM 2017                                    *
********************************************************************************/

// System include files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
// Robotics include files

#include "../utilities/constants.h"
#include "../utilities/structures.h"
#include "../simulator/simulation.h"
#include "../utilities/utilities.h"
#include "../utilities/inputs.h"
#include "../state_machines/state_machine_avoidance.h"
#include "../state_machines/state_machine_destination.h"
#include "../state_machines/state_machine_avoidance_destination.h"
#include "../state_machines/state_machine_surround.h"
#include "../state_machines/state_machine_surround_obst.h"
#include "../state_machines/potential_fields.h"



#include "ros/ros.h"
#include "../ROSutilities/receiveInputs.h"
#include "../ROSutilities/receiveInputsMV.h" 
#include "../ROSutilities/ros_util.h"
#include "../ROSutilities/over_state.h"

float K_GOAL=CNT_GOAL*MAG_ADVANCE;


// it moves the robot from the origen to the destination using state machines
int go_to()
{
 
 Inputs inputs;
 MV mv_inputs; /**///////////////////////////////////
 char file_obs[250];
 char world_file[250];
 char new_str[255];
 float theta=0;
 int j;
 int i=0,k;
 FILE *fpw;
 Raw observations;
 int num_obs=1;
 float distance1;
 coord coord_robot;
 coord coord_dest;
 coord coord_nodo; //nodo
 int flg,flag;
 int debug=0;
 float xmv,ymv,thetamv;
 int quantized_obs;
 int quantized_attraction;
 int quantized_intensity;
 AdvanceAngle mov_vector;
 int next_state;
 int next_state_avoidance=0, next_state_destination=0, next_state_avoidance_destination=0, next_state_surround=0,next_state_surround_obst=0;
 int next_state_potential_fields=0;
 int state=-1;
 AdvanceAngle DistTheta;
 AdvanceAngle mov_vector_avoidance;
 AdvanceAngle mov_vector_destination;
 AdvanceAngle mov_vector_avoidance_destination;
 AdvanceAngle mov_vector_potential_fields;
 int selection = 3;
 float largest_value;

 coord vector_destination;

 /*Para los cmapos potenciales contantes*/
float e=1,d=1,n=.02,d0=.002,delta=1;
int auxx=0;
//para el DFS
int once=1;
int contador_nodos=0;
coord fuerza_atraccion;
coord fuerza_repulsion;
coord new_step;
step *navegacion;
int flag2=0;
int numero_de_nodos;
float distance2;
int atascado=0;
float x_anterior=10,y_anterior=10;

float limit=-1.005;
int xyz=1;//quitar

//case 9
int contador_instruccion=0;
FILE *archivo;
		  char linea[500];
		  struc_linea palabra;
		  int comienza=0;
		  int n_instrucciones=0;
		  char **instrucciones;
		  int estamos=0;
		  char s1[]="s1";
		   coord coord_dest2;
		   int bandera_shingona;
		   int xxx;
		  
int flag_avoidance=0;


//get inputs from GUI
 std::string inputs_node_name= "receiveInputs";
 ROS_INFO("Waiting data from the GUI");
 flag=1;   
 while(flag) {
	flag=receiveInputs(&inputs,"receiveInputs");
	//flag=receiveInputs(&inputs,inputs_node_name);
	usleep(10000);
 }	

 strcpy(inputs.sensor,"laser");

 // it opens the observation's sensor file to be plot by the graphical interface
 sprintf(file_obs,"%s%s.raw",inputs.path,inputs.environment);
 //printf("\nobservations file: %s\n",file_obs);
 if((fpw=fopen(file_obs,"w")) == NULL){
	printf("File %s can not be open\n",file_obs);
		return(0);
 }	

 fprintf(fpw,"( radio_robot %f )\n",inputs.radio_robot);
 sprintf(new_str,"( radio_robot %f )\n",inputs.radio_robot);
 string_to_gui(new_str);
 memset(new_str, 0, sizeof new_str);
 //printf("Radio robot %f \n",inputs.radio_robot);

 coord_robot.xc=inputs.xo;
 coord_robot.yc=inputs.yo;
 coord_robot.anglec=inputs.angle_robot;
 coord_dest.xc=inputs.xd;
 coord_dest.yc=inputs.yd;
 fprintf(fpw,"( destination %f %f )\n",inputs.xd,inputs.yd);
 
 selection=inputs.selection; 
 largest_value=inputs.largest_value;

 flg=0;

 K_GOAL=CNT_GOAL*inputs.Mag_Advance;

next_state_avoidance=0;
 // it moves the robot to the final destination
 while(flg == 0){

	printf("\n\n ********************** STEP %d **************************************\n",num_obs);
	printf("Pose robot x:%f y:%f angle:%f \n",coord_robot.xc,coord_robot.yc,coord_robot.anglec);

 	// Get the position of the light source from the real robot or the simulate one
 	get_destination(&coord_robot,&coord_dest,&quantized_intensity,&quantized_attraction);

 	printf("Quantized intensity %d \n",quantized_intensity);
 	printf("Quantized destination %d \n",quantized_attraction);
 	printf("Destination x:%f y:%f\n",coord_dest.xc,coord_dest.yc);

	distance1=distance(coord_robot,coord_dest);
	printf("Distance destination %f threshold %f\n",distance1,K_GOAL);

	// it checks if the robot reached its destination
	if( distance1 < K_GOAL){
		printf("Reached distance destination %f\n",distance1);
		flg= 1;
		break;
	}

	// it gets laser observations from the simulator or the real robot
	GetObservations(&coord_robot,&observations,largest_value);
	//GetObservations_turtle(&observations,inputs.num_sensors,inputs.theta_sensor,inputs.range_sensor,inputs.largest_value);


	// it send the robot position to the base module either the simulator or the real robot
	SendPositionMVServer(coord_robot);

	
	// it saves the robot's position to be plotted by the GUI
	fprintf(fpw,"( robot Justina %f %f %f )\n",coord_robot.xc,coord_robot.yc,coord_robot.anglec);
	sprintf(new_str,"( robot Justina %f %f %f )\n",coord_robot.xc,coord_robot.yc,coord_robot.anglec);
    	string_to_gui(new_str); //send plotting data to gui
	memset(new_str, 0, sizeof new_str);

	// it saves the sensor data to be plot by Python/TK
	//write_obs_sensor(fpw,observations,inputs.sensor,inputs.num_sensors,inputs.theta_sensor,inputs.range_sensor);
	write_obs_sensor_pos(fpw,observations,inputs.sensor,inputs.num_sensors,inputs.theta_sensor,inputs.range_sensor,coord_robot);

	// It quantizes the laser inputs
	quantized_obs=quantize_inputs(observations,inputs.num_sensors,largest_value);
	//printf("quantized inputs %d\n",quantized_obs);


	// it executes the desired behaviour
	switch ( selection) {

		    case 0:

		    		//get inputs from GUI
			 
					 ROS_INFO("Waiting data from new step");
					 flag=1;   
					 while(flag) {
						flag=receiveInputsMV(&mv_inputs,"enviador");
						//flag=receiveInputs(&inputs,inputs_node_name);
						usleep(10000);
					 }

					 printf("Paso a pasito\n");


		              printf("Esto recibo %s\n",mv_inputs.param );
		            if(mv_inputs.param[0]=='0')
		            {
		            	DistTheta.angle=mv_inputs.coord_ang;
						DistTheta.distance=inputs.Mag_Advance;
		            }else
		            {
		            	sscanf(mv_inputs.param,"mv %f %f",&DistTheta.distance,&DistTheta.angle);
		           	
		            }  

			

			
		    break;

            case 1:
					// It calculates the robot's movement using an state machine avoidance
					
			           GetObservations(&coord_robot,&observations,largest_value);
						quantized_obs=quantize_inputs(observations,inputs.num_sensors,largest_value);
							

					if (state==0 && next_state_avoidance==0)
						while(state==0 && quantized_obs==0)
						{
							GetObservations(&coord_robot,&observations,largest_value);
							quantized_obs=quantize_inputs(observations,inputs.num_sensors,largest_value);	
							//usleep(1000000);
						}
					
					

					state=next_state_avoidance;

					mov_vector_avoidance = state_machine_avoidance(quantized_obs, state, &next_state_avoidance,inputs.Mag_Advance,inputs.max_angle);
					//printf("movement avoidance: angle  %f distance %f\n",mov_vector.angle,mov_vector.distance);
					DistTheta.angle=mov_vector_avoidance.angle;
					DistTheta.distance=mov_vector_avoidance.distance;





	        break;
	        case 10:
					// It calculates the robot's movement using an state machine avoidance
					
	        	
			        GetObservations(&coord_robot,&observations,largest_value);
					quantized_obs=quantize_inputs(observations,inputs.num_sensors,largest_value);
												

					state=next_state_avoidance;

					mov_vector_avoidance = state_machine_avoidance(quantized_obs, state, &next_state_avoidance,inputs.Mag_Advance,inputs.max_angle);
					//printf("movement avoidance: angle  %f distance %f\n",mov_vector.angle,mov_vector.distance);
					DistTheta.angle=mov_vector_avoidance.angle;
					DistTheta.distance=mov_vector_avoidance.distance;

	        break;

            case 2:
             
            while(xyz)
			{
				GetObservations(&coord_robot,&observations,largest_value);
				quantized_obs=quantize_inputs(observations,inputs.num_sensors,largest_value);	
				printf("Muestreo %d\n",xyz++);
			}

           
		// It calculates the robot's movement using an state machine destination
		state=next_state_destination;
		mov_vector_destination = state_machine_destination(quantized_attraction, quantized_intensity, state,  
									&next_state_destination,inputs.Mag_Advance,inputs.max_angle);

		//printf("movement destination: angle  %f distance %f\n",mov_vector.angle,mov_vector.distance);
		DistTheta.angle=mov_vector_destination.angle;
		DistTheta.distance=mov_vector_destination.distance;
	        break;

            case 3:
		// It calculates the robot's movement using an state machine avoidance destination
		state=next_state_avoidance_destination;
		mov_vector_avoidance_destination = state_machine_avoidance_destination(quantized_obs, quantized_attraction, quantized_intensity, state, 
										   &next_state_avoidance_destination,inputs.Mag_Advance,inputs.max_angle);
		DistTheta.angle=mov_vector_avoidance_destination.angle;
		DistTheta.distance=mov_vector_avoidance_destination.distance;
		//printf("movement avoidance destination: angle  %f distance %f\n",
					//mov_vector_avoidance_destination.angle,mov_vector_avoidance_destination.distance);
		break;

		    case 4:
		// It calculates the robot's movement using an state machine avoidance destination
		   quantized_obs=quantize_inputs_surround(observations,inputs.num_sensors);
		state=next_state_surround;
		mov_vector_avoidance_destination = state_machine_surround(quantized_obs, quantized_attraction, quantized_intensity, state, &next_state_surround,inputs.Mag_Advance,inputs.max_angle);
		DistTheta.angle=mov_vector_avoidance_destination.angle;
		DistTheta.distance=mov_vector_avoidance_destination.distance;
		//printf("movement avoidance destination: angle  %f distance %f\n",
					//mov_vector_avoidance_destination.angle,mov_vector_avoidance_destination.distance);
		break;

		    case 5:
		// It calculates the robot's movement using an state machine avoidance destination
		   quantized_obs=quantize_inputs_surround(observations,inputs.num_sensors);
		state=next_state_surround_obst;
		mov_vector_avoidance_destination = state_machine_surround_obst(quantized_obs, quantized_attraction, quantized_intensity, state, &next_state_surround_obst,inputs.Mag_Advance,inputs.max_angle);
		DistTheta.angle=mov_vector_avoidance_destination.angle;
		DistTheta.distance=mov_vector_avoidance_destination.distance;
		//printf("movement avoidance destination: angle  %f distance %f\n",
					//mov_vector_avoidance_destination.angle,mov_vector_avoidance_destination.distance);
		break;

		case 6:
		coord fuerza_atraccion;
		coord fuerza_repulsion;
		coord new_step;

		get_atraction(e, d,&coord_robot,&coord_dest ,&fuerza_atraccion);
		

		state=get_repultion(observations,n,d0,&coord_robot,&coord_dest,&fuerza_repulsion);
		new_step=get_next_position(delta,&coord_dest, &coord_robot,&fuerza_atraccion,&fuerza_repulsion);
		

		printf("Anterior:%f ahora: %f \n",x_anterior,coord_robot.xc );
      if(fabsf(coord_robot.xc-x_anterior)<limit && fabsf(coord_robot.yc-y_anterior)<limit)
      	{
			atascado++;
        	printf("REsta %f",fabsf(x_anterior-coord_robot.xc));
			if(atascado>10)
           {

           	printf("DESATASCON");
           	usleep(3000000);
			atascado=0;
			auxx=2;

			}
		}else
		{
			atascado=0;
		}
		mov_vector_potential_fields = potential_fields(&auxx,state,&coord_robot,&new_step,inputs.Mag_Advance);
		
        x_anterior=coord_robot.xc;
        y_anterior=coord_robot.yc;


		DistTheta.angle=mov_vector_potential_fields.angle;
		DistTheta.distance=mov_vector_potential_fields.distance;
		
		break;

		case 7:

		if(once)
		{

			//dfs();
			numero_de_nodos=num_nodos();
			printf("******************%d num nodos \n",numero_de_nodos);
			navegacion=(step *) malloc(numero_de_nodos*(sizeof(step)));
			/*for(int i=0;i<numero_de_nodos;i++)
			{
				navegacion[i]=(step *) malloc((sizeof(step)));
			}
			*/
            dfs(navegacion,&coord_dest, &coord_robot);
            contador_nodos=0;
			coord_nodo.xc=navegacion[contador_nodos].x;
			coord_nodo.yc=navegacion[contador_nodos].y;
			
			once=0;	
		}


		for(int i=0;i<numero_de_nodos;i++)
			{
				if(navegacion[i].n!=-1)
				printf("%d :  x: %f  y: %f \n  ",navegacion[i].n,navegacion[i].x,navegacion[i].y);
			}
		




		/*CORDENADAS DEL DESTINO REAL*/

		

			
			//usleep(10000);
	        distance2=distance(coord_robot,coord_nodo);
	        if( distance2 < K_GOAL)
	        {
				printf("Llegamos a un nodo  %d :  x: %f  y: %f \n  ",navegacion[contador_nodos].n,navegacion[contador_nodos].x,navegacion[contador_nodos].y);
			
				usleep(1000000);
				contador_nodos++;
				if(navegacion[contador_nodos].n==-1)
				{
					flg=1;
				}
				coord_nodo.xc=navegacion[contador_nodos].x;
				coord_nodo.yc=navegacion[contador_nodos].y;
				
			}
		     
			printf("Vamos al nodo %d: con coordenada  x(%f) y(%f)  \n",navegacion[contador_nodos].n,navegacion[contador_nodos].x,navegacion[contador_nodos].y);
			

			get_atraction(e, d,&coord_robot,&coord_nodo ,&fuerza_atraccion);
			state=get_repultion(observations,n,d0,&coord_robot,&coord_nodo,&fuerza_repulsion);
			new_step=get_next_position(delta,&coord_nodo, &coord_robot,&fuerza_atraccion,&fuerza_repulsion);
			
			printf("Anterior:%f ahora: %f \n",x_anterior,coord_robot.xc );
      if(fabsf(coord_robot.xc-x_anterior)<limit && fabsf(coord_robot.yc-y_anterior)<limit)
      	{
			atascado++;
        	printf("REsta %f",fabsf(x_anterior-coord_robot.xc));
			if(atascado>10)
           {

           	printf("DESATASCON");
           	usleep(1000000);
			atascado=0;
			auxx=2;

			}
		}else
		{
			atascado=0;
		}

			mov_vector_potential_fields = potential_fields(&auxx,state,&coord_robot,&new_step,inputs.Mag_Advance);
		 x_anterior=coord_robot.xc;
        y_anterior=coord_robot.yc;

        	DistTheta.angle=mov_vector_potential_fields.angle;
			DistTheta.distance=mov_vector_potential_fields.distance;

		
			
		break;

		case 8:

		if(once)
		{

			//dfs();
			numero_de_nodos=num_nodos();
			printf("******************%d num nodos \n",numero_de_nodos);
			navegacion=(step *) malloc(numero_de_nodos*(sizeof(step )));
		/*	for(int i=0;i<numero_de_nodos;i++)
			{
				navegacion[i]=(step *) malloc(numero_de_nodos* (sizeof(step)));
			}
*/

            djkstra(navegacion,&coord_dest, &coord_robot);
            contador_nodos=0;
			coord_nodo.xc=navegacion[contador_nodos].x;
			coord_nodo.yc=navegacion[contador_nodos].y;
			once=0;	
		}
		printf("          **********Ruta a seguir*********\n");
		for(int i=0;i<numero_de_nodos;i++)
			{
				if(navegacion[i].n!=-1)
				//printf(":D");
				printf("\t\t%d :  x: %f  y: %f \n  ",navegacion[i].n,navegacion[i].x,navegacion[i].y);
			}
		
			
			//usleep(100000);
	        distance2=distance(coord_robot,coord_nodo);
	        if( distance2 < K_GOAL)
	        {
				printf("Llegamos a un nodo  %d :  x: %f  y: %f \n  ",navegacion[contador_nodos].n,navegacion[contador_nodos].x,navegacion[contador_nodos].y);
			
				usleep(1000000);
				contador_nodos++;
				if(navegacion[contador_nodos].n==-1)
				{
					flg=1;
				}
				coord_nodo.xc=navegacion[contador_nodos].x;
				coord_nodo.yc=navegacion[contador_nodos].y;
				
			}
		     
			printf("Vamos al nodo %d: con coordenada  x(%f) y(%f)  \n",navegacion[contador_nodos].n,navegacion[contador_nodos].x,navegacion[contador_nodos].y);
			

			get_atraction(e, d,&coord_robot,&coord_nodo ,&fuerza_atraccion);
			state=get_repultion(observations,n,d0,&coord_robot,&coord_nodo,&fuerza_repulsion);
			new_step=get_next_position(delta,&coord_nodo, &coord_robot,&fuerza_atraccion,&fuerza_repulsion);
				printf("Anterior:%f ahora: %f \n",x_anterior,coord_robot.xc );
      if(fabsf(coord_robot.xc-x_anterior)<limit && fabsf(coord_robot.yc-y_anterior)<limit)
      	{
			atascado++;
        	printf("REsta %f",fabsf(x_anterior-coord_robot.xc));
			if(atascado>10)
           {

           	printf("DESATASCON");
           	usleep(1000000);
			atascado=0;
			auxx=2;

			}
		}else
		{
			atascado=0;
		}

			mov_vector_potential_fields = potential_fields(&auxx,state,&coord_robot,&new_step,inputs.Mag_Advance);
		 x_anterior=coord_robot.xc;
        y_anterior=coord_robot.yc;
        //mov_vector_potential_fields = potential_fields(&auxx,state,&coord_robot,&new_step,inputs.Mag_Advance);
			DistTheta.angle=mov_vector_potential_fields.angle;
			DistTheta.distance=mov_vector_potential_fields.distance;

			//for(int r=0;r<100;r++)
        	//printf("SI MERESCO ABUNDANCIA\n");
			
		break;
		case 9:



		if(once)
		{  
			int i=0;
		  /*Obtener instrucciones*/
		  archivo = fopen("../utilities/acciones.txt","r");
		  if (archivo == NULL){printf("NUUUUU"); return(0);}
		  while (feof(archivo) == 0)
		  {
		    fgets(linea,1000,archivo);
		    //  printf("%s",linea);  
		      n_instrucciones++;
		  }
		

		  instrucciones =(char **) malloc( n_instrucciones * sizeof( char *) ); /* RESERVAR MEMORIA PARA EL NUMERO DE instrucciones */
 
		  rewind(archivo);
		  while (feof(archivo) == 0)
		  {
		    fgets(linea,1000,archivo);
		    instrucciones[i] =(char *) malloc ( sizeof(char) *(strlen(linea)+2) );
		    strcpy(instrucciones[i],linea);
		    printf("Guardado %s\n",instrucciones[i]);
		    i++;
		  }
		  fclose(archivo);
			once=0;	
		}
        numero_de_nodos=13;


       	if (instrucciones[contador_instruccion][0]=='s')
       	{
       		bandera_shingona=0;

       		if ( instrucciones[contador_instruccion][1]=='1'  && estamos!=1  )
       		{		

					navegacion=(step *) malloc(numero_de_nodos*(sizeof(step )));
       			    coord_dest2.xc=4.6;
       			    coord_dest2.yc=1.7;
  					djkstra(navegacion,&coord_dest2, &coord_robot);
            		contador_nodos=0;
					coord_nodo.xc=navegacion[contador_nodos].x;
					coord_nodo.yc=navegacion[contador_nodos].y;

       			estamos=1;
       		}
       		if ( instrucciones[contador_instruccion][1]=='2'  && estamos!=2  )
       		{		
					navegacion=(step *) malloc(numero_de_nodos*(sizeof(step )));
       			    coord_dest2.xc=3.3;
       			    coord_dest2.yc=1.7;
  					djkstra(navegacion,&coord_dest2, &coord_robot);
            		contador_nodos=0;
					coord_nodo.xc=navegacion[contador_nodos].x;
					coord_nodo.yc=navegacion[contador_nodos].y;

       			estamos=2;
       		}
       		if ( instrucciones[contador_instruccion][1]=='3'  && estamos!=3  )
       		{		
					navegacion=(step *) malloc(numero_de_nodos*(sizeof(step )));
       			    coord_dest2.xc=.4;
       			    coord_dest2.yc=5.8;
  					djkstra(navegacion,&coord_dest2, &coord_robot);
            		contador_nodos=0;
					coord_nodo.xc=navegacion[contador_nodos].x;
					coord_nodo.yc=navegacion[contador_nodos].y;

       			estamos=3;
       		}
       		if ( instrucciones[contador_instruccion][1]=='4'  && estamos!=4  )
       		{		
					navegacion=(step *) malloc(numero_de_nodos*(sizeof(step )));
       			    coord_dest2.xc=1.3;
       			    coord_dest2.yc=11.6;
  					djkstra(navegacion,&coord_dest2, &coord_robot);
            		contador_nodos=0;
					coord_nodo.xc=navegacion[contador_nodos].x;
					coord_nodo.yc=navegacion[contador_nodos].y;

       			estamos=4;
       		}
       		if ( instrucciones[contador_instruccion][1]=='5'  && estamos!=5  )
       		{		
					navegacion=(step *) malloc(numero_de_nodos*(sizeof(step )));
       			    coord_dest2.xc=2.8;
       			    coord_dest2.yc=11.6;
  					djkstra(navegacion,&coord_dest2, &coord_robot);
            		contador_nodos=0;
					coord_nodo.xc=navegacion[contador_nodos].x;
					coord_nodo.yc=navegacion[contador_nodos].y;

       			estamos=5;
       		}
       		if ( instrucciones[contador_instruccion][1]=='6'  && estamos!=6  )
       		{		
					navegacion=(step *) malloc(numero_de_nodos*(sizeof(step )));
       			    coord_dest2.xc=4.5;
       			    coord_dest2.yc=11.6;
  					djkstra(navegacion,&coord_dest2, &coord_robot);
            		contador_nodos=0;
					coord_nodo.xc=navegacion[contador_nodos].x;
					coord_nodo.yc=navegacion[contador_nodos].y;

       			estamos=6;
       		}

       		
       	}else if( instrucciones[contador_instruccion][0]!='s' )
       	{
       		printf("######################################");
       		printf("%s\n",instrucciones[contador_instruccion]);
       		usleep(1000000);
             bandera_shingona=1;
       		if( instrucciones[contador_instruccion][0]=='F'  ){flg=1; continue;}
       		contador_instruccion++;
             
xxx=-1;
             if (instrucciones[contador_instruccion][0]=='s')
       		{
       		
       		if ( instrucciones[contador_instruccion][1]=='1'   )
       		{		
       				xxx=1;
       		}
       		if ( instrucciones[contador_instruccion][1]=='2'   )
       		{		
			    xxx=2;
       		}
       		if ( instrucciones[contador_instruccion][1]=='3'   )
       		{		
				xxx=3;
       		}
       		if ( instrucciones[contador_instruccion][1]=='4'   )
       		{		
				xxx=4;
       		}
       		if ( instrucciones[contador_instruccion][1]=='5'   )
       		{	
       			xxx=5;
       		}
       		if ( instrucciones[contador_instruccion][1]=='6' )
       		{		
					xxx=6;
       		}   }         
                      
while(estamos==xxx)

{

	printf("1111111111111111111111");
            if (instrucciones[contador_instruccion][0]=='s')
       		{
       		

       		if ( instrucciones[contador_instruccion][1]=='1'  && estamos==1  )
       		{		
       				 xxx=9;
       				 contador_instruccion++;
       		}
       		if ( instrucciones[contador_instruccion][1]=='2'  && estamos==2  )
       		{		
       			xxx=9;
			    contador_instruccion++;	
       		}
       		if ( instrucciones[contador_instruccion][1]=='3'  && estamos==3  )
       		{		
				xxx=93;
				contador_instruccion++;
       		}
       		if ( instrucciones[contador_instruccion][1]=='4'  && estamos==4  )
       		{		
				xxx=49;
				contador_instruccion++;
       		}
       		if ( instrucciones[contador_instruccion][1]=='5'  && estamos==5  )
       		{	
       			xxx=59;
       			contador_instruccion++;	
       		}
       		if ( instrucciones[contador_instruccion][1]=='6'  && estamos==6  )
       		{		
					xxx=69;
					contador_instruccion++;
       		}
	
		       	}
					 
					 
					 	
					 }



       	}


	

		printf("          **********Ruta a seguir*********\n");
		for(int i=0;i<numero_de_nodos;i++)
			{
				if(navegacion[i].n!=-1)
				//printf(":D");
				printf("\t\t%d :  x: %f  y: %f \n  ",navegacion[i].n,navegacion[i].x,navegacion[i].y);
			}
		
			
			//usleep(100000);
	        distance2=distance(coord_robot,coord_nodo);
	        if( distance2 < K_GOAL)
	        {
				printf("Llegamos a un nodo  %d :  x: %f  y: %f \n  ",navegacion[contador_nodos].n,navegacion[contador_nodos].x,navegacion[contador_nodos].y);
			
				usleep(1000000);
				contador_nodos++;
				if(navegacion[contador_nodos].n==-1)
				{
					
                     contador_instruccion++;
xxx=-1;
      if (instrucciones[contador_instruccion][0]=='s')
       		{
       		
       		if ( instrucciones[contador_instruccion][1]=='1'   )
       		{		
       				xxx=1;
       		}
       		if ( instrucciones[contador_instruccion][1]=='2'   )
       		{		
			    xxx=2;
       		}
       		if ( instrucciones[contador_instruccion][1]=='3'   )
       		{		
				xxx=3;
       		}
       		if ( instrucciones[contador_instruccion][1]=='4'   )
       		{		
				xxx=4;
       		}
       		if ( instrucciones[contador_instruccion][1]=='5'   )
       		{	
       			xxx=5;
       		}
       		if ( instrucciones[contador_instruccion][1]=='6' )
       		{		
					xxx=6;
       		}   }         
                      
while(estamos==xxx)

{

	printf("1111111111111111111111");
            if (instrucciones[contador_instruccion][0]=='s')
       		{
       		

       		if ( instrucciones[contador_instruccion][1]=='1'  && estamos==1  )
       		{		
       				 xxx=9;
       				 contador_instruccion++;
       		}
       		if ( instrucciones[contador_instruccion][1]=='2'  && estamos==2  )
       		{		
       			xxx=9;
			    contador_instruccion++;	
       		}
       		if ( instrucciones[contador_instruccion][1]=='3'  && estamos==3  )
       		{		
				xxx=93;
				contador_instruccion++;
       		}
       		if ( instrucciones[contador_instruccion][1]=='4'  && estamos==4  )
       		{		
				xxx=49;
				contador_instruccion++;
       		}
       		if ( instrucciones[contador_instruccion][1]=='5'  && estamos==5  )
       		{	
       			xxx=59;
       			contador_instruccion++;	
       		}
       		if ( instrucciones[contador_instruccion][1]=='6'  && estamos==6  )
       		{		
					xxx=69;
					contador_instruccion++;
       		}
	
		       	}
					 
					 
					 	
					 }
					 
					 	

					 printf("avanzamos la instruccion");
				}
				coord_nodo.xc=navegacion[contador_nodos].x;
				coord_nodo.yc=navegacion[contador_nodos].y;
				
			}
		     
			printf("Vamos al nodo %d: con coordenada  x(%f) y(%f)  \n",navegacion[contador_nodos].n,navegacion[contador_nodos].x,navegacion[contador_nodos].y);
			

			get_atraction(e, d,&coord_robot,&coord_nodo ,&fuerza_atraccion);
			state=get_repultion(observations,n,d0,&coord_robot,&coord_nodo,&fuerza_repulsion);
			new_step=get_next_position(delta,&coord_nodo, &coord_robot,&fuerza_atraccion,&fuerza_repulsion);
				printf("Anterior:%f ahora: %f \n",x_anterior,coord_robot.xc );
      if(fabsf(coord_robot.xc-x_anterior)<limit && fabsf(coord_robot.yc-y_anterior)<limit)
      	{
			atascado++;
        	printf("REsta %f",fabsf(x_anterior-coord_robot.xc));
			if(atascado>10)
           {

           	printf("DESATASCON");
           	usleep(1000000);
			atascado=0;
			auxx=2;

			}
		}else
		{
			atascado=0;
		}

			mov_vector_potential_fields = potential_fields(&auxx,state,&coord_robot,&new_step,inputs.Mag_Advance);
		 x_anterior=coord_robot.xc;
        y_anterior=coord_robot.yc;
        //mov_vector_potential_fields = potential_fields(&auxx,state,&coord_robot,&new_step,inputs.Mag_Advance);
			

        	if(!bandera_shingona)
        	{
			DistTheta.angle=mov_vector_potential_fields.angle;
			DistTheta.distance=mov_vector_potential_fields.distance;
			}else{
			DistTheta.angle=0;
			DistTheta.distance=0;

			}



		break;



	    default:
                printf("Selection %d not defined\n", selection);
		flg=1;
		DistTheta.angle=0.0;
		DistTheta.distance=0.0;
		break;

	  


	}


	//it moves the robot
	mvrobot(DistTheta,&coord_robot);

	num_obs++;
	if(num_obs > inputs.number_steps) flg=1;
	//usleep(1000000);
	//usleep(10000);

 }
 /*Para que se detenga al terminar y no continue hacia enfrente*/
DistTheta.angle=0;
DistTheta.distance=0;
mvrobot(DistTheta,&coord_robot);

 if(selection==7 || selection==8)
 free(navegacion);
 fclose(fpw);
 return(num_obs);
}



// Main program
int main(int argc, char *argv[])
{

 int num_steps;
 int flg = 1;

 ros::init(argc, argv, "motion_planner_client");
 ROS_INFO("Motion planner node started");


 while(flg){
 	num_steps=go_to();
 	over();//send IS_OVER signal
	usleep(10000);
 }


 return 0;

}


