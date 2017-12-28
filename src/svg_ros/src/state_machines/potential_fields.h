


// State Machine   
AdvanceAngle potential_fields(int* aux,int state,coord* coord_robot, coord* new_state,float Mag_Advance){

AdvanceAngle gen_vector;
float max_angle=1.5707;
int noc=state;

if (*aux==1)state=0;

if(*aux==2 || *aux==3 || *aux==4 ) state=*aux;
 //printf(" obs intensity %d obstacles %d dest %d\n",intensity,obs,dest);
;
 switch ( state ) {

        case 0:
                    


                    gen_vector=generate_output(5,Mag_Advance,new_state->anglec);                


                    printf( "\n------000-------anfulo %f\n",new_state->anglec);
                    *aux=1;

        break;
        case 1:
                    

                      *aux=1;
                    gen_vector=generate_output(5,0,new_state->anglec);                


                    printf( "\n------111-------anfulo %f\n",new_state->anglec);

        break;
        case 2:
                if(noc==1)
                gen_vector=generate_output(LEFT,Mag_Advance,max_angle/2);
            else
                gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                printf("MAquina de estados 2\n"); 
                *aux=3;
        break;
        case 3:
                gen_vector=generate_output(LEFT,5*Mag_Advance,max_angle); 
                printf("MAquina de estados 3\n"); 
                *aux=4;
        break;
        case 4:
                gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
                printf("MAquina de estados 4\n"); 
                *aux=1; 
        break;

        case 5:

        break;

        case 6:

        break;
                
 }

 //printf("Next State: %d\n", *next_state);
 return gen_vector;

}



                 

