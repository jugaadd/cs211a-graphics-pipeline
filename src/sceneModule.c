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

void My_translate(GLfloat xTranslate, GLfloat yTranslate, GLfloat zTranslate){
    GLfloat matrix[16];

    matrix[0] = matrix[5] =  matrix[10] = matrix[15] = 1.0;
    matrix[1] = matrix[2] = matrix[3] = matrix[4] = 0.0;
    matrix[6] = matrix[7] = matrix[8] = matrix[9] = 0.0;
    matrix[11] = 0.0;
    matrix[12] = xTranslate;
    matrix[13] = yTranslate;
    matrix[14] = zTranslate;

    glMultMatrixf(matrix);

}
void My_scale(GLfloat x_scale, GLfloat y_scale, GLfloat z_scale){
    GLfloat matrix[16];

    matrix[0] = x_scale;
    matrix[5] = y_scale;

    matrix[10] = z_scale;
    matrix[15] = 1.0;
    matrix[1] = matrix[2] = matrix[3] = matrix[4] = 0.0;
    matrix[6] = matrix[7] = matrix[8] = matrix[9] = 0.0;
    matrix[11] = matrix[12] = matrix[13] = matrix[14] = 0.0;

    glMultMatrixf(matrix);

}


void My_rotate(GLfloat angle,GLfloat x, GLfloat y, GLfloat z){
    GLfloat sinAngle, cosAngle;
   GLfloat mag = sqrtf(x * x + y * y + z * z);
    GLfloat matrix[16];
    GLfloat PI = 3.14159;
   sinAngle = sinf ( angle * PI / 180.0f );
   cosAngle = cosf ( angle * PI / 180.0f );
   if ( mag > 0.0f )
   {
      GLfloat xx, yy, zz, xy, yz, zx, xs, ys, zs;
      GLfloat oneMinusCos;

      x /= mag;
      y /= mag;
      z /= mag;

      xx = x * x;
      yy = y * y;
      zz = z * z;
      xy = x * y;
      yz = y * z;
      zx = z * x;
      xs = x * sinAngle;
      ys = y * sinAngle;
      zs = z * sinAngle;
      oneMinusCos = 1.0f - cosAngle;

      matrix[0] = (oneMinusCos * xx) + cosAngle;
      matrix[4] = (oneMinusCos * xy) - zs;
      matrix[8] = (oneMinusCos * zx) + ys;
      matrix[12] = 0.0F;

      matrix[1] = (oneMinusCos * xy) + zs;
      matrix[5] = (oneMinusCos * yy) + cosAngle;
      matrix[9] = (oneMinusCos * yz) - xs;
      matrix[13] = 0.0F;

      matrix[2] = (oneMinusCos * zx) - ys;
      matrix[6] = (oneMinusCos * yz) + xs;
      matrix[10] = (oneMinusCos * zz) + cosAngle;
      matrix[14] = 0.0F;

      matrix[3] = 0.0F;
      matrix[7] = 0.0F;
      matrix[11] = 0.0F;
      matrix[15] = 1.0F;

      glMultMatrixf(matrix);
   }
}

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
