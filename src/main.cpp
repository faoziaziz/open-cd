#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

  /*image read from terminal argumen*/
  Mat img=imread(argv[1], CV_8UC1);

  /* output text buffer */
  string outText;

  /* image output after image processing */
  Mat om;

  /* for thresholding */
  // Set maxValue, blockSize and c (constant value)
  double maxValue = 255;
  int blockSize = 9;
  double c = 2;

  /* detection image */
  if(img.empty()){
    cout<<"Kosong : "<<endl;
    return -1;
  }
  
  /* Declare pointer ocr buffer*/
  tesseract::TessBaseAPI *ocr=new tesseract::TessBaseAPI();

  /* Initialize tesseract to use trainning data */
  ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);

  /* Set to page segmentation mode to PSM_AUTO(3)*/
  ocr->SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);

  /* Open input image using OpenCV */
  //Mat img=imread(argv[1], -1);

  /* Extrapolation for magnifying image. */
  resize(img, om, Size(img.cols*3, img.rows*3), 0,0, INTER_LINEAR);

  /* blurring om with gaussian blurring*/
  GaussianBlur(om, om, Size(5,5), 0);

  /* threshoding with adaptive threshold*/
  //adaptiveThreshold(om, om, 255, CV_ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,11,2);
  adaptiveThreshold(om, om, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, c);
  cout <<"Thress holding"<<endl;
  
  //namedWindow("proc1", WINDOW_AUTOSIZE);
  //imshow("proc1", om);
  //waitKey(0);
 // destroyWindow("proc1");
  /* OCR processing */

  cout<<"OCR executed"<<endl;


  ocr->SetImage(om.data, om.cols, om.rows, 3, om.step);
  outText = string(ocr->GetUTF8Text());
  cout<<"\n============================"<<endl;
  cout<<outText<<endl;


 
  return 0;
}
