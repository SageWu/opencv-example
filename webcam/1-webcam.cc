#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {
  // 从第一个摄像头捕获数据
  VideoCapture cap(0);
  Mat img;

  while (true)
  {
    // 读取帧
    bool res = cap.read(img);
    if (!res) {
      break;
    }
    imshow("webcam", img);
    waitKey(16);
  }

  return 0;
}