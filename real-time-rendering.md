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
rigid body transform = 只有 translate 與 rotate 的 transform
rigid body 是剛體，也就是不能被壓縮、變形
rigid body transform 也是 affine map 仿射變換
transform 與 rotate 底部都是 0 0 1 有一定的結構
仿射變換等於先 rotate 再 translate

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

看了 [GAMES101-现代计算机图形学入门-闫令琪](https://www.bilibili.com/video/BV1X7411F744?p=3) 解釋為什麼要有齊次座標

因為在操作平移時不是線性變換（他是加法不是乘法）
齊次座標是一個很好的解決辦法

2D point = (x, y, 1)
2D vector = (x, y, 0)

點的 1 恰巧也符合以下情境

vector + vector = vector
point  + vector = point
point  - point = vector

point + point 再定義
point = (x, y, w)
如果最後 w 大於 1，那 x, y 可以同除 w
所以 point + point 就會是兩點的中點

妙呀，老師講得太好了

### Page 57

- veer 轉向
- sufficient 充足的

### Page 60

- derive /dɪˈraɪv/ 推導

### Page 61

- orthogonal /ɔːˈθɑː.ɡən.əl/ 正交

### Page 76

- Quaternions 四元數

在 bilibili 圖形學也沒介紹
四元數是很古老的東西
只說了可以解決萬向鎖
還有做內插很好用

## Chapter 5 Shading Basics

著色基礎
以前就斷在這一章

開場介紹了 Gooch shading model
這個著色模型在 Chapter 15 會再次被提及

!! Normal 也表示法向量 !!

<!-- 2022/2/19 繼續讀 -->
<!-- 前面複習了一點 OpenGL -->

PBR (Physically Based Render) 是 Chapter 9 ~ 14
NPR (Non Physically based Render) 則是 Chapter 15

Gooch shading model 的主要點子是用表面法向量做比較
如果表面法向量與光向夾角小，顏色越溫暖
相反則顏色越冰冷

```txt
最終顏色 = s * 高亮顏色 + (1 - s) * (t * 暖色 + (1 - t) * 冷色)

冷色 = (0, 0, 0.55) + 0.25 * 表面顏色
暖色 = (0.3, 0.3, 0) + 0.25 * 表面顏色
高亮顏色 = (1, 1, 1)

t = ((表面法向量與光向量內積) + 1) / 2
r = 2 * (表面法向量與光向量內積) * 表面發法向量 - 光向量
s = clamp((100 * (r 與相機向量的內積) - 97), 0, 1)
```

史丹佛大學有提供一系列的測試用 3D 模組
<http://graphics.stanford.edu/data/3Dscanrep/#uses>

使用內積是 shade 超級常見的作法

書中很常用縮寫表示向量：

- n：表面法向量（物體往外）
- l：與光線向量（物體往外）
- v：與相機香量（物體往外）

在 PBR，要是 n 與 l 超過 90 度就不會對顏色有影響
因此會先做內積，要是是負值，就不用處理。

光源影響常見做得法是

``` txt
最終顏色 = 不被光影響的部份(n, v) + all(光的顏色 * 被光照影影響的部份(l, n, v))
```

Directional Lights 是方向光
像是太陽，從超遠距離來，不會改變方向，顏色是常數

Punctual Lights 是點光源

喔喔
計算一個向量長度
可以直接內積同樣的向量開根號
靠北，阿不就是 sqrt(x ^ 2 + y ^ 2)
這樣的 normalize 在 GLSL 應該是有內建

Point/Omni Lights 在書中特別指另一種點光源
這種點光源與 Figure 5.4 一樣
用 ray density 會改變光的強弱
射線會呈現像四角錐
離點光越遠，呈現的面積也會越大，光線也就越弱
稱之為 [inverse-square light attenuation](https://zh.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E5%8F%8D%E6%AF%94%E5%AE%9A%E5%BE%8B)

光的強度與距離平方成反比

```txt
光強度 (r) = 光常數 * (距離常數 / r) ^ 2
```

這個公式會有兩個問題
第一是距離 r 可能會變成 0，解法是在 r 上加上一個常數 e，或是限制最小值
第二是超遠距離依然會有光強度，解法是乘上一個 [windowing function](https://zh.wikipedia.org/wiki/%E7%AA%97%E5%87%BD%E6%95%B0) ，讓最大值 r 可以壓到 0

有的渲染系統為了效能不是採用 inverse-square light attenuation
