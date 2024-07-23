#include<GL/glut.h>

#include<stdio.h>

#include<math.h>

int x1, x2, y11, y2, m;
int x, y, dx, dy, p, i;
int incx = 1, incy = 1;

void myinit() {
  glClearColor(1, 1, 1, 0);
  gluOrtho2D(0, 500, 0, 500);
}

void plotpoint(int x, int y) {
  glColor3d(1, 0, 0);
  glBegin(GL_POINTS);
  glVertex2d(x, y);
  glEnd();
}

void bresenhams(int x1, int y11, int x2, int y2) {
  x = x1;
  y = y11;
  dy = abs(y2 - y11);
  dx = abs(x2 - x1);

  m = (y2 - y11) / (x2 - x1);

  //-ve slope
  if (x2 < x1)
    incx = -1;
  if (y2 < y11)
    incy = -1;

  //if() m is less than one
  if (m < 1) {
    plotpoint(x1, y11);

    p = 2 * dy - dx;

    for (i = 0; i < dx; i++) {
      x = x + incx;

      if (p < 0) {
        p = p + 2 * dy;
        y = y;
      } else {
        p = p + 2 * (dy - dx);
        y = y + incy;
      }

      plotpoint(x, y);
    }
  }

  //if() m is greater than one
  else {
    plotpoint(x1, y11);

    p = 2 * dx - dy;

    for (i = 0; i < dy; i++) {
      y = y + incy;

      if (p < 0) {
        p = p + 2 * dx;
        x = x;
      } else {
        p = p + 2 * (dx - dy);
        x = x + incx;
      }

      plotpoint(x, y);
    }
  }
}

void displayMe() {
  glClear(GL_COLOR_BUFFER_BIT);
  bresenhams(x1, y11, x2, y2);
  glFlush();
}

int main(int argc, char ** argv) {
  printf("\nEnter the starting point:");
  scanf("%d %d", & x1, & y11);
  printf("\nEnter the end point:");
  scanf("%d %d", & x2, & y2);

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Line Drawing Algorithm");
  myinit();
  glutDisplayFunc(displayMe);
  glutMainLoop();
  return 0;
}
