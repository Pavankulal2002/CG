#include<stdio.h>
#include<GL/glut.h>
 float x;

void timer(int v)
{
	x=x+0.5;
	glutPostRedisplay();
	glutTimerFunc(100,timer,0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(5.0,5.0+x,0.0);
	glColor3f(0.5,0.2,0.4);
	glutWireSphere(5,120,50);
	glPopMatrix();
	glFlush();
	

}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);  //to initialize glut packages
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Sphere");
	glClearColor(1.0,1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,10.0,0.0,10.0,0.0,10.0);
	glutDisplayFunc(display);
	timer(0);
	glutMainLoop();
	return 0;


}
	
	
