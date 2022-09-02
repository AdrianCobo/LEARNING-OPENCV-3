#include <opencv2/opencv.hpp>
#include <iostream>

int main( int argc, char* argv[] ) {

  cv::namedWindow( "Example 2-11", cv::WINDOW_AUTOSIZE );
  cv::namedWindow( "Log_Polar",   cv::WINDOW_AUTOSIZE );

  // ( Note: could capture from a camera by giving a camera id as an int.)
  //
  cv::VideoCapture capture( argv[1] );

  double fps = capture.get( cv::CAP_PROP_FPS );
  cv::Size size(
    (int)capture.get( cv::CAP_PROP_FRAME_WIDTH ),
    (int)capture.get( cv::CAP_PROP_FRAME_HEIGHT )
  );

  cv::VideoWriter writer;
  //el segundo parametro que le pasamos al programa es el nombre de la grabacion, tiene que
  //tener la terminacion .avi ,ademas se va a guardar en el directorio donde llames al programa
  writer.open( argv[2], cv::VideoWriter::fourcc('M','J','P','G'), fps, size );

  cv::Mat logpolar_frame, bgr_frame;
  for(;;) {

    capture >> bgr_frame;
    if( bgr_frame.empty() ) break; // end if done

    cv::imshow( "Example 2-11", bgr_frame );
    //log polar es para transformar las imagenes a un formato visible para el ser humano como jpg
    cv::logPolar(
      bgr_frame,                      // Input color frame
      logpolar_frame,                 // Output log-polar frame
      cv::Point2f(                    // Centerpoint for log-polar transformation
        bgr_frame.cols/2,             //  x
        bgr_frame.rows/2              //  y
      ),
      40,                             // Magnitude (scale parameter)
      cv::WARP_FILL_OUTLIERS           // Fill outliers with 'zero'(los valores anomalos)
    );

    cv::imshow( "Log_Polar", logpolar_frame );
    writer << logpolar_frame;

    char c = (char) cv::waitKey(33);
    if( c == 27 ) break;        // allow the user to break out
  }

  capture.release();
}