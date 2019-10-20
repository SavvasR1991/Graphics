//libraries//
#include <stdio.h>     // - Just for some ASCII messages
#include <time.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include "gl/glut.h"   // - An interface and windows
#include "visuals.h"   // Header file for our OpenGL functions
#include <math.h>
//asteroid//
static float ast_go_up_down = 0.0;
static float ast_go_left_right = 0.0;
static float asteroid =-1500;
float asteroid_size =0.01;
float asteroid_radius =10.0;
float asteroid_colour_1 =0.1;
float asteroid_colour_2 =0.1;
float asteroid_colour_3 =0.1;
float field_aster_up_down_plus=0;
float field_aster_left_right_plus=0;
float field_aster_up_down_minus=0;
float field_aster_left_right_minus=0;
//spaceship//
static float go_up_down = 0.0;
static float go_left_right = 0.0;
float field_spacep_up_down_plus=0;
float field_spacep_left_right_plus=0;
float field_spacep_up_down_minus=0;
float field_spacep_left_right_minus=0;
//sun//
static float su_go_up_down = 0.0;
static float su_go_left_right = 0.0;
static float su_flare = 0.0;
static float su_flare_semaphore = 0.0;
static float ancle_left_rigth= 0.0;
static float tlx = 0.0;
//camera//
static float cam_go_left_right = 0.0;
static float cam_go_left_right_z = 0.0;
static float cam_go_left_right_x = 0.0;
static float cam_go_up_down = 0.0;
static float cam_go_up_down_z = 0.0;
static float cam_go_up_down_x = 0.0;
//animation//
static float u = 0.0;
static float end_game = 1.0;
static float rotx = 0.0;
static bool pause_game = false;
static bool animate = false;
static bool keyboard = false;
int i=0;
int j=0;
int k=0;
int l=0;
int m=0;
int n=0;
//model//
model md;
//choice message//
int message =0;
using namespace std;

			/////////////
			// Objects //
			/////////////

//////////
// Star //
//////////////////////////////////////
void star(int x,int y)				//
{									//
    float radius=0.2;				//
	glPushMatrix();					//
	  glTranslatef(x,y,0);			//
	  glColor3f(1.0, 1.0, 1.0);		//
	  glutSolidSphere(radius,20,20);//
  	glPopMatrix();					//
									//
}									//
//////////////////////////////////////

//////////////////////
// space_background //
//////////////////////////////////////
void space_background(){			//
	int x_p,y_p,i;					//
	srand (time(NULL));				//
	 glTranslatef(0,0,-400);		//
	for(i=0;i<200;i++){				//
		x_p= rand() % 480 ;			//
		y_p= rand() % 480 ;			//
		star(-x_p,-y_p);			//
	}								//
	for(i=0;i<200;i++){				//
		x_p= rand() % 480 ;			//
		y_p= rand() % 480 ;			//
		star(-x_p,y_p);				//
	}								//
	for(i=0;i<200;i++){				//
		x_p= rand() % 480 ;			//
		y_p= rand() % 480 ;			//
		star(x_p,-y_p);				//
	}								//
	for(i=0;i<200;i++){				//
		x_p= rand() % 480 ;			//
		y_p= rand() % 480 ;			//
		star(x_p,y_p);				//
	}								//
}									//
//////////////////////////////////////

/////////
// sun //
///////////////////////////////////////////////////
void sun(int radius)							 //
{												 //
	GLfloat specref[4];							 //
	glPushMatrix();							     //
	  glTranslatef(200,200,-500);				 //
	  specref[0] = 0.247;						 //
	  specref[1] = 0.225;						 //
	  specref[2] = 0.065;						 //
	  specref[3] = 1.0;							 //
	  glMaterialfv(GL_FRONT,GL_AMBIENT,specref); //
	  specref[0] = 0.346;						 //
	  specref[1] = 0.314;						 //
	  specref[2] = 0.090;						 //
	  specref[3] = 1.0;							 //
	  glMaterialfv(GL_FRONT,GL_DIFFUSE,specref); //
      specref[0] = 0.797;						 //
	  specref[1] = 0.724;						 //
	  specref[2] = 0.208;						 //
	  specref[3] = 1.0;							 //
      glMaterialfv(GL_FRONT,GL_SPECULAR,specref);//
      glMaterialf(GL_FRONT,GL_SHININESS,83.2);   //
	  glColor3f(1.0, 1.0, 0.0);					 //
	  glutSolidSphere(radius,20,20);			 //
  	glPopMatrix();								 //
}												 //
///////////////////////////////////////////////////

