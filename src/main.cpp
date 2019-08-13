/**
 *  Ini merupakan testing untuk membaca file video 
 *  dengan menggunakan opencv
 * 
*/

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace std;
using namespace cv;

int main(int argc, char** argv){
  namedWindow("Example3 ", WINDOW_AUTOSIZE);
  VideoCapture cap;
  cap.open(string(argv[1]));

  Mat frame;
  for(;;){
    cap>>frame;
    if(frame.empty())break;
    imshow("exampler", frame);
    if(waitKey(33)>=0)break;
  }
  return 0;
}
