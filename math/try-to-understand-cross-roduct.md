# 嘗試理解外積

## Why

以前數學課，外積都是由老師直接定義，  
並說明它的幾何意義就是法向量，  
沒道理呀，為啥這樣叉一叉就是法向量。

## 試著推導法向量

假設有向量 A = (a, b ,c), B = (e, f, g)
存在有一個法向量 C = (x, y ,z) ，求其中一個法向量？

法向量會符合內積公式

```txt

ax + by + cz = cos (π / 2) = 0
ex + fy + gz = cos (π / 2) = 0

agx + bgy + cgz = 0（同乘 g）
cex + cfy + cgz = 0（同乘 c）

(ag - ce) \* x + (bg - cf) \* y = 0（兩式相減））
(ag - ce) \* x =  (cf - bg) \* y（兩式相減））

x = (cf - bg) / (ag - ce) * y
```

同樣處理 x 以取得 y z 關係

```txt
aex + bey + cez = 0（同乘 e）
aex + afy + agz = 0（同乘 a）

(be - af) \* y + (ce - ag) \* z = 0
(ce - ag) \* z = (af - be) \* y

z = (af - be) / (ce - ag) * y
```

```txt
C = (x, y, z)  
  = ((cf - bg) / (ag - ce) \* y, y, (af - be) / (ce - ag) \* y)
  = ((cf - bg) / (ag - ce), 1, (af - be) / (ce - ag)) （同除 y）
  = ((cf - bg) / (ag - ce), 1, (be - af) / (ag - ce)) （移動 af - be 的負號）
  = ((cf - bg), (ag - ce), (be - af)) （同乘 ag - ce）
```

這就是外積公式
但外積公式好像是來自四元數
