# Part I - Getting started

## OpenGL

- OpenGL 是操作 graphics 與 images 的 API，更精準的說起來 OpenGL 是一個由 Khronos 制定的規格。
- 可以使用 OpenGL 的版本取決於你的顯卡供應商，如果有 Bug，更新顯卡驅動程式通常能夠解決。
- OpenGL 是 state machine，state 也就是 context，就跟 Browser Canvas 一樣。
- 跟 DOM 一樣，在 OpenGL 中是操作 Objects，表示各種元件，像是 Window 之類的。

以下是安裝相關：

- C++

```bash
sudo apt-get install build-essential
```

- OpenGL

```bash
sudo apt-get install libgl1-mesa-dev
sudo apt-get install libglu1-mesa-dev
```

- GLUT (freeglut)

```bash
sudo apt-get install freeglut3-dev
```

- GLEW

```bash
sudo apt-get install libglew-dev
```

- GLFW

功能等同於 freeglut
開視窗、處理 input 等等基本功能
把 OpenGL 封裝的比較好操作

```bash
sudo apt-get install libglfw3
sudo apt-get install libglfw3-dev
```

- GLAD

OpenGL 的 driver
省略掉一堆繁瑣的設定

依據這本書要選擇 gl 3.3 版
Profile 要選 Core

<https://www.itread01.com/content/1541158995.html>

- Core-profile vs Immediate mode
  Core 是比較自由、比較難用的模式，但是作者說用這個會學比較好，所以用這個。

## Hello Triangle

- 複習 render pipeline ，介紹 shader 渲染器、 OpenGL Shading Language (GLSL) 。
- 複習 primitives 形元，也就是 GL_POINTS 、 GL_TRIANGLES 、 GL_LINE_STRIP 。
- STRIP 是帶狀，如果是用 GL_LINE ，會是 AB 、 CD 、 EF 各線段， LINE_STRIP 才會是大家連在一起。
- geometry shader 好像就是將 vertex 轉換成 primitive 的步驟耶！
- 管理頂點的 Object 叫做 Vertex Buffer Objects (VBO) ，使用 glGenBuffers 產生 。
- VBO 的 buffer type 選擇 GL_ARRAY_BUFFER ，使用 glBindBuffer 綁定。
- 最後使用 glBufferData 綁定資料。
- glBufferData 最後一個參數有三個可能
  - GL_STREAM_DRAW  是只設定一次，使用很少次。
  - GL_STATIC_DRAW 是只設定一次，使用很多次。
  - GL_DYNAMIC_DRAW  是設定很多次，使用很多次。
- 這種左是 -1.0 右是 1.0 的座標，稱之為 Normalized Device Coordinates (NDC) ，我記得以前學叫做 Clipping Space ，兩者好像不太一樣。
- 解析 VBO 方式是要用 glVertexAttribPointer 耶，~~那 VAO 到底是幹麻的~~。
- glVertexAttribPointer 的設定會吃在 VAO 裡啦，一個 VAO 可以解析個很多個 VBO。
  - 參考這張圖 <https://learnopengl.com/img/getting-started/vertex_array_objects.png>

> 再來介紹 Element Buffer Objects (EBO)
> 寫出程式太麻煩了，我先看過就好

Exercises

## Shaders

- shader 間是可以 in out 的 ， vertex shader 可以 out 給 fragment shader in ，只要變數名稱與 type 相同就好。
- uniform 則是統一的 global variable ，在常改變的值很好用，像是使用者互動的資料。
- 示範了 fragment interpolate （內插法）的三角形，就是在三角形各個頂點設定 rgb 顏色。
- 封裝了一個 Shader Class ，看起來蠻好用的！

> 我先實作了讀檔 .vert .frag 建立 Shader
> 整個實作起來還蠻麻煩的
> TODO: webGL 還有一個 vary 可以用耶，忘記他是幹麻的了

Exercises

- 把正三角形改成倒三角形
- 使用一個 uniform 讓三角形離右側螢幕一段 offset。
- Output the vertex position to the fragment shader using the out keyword and set the fragment's color equal to this vertex position (see how even the vertex position values are interpolated across the triangle). Once you managed to do this; try to answer the following question: why is the bottom-left side of our triangle black?.

## Textures
