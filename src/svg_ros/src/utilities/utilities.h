/****************************************************
* utilities.h                                       *
*                         			    *
*                               J. Savage           *
*                                                   *
*                               FI-UNAM 2015        *
*****************************************************/
#include "svg_ros/LightSrv.h"
#include "svg_ros/MVServ.h"
#include "svg_ros/SensorSrv.h"
#include "svg_ros/ReadySrv.h"


//#include "./structures.h"

#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define DJKSTRA_INICIO 18
#define DJKSTRA_FIN 5

#define DPF_INICIO 18 
#define DPF_FIN   5


char entorno[]="../data/topological_maps/obstacles.top";

//char entorno[]="../data/topological_maps/el_chiningon.top";



int ready_gui=0;



//string to values
int  get_mv_params(std::string str,float *a, float* b){
  using namespace boost::algorithm;
  std::vector<std::string> tokens;

  split(tokens, str, is_any_of(" ")); // here it is

  *a=atof(tokens.at(1).c_str());
  *b=atof(tokens.at(2).c_str());
  return 0;
}




int string_to_gui(char *s){
  //Sends string s to gui
  //ros::NodeHandle n;
  //ros::ServiceClient client = n.serviceClient<svg_ros::MVServ> ("mv_gui_comm");
  //svg_ros::MVServ srv; 
  //srv.request.param=s;

  static int flg = 1;
  static ros::NodeHandle n;
  static ros::ServiceClient client;
  static svg_ros::MVServ srv;


  if(flg == 1){

         client = n.serviceClient<svg_ros::MVServ> ("mv_gui_comm");
         flg = 0;
  }


  srv.request.param=s;
  if (client.call(srv))
  {
    //ROS_INFO("success string_to_gui: %s", srv.response.answer.c_str());
    //ROS_INFO("success string_to_gui");
    //std::cout << srv.response.answer.c_str() << std::endl;
    return 0;
  }
  else
  {
    ROS_ERROR("Failed to call service mv_gui_comm");
    printf("Failed to call service mv_gui_comm");
    return 1;
  }
}
//unused at the moment:
// int  get_mv_params2(std::string str,float *a, float* b){
//   float x,y;
//   char * cstr = new char [str.length()+1];
//   std::strcpy (cstr, str.c_str());
//   // cstr now contains a c-string copy of str
//   char * p = std::strtok (cstr," ");
//   int i=0;
//   while (p!=0 && i<=2)
//   {
//     //std::cout << p << '\n';
//     p = std::strtok(NULL," ");
//     if(i==1){
//       x=atof(p);
//     }
//     else if(i==2){
//       y=atof(p);
//     }
//     i++;
//   }
//   delete[] cstr;
//   *a=x;
//   *b=y;
//   return 0;
// }

//communication with robot's base
int ROS_mvrobot(std::string s,float * answer_distance, float * answer_angle){
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<svg_ros::MVServ> ("move_robot");
  svg_ros::MVServ srv;
  
  srv.request.param=s;
  if (client.call(srv))
  {
    //ROS_INFO("success: %s", srv.response.answer.c_str());
    //std::cout << srv.response.answer.c_str() << std::endl;
  }
  else
  {
    ROS_ERROR("Failed to call service move_robot");
    printf("Failed to call service move_robot");
    return 1;
  }
  get_mv_params(srv.response.answer.c_str(),answer_distance, answer_angle);
  //printf("xxx mv params: %f %f\n", *answer_distance,*answer_angle);


  return 0;

}


int ROS_mvrobot_turtle(std::string s,float * answer_distance, float * answer_angle){
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<svg_ros::MVServ> ("move_robot_turtle");
  svg_ros::MVServ srv;
  
  srv.request.param=s;
  if (client.call(srv))
  {
    //ROS_INFO("success: %s", srv.response.answer.c_str());
    //std::cout << srv.response.answer.c_str() << std::endl;
  }
  else
  {
    ROS_ERROR("Failed to call service move_robot");
    printf("Failed to call service move_robot turtle");
    return 1;
  }
  get_mv_params(srv.response.answer.c_str(),answer_distance, answer_angle);
  //printf("xxx mv params: %f %f\n", *answer_distance,*answer_angle);


  return 0;

}

int GetObservations_turtle (Raw* observations,int num_sensors, float theta, float range,float largest){
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<svg_ros::SensorSrv> ("sensor_robot_turtle");
  svg_ros::SensorSrv srv;
  

  /*
float32 coord_x
float32 coord_y
float32 coord_ang
---
int32 flag
int32 region
float32 x
float32 y
float32 theta
float32[500] sensors
int32 num_sensors
string sensor

  */


  srv.request.coord_x=num_sensors;  //Numero de sensores
  srv.request.coord_y=theta;   //Enpezando desde
  srv.request.coord_ang=range;    //Rango
  




  if (client.call(srv))
  {
    //ROS_INFO("success: %s", srv.response.answer.c_str());
    //std::cout << srv.response.answer.c_str() << std::endl;
  }
  else
  {
    ROS_ERROR("Failed to call service move_robot turtele");
    printf("Failed to call service move_robot turtle");
    return 1;
  }
 // get_mv_params(srv.response.answer.c_str(),answer_distance, answer_angle);
  //printf("xxx mv params: %f %f\n", *answer_distance,*answer_angle);

  observations->flag=srv.response.flag;
  observations->region=srv.response.region;
  observations->x=srv.response.x;
  observations->y=srv.response.y;
  observations->theta=srv.response.theta;
printf("MMMMMMM  %f\n", largest);

  for(int j=0;j<srv.response.num_sensors;j++){
    if(largest<srv.response.sensors[j] ||  srv.response.sensors[j]==0)
     observations->sensors[j]=largest;
     else 
    observations->sensors[j]=srv.response.sensors[j];
    printf("observations->sensors[%d] %f srv.response.sensors[%d] %f\n",j,observations->sensors[j],j,srv.response.sensors[j]);
  }



  return 0;

}







