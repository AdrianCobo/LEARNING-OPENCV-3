#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;

int main( int argc, char** argv ) {

  cv::namedWindow( "Example 2-10", cv::WINDOW_AUTOSIZE );

  cv::VideoCapture cap;
  if (argc==1) {
    cap.open(0);           // open the first camera
  } else {
    cap.open(argv[1]);     //abre el video que le hayas indicado
  }
  if( !cap.isOpened() ) {  // check if we succeeded
    std::cerr << "Couldn't open capture." << std::endl;
    return -1;
  }
  cv::Mat rgb, hsv, mask_rojo1, mask_rojo2, mask_rojo, mask_rojo_vis;
  cv::Mat mask_naranja, mask_naranja_vis;
  cv::Mat mask_azul, mask_azul_vis;
  for(;;) {
    cap >> rgb;

    if( rgb.empty() ) break;             // Ran out of film

    cv::cvtColor(rgb, hsv, cv::COLOR_BGR2HSV);
    
    mask_rojo_vis = cv::Mat::zeros( rgb.size(), CV_8UC3 );
    mask_naranja_vis = cv::Mat::zeros( rgb.size(), CV_8UC3 );
    mask_azul_vis = cv::Mat::zeros( rgb.size(), CV_8UC3 );
    
    cv::inRange(hsv, cv::Scalar(160, 100, 20, 0), cv::Scalar(179, 255, 255, 0), mask_rojo);
    cv::bitwise_and(rgb, rgb, mask_rojo_vis, mask_rojo);

    cv::inRange(hsv, cv::Scalar(0, 100, 20, 0), cv::Scalar(35, 255, 255, 0), mask_naranja);
    cv::bitwise_and(rgb, rgb, mask_naranja_vis, mask_naranja);

    cv::inRange(hsv, cv::Scalar(75, 100, 20, 0), cv::Scalar(140, 255, 255, 0), mask_azul);
    cv::bitwise_and(rgb, rgb, mask_azul_vis, mask_azul);

    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> jerarquia;

    std::vector<cv::Mat> all_masks = {mask_rojo,mask_naranja,mask_azul};
    int max_area_mask, second_max_area_mask, contour_max_index, second_contour_max_index;
  
    max_area_mask = 0;
    second_max_area_mask = 0;
    contour_max_index = 0;
    second_contour_max_index = 0;
    double max_area_size = 0;
    double second_max_area_size = 0;

    cv::Mat drawing_1, drawing_2;

    for(int i = 0; i < 3; i++){

      findContours( all_masks[i], contours, jerarquia, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point(0,0));
  
      for( int j = 0; j < contours.size(); j++ )
      {
        if(cv::contourArea(contours[j]) > 500 && cv::contourArea(contours[j]) > max_area_size){
          max_area_mask = i;
          contour_max_index = j;
          max_area_size = cv::contourArea(contours[j]);
          drawing_1 = cv::Mat::zeros( rgb.size(), CV_8UC3 );
          cv::drawContours( drawing_1, contours, j, cv::Scalar(255,255,255), -1, cv::LINE_8);

        }else if(cv::contourArea(contours[j]) > 500 && cv::contourArea(contours[j]) > second_max_area_size && cv::contourArea(contours[j]) < max_area_size){
          second_max_area_mask = i;
          second_contour_max_index = j;
          second_max_area_size = cv::contourArea(contours[j]);
          drawing_2 = cv::Mat::zeros( rgb.size(), CV_8UC3 );
          cv::drawContours( drawing_2, contours, j, cv::Scalar(255,255,255), -1, cv::LINE_8);
        }
      }
    }
    printf("mask 1 %d, mask 2 %d", max_area_mask, second_max_area_mask);
    //cv::Mat result, result_drawing;
    //cv::add(drawing_1, drawing_2, result_drawing);

    //cv::bitwise_and(rgb,result_drawing,result);
    //cv::imshow( "Contours", result );

    cv::namedWindow( "rojo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "rojo", mask_rojo_vis);

    cv::namedWindow( "azul", cv::WINDOW_AUTOSIZE );
    cv::imshow( "azul", mask_azul_vis);

    cv::namedWindow( "naranja", cv::WINDOW_AUTOSIZE );
    cv::imshow( "naranja", mask_naranja_vis);

    /*
    cv::namedWindow( "blanco", cv::WINDOW_AUTOSIZE );
    cv::imshow( "blanco", mask_blanco_vis);
    cv::namedWindow( "negro", cv::WINDOW_AUTOSIZE );
    cv::imshow( "negro", mask_negro_vis);
    cv::namedWindow( "rojo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "rojo", mask_rojo_vis);
    cv::namedWindow( "naranja", cv::WINDOW_AUTOSIZE );
    cv::imshow( "naranja", mask_naranja_vis);
    cv::namedWindow( "amarillo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "amarillo", mask_amarilla_vis);
    cv::namedWindow( "verde", cv::WINDOW_AUTOSIZE );
    cv::imshow( "verde", mask_verde_vis);
    cv::namedWindow( "morado", cv::WINDOW_AUTOSIZE );
    cv::imshow( "morado", mask_morado_vis);
    cv::namedWindow( "rosa", cv::WINDOW_AUTOSIZE );
    cv::imshow( "rosa", mask_rosa_vis);
    cv::imshow( "Example 2-10", rgb );
    */
    cv::waitKey( 30 );
    if( (char) cv::waitKey(33) >= 0 ) break; //salir presionando escape
  }

  return 0;
}