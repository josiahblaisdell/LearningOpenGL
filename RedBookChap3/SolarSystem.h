#pragma once
#include "includes.h"
#include "utilities.h"

void reshapeSolarSystem(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLdouble)w/(GLdouble)h, 1.5, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//My initial thought was to have the solar system centered at the origin with the camera at (5,5,5) looking down at an angle.
	//gluLookAt(5, 5, 5, -100, -100, -100, -1, 1, -1);
	//The book uses the following:
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}
void drawSun(){
	glutWireSphere(10, 20, 16);
}
void drawPlanet(double x, double y, double z) {
	//could set revolution about different axis to model orbit on different plane.
	//Set the current day (position of earth around sun)
	glRotatef((.9863*day) / 360, 0, 1, 0);
	//move the camera away from the sun to coordinate x,y,z
	glTranslatef(x, y, z);
	//rotate the planet given time
	//could set rotation around different axis to model tilt of earth.
	glRotatef((0.25*time) / 360, 0, 1, 0);
	//draw the planet
	//could use different number of slices/stacks to model latitude/longitude
	glutWireSphere(0.1, 10, 8);
}
void displaySolarSystem() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	//push matrix storing transformations set in reshape
	glPushMatrix();
	drawSun();
	drawPlanet(2,0,0);
	//put the matrix storing projection and viewing back
	glPopMatrix();
	glutSwapBuffers();
}