// it gets data from the simulator or the real robot
int GetObservations(coord* coord_robot, Raw* observations,float largest_value){

  static ros::NodeHandle n;
  static ros::ServiceClient client;
  static svg_ros::SensorSrv srv;
  static int flg = 1;

  if(flg == 1){

  	client = n.serviceClient<svg_ros::SensorSrv> ("send_position");
	flg = 0;
  }

  
  srv.request.coord_x=coord_robot->xc;
  srv.request.coord_y=coord_robot->yc;
  srv.request.coord_ang=coord_robot->anglec;
  //printf("\n send_position x %f y %f angle %f\n",coord_robot->xc,coord_robot->yc,coord_robot->anglec);

  if (client.call(srv))
  {
    //ROS_INFO("success send position: %s", srv.response.sensor.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service send_position");
    return 1;
  }
  observations->flag=srv.response.flag;
  observations->region=srv.response.region;
  observations->x=srv.response.x;
  observations->y=srv.response.y;
  observations->theta=srv.response.theta;

  for(int j=0;j<srv.response.num_sensors;j++){
    if (srv.response.sensors[j]>largest_value)
        observations->sensors[j]=largest_value;
    else
      observations->sensors[j]=srv.response.sensors[j];
    //printf("observations->sensors[%d] %f srv.response.sensors[%d] %f\n",j,observations->sensors[j],j,srv.response.sensors[j]);
  }

  //printf("Answer GetObservations: %s \n", srv.response.sensor.c_str());

  return 0;

}



// it send the robot position to the base module either the simulator or the real robot
int SendPositionMVServer(coord coord_robot){

  static ros::NodeHandle n;
  static ros::ServiceClient client;
  static svg_ros::MVServ srv;
  static int flg = 1;

  if(flg == 1){

        client = n.serviceClient<svg_ros::MVServ> ("send_position_mv");
        flg = 0;
  }

  srv.request.coord_x=coord_robot.xc;
  srv.request.coord_y=coord_robot.yc;
  srv.request.coord_ang=coord_robot.anglec;
  //printf("\n send_position MVServer x %f y %f angle %f\n",coord_robot.xc,coord_robot.yc,coord_robot.anglec);

  if (client.call(srv))
  {
    //ROS_INFO("success send position MVServer: %s", srv.response.answer.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service send_position");
    return 1;
  }

  //printf("Answer SendPositionMVServer: %s \n", srv.response.answer.c_str());

  return 0;

}




//gets destination coordinates and quantized values via ROS communication with light_node
int get_destination(coord* coord_robot, coord* coord_dest, int* quantized_intensity = NULL,int* quantized_attraction = NULL){

  //ros::NodeHandle n;
  //ros::ServiceClient client = n.serviceClient<svg_ros::LightSrv> ("send_destination");
  //svg_ros::LightSrv srv;

  static int flg = 1;
  static ros::NodeHandle n;
  static ros::ServiceClient client;
  static svg_ros::LightSrv srv;

  if(flg == 1){

	client = n.serviceClient<svg_ros::LightSrv> ("send_destination");
        flg = 0;
  }

  srv.request.req=1;
  srv.request.coord_x=coord_robot->xc;
  srv.request.coord_y=coord_robot->yc;
  srv.request.coord_ang=coord_robot->anglec;
  if (client.call(srv))
  {
    //ROS_INFO("success send_destination: %f %f", srv.response.x,srv.response.y);
  }
  else
  {
    ROS_ERROR("Failed to call service send_destination");
    return 1;
  }
  //either get dest coords or quantized values
  /*if(srv.response.flag_dest){
    coord_dest->xc=srv.response.x;
    coord_dest->yc=srv.response.y;
  }else{*/
    *quantized_intensity = srv.response.quantized_intensity;
    *quantized_attraction = srv.response.quantized_attraction;
  //}

  //printf("Answer get_destination light sensor: %d %d\n", srv.response.quantized_attraction,srv.response.quantized_intensity);

  return 0;

}


// it writes the sensors' readings to be plot by Tk
int write_obs_sensor(FILE *fpw,Raw observations,char *sensor,int num_sensors, float start_angle,float range){
 
 int j;
 char aux[250],aux1[4];
 fprintf(fpw,"( sensor %s %d %f %f",sensor,num_sensors,range,start_angle);
 sprintf(aux,"( sensor %s %d %f %f",sensor,num_sensors,range,start_angle);

 for(j=0;j<num_sensors;j++){
        char aux2[20];
        fprintf(fpw ," %f",observations.sensors[j]);
        sprintf(aux2," %f",observations.sensors[j]);
        strcat(aux,aux2);
        printf(" %f",observations.sensors[j]);
 }

 fprintf(fpw ," )\n");
 sprintf(aux1," )\n");
 strcat(aux,aux1);

 //send plotting data to gui
 //printf("send plotting data to gui %s",aux);

 string_to_gui(aux);

 return(1);

}



