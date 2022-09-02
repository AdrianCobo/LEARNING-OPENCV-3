//Exercises_8_1.cpp Exercises at end of Chapter 8
//1
#include <opencv2/opencv.hpp>
#include <iostream>

void help(const char **argv) {
	std::cout << "\n\n"
		<< "This program solves the Exercise 1 at the end of Chapter 8 \n"
		<< "Call:\n"
		<< argv[0] << " <path/video_name>\n\n"
		<< "For example: ./" << argv[0] << " ../tree.avi\n"
		<< std::endl;
}

int main( int argc, const char** argv )
{
	help(argv);
	if(argc < 2) {
		std::cout << "\nERROR: You had too few parameters.\n" << std::endl;
		return -1;
	}
	/************************************************************************/
	/* 1.  Create a program that 
	(1) reads frames from a video, 
	(2) turns the result to gray‐scale,  and 
	(3) performs  Canny  edge  detection  on  the  image.  
	Display  all  three stages of processing in three different windows, with each window appropriately
	named for its function.
	a.  Display  all  three  stages  of  processing  in  one  image.  (Hint:  create  another
	image of the same height but three times the width as the video frame. Copy
	the  images  into  this,  either  by  using  pointers  or  (more  cleverly)  by  creating
	three new image headers that point to the beginning of and to one-third and
	two-thirds of the way into the imageData. Then use Mat::copyTo().)
	b.  Write  appropriate  text  labels  describing  the  processing  in  each  of  the  three
	slots.*/
	/************************************************************************/
	
	cv::VideoCapture capture; 
	if(!capture.open(argv[1])){
		std::cout << "Could not open " << argv[1] << std::endl;
		return 1;
	}
	double rate=capture.get(cv::CAP_PROP_FPS);
	cv::Mat MatFrame;
	cv::Mat MatGray;
	cv::Mat MatCanny;
	int delay=1000/rate;
	std::cout << "rate = " << rate << ", delay = " << delay << std::endl;
	std::cout << "\nEsq to exit, or let it run out, then any key to release capture and exit.\n" << std::endl; 
	int frame_count = 0;
	while(1)
	{
		capture >> MatFrame;
		if( !MatFrame.data ) {
			std::cout << "Done with capture" << std::endl;
			break;
		}

		//(1)
		cv::imshow("Raw Video",MatFrame);
		//(2)
		cv::cvtColor(MatFrame,MatGray,cv::COLOR_BGR2GRAY);
		cv::imshow("Gray Video",MatGray);
		//(3)
		cv::Canny(MatGray,MatCanny,100,255);
		cv::imshow("Canny Video",MatCanny);
		//question a
		cv::Mat MatAll(MatFrame.rows,3* MatFrame.cols  ,CV_8UC3,cv::Scalar::all(0));
		cv::cvtColor(MatGray,MatGray,cv::COLOR_GRAY2BGR);
		cv::cvtColor(MatCanny,MatCanny,cv::COLOR_GRAY2BGR);
		cv::Mat MatSub = MatAll.colRange(0, MatFrame.cols);
		MatFrame.copyTo(MatSub);
		MatSub = MatAll.colRange( MatFrame.cols,2*MatFrame.cols);
		MatGray.copyTo(MatSub);
		MatSub = MatAll.colRange(2*MatFrame.cols,3*MatFrame.cols);
		MatCanny.copyTo(MatSub);
		//question b
		cv::Scalar color = CV_RGB(255,0,0);
		cv::putText(MatAll,"raw video",cv::Point(50,30),cv::FONT_HERSHEY_DUPLEX,1.0f,color);
		cv::putText(MatAll,"gray video",cv::Point(50+MatFrame.cols,30),cv::FONT_HERSHEY_DUPLEX,1.0f,color);
		cv::putText(MatAll,"canny video",cv::Point(50+2*MatFrame.cols,30),cv::FONT_HERSHEY_DUPLEX,1.0f,color);
		cv::imshow("all Video",MatAll);

		if ((cv::waitKey(delay) & 255) == 27)
			break;			
	}
	cv::waitKey();
	capture.release();
	return 0;

}