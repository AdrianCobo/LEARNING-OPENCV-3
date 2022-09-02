#include <opencv2/opencv.hpp> //Include file for every supported OpenCV function

int main( int argc, char** argv ) {
  cv::Mat img = cv::imread(argv[1],-1);//lee la foto y tambien detecta el formato por el nombre
  if( img.empty() ) return -1;//si no existe la foto
  //abrimos una ventana con ese nombre ademas se creara con un tamaño automatico por el flag cv::WINDOW_AUTOSIZE
  cv::namedWindow( "Example 2-1", cv::WINDOW_AUTOSIZE );   
  cv::imshow( "Example 2-1", img );//cargamosla imagen en la ventana creada
  // esperamos a que se pulse una tecla, si ponemos un numero mayor que 0 espera esos milisegundos
  cv::waitKey( 0 );
  cv::destroyWindow( "Example 2-1" );//destruimos la ventana
  return 0;
}