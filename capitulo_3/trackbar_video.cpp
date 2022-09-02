#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int g_slider_position = 0;//indica la posicion del trackbar slider
int g_run = 1;//muestra nuevos frames mientras sea distinto de 0
int g_dontset = 0; //nos permite actualizar la posicion del trackbar sin cambiar el g_run
//si g_run es igual a 1, se para la reproduccion y se avanzan los frames de 1 en uno,
// si g_run es igual a -1, se reproduce automaticamente

cv::VideoCapture g_cap;

void onTrackbarSlide( int pos, void *) {

  g_cap.set( cv::CAP_PROP_POS_FRAMES, pos );//indicamos el frame del video numero posicion

  if( !g_dontset )
    g_run = 1;
  g_dontset = 0;

}

int main( int argc, char** argv ) {

  cv::namedWindow( "Example 2-4", cv::WINDOW_AUTOSIZE );
  g_cap.open( string(argv[1]) );
  int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
  int tmpw   = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
  int tmph   = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
  cout << "Video has " << frames << " frames of dimensions("
       << tmpw << ", " << tmph << ")." << endl;

  cv::createTrackbar("Position", "Example 2-4", &g_slider_position, frames,
                 onTrackbarSlide);

  cv::Mat frame;
  for(;;) {

    if( g_run != 0 ) {

      g_cap >> frame; if(frame.empty()) break;
      int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
      g_dontset = 1;//al avanzar el frame indicamos que esta desactualizado

      cv::setTrackbarPos("Position", "Example 2-4", current_pos);//actualizamos el trackbar
      cv::imshow( "Example 2-4", frame );

      g_run-=1;//cambaimos la variable grun

    }

    char c = (char) cv::waitKey(10);
    if( c == 's' ) // single step
      {g_run = 1; cout << "Single step, run = " << g_run << endl;}
    if( c == 'r' ) // run mode
      {g_run = -1; cout << "Run mode, run = " << g_run <<endl;}
    if( c == 27 )//si se presiona escape
      break;

  }
  return(0);

}