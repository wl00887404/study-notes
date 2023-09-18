# [GAMES101-现代计算机图形学入门-闫令琪](https://www.bilibili.com/video/BV1X7411F744?p=3)

在 Blibli 上真的很讚的教學

網站在 [這邊](https://sites.cs.ucsb.edu/~lingqi/teaching/games101.html)

## Episode 4

這章繼續講 transform
多講了一個 羅德里格旋轉公式 Rodrigue's Rotation Formula
在網站上有附證明

四元數 quaternion 在旋轉上的應用
除了避免萬向鎖
還可以很好做旋轉的插值

相機定義需要：

- 位置 Position
- Look-at / gaze direction
- Up direction

View / Camera Transformation 定義成：

- 相機移到原點
- Up 對齊 Y，Look-at 對齊 -Z

-Z 是約定俗成的事情

在將向量轉到 Y 與 -Z 不好寫

倒過來想把 X to g x t, Y to t, Z to -g 比較好做
再轉置矩陣，取得逆旋轉矩陣（因為旋轉矩陣是正交矩陣）

再來講正交投影與透視投影

正交投影就是直接去掉 Z 軸
以處理 z-index
因為相機看向 -Z
所以 Z 越大會越進

透視投影是以四角錐 frustum 為概念
把四角錐 frustum 壓成長方體 cuboid
再進行正交投影

正交投影完全看不懂 = =
回頭去看虎書 ch4

## 虎書 ch4

> recede  /rɪˈsiːd/ 逐漸遠離；變得模糊，逐漸淡漠
> emanates  /ˈem.ə.neɪt/ 表現；顯示
> whereas  /werˈæz/ 儘管；但是；卻
> underlying  /ˌʌn.dɚˈlaɪ.ɪŋ/ 暗含的；深層的；潛在的
> perpendicular /ˌpɝː.pənˈdɪk.juː.lɚ/ 垂直的，成直角的

### Ray Tracing

- Object-order Rendering:
  Each object is considered in turn, and for each object all the pixels that it influences are found and updated.
- Image-order Rendering:
  Each pixel is considered in turn, and for each pixel all the objects that influence it are found and the pixel value is computed.
  Image-order is simpler to get working and more flexible in the effects that can be produced.

### The Basic Ray-Tracing Algorithm

- Viewing Ray
  Each pixel “looks” in a different direction,
  and any object that is seen by a pixel must intersect the viewing ray,
  a line that emanates from the viewpoint in the direction that pixel is looking.
- Ray Generation
  Which computes the origin and direction of each pixel’s viewing ray based on the camera geometry.
- Ray Intersection
  Which finds the closest object intersecting the viewing ray.
- Shading
  Which computes the pixel color based on the results of ray inter-section.
- Parallel Projection
  It is the simplest projection, which 3D points are mapped to 2D by moving them along a projection direction until they hit the image plane.
  Parallel projections are often used for mechanical and architectural drawings,
  because they keep parallel lines parallel and they preserve the size and shape of planar objects that are parallel to the image plane.
- Orthographic V.S. Oblique
  If the image plane is perpendicular to the view direction, the projection is called orthographic; otherwise it is called oblique.