/////////////////
// solar flare //
///////////////////////////////////////////////////
void solar_flare(int radius)					 //
{												 //
	GLfloat specref[4];							 //
	glPushMatrix();							     //
	  glTranslatef(200,200,-500);				 //
	  specref[0] = 0.247;						 //
	  specref[1] = 0.225;						 //
	  specref[2] = 0.065;						 //
	  specref[3] = 1.0;							 //
	  glMaterialfv(GL_FRONT,GL_AMBIENT,specref); //
	  specref[0] = 0.346;						 //
	  specref[1] = 0.314;						 //
	  specref[2] = 0.090;						 //
	  specref[3] = 1.0;							 //
	  glMaterialfv(GL_FRONT,GL_DIFFUSE,specref); //
      specref[0] = 0.797;						 //
	  specref[1] = 0.724;						 //
	  specref[2] = 0.208;						 //
	  specref[3] = 1.0;							 //
      glMaterialfv(GL_FRONT,GL_SPECULAR,specref);//
      glMaterialf(GL_FRONT,GL_SHININESS,83.2);   //
	  glColor4f(1.0, 1.0, 0.0,su_flare);		 //
	  glutSolidSphere(radius,20,20);			 //
  	glPopMatrix();								 //
}												 //
///////////////////////////////////////////////////

///////////////
// spaceship //
//////////////////////////////////////////////////
void spaceship()								//
{												//
			///////////							//
			// cabin //							//
//////////////////////////////////////			//
    float radius=5;					//			//
	glTranslatef(0,0,-150);			//			//
	glPushMatrix();					//			//
	  glTranslatef(0,-5,-23);		//			//
	  glColor4f(1.0, 1.0, 1.0,0.1);	//			//
	  glutSolidSphere(radius,20,20);//			//
  	glPopMatrix();					//			//
//////////////////////////////////////			//
			///////////////						//
			// main part //						//
///////////////////////////////////				//
	glPushMatrix();				 //				//
		glTranslatef(0,-8,0);	 //				//
		glColor3f(0.0, 0.0, 1.0);//				//
		glScalef(7,8,50);		 //				//
		glutSolidCube(1.0);		 //				//
	glPopMatrix();				 //				//
								 //				//
	glPushMatrix();				 //				//
		glTranslatef(0,-6 , 25); //				//
		glColor3f(0.0, 0.0, 1.0);//				//
		glScalef(11,15,2);		 //				//
		glutSolidCube(1.0);		 //				//
	glPopMatrix();				 //				//
								 //				//
	glPushMatrix();				 //				//
		glTranslatef(0,-10,0);   //				//
		glColor3f(1.0, 1.0, 1.0);//				//
		glScalef(10,8,50);		 //				//
		glutSolidCube(1.0);		 //				//
	glPopMatrix();				 //				//
								 //				//
	glPushMatrix();				 //				//
		glTranslatef(0,-10,0);	 //				//
		glColor3f(0.0, 0.0, 1.0);//				//
		glScalef(11,4,50);		 //				//
		glutSolidCube(1.0);		 //				//
	glPopMatrix();				 //				//
///////////////////////////////////				//
			///////////							//
			// Wings //							//
//////////////////////////////////////			//
	glPushMatrix();					//			//
		glTranslatef(0,-10,-10);	//			//
		glColor3f(1.0, 1.0, 1.0);	//			//
		glScalef(40,2,10);			//			//
		glutSolidCube(1.0);			//			//
	glPopMatrix();					//			//
									//			//
	glPushMatrix();					//			//
		glTranslatef(0,-10,-10);	//			//
		glColor3f(1.0, 0.0, 0.0);	//			//
		glScalef(40,3,1);			//			//
		glutSolidCube(1.0);			//			//
	glPopMatrix();					//			//
									//			//
	glPushMatrix();					//			//
		glRotatef(u,-12,-10,-16);	//			//
		glTranslatef(-12,-10,-16);	//			//
		glColor3f(0.0, 1.0, 1.0);	//			//
		glScalef(10,0.5,1);			//			//
		glutSolidCube(1.0);			//			//
	glPopMatrix();					//			//
									//			//
	glPushMatrix();					//			//
		glRotatef(u,12,-10,-16);	//			//
		glTranslatef(12,-10,-16);	//			//
		glColor3f(0.0, 1.0, 1.0);	//			//
		glScalef(10,0.5,1);			//			//
		glutSolidCube(1.0);			//			//
	glPopMatrix();					//			//
//////////////////////////////////////			//
			 //////////							//
			 // Tail //							//
//////////////////////////////////////////		//
	glPushMatrix();						//		//
		glTranslatef(0,-10 , 27);		//		//
		glColor3f(1.0, 0.2, 0.2);		//		//
		glutSolidTorus( 5.0, 1.0, 2, 5);//		//
	glPopMatrix();						//		//
										//		//
	glPushMatrix();						//		//
		glTranslatef(9,0 , 25);			//		//
		glColor3f(1.0, 1.0, 1.0);		//		//
		glScalef(8,2,2);				//		//
		glutSolidCube(1.0);				//		//
	glPopMatrix();						//		//
										//		//
	glPushMatrix();						//		//
		glTranslatef(-9,0 , 25);		//		//
		glColor3f(1.0, 1.0, 1.0);		//		//
		glScalef(8,2,2);				//		//
		glutSolidCube(1.0);				//		//
	glPopMatrix();						//		//
//////////////////////////////////////////		//
}												//
//////////////////////////////////////////////////


