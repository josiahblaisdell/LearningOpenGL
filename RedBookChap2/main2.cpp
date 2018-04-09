#include <GL\glut.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Examples2.h"

void init(void);
void display(void);
void reshape(int w, int h);
void mouse(int, int, int, int);
void keyboard(unsigned char, int, int);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	//location of window on display
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Chapter 2");
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, "1: Table of Contents");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 40, "2: Drawing Lines");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 60, "3: Drawing Polygons");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 80, "4: Vertex Arrays: Triangle");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 100, "5: Vertex Arrays: Icosahedron");
	glFlush();
}


void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
	std::string str = "(x,y): (" + std::to_string(x) + "," + std::to_string(y) +")";
	glutSetWindowTitle(str.c_str());
}

void keyboard(unsigned char key, int x, int y) {
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	switch (key)
	{
	case '1':
		glClear(GL_COLOR_BUFFER_BIT);
		glutReshapeFunc(reshape);
		glutPostRedisplay();
		//Whenever GLUT determines the contents of the window need to be redisplayed,
		//the callback function registered by glutDisplayFunc() is executed. Therefore, you should put 
		//all the routines you need to redraw the scene in the display callback function.
		glutDisplayFunc(display);
		glutSetWindowTitle("Table of Contents");
		glutPostRedisplay();
		break;
	case '2':
		glClear(GL_COLOR_BUFFER_BIT);
		glutSetWindowTitle("2: Drawing Lines");
		glutDisplayFunc(displayLines);
		glutReshapeFunc(reshapeLines);
		reshapeLines(w, h);
		glutPostRedisplay();
		break;
	case '3':
		glClear(GL_COLOR_BUFFER_BIT);
		glutSetWindowTitle("3: Drawing Polygons");
		glutDisplayFunc(displayPolygons);
		glutReshapeFunc(reshapePolygons);
		reshapePolygons(w, h);
		glutPostRedisplay();
		break;
	case '4':
		glClear(GL_COLOR_BUFFER_BIT);
		glutSetWindowTitle("4: Vertex Arrays: Triangle");
		glutDisplayFunc(displayTriangle);
		glutReshapeFunc(reshapeTriangle);
		reshapeTriangle(w, h);
		glutPostRedisplay();
		break;
	case '5':
		glClear(GL_COLOR_BUFFER_BIT);
		glutSetWindowTitle("4: Vertex Arrays: Icosahedron");
		glutDisplayFunc(displayIcosahedron);
		glutReshapeFunc(reshapeIcosahedron);
		reshapeIcosahedron(w, h);
		glutPostRedisplay();
		break;
	default:
		break;
	}
}