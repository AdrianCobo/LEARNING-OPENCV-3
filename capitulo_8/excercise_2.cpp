/*
Create a program that reads in and displays an image. When the user’s mouse
clicks on the image, read in the corresponding pixel values (blue, green, red) and
write those values as text to the screen at the mouse location.
a. For the program of Exercise 2, display the mouse coordinates of the individual
image when clicking anywhere within the three-image display.
*/

#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

void on_click(int event, int x, int y, int flags, void* image)
{
    if (event != cv::EVENT_LBUTTONDOWN)
        return;
        
    cv::Mat* p_image = static_cast<cv::Mat*>(image);
    auto pixel = p_image->at<cv::Vec3b>(y, x);
    std::string value;
    value << cv::format(pixel, cv::Formatter::FMT_C);
    //std::cout << value << std::endl;
    cv::putText(*p_image, value, cv::Point(x, y), cv::FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(170, 15, 225), 2);
    std::cout << pixel << std::endl;
    
    cv::imshow("8.2", *p_image);
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "expects exactly one argument: filename" << std::endl;
        return -1;
    }
    
    cv::Mat image = cv::imread(argv[1]);
    if (image.empty())
    {
        std::cout << "provided file is not an image" << std::endl;
        return -2;
    }
    
    cv::namedWindow("8.2");
    cv::setMouseCallback("8.2", on_click, &image);
    cv::imshow("8.2", image);
    cv::waitKey(0);
    cv::destroyWindow("8.2");
    return 0;
}