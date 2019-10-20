
#include <stdio.h>     // - Just for some ASCII messages
#define GLUT_DISABLE_ATEXIT_HACK
#include "gl/glut.h"   // - An interface and windows
                       //   management library
#include "visuals.h"   // Header file for our OpenGL functions



////////////////// State Variables ////////////////////////
float t=0.0; ///Time

/////////////// Main Program ///////////////////////////

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
  glutInitWindowSize(480,480);
  glutInitWindowPosition(220,50);
  glutCreateWindow("InterStellar");
  Setup();
  glutDisplayFunc(Render);
  glutReshapeFunc(Resize);
  glutIdleFunc(Idle);
  glutKeyboardFunc(Keyboard);
  glutMouseFunc(Mouse);
  glutMainLoop();
  return 0;
}

