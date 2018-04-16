#pragma once
#include "utilities.h"
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW); //end with modelview matrix
}
void drawText() {
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, "1: Table of Contents");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 40, "2: Drawing a Cube");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 60, "3: Control a cheesy airplane");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 80, "4: Different Viewports");
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	drawText();
	glutSwapBuffers();
}