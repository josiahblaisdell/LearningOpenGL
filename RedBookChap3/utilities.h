#pragma once
#include "utilities.h"
#include "includes.h"
void display();
void reshape(int,int);
void displayCube();
void reshapeCube(int, int);
void displayPlane();
void reshapePlane(int, int);
void displayViewports();
void reshapeViewports(int, int);

//retrieved from http://programmingexamples.net/wiki/OpenGL/Text
//4/8/2018
int dx = 0, dy = 0, dz = 0;
float pitch = 0, roll = 0, yaw = 0;
std::string mode = "planeview";
void printtext(int x, int y, std::string String)
{
	//(x,y) is from the bottom left of the window
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT), -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glPushAttrib(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	glRasterPos2i(x, y);
	for (int i = 0; i<String.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
	}
	glPopAttrib();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
void yawTranslateL() {
	yaw += 1;
	if (abs(yaw) > 360) {
		yaw = abs(yaw) - 360;
	}
}

void yawTranslateR() {
	yaw -= 1;
	if (abs(yaw) > 360) {
		yaw = abs(yaw) - 360;
	}

}
void rollTranslateL() {
	roll += 1;
	if (abs(roll) > 360) {
		roll = abs(roll) - 360;
	}
}
void rollTranslateR() {
	roll -= 1;
	if (abs(roll) > 360) {
		roll = abs(roll) - 360;
	}
}
void pitchTranslateU() {
	pitch += 1;
	if (abs(pitch) > 360) {
		pitch = abs(pitch) - 360;
	}
}
void pitchTranslateD() {
	pitch -= 1;
	if (abs(pitch) > 360) {
		pitch = abs(pitch) - 360;
	}
}
void keyboard(unsigned char key, int x, int y) {
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	switch (key)
	{
	case '1':
		glClear(GL_COLOR_BUFFER_BIT);
		//Whenever GLUT determines the contents of the window need to be redisplayed,
		//the callback function registered by glutDisplayFunc() is executed. Therefore, you should put 
		//all the routines you need to redraw the scene in the display callback function.
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		glutSetWindowTitle("Table of Contents");
		dx = 0, dy = 0, dz = 0;
		pitch = 0, roll = 0, yaw = 0;
		glutPostRedisplay();
		break;
	case '2':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displayCube);
		glutReshapeFunc(reshapeCube);
		glutSetWindowTitle("Draw a Cube");
		reshapeCube(w, h);
		dx = 0, dy = 0, dz = 0;
		pitch = 0, roll = 0, yaw = 0;
		glutPostRedisplay();
		break;
	case '3':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displayPlane);
		glutReshapeFunc(reshapePlane);
		glutSetWindowTitle("Draw a Plane: plane view mode");
		reshapePlane(w, h);
		dx = 0, dy = 0, dz = 0;
		pitch = 0, roll = 0, yaw = 0;
		glutPostRedisplay();
		break;
	case '4':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displayViewports);
		glutReshapeFunc(reshapeViewports);
		glutSetWindowTitle("Draw Different Viewports");
		
		reshapeViewports(w, h);
		dx = 0, dy = 0, dz = 0;
		pitch = 0, roll = 0, yaw = 0;
		gluPerspective(60, w / (2 * h), 1.5, 20);
		glViewport(w/2, 0, w / 2, h);
		break;
	case '5':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displayClippingPlanes);
		glutReshapeFunc(reshapeClippingPlanes);
		glutSetWindowTitle("Try this: Clipping Planes");
		reshapeClippingPlanes(w, h);
		dx = 0, dy = 0, dz = 0;
		pitch = 0, roll = 0, yaw = 0;
		break;
	case 'w':
		dz += 1;
		break;
	case 's':
		dz -= 1;
		break;
	case 'a':
		dx -= 1;
		break;
	case 'd':
		dx += 1;
		break;
	case 'q':
		dy += 1;
		break;
	case 'z':
		dy -= 1;
		break;
	case 'i':
		pitchTranslateD();
		break;
	case 'k':
		pitchTranslateU();
		break;
	case 'j':
		yawTranslateL();
		break;
	case 'l':
		yawTranslateR();
		break;
	case 'u':
		rollTranslateL();
		break;
	case 'o':
		rollTranslateR();
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
