#pragma once
#include "utilities.h"
void reshapeViewports(int w, int h) {
	//first set up the viewport from x = 0 to x = w/2
	glViewport(0, 0, w / 2, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 0.5, 1.5, 20);
	glMatrixMode(GL_MODELVIEW);
	//second set up the viewport from x = w/2 to x =w
	glViewport(w / 2, 0, w / 2, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 0.5, 1.5, 20);
	glMatrixMode(GL_MODELVIEW);
}
//Modified draw function to take some arguments to that I can change how
//the model appears in each viewport.
void drawViewports(float dyaw,float droll,float dpitch) {
	glTranslatef(0, 0, -5);
	glScalef(1, 2, 0.1);
	glTranslatef(dx, dy, dz);
	glRotated(yaw+dyaw, 0.0, 1.0, 0.0);
	glRotated(roll+droll, 0.0, 0.0, 1.0);
	glRotated(pitch+dpitch, 1.0, 0.0, 0.0);
	glutWireCube(1.0);
}
void drawTextViewports() {
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
void displayViewports() {
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	//First: draw left viewport
	glViewport(0, 0, w / 2, h);
	drawTextViewports();
	drawViewports(0,0,0);
	//Second: draw right viewport
	glViewport(w / 2, 0, w / 2, h);
	glLoadIdentity();
	drawViewports(45,0,0);
	glutSwapBuffers();
}