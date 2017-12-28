/********************************************************
 *                                                      *
 *                                                      *
 *      state_machine_avoidance_destination.h           *
 *                                                      *
 *              Jesus Savage                            *
 *              FI-UNAM                                 *
 *              5-2-2015                                *
 *                                                      *
 ********************************************************/


// State Machine   
AdvanceAngle state_machine_surround(int obs, int dest, int intensity, int state, int *next_state,float Mag_Advance,float max_angle){

 AdvanceAngle gen_vector;

 //printf(" obs intensity %d obstacles %d dest %d\n",intensity,obs,dest);

 switch ( state ) {

        case 0:
                if (intensity == 1){
                        gen_vector=generate_output(STOP,Mag_Advance,max_angle);
                        //printf("Present State: %d STOP\n", state);
                        printf("\n **************** Reached light source ******************************\n");
                        *next_state = 1;

                }
                else{

                       switch (obs)
                       {
                        case 0:
                            gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                        break;
                        case 1:
                            gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);

                        break;
                        case 2:
                            gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                        break;
                        case 3:
                            gen_vector=generate_output(LEFT,Mag_Advance,2*max_angle);
                        break;
                        case 4:
                            gen_vector=generate_output(LEFT,Mag_Advance,2*max_angle);
                        break;
                        case 5:
                            gen_vector=generate_output(RIGHT,Mag_Advance,2*max_angle);
                        break;
                        case 6:
                            gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                        break;
                        case 7:
                            gen_vector=generate_output(RIGHT,Mag_Advance,4*max_angle);
                        break;
                            gen_vector=generate_output(BACKWARD,Mag_Advance,max_angle);


                       }


                       // gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                        //printf("Present State: %d FORWARD\n", state);
                        *next_state = 0;
                }

                break;

        case 1:
                if (obs == 0){
                        // there is not obstacle
                        gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                        //printf("Present State: %d FORWARD\n", state);
                        *next_state = 1;
                }
                else{
                        gen_vector=generate_output(STOP,Mag_Advance,max_angle);
                        //printf("Present State: %d STOP\n", state);

                        if (obs == 1){
                                // obtacle in the  right
                            gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                                *next_state = 4;
                        }
                        else if (obs == 2){
                            gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                                // obtacle in the left
                                *next_state = 2;
                        }
                        else if (obs == 3){
                            gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                                // obstacle in the front
                                *next_state = 6;
                        }
                }

                break;

        case 2: // Backward, obstacle in the left
                gen_vector=generate_output(BACKWARD,Mag_Advance,max_angle);
                //printf("Present State: %d BACKWARD, obstacle LEFT\n", state);
                *next_state = 3;
                break;

        case 3: // right turn
                gen_vector=generate_output(RIGHT,Mag_Advance,max_angle);
                //printf("Present State: %d TURN RIGHT\n", state);
                *next_state = 0;
                break;

        case 4: // Backward, obstacle in the right
                gen_vector=generate_output(BACKWARD,Mag_Advance,max_angle);
                //printf("Present State: %d BACKWARD, obstacle RIGHT\n", state);
                *next_state = 5;
                break;

        case 5: // left turn
                gen_vector=generate_output(LEFT,Mag_Advance,max_angle);
                //printf("Present State: %d TURN LEFT\n", state);
                *next_state = 0;
                break;

        case 6: // Backward, obstacle in front
                gen_vector=generate_output(BACKWARD,Mag_Advance,max_angle);
                //printf("Present State: %d BACKWARD, obstacle FRONT\n", state);
                *next_state = 7;
                break;

        case 7: /// Left turn
                gen_vector=generate_output(LEFT,Mag_Advance,max_angle);
                //printf("Present State: %d TURN 1 LEFT\n", state);
                *next_state = 8;
                break;

        case 8:// Left turn
                gen_vector=generate_output(LEFT,Mag_Advance,max_angle);
                //printf("Present State: %d TURN 2 LEFT\n", state);
                *next_state = 9;
                break;

        case 9:// Left turn
                gen_vector=generate_output(LEFT,Mag_Advance,max_angle);
                //printf("Present State: %d TURN 3 LEFT\n", state);
                *next_state = 10;
                break;

        case 10: // Forward
                gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                //printf("Present State: %d 1 FORWARD\n", state);
                *next_state = 11;
                break;

        case 11: // Forward
                gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                //printf("Present State: %d 2 FORWARD\n", state);
                *next_state = 12;
                break;

        case 12: // Forward
                gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                //printf("Present State: %d 3 FORWARD\n", state);
                *next_state = 13;
                break;

        case 13: // Right turn
                gen_vector=generate_output(RIGHT,Mag_Advance,max_angle);
                //printf("Present State: %d turn 1 RIGHT\n", state);
                *next_state = 14;
                break;

        case 14: // Right turn
                gen_vector=generate_output(RIGHT,Mag_Advance,max_angle);
                //printf("Present State: %d turn 2 RIGHT\n", state);
                *next_state = 15;
                break;

        case 15: // Right turn
                gen_vector=generate_output(RIGHT,Mag_Advance,max_angle);
                //printf("Present State: %d turn 3 RIGHT\n", state);
                *next_state = 0;
                break;


        case 16: // // check destination
                 if (dest == 0){
                                // go right
                                gen_vector=generate_output(RIGHT,Mag_Advance,max_angle);
                                //printf("Present State: %d RIGHT\n", state);
                                *next_state = 3;
                 }
                 else if (dest == 1){
                                // go left
                                gen_vector=generate_output(LEFT,Mag_Advance,max_angle);
                                //printf("Present State: %d LEFT\n", state);
                                *next_state = 5;
                 }
                 else if (dest == 2){
                                // go right single
                                gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                                //printf("Present State: %d RIGHT\n", state);
                                *next_state = 3;
                 }
                 else if (dest == 3){
                                // go left single
                                gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                                //printf("Present State: %d LEFT\n", state);
                                *next_state = 5;
                 }
                break;

        default:
                //printf("State %d not defined used ", state);
                gen_vector=generate_output(STOP,Mag_Advance,max_angle);
                next_state = 0;
                break;

                
 }

 //printf("Next State: %d\n", *next_state);
 return gen_vector;

}



                 

