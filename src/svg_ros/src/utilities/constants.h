// Defining constants

#define LIMIT_SIM 15  // Maximum number of steps
#define MAG_ADVANCE 0.04 // Advance magnitude in meters 
#define TURN_ANGLE PI/8.0
#define CNT_GOAL 1.5 // constant to find a threshold to reach the goal 
#define CNT_GOAL2 1.4
//#define K_GOAL CNT_GOAL2*MAG_ADVANCE 
//#define K_INTENSITY K_GOAL 
#define THRS_SENSOR .3//*MAG_ADVANCE // 
#ifndef PI
#define PI 3.1415926535f
#endif
#define RADIO_ROBOT 0.03 // Radio Robot in meters
//#define NUM_MAX_SENSORS 4097
#define STOP 0
#define FORWARD 1
#define FORWARD_FULL 5
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define NUM_MAX_WORDS 100



