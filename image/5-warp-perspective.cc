#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {
  float width = 250, height = 350;
  Point2f src[4] = {
    { 109, 216 },
    { 290, 186 },
    { 151, 484 },
    { 354, 441 }
  };
  Point2f dst[4] = {
    { 0, 0 },
    { width, 0 },
    { 0, height },
    { width, height }
  };
  // 获取透视转换矩阵
  Mat trans = getPerspectiveTransform(src, dst);

  Mat img = imread("static/cards.jpg");
  Mat imgWraped;
  // 应用透视转换
  warpPerspective(img, imgWraped, trans, Size(width, height));

  // 在原图上标记应用透视转换的点
  for (int i = 0; i < 4; ++i) {
    circle(img, src[i], 5, Scalar(0, 0, 255), FILLED);
  }

  imshow("origin image", img);
  imshow("wraped image", imgWraped);
  waitKey(0);

  return 0;
}