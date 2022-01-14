# Real-Time Rendering

## Chapter 3 The Graphics Processing Unit

CH3 講的大多都是硬體發展歷史
提了一下 GPU Pipeline

```txt
Vertex Shader => Tessellation => Geometry Shader => Clipping
  => Screen Mapping => Triangle Setup & Traversal => pixel Shader => Merger
```

Tessellation 密鋪

大部分都讀過，我就先跳過了 (12/29)

### Page 29

- interpolating /ɪnˈtɝː.pə.leɪt/ 內插
- dedicated /ˈded.ə.keɪ.t̬ɪd/ 專門的
- GPD = graphics processing unit

## Chapter 4 Transforms

線性代數單元
記得這章上次看到 Gimbal Lock 萬向鎖

homogeneous notation 是齊次座標，也就是 (x, y ,z, 1)
附錄有推薦[這個網站](http://immersivemath.com/ila/index.html)

旋轉公式怎麼推導的我給忘了
rigid body transform = 只有 Translate 與 Rotate 的 transform
rigid body 是剛體，也就是不能被壓縮、變形

2D 旋轉很容易推導，就是轉換成極座標 + 合角公式
依據任何點做旋轉也很簡單，就是移動回原點 => 旋轉 => 移回去

TODO: 4.2.4 之後都還沒看

FIXME: 四元數那章超難，我記得我那時候看特別想去買一本真正的線性代數

```txt
v = (x, y) = (r * cos(a), r * sin(a))
u = (r * cos(a+b), r * sin(a+b))
= (r * (cos(a) * cos(b) - sin(a) * sin(b)), r * (sin(a) * cos(b) - cos(a) * sin(b)))
= [cos(b)  -sin(b)] * [r * cos(a)]
  [sin(b)  +cos(b)]   [r * sin(a)]
  ^^rotate matrix^^
```

### Page 57

- veer 轉向
- sufficient 充足的

### Page 60

- derive /dɪˈraɪv/ 推導

### Page 61

- orthogonal /ɔːˈθɑː.ɡən.əl/ 正交

### Page 76

- Quaternions 四元數

## Chapter 5 Shading Basics

著色基礎
以前就斷在這一章

開場介紹了 Gooch shading model
這個著色模型在 Chapter 15 會再次被提及

!! Normal 也表示法向量 !!
