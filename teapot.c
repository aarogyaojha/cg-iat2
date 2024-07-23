#include<GL/glut.h>

float ambient[] = {
  0.5,
  0.5,
  1,
  1
};
float light_pos[] = {
  2,
  2,
  2,
  1
};

void align() {
  glRotated(50, 0, 1, 0);
  glRotated(10, -1, 0, 0);
  glRotated(11, 0, 0, -1);
}

void obj(double tx, double ty, double tz, double sx, double sy, double sz) {
  align();
  glTranslated(tx, ty, tz);
  glScaled(sx, sy, sz);
  glutSolidCube(1);
  glLoadIdentity();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //obj(0, 0, 0, 1, 1, 1);
  obj(0, 0, 0.5, 1, 1, 0.04); //right wall
  obj(-0.5, 0, 0, 0.04, 1, 1); //back wall
  obj(0, -0.5, 0, 1, 0.04, 1); //bottom wall

  obj(0.2, -0.2, -0.2, 0.6, 0.04, 0.6); //table top
  obj(-0.2, -0.4, -0.3, 0.02, 0.3, 0.02); //left leg
  obj(0.2, -0.4, 0.2, 0.02, 0.3, 0.02); //right leg
  obj(0.08, -0.4, -0.1, 0.02, 0.3, 0.02); //front leg
  obj(-0.1, -0.4, 0.1, 0.02, 0.3, 0.02); //behind leg

  align();
  glTranslated(0.3, -0.1, -0.3);

  glutSolidTeapot(0.09);
  glFlush();
  glLoadIdentity();
}

void main(int argc, char ** argv) {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(700, 700);
  glutCreateWindow("Teapot");
  glutDisplayFunc(display);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
}
