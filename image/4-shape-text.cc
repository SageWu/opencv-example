#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main() {
  Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));

  // 绘制圆
  circle(img, Point(250, 250), 50, Scalar(0, 0, 0), FILLED);
  // 绘制四边形
  rectangle(img, Rect(250, 250, 50, 50), Scalar(255, 0, 0), FILLED);
  // 绘制线条
  line(img, Point(250, 250), Point(250, 200), Scalar(0, 255, 0), 2);
  // 绘制文本
  putText(img, "Hello World", Point(250, 100), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255), 2);

  imshow("img", img);
  waitKey(0);

  return 0;
}