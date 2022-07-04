#include<stdio.h>

#include<GL/glut.h>

float x1, x2, x3, x4, y1, y2, y3, y4;
int le[1000], re[1000], i, y;
void edgedetect(float x1, float y1, float x2, float y2) {
   float mx, x;
   if ((y2 - y1) != 0)
      mx = (x2 - x1) / (y2 - y1);
   x = x1;
   for (i = y1; i < y2; i++) {
      if (x <= le[i])
         le[i] = x;
      else
         re[i] = x;
      x += mx;
   }

}
void scanfill(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
   for (i = 400; i <= 800; i++) {
      le[i] = 400;
      re[i] = 400;
   }
   edgedetect(x1, y1, x2, y2);
   edgedetect(x2, y2, x3, y3);
   edgedetect(x4, y4, x3, y3);
   edgedetect(x1, y1, x4, y4);
   for (y = 400; y <= 800; y++) {
      for (i = le[y]; i <= re[y]; i++) {
         glColor3f(0.0, 1.0, 0.0);
         glBegin(GL_POINTS);
         glVertex2f(i, y);
         glEnd();
      }
   }
}

void main_menu(int c) {
   switch (c) {
   case 3:
      exit(0);
   }
}
void sub_menu(int c) {
   switch (c) {
   case 1:
      glColor3f(0.0, 0.0, 0.0);
      glBegin(GL_LINE_LOOP);
      glVertex2f(x1, y1);
      glVertex2f(x2, y2);
      glVertex2f(x3, y3);
      glVertex2f(x4, y4);
      glEnd();
      glFlush();
      break;
   case 2:
      glColor3f(1.0, 0.0, 0.0);
      glBegin(GL_LINE_LOOP);
      glVertex2f(x1, y1);
      glVertex2f(x2, y2);
      glVertex2f(x3, y3);
      glVertex2f(x4, y4);
      glEnd();
      scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
      glFlush();
      break;
   }
}
void display() {
   x1 = 400.0;
   y1 = 400.0;
   x2 = 200.0;
   y2 = 600.0;
   x3 = 400.0;
   y3 = 800.0;
   x4 = 600.0;
   y4 = 600.0;
   glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char ** argv) {
   glutInit( & argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowPosition(200, 200);
   glutInitWindowSize(500, 500);
   glutCreateWindow("Scanline Polygon fill algorithm");
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glutDisplayFunc(display);
   gluOrtho2D(0.0, 900.0, 0.0, 900.0);
   int submenu = glutCreateMenu(sub_menu);
   glutAddMenuEntry("Draw Polygon", 1);
   glutAddMenuEntry("Fill Polygon", 2);
   glutCreateMenu(main_menu);
   glutAddSubMenu("Program to", submenu);
   glutAddMenuEntry("Quit", 3);
   glutAttachMenu(GLUT_RIGHT_BUTTON);
   glutMainLoop();
}
