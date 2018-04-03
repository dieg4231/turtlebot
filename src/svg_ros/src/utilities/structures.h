
// *****************************************************************************
// * Structures.                                                               *
// *****************************************************************************

typedef struct _step
{	int n;
	float x,y;

} step;


struct coneccion{
	struct nodo *nodo;
	float peso;
}coneccion; 

struct nodo{

	int cta;
	int n;
	float x,y;
	int n_conection;
	struct coneccion ** conection;
	

	int visitado;
	float acumulado;
	int anterior;
	int iteracion;
}; 


typedef struct linea{
	int n_palabras;
	char **palabra;
}struc_linea; 




typedef struct _coord{
        float xc,yc,anglec;
} coord;

typedef struct _Behavior{
        float xc,yc,status;
        int flg_vector;
} Behavior;

typedef struct _AdvanceAngle{
        float distance,angle;
        short int step;
} AdvanceAngle;


typedef struct _Inputs{

 char path[256];
 char file[256];
 char environment[100];
 char sensor[100];
 float xo,yo,xd,yd;
 float angle_robot;
 float theta_sensor;
 int num_sensors;
 float range_sensor;
 int num_vectors;
 float Mag_Advance;
 float radio_robot;
 float max_angle;
 int number_steps;
 int selection;
 float largest_value;
 int flgGUI;
 int flg_noise;
 int flg_real_environment;

} Inputs;



typedef struct _MV{

 char param[256];
 float coord_x;
 float coord_y;
 float coord_ang;

} MV;