/////////////
// Message //
//////////////////////////////////////////////////////////////
void Message(const char *str,float size)					//
{															//
	glPushMatrix();											//
		glColor3f(0.0, 0.1, 0.1);							//
		glTranslatef(-15,15,-50.0);							//
		glScalef(size,size,size);							//
		for (int i=0;i<strlen(str);i++)						//
			 glutStrokeCharacter(GLUT_STROKE_ROMAN,str[i]); //
	glPopMatrix();											//
}															//
//////////////////////////////////////////////////////////////

///////////////////////
// set_asteroid_size //
////////////////////////////////
float set_asteroid_size(){	  //
	return 0.01*(rand()%6+1); //
}							  //
////////////////////////////////

/////////////////
// check_crush //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int check_crush(float spac_up_down,float spac_left_right,float aster_up_down,float aster_left_right){							   //
	field_spacep_up_down_plus=spac_up_down+5;																					   //
	field_spacep_up_down_minus=spac_up_down-5;																					   //
	field_spacep_left_right_plus=spac_left_right+20;																			   //
	field_spacep_left_right_minus=spac_left_right-20;																			   //
	field_aster_up_down_plus=aster_up_down+asteroid_radius;																		   //
	field_aster_up_down_minus=aster_up_down-asteroid_radius;																	   //
	field_aster_left_right_plus=aster_left_right+asteroid_radius;																   //
	field_aster_left_right_minus=aster_left_right-asteroid_radius;																   //
	if(field_spacep_up_down_plus>=field_aster_up_down_minus&&field_spacep_up_down_minus<=field_aster_up_down_plus){				   //
		if(field_spacep_left_right_plus>=field_aster_left_right_minus&&field_spacep_left_right_minus<=field_aster_left_right_plus){//
			return 0;																											   //
		}																														   //
		else{																													   //
			return 1;																											   //
		}																														   //
	}																															   //
	else{																														   //
		return 1;																												   //
	}																															   //
}																																   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////
// Render //
////////////
void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Message
	if(!pause_game&&message==0){
		glPushMatrix();
			glTranslatef( -10.0,8, 0.0);
			Message("Interstellar!!Avoid the asteroids!",0.02f);
				glPushMatrix();
				glTranslatef( 0.0,-3, 0.0);
				Message("Press Mouse left click to begin!!",0.02f);
			glPopMatrix();

			glPushMatrix();
				glTranslatef( 0.0,-6, 0.0);
				Message("->SpaceShip moves: Up->W,Down->S,left->W,Right->S",0.01f);
			glPopMatrix();

			glPushMatrix();
				glTranslatef( 0.0,-9, 0.0);
				Message("->Camera moves: Up->E,Down->R,left->Z,Right->X",0.01f);
			glPopMatrix();

			glPushMatrix();
				glTranslatef( 0.0,-12, 0.0);
				Message("->Press Q for end game!!",0.01f);
			glPopMatrix();

			glPushMatrix();
				glTranslatef( 0.0,-15, 0.0);
				Message("->Press Mouse left click to pause!!",0.01f);
			glPopMatrix();
		glPopMatrix();
	}
	if(!pause_game&&message==1){
		Message("Pause!",0.02f);
	}
	if(end_game==0){
		Message("Boom!Press Q!",0.02f);
	}
	//Camera
	glPushMatrix();
		glTranslatef( 0.0,cam_go_up_down_x, cam_go_up_down_z);
		glRotatef(cam_go_up_down,1,0,0);
		glTranslatef( cam_go_left_right_x,0.0, cam_go_left_right_z);
		glRotatef(cam_go_left_right,0,-1,0);
			//Asteroid
			glPushMatrix();
				 glRotatef(u,ast_go_left_right,ast_go_up_down,asteroid);
				 glTranslatef(ast_go_left_right,ast_go_up_down,asteroid);
				 glColor3f(asteroid_colour_1, asteroid_colour_2, asteroid_colour_3);
				 glScalef(asteroid_size, asteroid_size, asteroid_size);
				 DisplayModel(md);
			glPopMatrix();
			//spaceship
			glPushMatrix();
				glRotatef(ancle_left_rigth,go_left_right,go_up_down,-150);
				glTranslatef(go_left_right,go_up_down,0);
				spaceship();
			glPopMatrix();
			//sun
			glPushMatrix();
				glTranslatef(tlx,0,0);
				glTranslatef(0,su_go_up_down,0);
				glTranslatef(su_go_left_right,0,0);
				sun(40);
				solar_flare(60);
			glPopMatrix();
	glPopMatrix();
	//Background
	space_background();
	glutSwapBuffers();
}


