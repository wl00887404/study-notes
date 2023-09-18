// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

unsigned int buildVAO() {
  // clang-format off
  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f, 0.5f, 0.0f
  };
  // clang-format on

  // 新建一個 Vertex Buffer Object
  unsigned int VBO;

  // 1 表示建立 1 個 buffer id
  // 因為第二個參數是可以傳陣列的
  glGenBuffers(1, &VBO);

  // 選擇 buffer target
  // 最常用的是 GL_ARRAY_BUFFER 、 GL_ELEMENT_ARRAY_BUFFER
  // TODO: 這兩個是幹麻的
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  // 綁定資料
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // 新建一個 Vertex Attributes Object
  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // 設定 VBO 的解析方式
  // glVertexAttribPointer 參數詳解
  //   1st 對應 vertex shader 的 location = 0
  //   2nd 要解析成 vec1 、 vec2 、 vec3 、 vec4 哪一種
  //   3rd 是否要 clamping 成 -1 ~ 1
  //   4th 是每筆資料的間隔
  //   5th 是開頭到第一筆資料的 shift
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  return VAO;
}

unsigned int buildShader() {
  ifstream vShaderFile("hello_triangle.vert");
  stringstream vBuffer;
  vBuffer << vShaderFile.rdbuf();
  string vertexShaderCode = vBuffer.str();
  const char* vertexShaderSource = vertexShaderCode.c_str();

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  // 輸入 shader 資料
  // glShaderSource 參數詳解：
  //   1st 是 shader 本人
  //   2nd 是 shader 數量
  //   3rd 是 shader 程式碼
  //   4th 是 shader 程式碼長度， NULL 應該表示略過
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  // 檢查 vertex shader 有沒有編譯成功
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << endl;
    cout << infoLog << endl;
  }

  ifstream fShaderFile("hello_triangle.frag");
  stringstream fBuffer;
  fBuffer << fShaderFile.rdbuf();
  string fragmentShaderCode = fBuffer.str();
  const char* fragmentShaderSource = fragmentShaderCode.c_str();

  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  // 檢查 fragment shader 有沒有編譯成功
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED" << endl;
    cout << infoLog << endl;
  }

  // 把 shader 連接在一起
  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED" << endl;
    cout << infoLog << endl;
  }

  // 剛剛的 shader 用不到了，可以清除他們
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return shaderProgram;
}

int main() {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, 800, 600);

  unsigned int shaderProgram = buildShader();
  glUseProgram(shaderProgram);

  unsigned int VAO = buildVAO();
  glBindVertexArray(VAO);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 最終畫畫 function ！！
    // glDrawArrays 參數詳解
    //   1st 是 primitive
    //   2nd 是從第幾個 location 開始嗎？
    //   3rd 是有幾個點要畫
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
