#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char** argv){
  Mat img=imread(argv[1], -1);
  if(img.empty()){
    cout<<"Kosong : "<<endl;
    return -1;
  }
  namedWindow("example1", WINDOW_AUTOSIZE);
  imshow("example1", img);
  waitKey(0);
  destroyWindow("example1");
  return 0;
}
