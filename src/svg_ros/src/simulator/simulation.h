/*****************************************************************************
*                                                                            *
*  simulation.h                                                   	     *
*  ============                                                              *
*                                                                            *
*									     *
*                               J. Savage                                    *
*                               	                                     *
*                               FI-UNAM 2015                                 *
*****************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ros/ros.h"
#define LARGEST_DISTANCE_SENSORS 5.0 // 5.0 meters
#define MAX_NUM_SENSORS 1024
#define MAX_NUM_RAW_SONAR 100
#define MAX_NUM_RAW_INFRARED 100
#define MAX_NUM_POLYGONS 100
#define NUM_MAX_VERTEX 10
#define STRSIZ 300
#define SIZE_LINE 10000
#define NUM_LASERS 682
#define INIT_ANGLE_LASER   (float) (((15.8f*PI*2)/360) - 2.3562f) // see Hokuyo laser manual for this
#define COVER_ANGLE  ((360.0f/1024.0f)*681.0f)




// *****************************************************************************
// * Structures.                                                               *
// *****************************************************************************

typedef struct _environment{
        int flag;
        char environment[100];
} Environment;


typedef struct _raw{
        int flag;
         int region;
         float x,y,theta,sensors[MAX_NUM_SENSORS];
} Raw;

typedef struct Vertex_ {
        float x;
        float y;
} Vertex;

typedef struct Line_ {
        float m;
        float b;
} Line;

typedef struct Polygon_ {
        char    name[STRSIZ];
        char    type[STRSIZ];
        int     num_vertex;
        Vertex  vertex[NUM_MAX_VERTEX];
        Line    line[NUM_MAX_VERTEX];
} Polygon;



// Global variables
Polygon polygons_wrl[MAX_NUM_POLYGONS],robot_sensor;
int num_polygons_wrl;




// it finds the elements of each of the polygon's lines
 // y=m*x-b
 // m=(y2-y1)/(x2-x1); b=(x2y1-y2x1)/(x2-x1)
void find_components_lines(int num_polygons,Polygon *polygons){
	int i,j;
	float m,b;
	float x1,y1,x2,y2;

	for(i=1;i<num_polygons;i++){

		for(j=1; j< polygons[i].num_vertex;j++){
			x1=polygons[i].vertex[j].x;
			x2=polygons[i].vertex[j+1].x+.00001f;
			y1=polygons[i].vertex[j].y;
			y2=polygons[i].vertex[j+1].y+.00001f;
			m=(y2-y1)/(x2-x1);
			b=(x2*y1-y2*x1)/(x2-x1);
			polygons[i].line[j].m=m;
			polygons[i].line[j].b=b;
		}
		// line of last and first vertex
		x1=polygons[i].vertex[j].x;
                x2=polygons[i].vertex[1].x+.00001f;
                y1=polygons[i].vertex[j].y;
                y2=polygons[i].vertex[1].y+.00001f;
                m=(y2-y1)/(x2-x1);
                b=(x2*y1-y2*x1)/(x2-x1);
                polygons[i].line[j].m=m;
                polygons[i].line[j].b=b;
		//printf("pol. %d line %d m %f b %f \n",i,j,polygons[i].line[j].m, polygons[i].line[j].b);

	}

}


// it finds if the intersection points, xinter and yinter, are between a line
int interval(float xinter,float yinter,Polygon polygon,int j){
	
	float x1,x2,y1,y2;

	if(polygon.vertex[j].x < polygon.vertex[j+1].x){
		x1=polygon.vertex[j].x;
		x2=polygon.vertex[j+1].x;
	}
	else{
		x2=polygon.vertex[j].x;
                x1=polygon.vertex[j+1].x;
	}
	if(polygon.vertex[j].y < polygon.vertex[j+1].y){
		y1=polygon.vertex[j].y;
		y2=polygon.vertex[j+1].y;
	}
	else{
		y2=polygon.vertex[j].y;
                y1=polygon.vertex[j+1].y;
	}

	//printf("line interval %d x1 %f y1 %f\n",j,x1,y1);
	//printf("line interval %d x2 %f y2 %f\n",j,x2,y2);
	

 	if(x1 != x2)
	if( (xinter < x1) || (xinter > x2))
		return(0);
 	if(y1 != y2)
	if( (yinter < y1) || (yinter > y2))
                return(0);


	return(1);

}




// it finds if the intersection points are between the robot's line
int interval_robot(float xinter,float yinter,Polygon robot){
                                                                               
        float x1,x2,y1,y2;
                                                                               
        if(robot.vertex[1].x < robot.vertex[2].x){
                x1=robot.vertex[1].x;
                x2=robot.vertex[2].x;
        }
        else{
                x2=robot.vertex[1].x;
                x1=robot.vertex[2].x;
        }
        if(robot.vertex[1].y < robot.vertex[2].y){
                y1=robot.vertex[1].y;
                y2=robot.vertex[2].y;
        }
        else{
                y2=robot.vertex[1].y;
                y1=robot.vertex[2].y;
        }
        //printf("line robot x1 %f y1 %f\n",x1,y1);
        //printf("line robot x2 %f y2 %f\n",x2,y2);
        
                                                                       
        if(x1 != x2)
        if( (xinter < x1) || (xinter > x2))
                return(0);
        if(y1 != y2)
        if( (yinter < y1) || (yinter > y2))
                return(0);
                                                                               
                                                                               
        return(1);
                                                                               
}

// it finds the distance between the robot and the intersection line
float magnitud(Polygon robot,float xinter,float yinter){
	
	float distance;
	float x,y;

	x = robot.vertex[1].x-xinter;
        y = robot.vertex[1].y-yinter;
	distance=sqrtf(x*x+y*y);

	return distance;
}



// it reads the file that conteins the environment description
int ReadPolygons(char *file,Polygon *polygons){

 FILE *fp;
 char data[STRSIZ];
 int i,num_poly=1;
 float tmp;
 int flg=0;
 float dimensions_room_x,dimensions_room_y;


 fp=fopen(file,"r");

 
 if(fp == NULL){
                sprintf(data,"File %s does not exists\n",file);
                printf("File %s does not exists\n",file);
                exit(0);
 }

 //printf("World environment %s \n",file);

 while(fscanf(fp,"%s",data) != EOF){

    if(strcmp(";(",data) == 0){
	flg=1;
     	while(flg == 1){
          	fscanf(fp,"%s",data);
		sscanf(data,"%f",&tmp);
		if(strcmp(")",data) == 0) flg = 0;
	}
    }
    else if((strcmp("polygon",data) == 0) && (flg == 0) ){
          fscanf(fp,"%s",data);
          strcpy(polygons[num_poly].type,data);
          fscanf(fp,"%s",data);
          strcpy(polygons[num_poly].name,data);
          i=1;
	  flg=1;
     	  while(flg == 1){
		fscanf(fp,"%s",data);
		if(strcmp(")",data) == 0) {
                	polygons[num_poly].num_vertex=i-1;
			polygons[num_poly].vertex[i].x=polygons[num_poly].vertex[1].x; // to calculate intersecction range
                        polygons[num_poly].vertex[i].y=polygons[num_poly].vertex[1].y; // the first vertex its repeated on the last
                	num_poly++;
			flg = 0;
	        }
		else{
			sscanf(data,"%f",&tmp);
              		polygons[num_poly].vertex[i].x=tmp;
              		fscanf(fp,"%s",data);
              		sscanf(data,"%f",&tmp);
              		polygons[num_poly].vertex[i].y=tmp;
	 		//printf("polygon vertex %d x %f y %f\n",i,polygons[num_poly].vertex[i].x,polygons[num_poly].vertex[i].y);
              		i++;
        	}

	}
    }
    else if(strcmp("dimensions",data) == 0  && (flg == 0) ){
         fscanf(fp,"%s",data);
         fscanf(fp,"%s",data);
         sscanf(data,"%f",&dimensions_room_x);
         fscanf(fp,"%s",data);
         sscanf(data,"%f",&dimensions_room_y);
	 //printf("dimensions x %f y %f\n",dimensions_room_x,dimensions_room_y);
    }

 }

 fclose(fp);
 return num_poly;
}



// it finds the distance to the closest polygon
float distance_polygon(int num_polygons,Polygon *polygons,Polygon robot,
							int *index_smallest){

	int i,j;
        float m,b,mr,br;
	float smallest_distance=(float)(0x7fffffff); 
	float xinter,yinter,distance;

	mr=robot.line[1].m;
	br=robot.line[1].b;
	//printf("\n robot m %f b %f", mr,br);

	for(i=1;i<num_polygons;i++){
                        
	  //printf("polygon %s \n", polygons[i].name);
                                                        
          for(j=1; j<= polygons[i].num_vertex;j++){
	  		//printf("line obstacle %d \n", j);
                	m=polygons[i].line[j].m;
                	b=polygons[i].line[j].b;
			//printf("pol. %d line %d m %f b %f \n",i,j,polygons[i].line[j].m, polygons[i].line[j].b);
			//printf("line m %f b %f\n", m,b);
			//xinter= (float)(br-b)/(float)(m-mr);
			xinter= (float)(b-br)/(float)(mr-m);
			//yinter=m*xinter+b;
			yinter=mr*xinter+br;

			//printf("intersection %d xinter %f yinter %f\n", j,xinter,yinter);

			if(interval(xinter,yinter,polygons[i],j)==1)
				if(interval_robot(xinter,yinter,robot)==1){
				

					distance=magnitud(robot,xinter,yinter);
					//printf("correct interval %d dist %f smallest %f\n",j,distance,smallest_distance);
					if(distance<smallest_distance){
						smallest_distance=distance;
						*index_smallest=i;
						//printf("smallest %f\n",smallest_distance);
					}
					//printf("smallest 1 %f\n",smallest_distance);
				}
        		}
    }

    //printf("smallest distance %f index %i\n",smallest_distance,*index_smallest);
    return smallest_distance;
}





// it reads the environment
void read_environment(char *file,int debug)
{
 
 int i;                                                                            
 int j;



/* it reads the polygons */
 strcpy(polygons_wrl[0].name,"NULL");
 if(debug == 1) printf("\nEnvironment file: %s\n",file);
 num_polygons_wrl=ReadPolygons(file,polygons_wrl);
                                                                           
 // it finds the elements of each of the polygon's lines
 // y=mx-b
 // m=(y2-y1)/(x2-x1); b=(x2y1-y2x1)/(x2-x1)
 find_components_lines(num_polygons_wrl,polygons_wrl);
                                                                               