////////////
//  Idle  //
////////////
void Idle()
{
	if(animate){
		message=1;
		u+=100;
		if(asteroid<0)
			asteroid+=10;
		else{
			asteroid_size=set_asteroid_size();
			asteroid_colour_1=0.1*(rand()%10);
			asteroid_colour_2=0.1*(rand()%10);
			asteroid_colour_3=0.1*(rand()%10);
			ast_go_up_down=go_up_down;
			ast_go_left_right=go_left_right;
			asteroid=-1500;
		}
		if(asteroid==-150){
			if(check_crush(go_up_down,go_left_right,ast_go_up_down,ast_go_left_right)==0){
				end_game=0;
				animate=false;
			}
		}
		if(su_flare<0.5)
		   su_flare+=0.02;
		if(su_flare>=0.5)
		   su_flare-=0.3;
		if(i==1&&ancle_left_rigth<0){
			ancle_left_rigth+=3;
		}
		if(j==1&&ancle_left_rigth>0){
			ancle_left_rigth-=3;
		}
		if(k==1&&cam_go_up_down>0){
			cam_go_up_down-=2.5;
			cam_go_up_down_x+=4;
			cam_go_up_down_z+=3;
		}
		else
			k=0;
		if(l==1&&cam_go_up_down<0){
			cam_go_up_down+=2.5;
			cam_go_up_down_x-=4;
			cam_go_up_down_z+=3;
		}
		else
			l=0;
		if(m==1&&cam_go_left_right>0){
			cam_go_left_right-=2.5;
			cam_go_left_right_x+=4;
			cam_go_left_right_z+=3;
		}
		else
			m=0;
		if(n==1&&cam_go_left_right<0){
			cam_go_left_right+=2.5;
			cam_go_left_right_x-=4;
			cam_go_left_right_z+=3;
		}
		else
			n=0;
	}
    glutPostRedisplay();

}

