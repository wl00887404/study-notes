#include <iostream>
#include <GL/glut.h>
using namespace std;
void display();

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(600, 600);
  glutCreateWindow("4.1.Basic");
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_TRIANGLES);
  glVertex2f(-0.4f, -0.4f);
  glVertex2f(0.0, 0.4);
  glVertex2f(0.4, -0.4);
  glEnd();
  glutSwapBuffers();
}