// it prints the polygons
 if(debug == 1)
 for(i=1;i < num_polygons_wrl;i++){
        //printf("\npolygon[%d].name=%s\n",i,polygons_wrl[i].name);
        //printf("polygon[%d].type=%s\n",i,polygons_wrl[i].type);
                                                                               
        for(j=1; j<= polygons_wrl[i].num_vertex;j++){
          printf("polygon[%d].vertex[%d] x=%f y=%f\n",
                i,j,polygons_wrl[i].vertex[j].x,polygons_wrl[i].vertex[j].y);
          printf("polygon[%d].line[%d] m=%f b=%f\n",
                i,j,polygons_wrl[i].line[j].m,polygons_wrl[i].line[j].b);
                                                                               
        }
  
 }


}



// it returns a laser reading 
float shs_sensor(float *pq){

 int index;
 float distance;
 float angle;

  // it gets the sensor's position
  index=0;
  robot_sensor.vertex[1].x=pq[0];
  robot_sensor.vertex[1].y=pq[1];
  angle=pq[2];

  //printf("sensor pos. x %f y %f angle %f\n",pq[0],pq[1],pq[2]);


  robot_sensor.vertex[2].x=
                        SIZE_LINE*cosf(angle)+robot_sensor.vertex[1].x;
  robot_sensor.vertex[2].y=
                        SIZE_LINE*sinf(angle)+robot_sensor.vertex[1].y;
  


  //m=(y2-y1)/(x2-x1);
  //b=(x2*y1-y2*x1)/(x2-x1);
  robot_sensor.line[1].m= (robot_sensor.vertex[2].y-robot_sensor.vertex[1].y)/
                        (robot_sensor.vertex[2].x-robot_sensor.vertex[1].x);
  robot_sensor.line[1].b= (robot_sensor.vertex[2].x*robot_sensor.vertex[1].y-
                         robot_sensor.vertex[2].y*robot_sensor.vertex[1].x)/
                        (robot_sensor.vertex[2].x-robot_sensor.vertex[1].x);
   

  // it finds the distance to the closest polygon      
  distance=distance_polygon(num_polygons_wrl,polygons_wrl,robot_sensor,&index);
                                                                               

 //if(distance > LARGEST_DISTANCE_SENSORS)
	////distance=LARGEST_DISTANCE_SENSORS;
                                                                       
 return distance;
 
}


