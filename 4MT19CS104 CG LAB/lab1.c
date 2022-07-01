#include<stdio.h>
#include<GL/glut.h>
 
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(2,3);
	glColor3f(0.0,0.0,1.0);
	glVertex2i(7,7);
	glColor3f(0.0,0.0,0.0);
	glVertex2i(8,3);
	glEnd();
	glFlush();
}

int main(int argc,char **argv)
{
	printf("NAME : PAVAN , USN : 4MT19CS104");
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Points");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,10.0,0.0,10.0);
	glClearColor(1.0,1.0,1.0,0.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;


}
	
	