// it writes the sensors' readings and position to be plot by Tk
int write_obs_sensor_pos(FILE *fpw,Raw observations,char *sensor,int num_sensors, float start_angle,float range,coord coord_robot){

 int j;
 char aux[2000],aux1[4];
 fprintf(fpw,"( sensor %s %d %f %f",sensor,num_sensors,range,start_angle);
 sprintf(aux,"( sensor %s %f %f %f %d %f %f",sensor,coord_robot.xc,coord_robot.yc,coord_robot.anglec,num_sensors,range,start_angle);


 for(j=0;j<num_sensors;j++){
        char aux2[20];
        fprintf(fpw ," %f",observations.sensors[j]);
        sprintf(aux2," %f",observations.sensors[j]);
        strcat(aux,aux2);
        //printf(" %f",observations.sensors[j]);
 }

 fprintf(fpw ," )\n");
 sprintf(aux1," )\n");
 strcat(aux,aux1);

 //send plotting data to gui
 //printf("send plotting data to gui %s",aux);

 string_to_gui(aux);

 return(1);

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


/*
 // It quantizes the intensity 
int quantize_intensity(coord coord_robot,coord coor_destination){

 int value=0;
 coord attraction_force;
 float mag;

 attraction_force=dif_vectors(coord_robot,coor_destination);
 mag=magnitude(attraction_force);

 if(mag > K_INTENSITY){
        value = 0;
 }
 else{
         value = 1;
 }

 return value;
}
*/



// it gets the range from the laser sensors
void get_average_sensor(Raw observations, int start, int end, float *average,float largest_value){
 int i;
 float sd=0;
 float distancia=largest_value;
 float bad_lecture=0;
 //printf("range %d %d\n",start,end); 
 for(i=start; i < end;i++){
        if(observations.sensors[i]>= distancia )
          sd=sd + distancia;
        else if (observations.sensors[i] == 0)
          bad_lecture++;
        else
          sd=sd + observations.sensors[i];
        //printf("%d %f %f\n",i,sd,observations.sensors[i]); 
 }

 *average = sd/( ((float)(end-start))-bad_lecture );

 printf("AVG %f  \n",*average );
 
 //printf(" average %f\n\n",*average);
/**average = 0;
  for(i=start; i < end;i++){
        if(observations.sensors[i] <= .3 )
          {
            count++;

            *average = 1;
            break;
          }
        //printf("%d %f %f\n",i,sd,observations.sensors[i]); 
 }*/

 
}


 // It quantizes the inputs
int quantize_inputs(Raw observations, int size,float largest_value){

 int value=0;
 int i;
 float left,right;
 int interval;

 interval = size/2;
 get_average_sensor(observations,interval,size,&left,largest_value);
 //printf("left sensor %f\n",left);
 get_average_sensor(observations,0,interval,&right,largest_value);
 //printf("right sensor %f\n",right);

 //if( left < THRS_SENSOR) value = (value << 1) + 1;
 if( (left*100/largest_value)<= 98 ) value = (value << 1) + 1;
 else value = (value << 1) + 0;

// if( right < THRS_SENSOR) value = (value << 1) + 1;
if( ( right *100/largest_value)<= 98  ) value = (value << 1) + 1;
 else value = (value << 1) + 0;

 //printf("value %d\n",value);
 value = value & 0xFFFFFFFF;
 //printf("value %x\n",value); 

 return(value);

}


 

// This function is used to calculate the rotation angle for the Mvto command
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







coord divide_vector_scalar(coord vector1,float cnt){

        coord div;

        div.xc=vector1.xc/cnt;
        div.yc=vector1.yc/cnt;
        return(div);
}



// it gets an unit vector
coord get_unit_vector(Behavior Bvector){

 float mag;
 coord unit_vector,vector;

 unit_vector.xc=0;
 unit_vector.yc=0;

 vector.xc=Bvector.xc;
 vector.yc=Bvector.yc;

 mag=magnitude(vector);

 if(mag != 0)
        unit_vector=divide_vector_scalar(vector,mag);

 return unit_vector;

}


// it returns the distance to closest poligon from the robot
int shs_distance_obstacle(float x1, float y1, float x2, float y2,float dist_advance){

 int index;
 float distance;


  index=0;
  robot_sensor.vertex[1].x=x1;
  robot_sensor.vertex[1].y=y1;
  robot_sensor.vertex[2].x=x2+0.0001;
  robot_sensor.vertex[2].y=y2+0.0001;

  //printf("check x1 %f y1 %f\n",robot_sensor.vertex[1].x,robot_sensor.vertex[1].y);
  ////printf("check x2 %f y2 %f\n",robot_sensor.vertex[2].x,robot_sensor.vertex[2].y);

  //m=(y2-y1)/(x2-x1);
  //b=(x2*y1-y2*x1)/(x2-x1);
  robot_sensor.line[1].m= (robot_sensor.vertex[2].y-robot_sensor.vertex[1].y)/
                        (robot_sensor.vertex[2].x-robot_sensor.vertex[1].x);
  robot_sensor.line[1].b= (robot_sensor.vertex[2].x*robot_sensor.vertex[1].y-
                         robot_sensor.vertex[2].y*robot_sensor.vertex[1].x)/
                        (robot_sensor.vertex[2].x-robot_sensor.vertex[1].x);




  // it finds the distance to the closest polygon
  distance=distance_polygon(num_polygons_wrl,polygons_wrl,robot_sensor,&index);

  //printf("distance_polygon %d  polygon name %s distance %f\n",index,polygons_wrl[index].name,distance);
  //printf("** check distance closests %f distance advance %f **\n",distance,dist_advance);

 if(distance > dist_advance){
        return 0;
 }else{
        return 1;
 }

}



// it will move the robot the desire angle and distance
void  mvrobot(AdvanceAngle DistTheta,coord *coord_robot ){
 int flg=0;
 float new_xmv,new_ymv,new_thetamv;
 float xc,yc;
 float speed;
 coord new_coord;
 float xmv,ymv,thetamv;
 float distance, angle1;
 float answer_distance;
 float answer_angle;
 char param[20];
 int stat;

 xmv=coord_robot->xc;
 ymv=coord_robot->yc;
 thetamv=coord_robot->anglec;

 angle1 = DistTheta.angle;
 //printf("angle1 %f\n",angle1);
 distance = DistTheta.distance;

 stat=DistTheta.step;


 if(angle1 > 5.75f) angle1=- (angle1 - 5.75f) ;

 sprintf(param,"mv %f %f ",distance,angle1);
 printf("mv %f %f ",distance,angle1);
 //ROS_mvrobot(param,&answer_distance, &answer_angle);
 ROS_mvrobot_turtle(param,&answer_distance, &answer_angle);
 angle1 = answer_angle;
 distance = answer_distance;


 new_thetamv = thetamv + angle1;
 if(new_thetamv > 6.2832) new_thetamv = new_thetamv - (float) 6.2832;
 else if(new_thetamv < -0.0) new_thetamv = new_thetamv + (float) 6.2832;

 new_xmv = xmv + (float) distance*(float)cos((float) (new_thetamv));
 new_ymv = ymv + (float) distance*(float)sin((float) (new_thetamv));

 // it checks if the robot new position is inside an obstacle
 //flg = shs_distance_obstacle(xmv,ymv,new_xmv,new_ymv,.5);
 //printf("check inside %d x:%.3f, y:%.3f,  rad:%.3f\n",flg,new_xmv,new_ymv,new_thetamv);

 //if(flg==0){
  coord_robot->xc=new_xmv;
  coord_robot->yc=new_ymv;
  coord_robot->anglec=new_thetamv;
 //}
 //else{
        //printf("The robot remains with the previous position\n");
 //}

 //printf("mv x:%f, y:%f,  rad:%f\n",coord_robot->xc,coord_robot->yc,coord_robot->anglec);
}



float distance(coord vector,coord vector1){
//distance between coordinates
 float x,x1,y,y1;
 float distance;

 x=vector.xc;
 x1=vector1.xc;
 y=vector.yc;
 y1=vector1.yc;

 // it calculates the distance
 distance=(float)sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
 //printf("Distance: %f\n",distance);

 return(distance);
}

// it generates a robot's output
AdvanceAngle generate_output(int out,float advance, float angle){

  AdvanceAngle output;

  switch(out){

        case 0: // Stop
                output.distance=0.0f;
                output.angle=0.0f;
                output.step=1;
                //printf("STOP\n");
                break;

        case 1: // Forward
                output.distance=advance;
                output.angle=0.0f;
                output.step=0;
                //printf("FORWARD\n");
                break;

        case 2: // backward
                output.distance=-advance;
                output.angle=0.0f;
                output.step=1;
                //printf("BACKWARD\n");
                break;

        case 3:// Turn left
                output.distance=0.0f;
                output.angle=angle;
                output.step=1;
                //printf("LEFT\n");
                break;

        case 4: // Turn right
                output.distance=0.0f;
                output.angle=-angle;
                output.step=1;
                //printf("RIGHT\n");
                break;
        case 5: 
                output.distance=advance+.05;
                output.angle=0;
                output.step=1;
                //printf("RIGHT\n");
                break;

        default:printf("Output %d not defined used ", out);
                output.distance=0.0f;
                output.angle=0.0f;
                output.step=1;
                break;
  }

  return(output);

}


/*
        _--"-.
      .-"      "-.
     |""--..      '-.
     |      ""--..   '-.
     |.-. .-".    ""--..".
     |'./  -_'  .-.      |
     |      .-. '.-'   .-'
     '--..  '.'    .-  -.
          ""--..   '_'   :
                ""--..   |
                      ""-' 
*/

int get_atraction(float e,float d,coord* coord_robot,coord* coord_dest,coord* fuerza_atraccion){
 float  modulo;
  modulo=sqrt( pow(coord_robot->xc-coord_dest->xc,2) + pow(coord_robot->yc- coord_dest->yc,2));
  
  //if(coord_dest->xc<coord_robot->xc)
    //fuerza_atraccion->xc=e*( coord_dest->xc-coord_robot->xc );
  //else
  fuerza_atraccion->xc=e*( coord_dest->xc - coord_robot->xc );
  
  fuerza_atraccion->yc=e*(  coord_dest->yc  -  coord_robot->yc);

  d=sqrt(  pow(coord_robot->xc-coord_dest->xc,2) + pow(coord_robot->yc-coord_dest->yc,2)   );

  if( modulo >d)
  { 
    fuerza_atraccion->xc=fuerza_atraccion->xc/modulo;
    fuerza_atraccion->yc=fuerza_atraccion->yc/modulo;
  }

  printf("\nAtraccion (%f,%f) \n",fuerza_atraccion->xc,fuerza_atraccion->yc );
  
  return 0;
}


int get_repultion(Raw observations,float n,float d0,coord* coord_robot,coord* coord_dest,coord* fuerza_repulsion){
 float  modulo;
 int num_obs=2,i;
 float angle_obst=.3,sensor,range=.3;//.06;
 float obstacle_x,obstacle_y;
  fuerza_repulsion->xc=0;
  fuerza_repulsion->yc=0;

 
int conta=4,algo=0;




for( i=0;i<num_obs;i++)
{

if(i<4)angle_obst=conta--*-.3926; else (angle_obst=conta++ *.3926);
//if(i==0)angle_obst=-.2; else  angle_obst=.2;



if(observations.sensors[i]>=range){

  

}else {
  sensor=observations.sensors[i];  
  algo++;
  obstacle_x=coord_robot->xc+sensor*cos(coord_robot->anglec+angle_obst);
  obstacle_y=coord_robot->yc+sensor*sin(coord_robot->anglec+angle_obst);

    printf("\nobstacle [%d] (%f,%f)\n",i,obstacle_x,obstacle_y);
modulo=sqrt( pow(coord_robot->xc-obstacle_x,2) + pow(coord_robot->yc- obstacle_y,2));
//printf("\nmodulo %f d %f \n",modulo,sensor);

//printf("entreeeeeEEEEEEEEEE");
    
    fuerza_repulsion->xc+=-n*(1/modulo-1/range)*( (  obstacle_x-coord_robot->xc  )/pow(modulo,1) );

    fuerza_repulsion->yc+=-n*(1/modulo-1/range)*( (  obstacle_y-coord_robot->yc )/pow(modulo,1) );

}



}
printf("algo %d",algo);

if (algo==0){

  fuerza_repulsion->xc=0;
  fuerza_repulsion->yc=0;
  //printf("SSSSSSSSSSSS");
}

  printf("\nRepulcion (%f,%f)   \n",fuerza_repulsion->xc,fuerza_repulsion->yc );


//return 0;
  printf("distancia al nodo %f \n",fabsf(coord_robot->xc-coord_dest->xc));
  if(fabsf(coord_robot->xc-coord_dest->xc)<=.06 &&  fabsf(coord_robot->yc-coord_dest->yc)<=.06 )  
 {
   fuerza_repulsion->xc =0;
   fuerza_repulsion->yc =0;
   return 0;
 }

 

if(fuerza_repulsion->xc || fuerza_repulsion->yc)
  return 1;
else  
  return 0;
}


coord get_next_position(float  delta,coord* coord_dest,coord* coord_robot,coord* fuerza_atraccion,coord* fuerza_repulsion )
{

  coord aux,res;
  float modulo;
//printf("\nRepulcion2 (%f,%f)   \n",fuerza_repulsion->xc,fuerza_repulsion->yc );
 printf("Destino x %f Destino y %f\n",coord_dest->xc,coord_dest->yc );

 aux.xc=fuerza_atraccion->xc+fuerza_repulsion->xc;
 aux.yc=fuerza_atraccion->yc+fuerza_repulsion->yc;

 modulo=sqrt( pow(aux.xc,2) + pow(aux.yc,2));

 aux.xc=aux.xc/modulo;
 aux.yc=aux.yc/modulo;



 res.xc=coord_robot->xc-delta*aux.xc;
 res.yc=coord_robot->yc-delta*aux.yc;

//printf("Resultado x:%f  y%f |n",res.xc,res.yc);


 res.anglec=atan( (res.yc- coord_robot->yc ) / (res.xc- coord_robot->xc+.00000000001)  );



  if( res.xc<coord_robot->xc  )
   { 
     res.anglec+=3.1415;
     //printf("\n Angulo que deves girar : %f\n  ",res.anglec);
   }

  if(res.xc<coord_robot->xc && res.yc<coord_robot->yc)
  {
    res.anglec=res.anglec-coord_robot->anglec-3.1415;
  }else
  {

    res.anglec=res.anglec-coord_robot->anglec+3.1415;
  }

  return res;
}




int quantize_inputs_surround(Raw observations, int size){

 int value=0;
 int i;
 float left,right,middle;
 int interval;

printf("\n++0++ %f ++++\n",observations.sensors[0]); //derecho
printf("\n++1++ %f ++++\n",observations.sensors[1]); //centro
printf("\n++2++ %f ++++\n",observations.sensors[2]); //izq

if( observations.sensors[0] < .06 )right=1;else right=0;
if( observations.sensors[1] < .06 )middle=1;else middle=0;
if( observations.sensors[2] < .06 )left=1;else left=0;


if( (!left )  && (!middle) && (!right)   ) value=0;
 if( (!left )  && (!middle) && (right)    ) value=1;
 if( (left )  && (!middle) && (!right)    ) value=2;
 if( (!left )  && (middle) && (!right)    ) value=3;
 if( (!left )  && (middle) && (right)    ) value=4;
 if( (left )  && (middle) && (!right)    ) value=5;
 if( (left )  && (!middle) && (right)    ) value=6;
 if( (left )  && (middle) && (right)    ) value=7;


 printf("value %d\n",value); 

 return(value);

}


int comparar(char *uno,char *dos)
{
  //printf("%s=%s\n",uno,dos );
  if(strcmp(uno,dos)==0)
    {
         for(int i=0;i<strlen(uno);i++)
          if(uno[i]!=dos[i])
            return 0;
    }else{return 0;}
  return 1;
}


struc_linea descomponer_en_palabras(char *linea)
{
  char *trozo = NULL;
  int filas=300;
  int i=0;
  char separador[] = " ";
  struc_linea regresa;

  //printf("%s\n",linea );/*trozo = strtok( linea,separador);while( trozo != NULL ){  filas++;//printf("%s-\n",trozo );trozo = strtok(NULL, separador);}*/
    
  regresa.palabra =(char **) malloc ( filas * sizeof(char *) ); 
  trozo = strtok( linea,separador);
  while( trozo != NULL ) 
    {
      regresa.palabra[i++] =(char *) malloc ( (strlen(trozo)+3) * sizeof(char)  );  
      strcpy(regresa.palabra[i-1],trozo);
      //printf("Trozo %s    el mero  %s  ii:%d\n",trozo,palabra[i-1],i );
      trozo = strtok(NULL, separador);
    }
  return regresa;
}

/******************************************/



/******************************************/


 int num_nodos(){
    FILE *archivo;
  char linea[1000];
  struc_linea palabra;
    char separador[] = " ";
    char cadena_nodo[]="node";
    char cadena_connection[]="connection";
    char *trozo = NULL;
    int num_nodos;
    struct nodo ** nodo;
  int cta=1;
  int i=0;
  
  archivo = fopen(entorno,"r");
/* PARA ABRIR EL ARCHIVO */
  if (archivo == NULL)return(0);

/* PARA ENCONTRAR EL NUMERO DE NODOS */
  while (feof(archivo) == 0)
  {
    fgets(linea,1000,archivo);
    palabra=descomponer_en_palabras(linea);
    if( !strcmp(palabra.palabra[1],"num") )num_nodos=atoi(palabra.palabra[3]);
      break;
  }
  rewind(archivo);
  printf("Numero de  nodos %d\n",num_nodos );

  fclose(archivo);
  return num_nodos;
 }


/*+++++++++

______________________________________       
___  __ \__  ____/__  __ \__  __/__  /_      
__  / / /_  __/  __  /_/ /_  /  __  __ \     
_  /_/ /_  /___  _  ____/_  /   _  / / /     
/_____/ /_____/  /_/     /_/    /_/ /_/    
              ____________________________  __
              ___  __ \__    |__  __/__  / / /
              __  /_/ /_  /| |_  /  __  /_/ / 
              _  ____/_  ___ |  /   _  __  /  
              /_/     /_/  |_/_/    /_/ /_/  
                      _______________________________________
                      ___  ____/___  _/__  __ \_  ___/__  __/
                      __  /_    __  / __  /_/ /____ \__  /   
                      _  __/   __/ /  _  _, _/____/ /_  /    
                      /_/      /___/  /_/ |_| /____/ /_/  

++++++++++++++*/



 int  dfs(step * navegacion,coord* coord_dest,coord* coord_robot){

  FILE *archivo;
  char linea[1000];
  struc_linea palabra;
    char separador[] = " ";
    char cadena_nodo[]="node";
    char cadena_connection[]="connection";
    char *trozo = NULL;
    int num_nodos;
    struct nodo ** nodo=NULL;
  int cta=1;
  int i=0;
  
  archivo = fopen(entorno,"r");
/* PARA ABRIR EL ARCHIVO */
  if (archivo == NULL)return(0);

/* PARA ENCONTRAR EL NUMERO DE NODOS */
  while (feof(archivo) == 0)
  {
    fgets(linea,1000,archivo);
    palabra=descomponer_en_palabras(linea);
    if( !strcmp(palabra.palabra[1],"num") )num_nodos=atoi(palabra.palabra[3]);
      break;
  }
  rewind(archivo);
  printf("Numero de  nodos %d\n",num_nodos );
  nodo =(struct nodo **) malloc( num_nodos * sizeof( struct nodo *) ); /* RESERVAR MEMORIA PARA EL NUMERO DE NODOS */
 
/* PARA CREAR LOS NODOS */
  while (feof(archivo) == 0)
  {
    fgets(linea,1000,archivo);
    palabra=descomponer_en_palabras(linea);
    if( comparar(palabra.palabra[1],cadena_nodo) && atoi(palabra.palabra[2])==i )
    {
      printf("--%s\n",palabra.palabra[3] );
      nodo[i] =(struct nodo *) malloc ( sizeof(struct nodo)  );
      nodo[i]->n=i; 
      nodo[i]->n_conection=0;
      nodo[i]->visitado=0;
      nodo[i]->cta=0;  
        nodo[i]->x=atof(palabra.palabra[3]);
        nodo[i]->y=atof(palabra.palabra[4]);

        i++;
      }

      if( comparar(palabra.palabra[1],cadena_connection) )
    {
      nodo[atoi(palabra.palabra[2])]->n_conection++; 
      }

       printf("Numero de  nodoss %d\n",num_nodos );
  }

  rewind(archivo);


  for(int i=0;i<num_nodos;i++)
    {
      nodo[i]->conection=(struct coneccion **) malloc ( nodo[i]->n_conection* sizeof(struct coneccion *)  );
      printf("Nodo %d conecciones %d \n",i,nodo[i]->n_conection );
    }
        

/* PARA RELACIONAR LOS NODOS */
  while (feof(archivo) == 0)
    {
      fgets(linea,1000,archivo);
      palabra=descomponer_en_palabras(linea);
      if( comparar(palabra.palabra[1],cadena_connection)  )
      {
        nodo[atoi(palabra.palabra[2])]->conection[ nodo[atoi(palabra.palabra[2])]->cta ] =(struct coneccion *)malloc( sizeof(struct coneccion )  );
        nodo[atoi(palabra.palabra[2])]->conection[ nodo[atoi(palabra.palabra[2])]->cta ]->nodo=nodo[atoi(palabra.palabra[3])]; 
        nodo[atoi(palabra.palabra[2])]->conection[ nodo[atoi(palabra.palabra[2])]->cta ] ->peso=atof(palabra.palabra[4]);
        nodo[atoi(palabra.palabra[2])]->cta++;
        }

  
    }
    rewind(archivo);

   fclose(archivo);

 printf("%f\n",nodo[5]->conection[3]->peso );



for(int i=0;i<num_nodos;i++)
{
  printf("Nodo: %d \n",nodo[i]->n);
  for(int j;j<nodo[i]->n_conection;j++)
  {
    printf("\tConeccion: %d \n",nodo[i]->conection[j]->nodo->n);
  }
}





int inicial=DPF_INICIO,final=DPF_FIN,actual=-1;
int recorrido[num_nodos];
for(int i;i<num_nodos;i++)recorrido[i]=-1;
int camino=0;
int completo;


/*DETERMINAR EL NODO MAS CERCANO al inicio*/
float finalito=99999;
for(i=0;i<num_nodos;i++)
 {
  printf("Nodo %d, distancia: %f \n",i,sqrt( pow(nodo[i]->x-coord_robot->xc,2)+pow(nodo[i]->y-coord_robot->yc,2) ) );
  if(finalito>(sqrt( pow(nodo[i]->x-coord_robot->xc,2)+pow(nodo[i]->y-coord_robot->yc,2) )))
   { inicial=nodo[i]->n;
    finalito=sqrt( pow(nodo[i]->x-coord_robot->xc,2)+pow(nodo[i]->y-coord_robot->yc,2));
  }
}

/*DETERMINAR EL NODO MAS CERCANO al final*/
finalito=99999;
for(i=0;i<num_nodos;i++)
 {
  printf("Nodo %d, distancia: %f \n",i,sqrt( pow(nodo[i]->x-coord_dest->xc,2)+pow(nodo[i]->y-coord_dest->yc,2) ) );
  if(finalito>(sqrt( pow(nodo[i]->x-coord_dest->xc,2)+pow(nodo[i]->y-coord_dest->yc,2) )))
   { 
    final=nodo[i]->n;
    finalito=sqrt( pow(nodo[i]->x-coord_dest->xc,2)+pow(nodo[i]->y-coord_dest->yc,2));
  }
}




actual=inicial;



while(actual!=final)
{
  printf("Actual: %d\n",actual);
  nodo[actual]->visitado=1;
  recorrido[camino]=actual;
  camino++;
  completo=1;
  for(int i=0;i<nodo[actual]->n_conection;i++)
  {
    
    printf("\trevisado: %d\n",nodo[actual]->conection[i]->nodo->n);
    if(nodo[actual]->conection[i]->nodo->visitado==0)
    {
      actual=nodo[actual]->conection[i]->nodo->n;
      completo=0;
      break;
    }
    //nodo[actual]->visitado=2;
  }

  if(completo>0)
  {
    printf("\t\tCompleto: %d\n",actual);
    camino--;
    recorrido[camino]=-1;
    camino--;
    actual=recorrido[camino];
  }
}



int pasos=0,pasos_aux;

//step **navegacion;

//navegacion=(step **)malloc(num_nodos+2*sizeof(step * ));

for(int i=0;i<num_nodos;i++)
{
  if(recorrido[i]!=-1)
  {
    printf("%d -> ",recorrido[i]);
  //  navegacion[pasos]=(step *)malloc( sizeof(step  ));
    navegacion[pasos].n=nodo[recorrido[i]]->n;
    navegacion[pasos].x=nodo[recorrido[i]]->x;
    navegacion[pasos].y=nodo[recorrido[i]]->y;
    printf("-----%d :  x: %f  y: %f \n  ",navegacion[i].n,nodo[recorrido[i]]->x,navegacion[i].y);
  
    pasos++;
    pasos_aux=pasos;
  }else
  {
  //  navegacion[pasos]=(step *)malloc( sizeof(step  ));
    
     
    navegacion[pasos].n=-1;
    navegacion[pasos].x=-1;
    navegacion[pasos].y=-1;
    pasos++;
  }
}
    //navegacion[pasos]=(step *)malloc( sizeof(step  ));
    navegacion[pasos_aux].n=final;
    navegacion[pasos_aux].x=nodo[final]->x;
    navegacion[pasos_aux].y=nodo[final]->y;

  
    navegacion[pasos_aux+1].n=1000;
    navegacion[pasos_aux+1].x=coord_dest->xc;
    navegacion[pasos_aux+1].y=coord_dest->yc;
    



   // pasos++;
if(nodo!=NULL)free(nodo);
if(trozo!=NULL)free(trozo);
return 0;
} 




/*
          _____                    _____                    _____                    _____                _____                    _____                    _____          
         /\    \                  /\    \                  /\    \                  /\    \              /\    \                  /\    \                  /\    \         
        /::\    \                /::\    \                /::\____\                /::\    \            /::\    \                /::\    \                /::\    \        
       /::::\    \               \:::\    \              /:::/    /               /::::\    \           \:::\    \              /::::\    \              /::::\    \       
      /::::::\    \               \:::\    \            /:::/    /               /::::::\    \           \:::\    \            /::::::\    \            /::::::\    \      
     /:::/\:::\    \               \:::\    \          /:::/    /               /:::/\:::\    \           \:::\    \          /:::/\:::\    \          /:::/\:::\    \     
    /:::/  \:::\    \               \:::\    \        /:::/____/               /:::/__\:::\    \           \:::\    \        /:::/__\:::\    \        /:::/__\:::\    \    
   /:::/    \:::\    \              /::::\    \      /::::\    \               \:::\   \:::\    \          /::::\    \      /::::\   \:::\    \      /::::\   \:::\    \   
  /:::/    / \:::\    \    _____   /::::::\    \    /::::::\____\________    ___\:::\   \:::\    \        /::::::\    \    /::::::\   \:::\    \    /::::::\   \:::\    \  
 /:::/    /   \:::\ ___\  /\    \ /:::/\:::\    \  /:::/\:::::::::::\    \  /\   \:::\   \:::\    \      /:::/\:::\    \  /:::/\:::\   \:::\____\  /:::/\:::\   \:::\    \ 
/:::/____/     \:::|    |/::\    /:::/  \:::\____\/:::/  |:::::::::::\____\/::\   \:::\   \:::\____\    /:::/  \:::\____\/:::/  \:::\   \:::|    |/:::/  \:::\   \:::\____\
\:::\    \     /:::|____|\:::\  /:::/    \::/    /\::/   |::|~~~|~~~~~     \:::\   \:::\   \::/    /   /:::/    \::/    /\::/   |::::\  /:::|____|\::/    \:::\  /:::/    /
 \:::\    \   /:::/    /  \:::\/:::/    / \/____/  \/____|::|   |           \:::\   \:::\   \/____/   /:::/    / \/____/  \/____|:::::\/:::/    /  \/____/ \:::\/:::/    / 
  \:::\    \ /:::/    /    \::::::/    /                 |::|   |            \:::\   \:::\    \      /:::/    /                 |:::::::::/    /            \::::::/    /  
   \:::\    /:::/    /      \::::/    /                  |::|   |             \:::\   \:::\____\    /:::/    /                  |::|\::::/    /              \::::/    /   
    \:::\  /:::/    /        \::/    /                   |::|   |              \:::\  /:::/    /    \::/    /                   |::| \::/____/               /:::/    /    
     \:::\/:::/    /          \/____/                    |::|   |               \:::\/:::/    /      \/____/                    |::|  ~|                    /:::/    /     
      \::::::/    /                                      |::|   |                \::::::/    /                                  |::|   |                   /:::/    /      
       \::::/    /                                       \::|   |                 \::::/    /                                   \::|   |                  /:::/    /       
        \::/____/                                         \:|   |                  \::/    /                                     \:|   |                  \::/    /        
         ~~                                                \|___|                   \/____/                                       \|___|                                 
*/


int djkstra(step *navegacion,coord* coord_dest,coord* coord_robot){

 FILE *archivo;
  char linea[1000];
  struc_linea palabra;
    char separador[] = " ";
    char cadena_nodo[]="node";
    char cadena_connection[]="connection";
    char *trozo = NULL;
    int num_nodos;
    struct nodo ** nodo=NULL;
  int cta=1;
  int i=0;

  int *camino=NULL;
  
  archivo = fopen(entorno,"r");
/* PARA ABRIR EL ARCHIVO */
  if (archivo == NULL)return(0);

/* PARA ENCONTRAR EL NUMERO DE NODOS */
  while (feof(archivo) == 0)
  {
    fgets(linea,1000,archivo);
    palabra=descomponer_en_palabras(linea);
    if( !strcmp(palabra.palabra[1],"num") )num_nodos=atoi(palabra.palabra[3]);
      break;
  }
  rewind(archivo);
  printf("Numero de  nodos %d\n",num_nodos );
  nodo =(struct nodo **) malloc( num_nodos * sizeof( struct nodo *) ); /* RESERVAR MEMORIA PARA EL NUMERO DE NODOS */
 
/* PARA CREAR LOS NODOS */
  while (feof(archivo) == 0)
  {
    fgets(linea,1000,archivo);
    palabra=descomponer_en_palabras(linea);
    if( comparar(palabra.palabra[1],cadena_nodo) && atoi(palabra.palabra[2])==i )
    {
      printf("--%s\n",palabra.palabra[3] );
      nodo[i] =(struct nodo *) malloc ( sizeof(struct nodo)  );
      nodo[i]->n=i; 
      nodo[i]->n_conection=0;
      nodo[i]->visitado=0;
      nodo[i]->cta=0;  
        nodo[i]->x=atof(palabra.palabra[3]);
        nodo[i]->y=atof(palabra.palabra[4]);
        nodo[i]->visitado=-1;
      nodo[i]->acumulado=-1;
      nodo[i]->anterior=-1;
      nodo[i]->iteracion=-1;

        i++;
      }

      if( comparar(palabra.palabra[1],cadena_connection) )
    {
      nodo[atoi(palabra.palabra[2])]->n_conection++; 
      }

       printf("Numero de  nodoss %d\n",num_nodos );
  }

  rewind(archivo);


  for( i=0;i<num_nodos;i++)
    {
      nodo[i]->conection=(struct coneccion **) malloc ( nodo[i]->n_conection* sizeof(struct coneccion *)  );
      printf("Nodo %d conecciones %d \n",i,nodo[i]->n_conection );
    }
        

/* PARA RELACIONAR LOS NODOS */
  while (feof(archivo) == 0)
    {
      fgets(linea,1000,archivo);
      palabra=descomponer_en_palabras(linea);
      if( comparar(palabra.palabra[1],cadena_connection)  )
      {
        nodo[atoi(palabra.palabra[2])]->conection[ nodo[atoi(palabra.palabra[2])]->cta ] =(struct coneccion *)malloc( sizeof(struct coneccion )  );
        nodo[atoi(palabra.palabra[2])]->conection[ nodo[atoi(palabra.palabra[2])]->cta ]->nodo=nodo[atoi(palabra.palabra[3])]; 
        nodo[atoi(palabra.palabra[2])]->conection[ nodo[atoi(palabra.palabra[2])]->cta ] ->peso=atof(palabra.palabra[4]);
        nodo[atoi(palabra.palabra[2])]->cta++;
        }

  
    }
    rewind(archivo);

   fclose(archivo);

 //printf("%f\n",nodo[5]->conection[3]->peso );



for( i=0;i<num_nodos;i++)
{
  printf("Nodo: %d \n",nodo[i]->n);
  for(int j;j<nodo[i]->n_conection;j++)
  {
    printf("\tConeccion: %d \n",nodo[i]->conection[j]->nodo->n);
  }
}





int inicial=DJKSTRA_FIN,final=DJKSTRA_INICIO;
int recorrido[num_nodos];
for(int i;i<num_nodos;i++){recorrido[i]=-1; nodo[i]->visitado=-1;}
int actual=0;
int completo;

int iteracion;
float acumulado;
float menor_acumulado=0;
int bandera_primero_a_comparar=0;
int nodo_siguiente=0;
int bandera_ninguno=0;
int once=1;

int aa=0;


/*DETERMINAR EL NODO MAS CERCANO al inicio*/
float finalito=99999;
for(i=0;i<num_nodos;i++)
 {
  printf("Nodo %d, distancia: %f \n",i,sqrt( pow(nodo[i]->x-coord_robot->xc,2)+pow(nodo[i]->y-coord_robot->yc,2) ) );
  if(finalito>(sqrt( pow(nodo[i]->x-coord_robot->xc,2)+pow(nodo[i]->y-coord_robot->yc,2) )))
   { final=nodo[i]->n;
    finalito=sqrt( pow(nodo[i]->x-coord_robot->xc,2)+pow(nodo[i]->y-coord_robot->yc,2));
  }
}

/*DETERMINAR EL NODO MAS CERCANO al final*/
finalito=99999;
for(i=0;i<num_nodos;i++)
 {
  printf("Nodo %d, distancia: %f \n",i,sqrt( pow(nodo[i]->x-coord_dest->xc,2)+pow(nodo[i]->y-coord_dest->yc,2) ) );
  if(finalito>(sqrt( pow(nodo[i]->x-coord_dest->xc,2)+pow(nodo[i]->y-coord_dest->yc,2) )))
   { 
    inicial=nodo[i]->n;
    finalito=sqrt( pow(nodo[i]->x-coord_dest->xc,2)+pow(nodo[i]->y-coord_dest->yc,2));
  }
}


actual=inicial;
nodo[actual]->visitado=0;
nodo[actual]->acumulado=0;
nodo[actual]->anterior=-1;
nodo[actual]->iteracion=0;


while(nodo[final]->visitado==-1)
{ 
  
  bandera_primero_a_comparar=0;
  bandera_ninguno=0;
 
  /*Expandir los adyacentes*/

  for(i=0;i<nodo[actual]->n_conection;i++)
  {  bandera_ninguno++;
  //printf("Numero de conecciones --%d-- Nodo Actual: %d\n",nodo[actual]->n_conection,actual);
   // printf("Interaccion %d  Proviene de %d \n",nodo[actual]->conection[i]->nodo->n,nodo[actual]->n);

     if(nodo[actual]->conection[i]->nodo->visitado==1 || nodo[actual]->conection[i]->nodo->n==nodo[actual]->n)/*Si este nodo ya esta completo no hacemos algo*/
       continue;

    // printf(" 1  V: %d acumulado %f  anterior %d  iteracion %d\n",nodo[actual]->conection[i]->nodo->visitado,nodo[actual]->conection[i]->nodo->acumulado,nodo[actual]->conection[i]->nodo->anterior,nodo[actual]->conection[i]->nodo->iteracion );
    
     if( nodo[actual]->conection[i]->nodo->acumulado>-1)
     {
      acumulado=nodo[actual]->acumulado + nodo[actual]->conection[i]->peso;
      if(acumulado< nodo[actual]->conection[i]->nodo->acumulado)/* Aqui decidimos  en caso de un empate quedarnos con el  que ya se tenia*/
      {
        /*___Variable acumulada del nodo vecino_____  __Valor acumulado del nodo actual + la distancia que los separa____*/
      nodo[actual]->conection[i]->nodo->acumulado=nodo[actual]->acumulado + nodo[actual]->conection[i]->peso;
      /*___________Agregamos  el nodo padre______________*/
      nodo[actual]->conection[i]->nodo->anterior=actual;
      /*______________*/
      nodo[actual]->conection[i]->nodo->iteracion=iteracion;
      }

     }else /*Lo que esta eb el else es el mismo codigo que arriba U_U deberiamos reducir el codigo*/
     {
        /*___Variable acumulada del nodo vecino_____  __Valor acumulado del nodo actual + la distancia que los separa____*/
      nodo[actual]->conection[i]->nodo->acumulado=nodo[actual]->acumulado + nodo[actual]->conection[i]->peso;
        /*___________Agregamos  el nodo padre______________*/
      nodo[actual]->conection[i]->nodo->anterior=actual;
        /*______________*/
      nodo[actual]->conection[i]->nodo->iteracion=iteracion;
     }

     //printf("  2  V: %d acumulado %f  anterior %d  iteracion %d\n",nodo[actual]->conection[i]->nodo->visitado,nodo[actual]->conection[i]->nodo->acumulado,nodo[actual]->conection[i]->nodo->anterior,nodo[actual]->conection[i]->nodo->iteracion );
    
  }


  for(i=0;i<num_nodos;i++)
  {
     /*BUSCAMOS EL DE MENOR PESO (SI HAY UN EMPATE SE TOMA EL PRIMERO QUE SE ENCUENTRE)*/ 
    // printf("Nodo iterado %d, nodo acumulado %f\n",nodo[i]->n,nodo[i]->acumulado);


    if(nodo[i]->visitado==1 || nodo[i]->anterior==-1 )
      continue;

       if(bandera_primero_a_comparar==0)
         {
          menor_acumulado=nodo[i]->acumulado;
          nodo_siguiente=nodo[i]->n;
          bandera_primero_a_comparar=1;
         }

    //  printf("\tMenor acumulado %f + actual actumulado %f\n",menor_acumulado,nodo[i]->acumulado );
      if(menor_acumulado>nodo[i]->acumulado)
       {
        menor_acumulado=nodo[i]->acumulado;
        nodo_siguiente=nodo[i]->n;
       }
    //   printf("Nodo con el menor %d \n", nodo_siguiente);
    
  }


   printf("\t\t\t\t\t         ****SIGUIENTE %d **\n",nodo_siguiente);
   nodo[actual]->visitado=1;
   actual=nodo_siguiente;
   iteracion++;


 
}




actual=final;
aa++;
while(nodo[actual]->anterior!=-1)
{
//  printf(" %d ->",nodo[actual]->anterior);
  actual=nodo[actual]->anterior;
  aa++;
}




camino=(int *)malloc(aa*(sizeof(int ) ) );


//camino[0]=(int *)malloc((sizeof(int )));
camino[0]=final;

actual=final;
aa=1;
while(nodo[actual]->anterior!=-1)
{
  //printf(" %d ->",nodo[actual]->anterior);
  actual=nodo[actual]->anterior;
 // camino[aa]=(int *)malloc((sizeof(int )));
  camino[aa]=actual;
  aa++;

}

  for(i=0;i<aa;i++)

   // printf(" -> %d ",camino[i]);
  

for( i=0;i<num_nodos;i++)
{
  if(i<aa)
  {
  // printf("%d -> ",camino[i]);
  //  navegacion[pasos]=(step *)malloc( sizeof(step  ));
    navegacion[i].n=nodo[camino[i]]->n;
    navegacion[i].x=nodo[camino[i]]->x;
    navegacion[i].y=nodo[camino[i]]->y;
  //printf("%d :  x: %f  y: %f \n  ",nodo[camino[i]]->n,nodo[camino[i]]->x,nodo[camino[i]]->y);
  
    
  }else
  {
    if(once)
    {
    navegacion[i].n=1000;
    navegacion[i].x=coord_dest->xc;
    navegacion[i].y=coord_dest->yc;
    //printf("aquie stoysssssssssss %d   x: %f",navegacion[i].n,navegacion[i].x);
    once=0;
    }
    else{
    navegacion[i].n=-1;
    navegacion[i].x=-1;
    navegacion[i].y=-1;
    }
  }
}

 if(nodo!=NULL)free(nodo);
 if(camino!=NULL)free(camino);
 if(trozo!=NULL)free(trozo);
 
return 0;
} 


