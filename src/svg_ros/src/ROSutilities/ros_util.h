

 // It quantizes the destination this later
int quantize_destination(coord coord_robot,coord coord_dest){

 int value=0;
 float angle;
 coord dif;
 float theta;

 theta=coord_robot.anglec;
 printf("pose x %f y %f theta %f dest x %f y %f\n",coord_robot.xc,coord_robot.yc,theta,coord_dest.xc,coord_dest.yc);

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