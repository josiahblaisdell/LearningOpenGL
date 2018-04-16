#pragma once
#include "utilities.h"
void reshapePlane(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 1, 1.5, 20);
	glMatrixMode(GL_MODELVIEW);
}
void drawPlane() {
	glTranslatef(0, 0, -5);
	glScalef(1, 2, 0.1);
	glTranslatef(dx, dy, dz);
	glRotated(yaw, 0.0, 1.0, 0.0);
	glRotated(roll, 0.0, 0.0, 1.0);
	glRotated(pitch, 1.0, 0.0, 0.0);
	glutWireCube(1.0);
}
void drawTextPlane() {
	glLoadIdentity();
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, "Control a cheesy airplane");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 40, "a: camera left");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 60, "d: camera right");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 80, "w: camera up");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 100, "s: camera down");
	printtext(10, 100, "i: pitch cube up");
	printtext(10, 80, "k: pitch cube down");
	printtext(10, 60, "j: yaw left");
	printtext(10, 40, "l: yaw right");
	printtext(10, 20, "p/u: roll left/right");
}
void displayPlane() {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	drawTextPlane();
	drawPlane();
	glutSwapBuffers();
}
