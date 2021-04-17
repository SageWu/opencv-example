#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main() {
  string path = "static/test.jpg";
  Mat img = imread(path);
  Mat imgBlur, imgCanny;

  GaussianBlur(img, imgBlur, Size(3, 3), 3);
  // 边界检测
  Canny(imgBlur, imgCanny, 50, 150);
  // dilate 扩张像素点
  // erode  侵蚀像素点

  imshow("origin image", img);
  imshow("edges", imgCanny);
  waitKey(0);

  return 0;
}