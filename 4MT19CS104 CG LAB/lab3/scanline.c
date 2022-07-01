#include<stdio.h>
#include<GL/glut.h>
float x1,x2,x3,x4,y1,y2,y3,y4;
int le[1000],re[1000];

void submenu(int c)
{
switch(c)
{
	case 1 :
		glBegin(GL_LINE_LOOP);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
		glEnd();
		glFlush();
		break;

	case 2 :
		glbegin(GL_LINE_LOOP);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
		glEnd();
		scanfill(x1,y1,x2,y2,x3,y3,x4,y4);
		glFlush();
		break;
	case 3 :
		exit(0);
}
}


void display()
{
	x1=400;
	y1=400;
	x2=200;
	y2=600;
	x3=400;
	y3=800;
	x4=600;
	y4=600;
	glColor(GL_COLOR_BUFFER_BIT);
}


void scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
	int i,y;
	for(i=400;i<=800;i++)
	{
		le[i]=400;
		re[i]=400;
	}
	edgedetect(x1,y1,x2,y2);
	edgedetect(x2,y2,x3,y3);
	edgedetect(x4,y4,x3,y3);
	edgedetect(x1,y1,x4,y4);

	for(y=400;y<=800;y++)
	{
		for(i=le[i];i<=re[y];i++)
		{
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_POINTS);
			glVertex(i,y);
			glEnd();
		}
	}

}

void edgedetect(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
	float mx,x;
	int i;
	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	x=x1;
	for(i=y1;i<=y2;i++)
	{
		if(x<=le[i])
		{
			le[i]=x;
		}
		else
		{
			re[i]=x;
		}		
		x+=mx;
	}
}


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glutDisplayFunc(display);

	int submenu=glutCreateMenu(sub_menu);
	glutAddMenuEntry("Draw Polygon",1);
	glutAddMenuEntry("Fill polygon",2);
	glutCreateMenu(main_menu);
	glutAddSubMenu("Program to",submenu);
	glutAddMenuEntry("Quit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}
