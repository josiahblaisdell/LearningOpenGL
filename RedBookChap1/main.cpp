#include<GL\glut.h>
#include<iostream>
#include<windows.h>
void dummyDisplay();
void displaySquare();
void displaySquareAnimation();
void flashingTitle(int, const char*);
void reshape(int, int);
void keyboardFunc(unsigned char, int, int);
void init();

int state = 0;
static double spin = 0.0;

int main(int argc, char** argv) {
	//initializes glut state machine w/ command line args
	glutInit(&argc, argv);
	//single/double buffered | RGBA or color index | Depth
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	//Specifies the size of the window in pixels. width, height
	glutInitWindowSize(250, 250);
	//Specifies the position for upper left corner of window.
	glutInitWindowPosition(100, 100);
	//returns unique identifier for window.
	//window will not be displayed until glutMainLoop() is called.
	glutCreateWindow("Draw Square");
	init();
	glutDisplayFunc(dummyDisplay);
	//indicates what action should be taken when the window is resized. 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardFunc);	
	glutPostRedisplay();
	glutMainLoop();
	return 0;
}

void dummyDisplay(){}

void init() {
	//color window is cleared to white.
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//specify the coordinate system, defines how image gets mapped to screen
	glOrtho(0, 1, 0, 1, -1, 1);
}

void displaySquare() {
	//clear the window to clear color
	glClear(GL_COLOR_BUFFER_BIT);
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	//color to use for drawing objects (white).
	glColor3f(1, 1, 1);
	//draw white polygon at (.25,.25,0) (.75,.75,0)
	/*glBegin(GL_POLYGON);
		glVertex3f(w/2 - 25, h/2 - 25, 0.0);
		glVertex3f(w/2 + 25, h/2 - 25, 0.0);
		glVertex3f(w/2 + 25, w/2 + 25, 0.0);
		glVertex3f(w/2 - 25, h/2 + 25, 0.0);
	glEnd();*/
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glutSwapBuffers();
}

void spinDisplay() {
	spin += 2;
	if (spin > 360) {
		spin = spin - 360;
	}
	Sleep(20);
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50, 50, -50, 50, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void displaySquareAnimation() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0, 0, 1);
	glColor3f(1, 1, 1);
	glRectf(-25, -25, 25, 25);
	glPopMatrix();
	glutSwapBuffers();
}
//n is the number of seconds to flash
//title is the title.
void flashingTitle(int n, const char* title) {
	int i = 0;
	do {
		glutSetWindowTitle(title);
		Sleep(250);
		glutSetWindowTitle("");
		Sleep(250);
		i++;
	} while (i <= 2*n);
	glutSetWindowTitle(title);
}

void keyboardFunc(unsigned char key, int x, int y) {
	switch (key)
	{
	case (char)49:
		glClear(GL_COLOR_BUFFER_BIT);
		//Whenever GLUT determines the contents of the window need to be redisplayed,
		//the callback function registered by glutDisplayFunc() is executed. Therefore, you should put 
		//all the routines you need to redraw the scene in the display callback function.
		glutDisplayFunc(displaySquare);
		glutSetWindowTitle("Display Square");
		glutPostRedisplay();
		break;
	case (char)50:
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(displaySquareAnimation);
		glutSetWindowTitle("Animate Square");
		glutPostRedisplay();
		break;
	//w
	case 'w':
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	//s
	case 's':
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}