//////////////
//  Resize  //
//////////////
void Resize(int w, int h)
{
	if (h==0) h=1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float aspect = (float)w/(float)h;
	gluPerspective(60.0, aspect, 1, 1000.0);
}

////////////////
//  Keyboard  //
////////////////
void Keyboard(unsigned char key,int x,int y)
{	i=0;
	j=0;

	if(key=='q'){
		exit(0);
	}
	if(keyboard){
		if(end_game==0)
		{
			switch(key)
			{	case 'q' :
					exit(0);
					break;
				default :
					break;
			}
		}
		else{
			switch(key)
			{
			case 'q' :
				exit(0);
				break;
			case 's' :
				if(go_up_down>-15)
					go_up_down-=1;

				else{
					go_up_down=-15;
					su_go_up_down+=2.5f;
				}
				ast_go_up_down+=1;
				break;
			case 'w' :
				if(go_up_down<13)
					go_up_down+=1;
				else
					go_up_down=13;
				if(su_go_up_down>0)
					su_go_up_down-=2.5f;
				else
					su_go_up_down=0;
				ast_go_up_down-=1;
				break;
			case 'a' :
				if(ancle_left_rigth>-30)
					ancle_left_rigth-=3;
				else{
					ancle_left_rigth=-30;
				}
				if(go_left_right>-10)
					go_left_right-=1;
				else{
					go_left_right=-10;
					su_go_left_right+=2.5f;
				}
				ast_go_left_right+=1;
				break;
			case 'd' :
				if(ancle_left_rigth<30)
					ancle_left_rigth+=3;
				else{
					ancle_left_rigth=30;
				}
				if(go_left_right<10)
					go_left_right+=1;
				else
					go_left_right=10;
				if(su_go_left_right>0)
					su_go_left_right-=2.5f;
				else
					su_go_left_right=0;
				ast_go_left_right-=1;
				break;
			case 'z' :
				if(cam_go_left_right>=0){
					cam_go_left_right-=2.5;
					cam_go_left_right_x+=4;
					cam_go_left_right_z+=3;
				}
				else if(cam_go_left_right>=-100){
					cam_go_left_right-=2.5;
					cam_go_left_right_x+=4;
					cam_go_left_right_z-=3;
				}
				 if(cam_go_left_right>=-100){
					cam_go_left_right==-100;
					cam_go_left_right_x==150;
					cam_go_left_right_z==-200;
				 }
				break;
			case 'x' :
				if(cam_go_left_right<0){
					cam_go_left_right+=2.5;
					cam_go_left_right_x-=4;
					cam_go_left_right_z+=3;
				}
				else if(cam_go_left_right<=100){
					cam_go_left_right+=2.5;
					cam_go_left_right_x-=4;
					cam_go_left_right_z-=3;
				}
				break;
			case 'e' :
				if(cam_go_up_down<0){
					cam_go_up_down+=2.5;
					cam_go_up_down_x-=4;
					cam_go_up_down_z+=3;
				}
				else if(cam_go_up_down<=100){
					cam_go_up_down+=2.5;
					cam_go_up_down_x-=4;
					cam_go_up_down_z-=3;
				}

				break;
			case 'r' :
				if(cam_go_up_down>=0){
					cam_go_up_down-=2.5;
					cam_go_up_down_x+=4;
					cam_go_up_down_z+=3;
				}
				else if(cam_go_up_down>=-100){
					cam_go_up_down-=2.5;
					cam_go_up_down_x+=4;
					cam_go_up_down_z-=3;
				}
			    if(cam_go_up_down>=-100){
					cam_go_up_down==-100;
					cam_go_up_down_x==150;
					cam_go_up_down_z==-200;
				}
				break;
			default :
				break;
			}
		}
	}
	glutPostRedisplay();
	if(ancle_left_rigth==-30){
		i=1;
	}
	if(ancle_left_rigth==30){
		j=1;
	}
	if(cam_go_up_down==97.5){
		k=1;
	}
	if(cam_go_up_down==-97.5){
		l=1;
	}
	if(cam_go_left_right==97.5){
		m=1;
	}
	if(cam_go_left_right==-97.5){
		n=1;
	}
}
//////////////
//  Mouse   //
//////////////
void Mouse(int button,int state,int x,int y)
{
	 if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON&&end_game==1)
	 {
		 animate = !animate;
		 keyboard=!keyboard;
		 pause_game=!pause_game;
         glutPostRedisplay();
	 }
}

