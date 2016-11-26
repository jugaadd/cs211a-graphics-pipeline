/*
 * OpenGL demonstration program for ICS Computer Graphics courses
 * $Id: cube.c,v 1.1 2002/04/03 00:00:35 mshafae Exp $
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include <signal.h>

#include "sceneModule.h"
#include "viewModule.h"
#include "inputModule.h"

int window;
int updateFlag;

perspectiveData pD;

#ifdef __cplusplus
extern "C"
#endif
void cleanup( int sig ){
  // insert cleanup code here (i.e. deleting structures or so)
  exit( 0 );
}


//##########################################3
// OpenGL Display function
#ifdef __cplusplus
extern "C"
#endif
void display( void ){

  static float theta = 0;

  glutSetWindow(window);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glColor3f( 1.0, 1.0, 1.0 );

  /* Set up where the projection */
  setUserView( );
  /* Draw the scene into the back buffer */
  My_rotate(theta, 0.0f, 1.0f, 0.0f);
  drawSpinner();
  My_rotate(-theta, 0.0f, 1.0f, 0.0f);

  My_rotate(theta, 0.0f, 1.0f, 0.0f);
  My_translate(5.0f,0.0f,0.0f);
  My_scale(0.75f,0.75f,0.75f);
  drawRevolver();
  My_translate(-5.0f,0.0f,0.0f);
  My_rotate(-theta, 0.0f, 1.0f, 0.0f);

  /* Swap the front buffer with the back buffer - assumes double buffering */
  glutSwapBuffers( );
  glutPostRedisplay();

  theta = theta + 0.75f;
}


//##########################################
// Init display settings
#ifdef __cplusplus
extern "C"
#endif
void initDisplay( ){
  /* Perspective projection parameters */
  pD.fieldOfView = 80.0;
  pD.aspect      = (float)IMAGE_WIDTH/IMAGE_HEIGHT;
  pD.nearPlane   = 0.01;
  pD.farPlane    = 250.0;

  /* setup context */
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluPerspective( pD.fieldOfView, pD.aspect, pD.nearPlane, pD.farPlane );

  GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
  GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position[] = {-2.0, -2.0, -2.0, 0.0 };

  //glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); //Defines the light0
//  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); //Defines the light1
//Change the parameters for the diffuse light to see different colors.
//Use the l,k keys to change the position of light1
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  GLfloat light2_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
  GLfloat light2_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light2_position[] = {2.0, 2.0, 2.0, 0.0 };

  glLightfv(GL_LIGHT1, GL_DIFFUSE, light2_diffuse);
//  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT1, GL_POSITION, light2_position);

  glEnable( GL_DEPTH_TEST );
  glEnable( GL_CULL_FACE );
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);

  glClearColor( 0.0, 0.0, 0.0, 1.0 );
  glClearIndex( 0 );
  glClearDepth( 1 );

  glMatrixMode( GL_MODELVIEW );
}

//##########################################
// Main function

int main( int argc, char **argv ){
//  signal( SIGHUP, cleanup );

  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB |
                       GLUT_DEPTH | GLUT_MULTISAMPLE );

  glutInitWindowSize( IMAGE_WIDTH,IMAGE_HEIGHT );

  /* glutInitWindowPosition(0,0); */
  window = glutCreateWindow( argv[0] );

  /* Register the appropriate callback functions with GLUT */
  glutDisplayFunc( display );
  glutKeyboardFunc( readKeyboard );
  glutMouseFunc( mouseButtHandler );
  glutMotionFunc( mouseMoveHandler );
  glutPassiveMotionFunc( mouseMoveHandler );
  glutIdleFunc( display );

  initDisplay( );

  /* This function doesn't return - put all clean up code in
   * the cleanup function */
  glutMainLoop( );

  /* ANSI C requires main to return an int. */
  return( 0 );
}
