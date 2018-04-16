#pragma once
#include <GL\glut.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>
int dx = 0, dy = 0, dz = 0;
float pitch = 0;
float roll = 0;
float yaw = 0;
void keyboardPlane(unsigned char key, int x, int y);
//retrieved from http://programmingexamples.net/wiki/OpenGL/Text
//4/8/2018
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


void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW); //end with modelview matrix
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, "1: Table of Contents");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 40, "2: Drawing a Cube");
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 60, "3: Drawing a cheesy air plane");
	glutSwapBuffers();
}
void reshapeCube(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	//the projection transformation determines how objects are projected onto the screen
	//1:  Perspective projection matches how you see things in daily life. 
	//	  Perspective makes objects that are farther away appear smaller; 
	//2:  Orthographic projection maps objects directly onto the screen without affecting 
	//    their relative size. Orthographic projection is used in architectural and 
	//	  computer-aided design applications where the final image needs to reflect 
	//    the measurements of objects rather than how they might look. 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	//Equivalently: gluPerspective(60, 1, 1.5, 20); (fovy,aspect,znear,zfar)
	//gluPerspective(20, 1, 1.5, 20); //decreasing fovy increases the size of the cube
	//gluPerspective(60, .1, 1.5, 20); //decreasing aspect less than 1 means height is bigger than width like a door
									 //				  greater than 1 means height is smaller than width like a monitor
									 //Increasing aspect ratio makes cube short in x direction, 
									 //Decreasing makes cube longer in x direction
	//gluPerspective(20, 10, 1.5, 20);
	gluPerspective(70, 1, 1.5, 20); //can get a black screen if znear and zfar are too close.
	glMatrixMode(GL_MODELVIEW);
}
void displayCube(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, "Draw a Cube");
	//default location of camera is at origin (0,0,0) pointing down negative z axis, w/ up vector of (0,1,0)
	//gluLookAt: arguments place camera at (0,0,5), camera aimed towards (0,0,0), up vector is (0,1,0) defining unique orientation.
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); /* viewing transformation */
	//alternatively, could translate cube 5 units down z access leaving camera in default position for same effect.
	glTranslatef(0, 0, -5.0);
	glScalef(1.0, 2.0, 1.0);      /* modeling transformation */
	//Now suppose I want to rotate the cube around the z axis 45 degrees can I do it?
	GLfloat xaxis[16] = { 1,0,0,0,0,sqrt(2)/2,-sqrt(2)/2,0,0,sqrt(2)/2,sqrt(2)/2,0,0,0,0,1 };
	GLfloat	yaxis[16] = { sqrt(2) / 2,0,sqrt(2) / 2 ,0,0,1,0,0,-sqrt(2) / 2 ,0,sqrt(2) / 2 ,0,0,0,0,1 };
	GLfloat zaxis[16] = { sqrt(2) / 2 ,-sqrt(2) / 2 ,0,0,sqrt(2) / 2 ,sqrt(2) / 2 ,0,0,0,0,1,0,0,0,0,1 };
	//glMultMatrixf(zaxis);
	//glRotatef(45, 0, 0, 1);
	glutWireCube(1.0);
	glutSwapBuffers();
}

void reshapePlane(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 1, 1.5, 20);
	glMatrixMode(GL_MODELVIEW);
}
void drawPlane() {
	glTranslatef(dx, dy, dz);
	glRotated(yaw, 0.0, 1.0, 0.0);
	glRotated(roll, 0.0, 0.0, 1.0);
	glRotated(pitch, 1.0, 0.0, 0.0);
	glutWireCube(1.0);
}
void displayPlane() {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glLoadIdentity();
	printtext(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, "Draw a cheesy airplane");
	glTranslatef(0, 0, -5);
	glScalef(1, 2, 0.1);
	drawPlane();
	glutSwapBuffers();
	//glLoadIdentity();
	//glTranslatef(1, 2.5, 0);
	//glScalef(2, 0.5, 1);
	//glutWireCube(1.0);
	//glLoadIdentity();
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glutSwapBuffers();
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
		glutPostRedisplay();
		break;
	case '2':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displayCube);
		glutReshapeFunc(reshapeCube);
		glutSetWindowTitle("Draw a Cube");
		reshapeCube(w, h);
		glutPostRedisplay();
		break;
	case '3':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displayPlane);
		glutReshapeFunc(reshapePlane);
		glutSetWindowTitle("Draw a Plane");
		glutKeyboardFunc(keyboardPlane);
		reshapePlane(w, h);
		glutPostRedisplay();
		break;
	default:
		break;
	}
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
		yaw = abs(yaw)-360;
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
void keyboardPlane(unsigned char key, int x, int y) {
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
		glutKeyboardFunc(keyboard);
		glutPostRedisplay();
		break;
	case '2':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displayCube);
		glutReshapeFunc(reshapeCube);
		glutSetWindowTitle("Draw a Cube");
		glutKeyboardFunc(keyboard);
		reshapeCube(w, h);
		glutPostRedisplay();
		break;
	case '3':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displayPlane);
		glutReshapeFunc(reshapePlane);
		glutSetWindowTitle("Draw a Plane");
		glutKeyboardFunc(keyboardPlane);
		reshapePlane(w, h);
		glutPostRedisplay();
		break;
	case 'w':
		dz -= 1;
		break;
	case 's':
		dz += 1;
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



