#include <GL\glut.h>
#include <iostream>
#include <string>
#include "Examples3.h"

void init();
void display();
void keyboard(unsigned char key,int x,int y);

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


