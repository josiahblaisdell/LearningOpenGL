#include<GL\glut.h>
#include<iostream>
void display();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Chapter 1");
	//Whenever GLUT determines the contents of the window need to be redisplayed,
	//the callback function registered by glutDisplayFunc() is executed. Therefore, you should put 
	//all the routines you need to redraw the scene in the display callback function.
	glutDisplayFunc(display);
	glutSwapBuffers();
	glutMainLoop();
	return 0;
}

void init() {
	//color window is cleared to.
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//specify the coordinate system, defines how image gets mapped to screen
	glOrtho(0, 1, 0, 1, -1, 1);
}

void display() {
	//clear the window to clear color
	glClear(GL_COLOR_BUFFER_BIT);
	//color to use for drawing objects (white).
	glColor3f(1, 1, 1);
	//draw white polygon at (.25,.25,0) (.75,.75,0)
	glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.4, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glutSolidSphere(.75,20,2);
	glutSwapBuffers();
}