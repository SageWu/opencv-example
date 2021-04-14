## 图片分辨率
VGA, HD, FHD, 4K

## 高斯模糊
可使用`convolution kernel`或`weighed kernel`。\
对图片的每个像素的每个颜色渠道进行处理，将落入 kernel 中的像素颜色值相加之后求平均值，即可得到该像素新的颜色值。\
算法速度依赖图片大小和 kernel 的大小。运行多次或使用更大的 `convolution kernel`可以得到效果更加显著的结果。