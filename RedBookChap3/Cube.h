#pragma once
#include "includes.h"
#include "utilities.h"
void reshapeCube(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	//the projection transformation determines how objects are projected onto the screen
	//1:  Perspective projection matches how you see things in daily life. 
	//	  Perspective makes objects that are farther away appear smaller; 
	//2:  Orthographic projection maps objects directly onto the screen without affecting 
	//    their relative size. Orthographic projection is used in architectural and 
	//	  computer-aided design applications where the final image needs to reflect 
	//    the measurements of objects rather than how they might look. 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	//Equivalently: gluPerspective(60, 1, 1.5, 20); (fovy,aspect,znear,zfar)
	//gluPerspective(20, 1, 1.5, 20); //decreasing fovy increases the size of the cube
	//gluPerspective(60, .1, 1.5, 20); //decreasing aspect less than 1 means height is bigger than width like a door
	//				  greater than 1 means height is smaller than width like a monitor
	//Increasing aspect ratio makes cube short in x direction, REMEMBER: w/h 
	//Decreasing makes cube longer in x direction
	//gluPerspective(20, 10, 1.5, 20);
	gluPerspective(70, 1, 1.5, 20); //can get a black screen if znear and zfar are too close.
	glMatrixMode(GL_MODELVIEW);
}
void drawCube() {
	//default location of camera is at origin (0,0,0) pointing down negative z axis, w/ up vector of (0,1,0)
	//gluLookAt: arguments place camera at (0,0,5), camera aimed towards (0,0,0), up vector is (0,1,0) defining unique orientation.
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); /* viewing transformation */
	//alternatively, could translate cube 5 units down z access leaving camera in default position for same effect.
	glTranslatef(0, 0, -5.0);
	glScalef(1.0, 2.0, 1.0);      /* modeling transformation */
								  //Now suppose I want to rotate the cube around the z axis 45 degrees can I do it?
	GLfloat xaxis[16] = { 1,0,0,0,0,sqrt(2) / 2,-sqrt(2) / 2,0,0,sqrt(2) / 2,sqrt(2) / 2,0,0,0,0,1 };
	GLfloat	yaxis[16] = { sqrt(2) / 2,0,sqrt(2) / 2 ,0,0,1,0,0,-sqrt(2) / 2 ,0,sqrt(2) / 2 ,0,0,0,0,1 };
	GLfloat zaxis[16] = { sqrt(2) / 2 ,-sqrt(2) / 2 ,0,0,sqrt(2) / 2 ,sqrt(2) / 2 ,0,0,0,0,1,0,0,0,0,1 };
	//glMultMatrixf(zaxis);
	//glRotatef(45, 0, 0, 1);
	glutWireCube(1.0);
}
void displayCube(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, "Draw a Cube");
	drawCube();
	glutSwapBuffers();
}
