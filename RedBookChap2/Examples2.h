#pragma once
#include <GL\glut.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>
const float PI = 3.14159265;
#define X (0.525731112119133606 )
#define Z (0.850650808352039932)

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

#define drawSquare(x1,y1,x2,y2)  glBegin(GL_POLYGON); \
	glVertex2f((x1),(y1)); glVertex2f ((x1),(y2));	\
	glVertex2f((x2), (y2)); glVertex2f((x2), (y1)); \
	glEnd();

#define drawPentagon(x,y,r) glBegin(GL_POLYGON); \
		glVertex2f((x + r), (y)); \
		glVertex2f((x + r * cos(2 * PI / 5)), (y + r * sin(2 * PI / 5))); \
		glVertex2f((x + r * cos(4 * PI / 5)), (y + r * sin(4 * PI / 5))); \
		glVertex2f((x + r * cos(6 * PI / 5)), (y + r * sin(6 * PI / 5))); \
		glVertex2f((x + r * cos(8 * PI / 5)), (y + r * sin(8 * PI / 5))); \
	glEnd();

void drawNGon(double x, double y, double r, int n) {
	glBegin(GL_POLYGON);
	for (int k = 0; k < n; k++)
	{
		glVertex2f(x + r * cos(2 * k*PI / n), y + r * sin(2 * k*PI / n));
	}
	glEnd();
}

void reshapeLines(int w, int h)
{
	GLfloat model[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, model);
	GLfloat projection[16];
	glGetFloatv(GL_PROJECTION_MATRIX, projection);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);

}
void displayLines()
{
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	/* select white for all lines  */
	glColor3f(1.0, 1.0, 1.0);

	/* in 1st row, 3 lines, each with a different stipple  */
	glEnable(GL_LINE_STIPPLE);

	glLineStipple(1, 0x0101);  /*  dotted  */
	drawOneLine(50.0, h - 50.0, 150.0, h - 50.0);
	glLineStipple(1, 0x00FF);  /*  dashed  */
	drawOneLine(150.0, h - 50.0, 250.0, h - 50.0);
	glLineStipple(1, 0x1C47);  /*  dash/dot/dash  */
	drawOneLine(250.0, h - 50.0, 350.0, h - 50.0);
	/* in 2nd row, 3 wide lines, each with different stipple */
	glLineWidth(5.0);
	glLineStipple(1, 0x0101);  /*  dotted  */
	drawOneLine(50.0, h - 75.0, 150.0, h - 75.0);
	glLineStipple(1, 0x00FF);  /*  dashed  */
	drawOneLine(150.0, h - 75.0, 250.0, h - 75.0);
	glLineStipple(1, 0x1C47);  /*  dash/dot/dash  */
	drawOneLine(250.0, h - 75.0, 350.0, h - 75.0);
	glLineWidth(1.0);

	/* in 3rd row, 6 lines, with dash/dot/dash stipple  */
	/* as part of a single connected line strip         */
	glLineStipple(1, 0x1C47);  /*  dash/dot/dash  */
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < 7; i++)
		glVertex2f(50.0 + ((GLfloat)i * 50.0), h - 100.0);
	glEnd();

	/* in 4th row, 6 independent lines with same stipple  */
	for (i = 0; i < 6; i++) {
		drawOneLine(50.0 + ((GLfloat)i * 50.0), h - 125.0,
			50.0 + ((GLfloat)(i + 1) * 50.0), h - 125.0);
	}

	/* in 5th row, 1 line, with dash/dot/dash stipple    */
	/* and a stipple repeat factor of 5                  */
	glLineStipple(5, 0x1C47);  /*  dash/dot/dash  */
	drawOneLine(50.0, h - 150, 350.0, h - 150.0);

	glDisable(GL_LINE_STIPPLE);
	glFlush();
}

