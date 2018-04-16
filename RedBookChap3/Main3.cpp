#pragma once
#include "includes.h"
#include "utilities.h"
void init();
int main(int count, char** arguments) {
	glutInit(&count, arguments);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Chapter 3");
	init();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

void init() {
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT);
}


