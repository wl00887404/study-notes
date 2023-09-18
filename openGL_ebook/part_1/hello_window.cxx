// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <iostream>
using namespace std;

// 當視窗 resize 的 callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

// key 相關事件
void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

int main() {
  glfwInit();

  // 設定 OpenGL 版本
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // 設定 OpenGL 成 Core 模式（相對是 Immediate Mode）
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // macOS 需要這行相容性
  // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // 開啟一個 Window !
  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

  // 開失敗了 GG
  if (window == NULL) {
    cout << "Failed to create GLFW window" << endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  // 檢查 GLAD 有沒有啟動成功
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    cout << "Failed to initialize GLAD" << endl;
    return -1;
  }

  // View Port 不用解釋了吧
  glViewport(0, 0, 800, 600);

  // 註冊視窗 resize 的 callback
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // 讓 glfw 無限循環
  // 保持 Window 開啟
  while (!glfwWindowShouldClose(window)) {
    // 註冊 input 事件
    processInput(window);
    // 這邊可以放一些渲染指令

    // 設定清除的顏色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // 另外還有 GL_DEPTH_BUFFER_BIT 、 GL_STENCIL_BUFFER_BIT
    // 分別是清除其他區域的
    // FIXME: DEPTH_BUFFER 與 STENCIL_BUFFER 是三小
    glClear(GL_COLOR_BUFFER_BIT);

    // 換 Buffer 以及檢查事件
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
