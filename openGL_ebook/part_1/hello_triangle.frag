#version 330 core

// fragment shader 要求有一個 out 參數
// 不知道是不是跟上面的 in 關鍵字有關系
out vec4 FragColor;

void main() { FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); };