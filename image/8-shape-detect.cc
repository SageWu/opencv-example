#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

void getContours(Mat imgDilate, Mat img) {
  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;

  // 找出所有轮廓
  findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
  // 绘制所有轮廓
  // drawContours(img, contours, -1, Scalar(0, 0, 255), 2);

  vector<vector<Point>> contourPoly(contours.size());
  vector<Rect> boundRects(contours.size());
  for (int i = 0; i < contours.size(); ++i) {
    // 计算轮廓的面积
    double area = contourArea(contours[i]);
    if (area > 5000) {
      // 计算轮廓的周长
      double perimeter = arcLength(contours[i], true);
      // 获取轮廓近似的多边形曲线
      approxPolyDP(contours[i], contourPoly[i], 0.02 * perimeter, true);
      // 绘制轮廓
      drawContours(img, contourPoly, i, Scalar(0, 0, 255), 2);

      // 获取包含轮廓的四边形盒子
      boundRects[i] = boundingRect(contourPoly[i]);
      // 并且绘制
      rectangle(img, boundRects[i], Scalar(0, 255, 0), 2);

      // 判断形状
      string shape;
      switch (contourPoly[i].size()) {
        case 3: {
          // 有3个顶点则为三角形
          shape = "triangle";
          break;
        }
        case 4:  {
          // 计算宽高比
          float width = norm(contourPoly[i][0] - contourPoly[i][1]);  // 点到点的距离
          float height = norm(contourPoly[i][1] - contourPoly[i][2]);
          float aspRatio = width / height;
          if (aspRatio > 0.95 && aspRatio < 1.05) {
            // 宽高基本相同则为正方形
            shape = "square";
          } else {
            // 否则为长方形
            shape = "rectangle";
          }
          break;
        }
        default: {
          shape = "circle";
        }
      }
      // 形状名称绘制到图片
      putText(img, shape, boundRects[i].tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255), 1);
    }
  }
}

int main() {
  Mat img = imread("static/shapes.png");
  Mat imgGray, imgBlur, imgCanny, imgDilate;

  // 预处理
  cvtColor(img, imgGray, COLOR_BGR2GRAY);
  GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
  Canny(imgBlur, imgCanny, 135, 575);
  dilate(imgCanny, imgDilate, getStructuringElement(MORPH_RECT, Size(3, 3)));

  // 检测物体形状
  getContours(imgDilate, img);

  imshow("image", img);
  waitKey(0);

  return 0;
}