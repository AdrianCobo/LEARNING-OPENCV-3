#include <iostream>
#include <opencv2/core.hpp>

using namespace cv;


/* 1
a) choose negative floating point number
b) abs(n), round(n), ceil(n), floor(n)
c) generate some random numbers
d) convert: Point2f->Point->Point2f
*/

void _1()
{
    float f;
    std::cout << "gib negative float plz: ";
    std::cin >> f;
    
    std::cout << "abs, round, ceil, floor:" << std::endl;
    std::cout << cv::abs(f) << std::endl << cvRound(f) << std::endl << cvCeil(f) << std::endl << cvFloor(f) << std::endl;  
    
    std::cout << "the randomness: " << std::endl;
    cv::RNG rng;
    for (auto i = 0; i < 20; ++i)
    {
        std::cout << rng.uniform(0., 1.) << " " << rng.uniform(0, 25) << " " << rng.uniform(0.f, 1.f) << " " << rng.gaussian(0.25) << std::endl;
    }
    
    cv::Point2f p { 1.25f, -2.5f };
    cv::Point p_ { p };
    cv::Point2f p__ { p_ };
    
    std::cout << "p2f: " << p << " p2f->p: " << p_ << " p->p2f: " << p__ << std::endl;
}

/*
a) create 3x3 matrix and 3 component vector with "shorthands"
b) multiply yes/no? why?
*/
void _2()
{
    std::cout << "matrix multiplication exercise 2" << std::endl;
    auto m = cv::Matx33f::eye();
    auto v = cv::Vec3f(1.25f, -0.66f, 0.4f);
    
    // multiplication mat*vec works because opencv vectors are a specialization of opencv matrices
    auto p = m * v; 
    
    // multiplication vec*mat does not work
    // auto p = v * m;
    std::cout << p << std::endl;
}

/*
a) create 3x3 matrix and 3 component vector from explicit template instantiations
b) m * v yes/no? why?
c) what happens when casting the vector to a 3x1 matrix?
*/
void _3()
{
    std::cout << "matrix multiplication exercise 3" << std::endl;
    auto m = cv::Matx<float, 3, 3>::eye();
    auto v = cv::Vec<float, 3> {1.25f, -0.66f, 0.4f};
    
    auto p = m * v;
    std::cout << p << std::endl;
    
    auto q = m * (cv::Matx<float, 3, 1>)v; // q == p, but is a matrix and not a vector.
    std::cout << q << std::endl; 
}

int main(int argc, char** argv)
{  
    _1();
    _2();
    _3();
    
    return 0;
}