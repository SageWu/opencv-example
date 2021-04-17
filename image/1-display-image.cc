#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main() {
  string path = "static/test.jpg";
  // 读取图片
  Mat img = imread(path);
  // 显示图片
  imshow("show image", img);
  // 等待按键
  waitKey(0);

  return 0;
}