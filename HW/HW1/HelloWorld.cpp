#include "glut.h"
#include<math.h>
float fTranslate;
float fRotate;
float fScale = 1.0f;								// set inital scale value to 1.0f

// A class used to represent the current point (x,y)
class Pixel
{
private:
	GLfloat x, y;
	
public:
	Pixel() {
		x = 0;
		y = 0;
	}

	void setCoords(GLfloat xCoordinate, GLfloat yCoordinate) {
		x = xCoordinate;
		y = yCoordinate;
	}

	GLfloat getx() const {
		return x;
	}

	GLfloat gety() const {
		return y;
	}

	// suppose the size of pixel is 1
	// in fact, we can implement a function using input value
	void incrementX() {
		x += 1;
	}

	// suppose the size of pixel is 1
	void decrementY() {
		y -= 1;
	}
};


/**
 * used to draw
 * 1) points gotton by bresenham algorithm
 * 2) lines to show X-Y coordinate
 * 3) midpoints of two neighboring pixels used to verify the correctness
*/
void setPixel(GLfloat xCoord, GLfloat yCoord) {
	
	// enable to adjust the size of points
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//make the pixels of point be 6
	glPointSize(6);
	
	// 1) points gotton by bresenham algo
	glBegin(GL_POINTS);
	glColor3f(1,0 , 0);
	glVertex2f(xCoord, yCoord);
	glEnd();

	// used to draw lines of coordinate
	GLfloat maxLen = 100;

	glBegin(GL_LINES);
	glColor3f(0, 0, 1);
	glVertex2f(xCoord + 0.5, maxLen);
	glVertex2f(xCoord + 0.5, -1*maxLen);
	glEnd();

	glBegin(GL_LINES);
	// glColor3f(0, 0, 1);
	glVertex2f(xCoord - 0.5, maxLen);
	glVertex2f(xCoord - 0.5, -1*maxLen);
	glEnd();

	glBegin(GL_LINES);
	// glColor3f(0, 0, 1);
	glVertex2f(maxLen,yCoord-0.5);
	glVertex2f(-1*maxLen,yCoord-0.5);
	glEnd();

	glBegin(GL_LINES);
	// glColor3f(0, 0, 1);
	glVertex2f(maxLen, yCoord + 0.5);
	glVertex2f(-1*maxLen, yCoord + 0.5);
	glEnd();

	// used to draw midpoints
	glPointSize(3);
	glBegin(GL_POINTS);

	glColor3f(0, 1, 0);
	glVertex2f(xCoord+0.5, yCoord);

	glEnd();
	glBegin(GL_POINTS);
	//glColor3f(1, 0, 0);
	glVertex2f(xCoord-0.5, yCoord);
	glEnd();

	glBegin(GL_POINTS);
	//glColor3f(1, 0, 0);
	glVertex2f(xCoord, yCoord+0.5);
	glEnd();

	glBegin(GL_POINTS);
	//glColor3f(1, 0, 0);
	glVertex2f(xCoord, yCoord-0.5);
	glEnd();
}

/**
 * used to draw symmertric points of eighth circle
*/
void circlePlotPoints(GLfloat xc, GLfloat yc, Pixel cirPt) {
	setPixel(xc + cirPt.getx(), yc + cirPt.gety());
	setPixel(xc - cirPt.getx(), yc + cirPt.gety());
	setPixel(xc + cirPt.getx(), yc - cirPt.gety());
	setPixel(xc - cirPt.getx(), yc - cirPt.gety());
	setPixel(xc + cirPt.gety(), yc + cirPt.getx());
	setPixel(xc - cirPt.gety(), yc + cirPt.getx());
	setPixel(xc + cirPt.gety(), yc - cirPt.getx());
	setPixel(xc - cirPt.gety(), yc - cirPt.getx());
}

/**
 * main function used to draw
*/
void circleMidpoint(GLfloat xc, GLfloat yc, GLfloat radius) {
	Pixel cirPt;

	// initialize the decision parameter
	GLfloat p = 1.25 - radius;

	// set initial point located in the top position
	cirPt.setCoords(0, radius);

	// initialize symmetric poits
	circlePlotPoints(xc, yc, cirPt);

	// core procedure of bresenham algorithm
	while (cirPt.getx() < cirPt.gety()) {
		
		// next point
		cirPt.incrementX();
		
		// recursive procedure
		if (p < 0) {
			p += 2 * cirPt.getx() + 1;
		}
		else
		{
			cirPt.decrementY();
			p += 2 * (cirPt.getx() - cirPt.gety()) + 1;
		}

		// draw points of eight symmetric circles
		circlePlotPoints(xc, yc, cirPt);
	}

}

/**
 * used to adjust size of screen
*/
void reshape(int width, int height)
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// to avoid width or height of graph being changed when size of screen changed
	if (width <= height) {
		glOrtho(-4, 4, -4*height/width, 4 * height / width, 0, 100);
	}
	else
	{
		glOrtho(-4*width/height, 4 * width / height, -4, 4, 0, 100);
	}

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

void idle()
{
	glutPostRedisplay();
}

void redraw()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();									// 重置变换矩阵（回到世界坐标系）

	glPushMatrix(); // 设置一个新的坐标系

	glScalef(0.15f, 0.15f, 0.0f); // 设置三个轴分别的缩放比例

	// used to draw coordinate lines, midpoint, points gotton by bresenham
	circleMidpoint(0, 0, 20);

	// draw actual circle by cyclotomic method
	// used to compare with the circle created by bresenham
	int n=1000;
	GLfloat r = 20;
	GLfloat PI = 3.1415926536f;
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	for (int i = 0; i < n; i++) {
		glVertex2f(r*cos(2 * PI / n * i), r*sin(2 * PI / n * i));
	}
	glEnd();


	glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(960,960);  
	int windowHandle
		= glutCreateWindow("Simple GLUT App");

	glutDisplayFunc(redraw);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}


