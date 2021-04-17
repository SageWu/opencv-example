#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int hmin = 0, hmax = 179;
int smin = 0, smax = 255;
int vmin = 0, vmax = 255;

int main() {
  Mat img = imread("static/lambo.png");
  Mat imgHSV;
  // 转换成HSV颜色空间
  cvtColor(img, imgHSV, COLOR_BGR2HSV);
  imshow("hsv image", imgHSV);

  // 创建控制面板，调节最小/最大阀值
  namedWindow("color picker", (200, 200));
  createTrackbar("hmin", "color picker", &hmin, 179);
  createTrackbar("hmax", "color picker", &hmax, 179);
  createTrackbar("smin", "color picker", &smin, 255);
  createTrackbar("smax", "color picker", &smax, 255);
  createTrackbar("vmin", "color picker", &vmin, 255);
  createTrackbar("vmax", "color picker", &vmax, 255);

  Mat imageMask;
  while (true) {
    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax, smax, vmax);
    // 筛选在指定范围内的颜色
    inRange(imgHSV, lower, upper, imageMask);
    imshow("mask image", imageMask);
    waitKey(16);
  }

  return 0;
}