#include "glut.h"

float fTranslate;
float fRotate;
float fScale = 1.0f;								// set inital scale value to 1.0f


//use to draw a quad
//(x1,y1) is the point at the upper right corner
//(x2,y2) is the point at the lowe left corner
//use multiple color
void Draw_Quads(float x1,float y1,float x2,float y2)							
{
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x1, y1, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(x2,y1,  0.0f);
	
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(x2,y2, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x1, y2,0.0f);

	glEnd();
}

void reshape(int width, int height)
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	glOrtho(-4, 4, -4, 4, 0, 100);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

void idle()
{
	glutPostRedisplay();
}

void redraw()
{
	// 如果想使用线框模式
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();									// 重置变换矩阵（回到世界坐标系）

	glPushMatrix(); // 设置一个新的坐标系
	glTranslatef(0.0f, 0.0f, 0.0f);				// 向左平移
	glScalef(0.5f, 0.5f, 0.5f); // 设置三个轴分别的缩放比例


	//the last three number of my student ID is '370'

	//define the initial points to draw
	//draw three horizontal lines of '3' 
	float x1 = 0, y1 = 0, x2 = -1, y2 = -0.1;
	Draw_Quads(x1, y1, x2, y2);
	y1 -= 1;
	y2 -= 1;
	Draw_Quads(x1, y1, x2, y2);

	y1 -= 1;
	y2 -= 1;
	Draw_Quads(x1, y1, x2, y2);

	//draw one vertical line of '3'
	x2 = -0.1;
	y1 = 0;
	Draw_Quads(x1, y1, x2, y2);

	//draw the horizontal line of '7'
	x1 = 2;
	y1 = 0;
	x2 = 1;
	y2 = -0.1;
	Draw_Quads(x1, y1, x2, y2);

	//draw  the vertical line of '7'
	x2 = x1-0.1;
	y2 = -2.1;
	Draw_Quads(x1, y1, x2, y2);

	//draw two vertical lines of '0' 
	x1 = 4;
	y1 = 0;
	x2 = x1 - 0.1;
	y2 = -2.1;
	Draw_Quads(x1, y1, x2, y2);

	x1 -= 1;
	x2 = x1 - 0.1;
	Draw_Quads(x1, y1, x2, y2);

	//draw two horizontal lines of '0'
	x1 = 4;
	y1 = 0;
	x2 = 3;
	y2 = -0.1;
	Draw_Quads(x1, y1, x2, y2);

	x1 = 4;
	y1 = -2;
	x2 = 3;
	y2 = -2.1;
	Draw_Quads(x1, y1, x2, y2); //over
	
	glPopMatrix(); // 回到前一个坐标系

	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(640, 480);  
	int windowHandle
		= glutCreateWindow("Simple GLUT App");

	glutDisplayFunc(redraw);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}