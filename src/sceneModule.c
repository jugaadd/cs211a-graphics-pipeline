/*
 * OpenGL demonstration program for ICS Computer Graphics courses
 * $Id: sceneModule.c,v 1.1 2002/04/03 00:00:43 mshafae Exp $
 *
 */

#include "sceneModule.h"

static float spinnerColors[6][4] =
{
  {0.600, 0.827, 0.122, 1.0},
  {0.114, 0.373, 0.569, 1.0},
  {0.882, 0.690, 0.129, 1.0},
  {0.600, 0.827, 0.122, 1.0},
  {0.114, 0.373, 0.569, 1.0},
  {0.882, 0.690, 0.129, 1.0},
};

static float revolverColors[6][4] =
{
  {1.000, 0.667, 0.000, 1.0},
  {1.000, 0.824, 0.000, 1.0},
  {1.000, 0.463, 0.000, 1.0},
  {1.000, 0.667, 0.000, 1.0},
  {1.000, 0.824, 0.000, 1.0},
  {1.000, 0.463, 0.000, 1.0},
};

static float cubeVertexes[6][4][4] =
{
  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0}}
};

void drawSpinner(){
  int i;
  for (i = 0; i < 6; ++i) {
    glBegin(GL_POLYGON);
    glColor3fv(&spinnerColors[i][0]);
    glVertex4fv(&cubeVertexes[i][0][0]);
    glVertex4fv(&cubeVertexes[i][1][0]);
    glVertex4fv(&cubeVertexes[i][2][0]);
    glVertex4fv(&cubeVertexes[i][3][0]);
    glEnd();
  }
}

void drawRevolver(){
  int i;
  for (i = 0; i < 6; ++i) {
    glBegin(GL_POLYGON);
    glColor3fv(&revolverColors[i][0]);
    glVertex4fv(&cubeVertexes[i][0][0]);
    glVertex4fv(&cubeVertexes[i][1][0]);
    glVertex4fv(&cubeVertexes[i][2][0]);
    glVertex4fv(&cubeVertexes[i][3][0]);
    glEnd();
  }
}
