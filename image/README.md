## 图片分辨率
VGA, HD, FHD, 4K

## 高斯模糊
可使用`convolution kernel`或`weighed kernel`。\
对图片的每个像素的每个颜色渠道进行处理，将落入 kernel 中的像素颜色值相加之后求平均值，即可得到该像素新的颜色值。\
算法速度依赖图片大小和 kernel 的大小。运行多次或使用更大的`convolution kernel`可以得到效果更加显著的结果。

## 正态分布
高斯分布。\
其概率密度函数由两个参数决定，分别为`mean(期望)`以及`standard deviation(标准差)`。在整个群体中，分别使用符号`μ`和`σ`。在随机样本中，分别使用`x̅`和`s`。

![正态分布-期望不同](/static/normal_distribution_means_different.webp)
![正态分布-标准差不同](/static/normal_distribution_standard_deviation_different.webp)

* 左右对称
* 经验法则：落在`-σ`到`σ`的概率为`68%`，落在`-2σ`到`2σ`的概率为`95%`，落在`-3σ`到`3σ`的概率为`99.7%`
* 标准正态分布也叫`Z-distribution`，使用`Z-scores`对比不同的样本。![Z-score](https://latex.codecogs.com/png.image?\dpi{110}&space;Z=\frac{X&space;-&space;\mu}{\sigma})