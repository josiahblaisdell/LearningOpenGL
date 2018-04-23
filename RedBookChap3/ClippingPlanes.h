#pragma once
#include "includes.h"
#include "utilities.h"
void drawClippingPlane() {
	GLdouble eqn[4] = { 1.0, 0.0, 0.0, 0.0 };
	glRotated(yaw, 0.0, 1.0, 0.0);
	glRotated(roll, 0.0, 0.0, 1.0);
	glRotated(pitch, 1.0, 0.0, 0.0);
	glClipPlane(GL_CLIP_PLANE0, eqn);
}
void drawSphere() {
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutWireSphere(1.0, 20, 16);
}
void drawClippingPlaneText() {
	printtext(10, 20, "i/k: rotate clipping plane around x axis");
	printtext(10, 100, "j/l: rotate clipping plane around y axis");
	printtext(10, 80, "u/o: rotate clipping plane around z axis");
}
void displayClippingPlanes(void)
{
	//0,1,0 is the plane for the bottom half of the sphere
	//0,1,0 points "up" and is a vector orthogonal to the z,x plane
	//1,0,0 points in the direction of the positive x axis
	//1,0,0 defines the z,y plane, clips everything in the left hemisphere
	//-1,0,0 defines the z,y plane but clips everything in the right hemisphere
	//changing the magnitude of the vectors defining the equation does not affect 
	//the clipping plane.
	//GLdouble eqn[4] = { -0.01, 0.0, 0.0, 0.0 };
	//GLdouble eqn2[4] = { -0.01, 0.0, 0.0, 0.0 };

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_CLIP_PLANE0);
	/*    clip lower half -- y < 0          */
	//glClipPlane(GL_CLIP_PLANE0, eqn);
	//glEnable(GL_CLIP_PLANE0);
  /*//   clip left half -- x < 0 */
	//glClipPlane(GL_CLIP_PLANE1, eqn2);
	//glEnable(GL_CLIP_PLANE1);
	drawClippingPlaneText();
	glPushMatrix();
	glTranslatef(0, 0, -5);
	drawClippingPlane();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, -5);
	drawSphere();
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