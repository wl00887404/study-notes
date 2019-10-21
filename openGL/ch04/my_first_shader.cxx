#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

// 下面這些不知道再幹麻
GLuint triangle_buffer;
GLuint triangle_vao;
GLuint program;

static const GLfloat triangle_vertices[] = {
    -0.4f, -0.4f, 0.0f, 1.0f, 0.0f, 0.4f, 0.0f, 1.0f, 0.4f, -0.4f, 0.0f, 1.0f,
};

char *vsSource = R"glsl(
	#version 400

	layout (location = 0) in vec4 position;

	void main()
	{
		gl_Position = position;
	}
)glsl";
char *fsSource = R"glsl(
	#version 400

	out vec4 color;

	void main()
	{
		color = vec4(1.0, 0.0, 0.0, 1.0);
	}
)glsl";

void init();
void display();

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(600, 600);
  glutCreateWindow("4.2.Shader");

  init();
  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}

void init() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glewInit();

  GLuint vs = glCreateShader(GL_VERTEX_SHADER);
  GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vs, 1, &vsSource, NULL);
  glShaderSource(fs, 1, &fsSource, NULL);

  glCompileShader(vs);
  glCompileShader(fs);

  program = glCreateProgram();

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);

  // 下面這些不知道在幹麻
  // 好像在設定頂點資料吧
  glGenVertexArrays(1, &triangle_vao);
  glBindVertexArray(triangle_vao);
  glGenBuffers(1, &triangle_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, triangle_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices) * sizeof(float),
               &triangle_vertices[0], GL_STATIC_DRAW);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glUseProgram(program);
  glBindVertexArray(triangle_vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glutSwapBuffers();
}