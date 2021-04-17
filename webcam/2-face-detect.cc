#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

int main() {
  VideoCapture cap(0);
  Mat img;

  CascadeClassifier faceClassifier;
  // 加载模型
  faceClassifier.load("static/haarcascade_frontalface_default.xml");
  if (faceClassifier.empty()) {
    cout << "加载模型失败" << endl;
    return -1;
  }

  while (true) {
    // 读取帧数据
    bool res = cap.read(img);
    if (!res) {
      break;
    }

    vector<Rect> faces;
    // 识别人脸
    faceClassifier.detectMultiScale(img, faces, 1.1, 5);
    // 绘制包含人脸的盒子
    for (int i = 0; i < faces.size(); ++i) {
      rectangle(img, faces[i], Scalar(0, 255, 0), 2);
    }

    imshow("face dectect", img);
    waitKey(16);
  }

  return 0;
}