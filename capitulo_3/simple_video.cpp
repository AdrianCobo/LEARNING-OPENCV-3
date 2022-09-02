#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

int main( int argc, char** argv ) {

  cv::namedWindow( "Example 2-3", cv::WINDOW_AUTOSIZE );
  cv::VideoCapture cap;//creamos un objeto que puede abrir y cerrar videos
  cap.open( string(argv[1]) );//indicamos que video debe abrir usando el path

  cv::Mat frame;//creamos un objeto para guardar los frames
  for(;;) {
    cap >> frame;//vamos pasando los frames
    if( frame.empty() ) break;//si no hay mas frames nos ssalimos
    cv::imshow( "Example 2-3", frame );//mostramos los frames
    //esperamos 33 ms para ver si el usuario ha pulsado alguna tecla y sino nos salimos
    if( (char) cv::waitKey(33) >= 0 ) break;
  }

  return 0;
}