// version 330 表示使用 OpenGL 3.3
#version 330 core

layout(location = 0) in vec3 aPos;

void main() {
  // gl_Position 是最後輸出的位置
  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}