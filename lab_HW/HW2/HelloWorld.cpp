#include "glut.h"
#include<math.h>

float fTranslate;
float fRotate;
float fScale = 1.0f;								// set inital scale value to 1.0f

//void Draw_Triangle()									// This function draws a triangle with RGB colors
//{
//	glBegin(GL_TRIANGLES);
//	// 设置顶点颜色
//	glColor3f(1.0f, 0.0f, 0.0f);
//	// 设置顶点坐标
//	glVertex3f(-1.0f, 1.0f, 0.0f);
//
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glVertex3f(-1.0f, -1.0f, 0.0f);
//	
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glVertex3f(1.0f, -1.0f, 0.0f);
//
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glVertex3f(-1.0f, 1.0f, 0.0f);
//
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glVertex3f(1.0f, -1.0f, 0.0f);
//
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glVertex3f(1.0f, 1.0f, 0.0f);
//	
//	glEnd();
//}



void MyWireCube(double dSize)
{
	double halfSize = dSize / 2;
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(halfSize, halfSize, halfSize);
	glVertex3f(halfSize, halfSize, -1.0*halfSize);
	glVertex3f(-1.0*halfSize, halfSize, -1.0*halfSize);
	glVertex3f(-1.0*halfSize, halfSize, halfSize);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(halfSize, -1.0*halfSize, halfSize);
	glVertex3f(halfSize, -1.0*halfSize, -1.0*halfSize);
	glVertex3f(-1.0*halfSize, -1.0*halfSize, -1.0*halfSize);
	glVertex3f(-1.0*halfSize, -1.0*halfSize, halfSize);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(halfSize, -1.0*halfSize, halfSize);
	glVertex3f(halfSize, halfSize, halfSize);

	glVertex3f(halfSize, -1.0*halfSize, -1.0*halfSize);
	glVertex3f(halfSize, halfSize, -1.0*halfSize);

	glVertex3f(-1.0*halfSize, -1.0*halfSize, halfSize);
	glVertex3f(-1.0*halfSize, halfSize, halfSize);

	glVertex3f(-1.0*halfSize, -1.0*halfSize, -1.0*halfSize);
	glVertex3f(-1.0*halfSize, halfSize, -1.0*halfSize);
	glEnd();

}

//画三维图形 
void Draw()
{
	//glutWireCube(1.0);
	MyWireCube(1.0);
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

	// Calculate The Aspect Ratio Of The Window
	// Perspective view
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	// Ortho view
	//glOrtho(-4, 4, -4, 4, 0, 100);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

void idle()
{
	glutPostRedisplay();
}

double timePara = 0;

void redraw()
{
	// 如果想使用线框模式
	//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();									// 重置变换矩阵（回到世界坐标系）

	//左边
	double yMovement = sin(timePara);
	timePara += 0.0004;
	glPushMatrix(); // 设置一个新的坐标系

	glTranslatef(-2.0f, yMovement, -6.0f);				// 向左平移
	glScalef(0.25, 2, 0.25);
	Draw();
	glScalef(4, 0.5, 4);

	glTranslatef(-0.375f, 0.875, 0);				// 向左平移
	glScalef(1, 0.25, 0.25);
	Draw();
	glScalef(1, 4, 4);

	glTranslatef(0, -0.875, 0);				// 向左平移
	glScalef(1, 0.25, 0.25);
	Draw();
	glScalef(1, 4, 4);

	glTranslatef(0, -0.875, 0);				// 向左平移
	glScalef(1, 0.25, 0.25);
	Draw();
	glScalef(1, 4, 4);

	glPopMatrix(); // 回到前一个坐标系

	//中间
	glPushMatrix();
	//glRotatef(19.198f, 0.0f, 1.0f, 0.0f); // 绕轴（0, 1, 0)旋转19.198°（角度制）
	glTranslatef(0.0f, 0.0f, -6.0f);
	//where you need to write 以y轴为旋转轴
	glRotatef(timePara*360, 0.0f, 1.0f, 0.0f);

	glScalef(0.25, 2, 0.25);
	Draw();
	glScalef(4, 0.5, 4);

	glTranslatef(-0.375f, 0.875, 0);				// 向左平移
	glScalef(1, 0.25, 0.25);
	Draw();
	glScalef(1, 4, 4);

	glPopMatrix();

	//右边
	glPushMatrix();
	glTranslatef(2.0f, 0.0f, -6.0f);
	//where you need to write 等比例缩放

	glScalef(fabs(yMovement) + 0.1, fabs(yMovement) + 0.1, fabs(yMovement) + 0.1);
	glScalef(0.25, 2, 0.25);
	Draw();
	glScalef(4, 0.5, 4);

	glTranslatef(-0.375f, 0.875, 0);				// 向左平移
	glScalef(1, 0.25, 0.25);
	Draw();
	glScalef(1, 4, 4);

	glTranslatef(0, -1.750, 0);				// 向左平移
	glScalef(1, 0.25, 0.25);
	Draw();
	glScalef(1, 4, 4);

	glTranslatef(-0.625f, 0.875, 0);
	glScalef(0.25, 2, 0.25);
	Draw();
	glScalef(4, 0.5, 4);

	glPopMatrix();

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


