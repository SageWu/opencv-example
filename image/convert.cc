#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
  string path = "static/test.jpg";
  Mat img = imread(path);
  Mat imgGray, imgBlur;
  
  // 转换颜色空间
  cvtColor(img, imgGray, COLOR_BGR2GRAY);
  // 高斯模糊
  GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);

  imshow("origin image", img);
  imshow("gray image", imgGray);
  imshow("blur image", imgBlur);
  waitKey(0);

  return 0;
}