void reshapePolygons(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
void displayPolygons() {

	int h = glutGet(GLUT_WINDOW_HEIGHT);
	int w = glutGet(GLUT_WINDOW_WIDTH);

	//Try this: add some filled polygons. Experiment with different colors.
	//          Try different polygon modes. Also enable culling to see its effect.
	//glEnable(GL_CULL_FACE);

	//COLOR TEST
	glColor3f(0.8, 1.0, 0.2);
	glPolygonMode(GL_FRONT, GL_FILL);
	drawNGon(75, h - 225, 50, 5);
	glPolygonMode(GL_FRONT, GL_LINE);
	drawNGon(200, h - 225, 50, 6);
	glPolygonMode(GL_FRONT, GL_POINT);
	drawNGon(325, h - 225, 50, 7);
	//glCullFace(GL_FRONT);
	//RED
	glColor3f(1, 0, 0);
	glPolygonMode(GL_BACK, GL_FILL);
	drawNGon(75, h - 350, 50, 5);
	glPolygonMode(GL_BACK, GL_LINE);
	drawNGon(200, h - 350, 50, 6);
	glPolygonMode(GL_BACK, GL_POINT);
	drawNGon(325, h - 350, 50, 7);
	//GREEN
	glColor3f(0, 1, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	drawNGon(75, h - 475, 50, 5);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	drawNGon(200, h - 475, 50, 6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	drawNGon(325, h - 475, 50, 7);
	//BLUE
	glColor3f(0, 0, 1);
	glPolygonMode(GL_FRONT, GL_FILL);
	drawNGon(75, h - 600, 50, 5);
	glPolygonMode(GL_FRONT, GL_LINE);
	drawNGon(200, h - 600, 50, 6);
	glPolygonMode(GL_FRONT, GL_POINT);
	drawNGon(325, h - 600, 50, 7);
	glFlush();
}

void reshapeTriangle(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
void displayTriangle() {
	glClear(GL_COLOR_BUFFER_BIT);
	/* select white for all lines  */
	glColor3f(1.0, 1.0, 1.0);
	glPolygonMode(GL_FRONT, GL_FILL);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	int w = glutGet(GLUT_WINDOW_WIDTH);
	static GLfloat vertices[] = { 80, 100,0,
		80, 50,0,
		100, 75,0 };
	static GLfloat colors[] = { 0.5, 0.5, 0.5,
		0.5, 0.5, 0.5,
		0.5, 0.5, 0.5 };
	glColorPointer(3, GL_FLOAT, 0, colors);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glBegin(GL_TRIANGLES);
		glArrayElement(0);
		glArrayElement(1);
		glArrayElement(2);
	glEnd();
	//same thing in alternative form
	//colors points to address of colors[0]
	//glBegin(GL_TRIANGLES);
	//	glColor3fv(colors);
	//	glVertex3fv(vertices);
	//	glColor3fv(colors + 3);
	//	glVertex3fv(vertices + 3);
	//	glColor3fv(colors + 2*3);
	//	glVertex3fv(vertices + 2*3);
	//glEnd();
	glFlush();
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void reshapeIcosahedron(int w, int h) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	gluPerspective(50.0, 1, 1.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}
void displayIcosahedron() {
	glClear(GL_COLOR_BUFFER_BIT);
	/* select white for all lines  */
	glColor3f(1.0, 0.0, 0.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	//glPolygonMode(GL_FRONT, GL_FILL);
	//glDisable(GL_CULL_FACE);
	//static GLfloat vdata[12][3] = {
	//	{ -X, 0.0, Z },{ X, 0.0, Z },{ -X, 0.0, -Z },{ X, 0.0, -Z },
	//{ 0.0, Z, X },{ 0.0, Z, -X },{ 0.0, -Z, X },{ 0.0, -Z, -X },
	//{ Z, X, 0.0 },{ -Z, X, 0.0 },{ Z, -X, 0.0 },{ -Z, -X, 0.0 }
	//};
	/*static GLuint tindices[] = {
	0,12,3,
	0,27,12,
	27,15,12,
	12,15,24,
	12,24,3,
	24,30,3,
	24,9,30,
	15,9,24,
	15,6,9,
	6,21,9,
	21,30,9,
	21,18,30,
	21,33,18,
	33,0,18,
	0,3,18,
	18,3,30,
	27,0,33,
	27,33,6,
	27,6,15,
	21,6,33
	};*/
	static GLfloat vdata[] = {
		-X, 0.0, Z,
		X, 0.0, Z,
		-X, 0.0, -Z,
		X, 0.0, -Z,
		0.0, Z, X,
		0.0, Z, -X,
		0.0, -Z, X,
		0.0, -Z, -X,
		Z, X, 0.0,
		-Z, X, 0.0,
		Z, -X, 0.0,
		-Z, -X, 0.0
	};
	static GLfloat cdata[] = {
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0
	};
	//get the view vector
	GLfloat matrix[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
	float x = matrix[2]; // x
	float y = matrix[6]; // y
	float z = matrix[10]; // z
	static GLuint tindices[20][3] = {
		{ 0,4,1 },{ 0,9,4 },{ 9,5,4 },{ 4,5,8 },{ 4,8,1 },
	{ 8,10,1 },{ 8,3,10 },{ 5,3,8 },{ 5,2,3 },{ 2,7,3 },
	{ 7,10,3 },{ 7,6,10 },{ 7,11,6 },{ 11,0,6 },{ 0,1,6 },
	{ 6,1,10 },{ 9,0,11 },{ 9,11,2 },{ 9,2,5 },{ 7,2,11 }
	};
	glVertexPointer(3, GL_FLOAT, 0, vdata);
	glColorPointer(3, GL_FLOAT, 0, cdata);
	GLfloat nx, ny, nz;
	glBegin(GL_TRIANGLES);
		for (int i = 0; i < 20; i++) {

			/*GLfloat x1 = vdata[3 * tindices[i][0]];
			GLfloat y1 = vdata[3 * tindices[i][0] + 1];
			GLfloat z1 = vdata[3 * tindices[i][0] + 2];

			GLfloat x2 = vdata[3 * tindices[i][1]];
			GLfloat y2 = vdata[3 * tindices[i][1] + 1];
			GLfloat z2 = vdata[3 * tindices[i][1] + 2];

			GLfloat x3 = vdata[3 * tindices[i][2]];
			GLfloat y3 = vdata[3 * tindices[i][2] + 1];
			GLfloat z3 = vdata[3 * tindices[i][2] + 2];

			GLfloat nx = -y2 * z1 + y3 * z1 + y1 * z2 - y3 * z2 - y1 * z3 + y2 * z3;
			GLfloat ny = x2 * z1 - x3 * z1 - x1 * z2 + x3 * z2 + x1 * z3 - x2 * z3;
			GLfloat nz = -(x2*y1) + x3 * y1 + x1 * y2 - x3 * y2 - x1 * y3 + x2 * y3;

			GLfloat len = sqrt(nx*nx + ny * ny + nz * nz);
			nx /= len;
			ny /= len;
			nz /= len;*/

			nx = vdata[3*tindices[i][0]];

			ny = vdata[3*tindices[i][0]+1];

			nz = vdata[3*tindices[i][0]+2];

			nx += vdata[3*tindices[i][1]];

			ny += vdata[3*tindices[i][1]+1];

			nz += vdata[3*tindices[i][1]+2];

			nx += vdata[3*tindices[i][2]];

			ny += vdata[3*tindices[i][2]+1];
			
			nz += vdata[3*tindices[i][2]+2];
			GLfloat len = sqrt(nx*nx + ny * ny + nz * nz);
			nx /= len; ny /= len; nz /= len;
			//need to check if this face is on the back side of the icosahedron,
			//if it is then the inner product of the view vector and the current normal vector will be negative
			//and so the normal vector needs to point out in the opositte direction
			if (nx*x + ny * y + nz * z > 0) {
				glNormal3f(nx, ny, nz);
			}else{ glNormal3f(-nx, -ny, -nz); }
			
			glArrayElement(tindices[i][0]);
			glArrayElement(tindices[i][1]);
			glArrayElement(tindices[i][2]);
		}
	glEnd();
	glFlush();
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

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