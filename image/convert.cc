#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
  string path = "static/test.jpg";
  Mat img = imread(path);
  Mat imgGray;
  
  // 转换颜色空间
  cvtColor(img, imgGray, COLOR_BGR2GRAY);

  imshow("origin image", img);
  imshow("gray image", imgGray);
  waitKey(0);

  return 0;
}