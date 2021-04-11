#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main() {
  string path = "static/test_video.mp4";
  // 从视频文件捕获数据
  VideoCapture cap(path);
  Mat img;

  while (true)
  {
    // 读取帧
    bool res = cap.read(img);
    if (!res) {
      break;
    }
    imshow("display video", img);
    waitKey(16);
  }

  return 0;
}