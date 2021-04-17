#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main() {
  string path = "static/test.jpg";
  Mat img = imread(path);
  Mat imgResized;

  // 更改图片大小
  // resize(img, imgResized, Size(width, height));
  resize(img, imgResized, Size(), 0.5, 0.5);

  // 裁剪图片
  Rect box(100, 100, 100, 100);
  Mat imgCroped = img(box);

  imshow("origin img", img);
  imshow("resized img", imgResized);
  imshow("croped img", imgCroped);
  waitKey(0);

  return 0;
}