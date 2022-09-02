// alphablend <imageA> <image B> <x> <y> <width> <height> <alpha> <beta>
//
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv) {

  cv::Mat src1 = cv::imread(argv[1],1);
  cv::Mat src2 = cv::imread(argv[2],1);

  if( argc==9 && !src1.empty() && !src2.empty() ) {

    int    x     = atoi(argv[3]);//posicion x rectangulo roi1
    int    y     = atoi(argv[4]);//posicion y rectangulo roi1
    int    w     = atoi(argv[5]);//anchura rectangulo roi21 y roi2
    int    h     = atoi(argv[6]);//altura rectangulo roi21 y roi2
    double alpha = (double)atof(argv[7]);//valor que va a multiplicar a src1
    double beta  = (double)atof(argv[8]);//valor que va a multiplicar a src2

    cv::Mat roi1( src1, cv::Rect(x,y,w,h) );
    cv::Mat roi2( src2, cv::Rect(0,0,w,h) );

    //ro1*alpha + roi*beta y se va a mostrar con origen 0.0 y resultado roi1
    cv::addWeighted( roi1, alpha, roi2, beta, 0.0, roi1 );

    cv::namedWindow( "Alpha Blend", 1 );
    cv::imshow( "Alpha Blend", roi1 );
    cv::waitKey( 0 );
  }

  return 0;
}