#include<GL\glut.h>
#include<iostream>
void display();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Chapter 1");
	//color window is cleared to.
	glClearColor(0, 0, 0, 0);
	//clear the window to clear color
	glClear(GL_COLOR_BUFFER_BIT);
	//color to use for drawing objects (white).
	glColor3f(1, 1, 1);
	//specify the coordinate system, defines how image gets mapped to screen
	glOrtho(0, 1, 0, 1, -1, 1);
	//Whenever GLUT determines the contents of the window need to be redisplayed,
	//the callback function registered by glutDisplayFunc() is executed. Therefore, you should put 
	//all the routines you need to redraw the scene in the display callback function.
	glutDisplayFunc(display);
	glutSwapBuffers();
	glutMainLoop();
	return 0;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glutSwapBuffers();
}