//////////////
//  Setup   //
//////////////
void Setup()
{
    ReadFile(&md);
    glEnable( GL_CULL_FACE );
    glShadeModel( GL_SMOOTH );
    glEnable(GL_DEPTH_TEST);
    glDepthFunc( GL_LEQUAL );
    glClearDepth(1.0);
    GLfloat light_position[] = { su_go_left_right, su_go_up_down, -500.0, 0.0 };
	glLightfv( GL_LIGHT0, GL_POSITION, light_position);
	GLfloat ambientLight[] = { 1,1,1,1.0};
	GLfloat diffuseLight[] = { 1, 1, 1, 1.0 };
	glLightfv( GL_LIGHT0, GL_AMBIENT, ambientLight );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuseLight );
	GLfloat specref[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT,GL_SPECULAR,specref);
	glMateriali(GL_FRONT,GL_SHININESS,60);
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0f,0.0f,0.0f,1.0f);
}

/////////////////
//  ReadFile   //
/////////////////
void ReadFile(model *md)
{
	ifstream obj_file;                 // Open the file for reading OBJINFO.TXT
	obj_file.open("asteroid.obj");
	if (obj_file.fail())
		exit(1);
	float no_f=0,no_v=0;
	char fline[1000];
	char *pch;
	int i=0,j=0;
	/*while(obj_file){
		obj_file.getline(fline, 1000);
		pch = strtok (fline," ");
        while (pch != NULL){
			if(strcmp(pch,"f")==0){
				 no_f++;
			}
		    if(strcmp(pch,"v")==0){
				no_v++;
			}
			pch = strtok (NULL," ");
		}
    }*/
	md->vertices=9122;                               // Get the number of vertices
    md->faces=18240;									// Get the number of faces
	while(obj_file){
		obj_file.getline(fline, 1000);
        pch = strtok (fline," ");
        while (pch != NULL){
			 if(strcmp(pch,"v")==0){
					pch = strtok (NULL," ");
					md->obj_points[i].x=atof(pch);
					pch = strtok (NULL," ");
					md->obj_points[i].y=atof(pch);
					pch = strtok (NULL," ");
					md->obj_points[i].z=atof(pch);
					i++;
			 }
			 else if(strcmp(pch,"f")==0){
					pch = strtok (NULL," //");
					md->obj_faces[j].vtx[0]=atoi(pch);
					pch = strtok (NULL," //");

					pch = strtok (NULL," //");
					md->obj_faces[j].vtx[1]=atoi(pch);
					pch = strtok (NULL," //");

					pch = strtok (NULL," //");
					md->obj_faces[j].vtx[2]=atoi(pch);
					pch = strtok (NULL," //");
					j++;
			 }
			 pch = strtok (NULL," ");
		}
	}
    obj_file.close();
}

/////////////////////
//  DisplayModel   //
/////////////////////
void DisplayModel(model md)
{
	glPushMatrix();
	glBegin(GL_TRIANGLES  );
	for (int i = 0; i < md.faces; i++)
	{
		glVertex3f(md.obj_points[md.obj_faces[i].vtx[0]-1].x,md.obj_points[md.obj_faces[i].vtx[0]-1].y,md.obj_points[md.obj_faces[i].vtx[0]-1].z);
		glVertex3f(md.obj_points[md.obj_faces[i].vtx[1]-1].x,md.obj_points[md.obj_faces[i].vtx[1]-1].y,md.obj_points[md.obj_faces[i].vtx[1]-1].z);
		glVertex3f(md.obj_points[md.obj_faces[i].vtx[2]-1].x,md.obj_points[md.obj_faces[i].vtx[2]-1].y,md.obj_points[md.obj_faces[i].vtx[2]-1].z);
	}
	glEnd();
	glPopMatrix();

}
