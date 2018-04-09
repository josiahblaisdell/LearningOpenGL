#include <GL\glut.h>
#include <iostream>
#include <string>

void init();
void display();
void displayCube();
void reshape(int x,int y);
void keyboard(unsigned char key,int x,int y);
void printtext(int x, int y, std::string String);
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

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, "1: Table of Contents");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 40, "2: Drawing a Cube");
	glutSwapBuffers();
}

void displayCube(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, "Draw a Cube");
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case '1':
		glClear(GL_COLOR_BUFFER_BIT);
		//Whenever GLUT determines the contents of the window need to be redisplayed,
		//the callback function registered by glutDisplayFunc() is executed. Therefore, you should put 
		//all the routines you need to redraw the scene in the display callback function.
		glutDisplayFunc(display);
		glutSetWindowTitle("Table of Contents");
		glutPostRedisplay();
		break;
	case '2':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displayCube);
		glutSetWindowTitle("Draw a Cube");
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

