

// it gets line inputs 
int get_inputs(int argc, char **argv, Inputs *inputs)
{

 int i;

 // It sets default values 
 inputs->xo=3.925;
 inputs->yo=7.6;
 inputs->angle_robot=0.0;
 inputs->xd=7.80;
 inputs->yd=8.025;
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

  // reads input parameters 
  if (argc>1) {
        for(i=1;i<argc;i++){
          if (!strcmp(argv[i],"-h")){

  //               printf("Sintax: GoTo_State_Machine -x x_origen -y y_origen -a angle_robot -v x_destination -z y_destination -s sensor -n num_sensors -t theta_sensor -r range_sensor -p path_data -e environment -radio radio_robot -advance magnitud_advance -MaxAngle max_angle -steps number_steps -largest largest_value_sensors\n");
  //               printf("examples:\n");
  //               printf("./GoTo_State_Machine -x 1 -y 2.5 -a 3.1416 -v 2.0 -z 3.1 -s laser -n 4 -t -0.7075 -r 3.1416\n");
		// printf("./GoTo_State_Machine -x 0.28 -y 0.795 -a 0.0 -v 0.6525 -z 0.7875 -s laser -n 2 -t -0.2000 -r 0.4000 -radio 0.03 -advance 0.04 -MaxAngle 0.3 -steps 100 -largest 0.3\n");
                exit(1);
          }
	  else if (!strcmp(argv[i],"-a")){
                inputs->angle_robot=atof(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-e")){
                strcpy(inputs->environment,argv[i+1]);
          }
          else if (!strcmp(argv[i],"-n")){
                inputs->num_sensors=atoi(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-p")){
                strcpy(inputs->path,argv[i+1]);
          }
          else if (!strcmp(argv[i],"-advance")){
                inputs->Mag_Advance=atof(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-r")){
                inputs->range_sensor=atof(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-radio")){
                inputs->radio_robot=atof(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-s")){
                strcpy(inputs->sensor,argv[i+1]);
          }
          else if (!strcmp(argv[i],"-t")){
                inputs->theta_sensor=atof(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-v")){
                inputs->xd=atof(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-x")){
                inputs->xo=atof(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-y")){
                inputs->yo=atof(argv[i+1]);
          }
	  else if (!strcmp(argv[i],"-z")){
                inputs->yd=atof(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-MaxAngle")){
                inputs->max_angle=atof(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-steps")){
                inputs->number_steps=atoi(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-selection")){
                inputs->selection=atoi(argv[i+1]);
          }
          else if (!strcmp(argv[i],"-largest")){
                inputs->largest_value=atof(argv[i+1]);
          }

    }
  }
  else{

      //printf("\nIt will use default values:\n");
  }

  //printf("GoTo_State_Machine -x %f -y %f -a %f -v %f -z %f -s %s -n %d -t %f -r %f -p %s -e %s -advance %f -MaxAngle %f -selection %d -largest %f \n",inputs->xo,inputs->yo,inputs->angle_robot,inputs->xd,inputs->yd,inputs->sensor,inputs->num_sensors,inputs->theta_sensor,inputs->range_sensor, inputs->path,inputs->environment,inputs->Mag_Advance,inputs->max_angle,inputs->selection,inputs->largest_value);

  return(0);

}



