#include <iostream>
#include <GL\glut.h>
using namespace std;

int dx=0, dy=0, dz=0;
int cn;

struct Quads {
	int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
	float r, g, b;
	//Stores quad quad location: x1,y1,z1 or x2,y2,z2 or x3,y3,z3 test
	int state;
	//keep track of total number of quads to draw.
	int total;
}; Quads Q[100];

void addQuad() {
	Q[0].state > 4 ? Q[0].state = 1 : Q[0].state++;
	int st = Q[0].state;
	if (st == 1) {
		Q[0].total++;
		cn = Q[0].total;
		Q[cn].x1 = dx;
		Q[cn].y1 = dy;
		Q[cn].z1 = dz;
	}
	if (st == 1 || st == 2) {
		Q[cn].x2 = dx;
		Q[cn].y2 = dy;
		Q[cn].z2 = dz;
	}
	if (st == 1 || st == 2 || st == 3) {
		Q[cn].x3 = dx;
		Q[cn].y3 = dy;
		Q[cn].z3 = dz;
	}
	if (st == 1 || st == 2 || st == 3 || st==4) {
		Q[cn].x4 = dx;
		Q[cn].y4 = dy;
		Q[cn].z4 = dz;
	}
}

void drawQuads() {
	for (int i = 1; i < Q[0].total+1; i++) {
		glBegin(GL_QUADS);
		glVertex3f(Q[i].x1, Q[i].y1, Q[i].z1);
		glVertex3f(Q[i].x2, Q[i].y2, Q[i].z2);
		glVertex3f(Q[i].x3, Q[i].y3, Q[i].z3);
		glVertex3f(Q[i].x4, Q[i].y4, Q[i].z4);
		glEnd();

	}
}

void theCube() {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(dx, dy, dz);
	glutSolidCube(0.4);
	glPopMatrix();
}

void drawGrid() {
	for (int i = 0; i < 40; i++) {
		glPushMatrix();
		if (i < 20) { glTranslatef(0, 0, i); }
		if (i >= 20) { 
			glTranslatef(i-20, 0, 0);
			glRotatef(-90, 0, 1, 0);
		}

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glLineWidth(1);
		glVertex3f(0, -0.1, 0);
		glVertex3f(19, -0.1, 0);
		glEnd();
		glPopMatrix();
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-13, 0, -45);
	glRotatef(40, 1, 1, 0);
	drawGrid();
	drawQuads();
	theCube();
	glutSwapBuffers();
}

void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35, 1.0f, 0.1f, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2, 0.2, 0.2, 1);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
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
	default:
		break;
	}
	if (key == 32) { addQuad(); }
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutCreateWindow("LearningOpenGL");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}