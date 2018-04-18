#pragma once
#include "includes.h"
#include "utilities.h"

void displayClippingPlanes(void)
{
	//0,1,0 is the plane for the bottom half of the sphere
	//0,1,0 points "up" and is a vector orthogonal to the z,x plane
	//1,0,0 points in the direction of the positive x axis
	//1,0,0 defines the z,y plane, clips everything in the left hemisphere
	//-1,0,0 defines the z,y plane but clips everything in the right hemisphere
	//changing the magnitude of the vectors defining the equation does not affect 
	//the clipping plane.
	GLdouble eqn[4] = { -0.01, 0.0, 0.0, 0.0 };
	GLdouble eqn2[4] = { -0.01, 0.0, 0.0, 0.0 };

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);

	/*    clip lower half -- y < 0          */
	glClipPlane(GL_CLIP_PLANE0, eqn);
	glEnable(GL_CLIP_PLANE0);
	/*    clip left half -- x < 0           */
	glClipPlane(GL_CLIP_PLANE1, eqn2);
	glEnable(GL_CLIP_PLANE1);

	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutWireSphere(1.0, 20, 16);
	glPopMatrix();
	glutSwapBuffers();
}

void reshapeClippingPlanes(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}