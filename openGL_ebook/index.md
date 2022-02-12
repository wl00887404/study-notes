# Learn OpenGL - Graphics Programming

> <https://learnopengl.com/>
> TODO: 還有 <https://thebookofshaders.com/04/?lan=ch> 可以看

## Part I - Getting started

### 2. OpenGL

- OpenGL 是操作 graphics 與 images 的 API ，更精準的說起來 OpenGL 是一個由 khronos 制定的規格。
- 可以使用 OpenGL 的版本取決於你的顯卡供應商，如果有 Bug ，更新顯卡驅動程式通常能夠解決。
- OpenGL 是 state machine ， state 也就是 context ，就跟 Browser Canvas 一樣。
- 跟 DOM 一樣，在 OpenGL 中是操作 Objects ，表示各種元件，像是 Window 之類的。

以下是安裝相關：

#### C++

```bash
sudo apt-get install build-essential
```

#### OpenGL

```bash
sudo apt-get install libgl1-mesa-dev
sudo apt-get install libglu1-mesa-dev
```

#### GLUT (freeglut)

```bash
sudo apt-get install freeglut3-dev
```

#### GLEW

```bash
sudo apt-get install libglew-dev
```

#### GLFW

功能等同於 freeglut
開視窗、處理 input 等等基本功能
把 OpenGL 封裝的比較好操作

```bash
sudo apt-get install libglfw3
sudo apt-get install libglfw3-dev
```

#### GLAD

OpenGL 的 driver
省略掉一堆繁瑣的設定

依據這本書要選擇 gl 3.3 版
Profile 要選 Core

<https://www.itread01.com/content/1541158995.html>

- Core-profile vs Immediate mode
  Core 是比較自由、比較難用的模式，但是作者說用這個會學比較好，所以用這個。

### 5. Hello Triangle

- 老樣子 render pipeline ，介紹 shader 渲染器、 OpenGL Shading Language (GLSL) 。
- 老樣子提了 primitives 形元，也就是 GL_POINTS 、 GL_TRIANGLES 、 GL_LINE_STRIP 。
- 管理頂點的 Object 叫做 Vertex Buffer Objects (VBO) ，使用 glGenBuffers 產生 。
- VBO 的 buffer type 選擇 GL_ARRAY_BUFFER ，使用 glBindBuffer 綁定。
- 最後使用 glBufferData 綁定資料。
- 這種左是 -1.0 右是 1.0 的座標，稱之為 Normalized Device Coordinates (NDC) ，我記得以前學叫做 Clipping Space ，兩者好像不太一樣。
