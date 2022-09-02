#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
	
	cv::Mat Igray = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::Mat Inormal = cv::imread(argv[1]);

	// Read in gray image.
	//
	if( Igray.empty() ){ cout << "Can not load " << argv[1] << endl; return -1; }
    if( Inormal.empty() ){ cout << "Can not load " << argv[1] << endl; return -1; }

	// Declare the output images.
	//
	cv::Mat blur, median_blur, gaussian_blur, bilateral_filter;

    //smoothing
    cv::blur(Igray,blur,cv::Size(3,3));
    cv::medianBlur(Igray, median_blur, 3);
    cv::GaussianBlur(Igray,gaussian_blur, cv::Size(3,3), 0);
    cv::bilateralFilter(Igray, bilateral_filter,9, 10.0,10.0);//for videoprocessing 5 or less, for images 9 or less can be used(3rd param)

    cv::imshow("blur",blur);
	cv::imshow("median_blur",median_blur);
	cv::imshow("gaussian_blur",gaussian_blur);
    cv::imshow("bilateral_filter",bilateral_filter);
    cv::waitKey(0);
    //derivates
    cv::Mat sobel, laplacian;
    //src,dest, output, x derivate and y derivate
    //cv::SCHARR si luego vas a querer usar la imagen para obtener medidas entre objetos
    cv::Sobel(Igray, sobel, CV_8U,1,0);
    cv::Laplacian(Igray, laplacian, CV_8U);

    cv::imshow("sobel",sobel);
    cv::imshow("sobel",sobel);
    cv::waitKey(0);
    //image morphology

    cv::Mat erode, dilate;
    //for bolean images (or pixel value > 0 or 0)
    cv::erode(Igray, erode, cv::Mat());// often used to eliminate speackle
    cv::dilate(Igray, dilate, cv::Mat());//often used to try to find connected components
    cv::imshow("erode",erode);
    cv::imshow("dilate",dilate);
    cv::waitKey(0);
    
    //for grayscale and color images
    cv::Mat mop_open, mop_close, mop_gradient, mop_tophat, mop_blackhat;

    //tipes:cv::MOP_OPEN, cv::MOP_CLOSE, cv::MOP_GRADIENT, cv::MOP_TOPHAT, cv::MOP_BLACKHAT
    cv::morphologyEx(Inormal, mop_open, cv::MORPH_OPEN, cv::Mat());
    cv::morphologyEx(Inormal, mop_close, cv::MORPH_CLOSE, cv::Mat());
    cv::morphologyEx(Inormal, mop_gradient, cv::MORPH_GRADIENT, cv::Mat());
    cv::morphologyEx(Inormal, mop_tophat, cv::MORPH_TOPHAT, cv::Mat());
    cv::morphologyEx(Inormal, mop_blackhat, cv::MORPH_BLACKHAT, cv::Mat());

    cv::imshow("mop_open",mop_open);
    cv::imshow("mop_close",mop_close);
    cv::imshow("mop_gradient",mop_gradient);
    cv::imshow("mop_tophat",mop_tophat);
    cv::imshow("mop_blackhat",mop_blackhat);
    cv::waitKey(0);

	return 0;
}