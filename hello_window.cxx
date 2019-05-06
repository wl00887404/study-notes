#include <iostream>
#include <GL/glut.h>
using namespace std;

void display();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);

float backgroundGray = 1.0f;
float teapot_size = 1.0f;
float teapot_posX = 0.0f;
float teapot_posY = 0.0f;

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowPosition(100, 100); //設定初始化視窗位置
  glutInitWindowSize(600, 600);     //設定初始化視窗大小

  glutCreateWindow("OpenGL 3D View");                                 //創立一個GLUT視窗
  glClearColor(backgroundGray, backgroundGray, backgroundGray, 1.0f); //設定清除顏色

  glutDisplayFunc(display);
  glutReshapeFunc(reshape); //註冊視窗重塑事件
  glutKeyboardFunc(keyboard);

  glutMainLoop();
  return 0;
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(backgroundGray, backgroundGray, backgroundGray, 1.0f);

  glMatrixMode(GL_MODELVIEW); //指定目前運算的矩陣為視覽座標矩陣及模塑座標矩陣
  glLoadIdentity();
  gluLookAt(0.0f, 2.0f, 5.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0); //設定相機的位置，視點，y軸向量

  glTranslatef(teapot_posX, teapot_posY, 0.0f); //將目前的矩陣乘上位移矩陣
  glColor3b(125, 0, 0);                         //設定目前所使用的顏色
  glutWireTeapot(teapot_size);                  //畫出線框茶壺

  glutSwapBuffers();
}

void reshape(int width, int height)
{
  float aspect = width * 1.0f / height;
  glMatrixMode(GL_PROJECTION);                //指定目前運算的矩陣為投影矩陣
  glLoadIdentity();                           //將目前指定的矩陣重設為單位矩陣
  glViewport(0, 0, width, height);            //視埠，將投影影像對應在視窗座標上
  gluPerspective(60.0f, aspect, 0.1f, 10.0f); //投影模式為透視，並設定其參數
}

void keyboard(unsigned char key, int x, int y)
{
  if (key == 'W' || key == 'w')
  {
    teapot_posY += 0.05f;
  }
  else if (key == 'S' || key == 's')
  {
    teapot_posY -= 0.05f;
  }
  else if (key == 'A' || key == 'a')
  {
    teapot_posX -= 0.05f;
  }
  else if (key == 'D' || key == 'd')
  {
    teapot_posX += 0.05f;
  }

  glutPostRedisplay();
}