// it selects the observations used
void select_obs(Raw observations, int num, Raw *sensor_vector, int num_sensors){
 int aux,pt,k;


 aux = (int) (num/num_sensors);
 for( k=1,pt=1; k<= num_sensors; k++,pt+=aux) {
          sensor_vector[0].sensors[k]=observations.sensors[pt];
          //printf("%d sensor(%d) = %f %f\n",k,pt,sensor_vector[0].sensors[k],observations.sensors[pt]);
 }

}


// it selects the angles of the sensors 
void select_angles(int num, float *Angles, float *angle_sensors, int num_sensors){
 int aux,pt,k;


 aux = (int) (num/num_sensors);
 for( k=1,pt=1; k<= num_sensors; k++,pt+=aux) {
          angle_sensors[k]=Angles[pt];
          //printf("%d angle sensor(%d) = %f \n",k,pt,angle_sensors[k]);
 }

}







// it generates simulated sensor values
void get_sensor_values(coord coord_robot,float start_angle,float range, Raw *sensor_vector, int num, float largest_value){

 int k;
 float distance;
 float pos[5];
 float angle;
 float inc_angle;
 float x, y, theta;


 x=coord_robot.xc;
 y=coord_robot.yc;
 theta=coord_robot.anglec;


 pos[0]=x;
 pos[1]=y;
 if(range == 1) inc_angle= range;
 else inc_angle = range /( num -1); 
 angle = start_angle;

 sensor_vector[0].x=x;
 sensor_vector[0].y=y;


 for( k=0; k< num; k++) {

 	  pos[2]=theta + k*inc_angle + start_angle;
	  //printf("k %d angle %f\n",k,pos[2]);
	  
          distance=shs_sensor(pos);
	  if(distance > largest_value) distance = largest_value;
          sensor_vector[0].sensors[k]=distance;
 	  sensor_vector[0].theta=pos[2];
          //printf("sensor(%d) = %f\n",k,sensor_vector[0].sensors[k]);
 }

}




