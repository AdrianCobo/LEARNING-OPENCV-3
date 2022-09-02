//Exercises at end of Chapter 7
// 1-4
#include <opencv2/opencv.hpp>
#include <opencv2/core/core_c.h>
#include <iostream>

void help(const char **argv) {
	std::cout << "\n\n"
		<< "This program solves the Exercises at the end of Chapter 7\n"
		<< std::endl;
}


int main( int argc, const char** argv )
{
	help(argv);
	
	/************************************************************************/
	/* 1.  Using the cv::RNG random number generator:
	a.  Generate and print three floating-point numbers, each drawn from a uniform
	distribution from 0.0 to 1.0.
	b.  Generate  and  print  three  double-precision  numbers,  each  drawn  from  a
	Gaussian distribution centered at 0.0 and with a standard deviation of 1.0.
	c.  Generate and print three unsigned bytes, each drawn from a uniform distri‐
	bution from 0 to 255.                                                                     
	/************************************************************************/
	cv::RNG rng = cv::theRNG();
	// a
	float f1 = rng.uniform(0.f,1.f);
	float f2 = rng.uniform(0.f,1.f);
	float f3 = rng.uniform(0.f,1.f);
	std::cout<<" f1 " << f1 <<" f2 "<<f2<<" f3 "<<f3<<std::endl;
	// b
	cv::Vec3d vec3d;
    rng.fill(vec3d,cv::RNG::NORMAL,0.,1.);
	std::cout<<" d1 "<<vec3d[0]<<" d2 "<<vec3d[1]<<" d3 "<<vec3d[2]<<std::endl;
	// c
	unsigned byte1 = rng.uniform(0,255);
	unsigned byte2 = rng.uniform(0,255);
	unsigned byte3 = rng.uniform(0,255);
	std::cout<<" byte1 " << byte1 <<" byte2 "<<byte2<<" byte3 "<<byte3<<std::endl;

	/************************************************************************/
	/* 2.  Using  the  fill()  method  of  the  cv::RNG  random  number  generator,  create  an
	array of:
	a.  20 floating-point numbers with a uniform distribution from 0.0 to 1.0.
	b.  20  floating-point  numbers  with  a  Gaussian  distribution  centered  at  0.0  and
	with a standard deviation of 1.0.
	c.  20 unsigned bytes with a uniform distribution from 0 to 255.
	d.  20 color triplets, each of three bytes with a uniform distribution from 0 to 255.                                                                     */
	/************************************************************************/
	// a
	cv::Mat matFloat20 = cv::Mat(20,1,CV_32FC1,cv::Scalar(0));
	rng.fill(matFloat20,cv::RNG::UNIFORM,0.f,1.f);
	// b
	rng.fill(matFloat20,cv::RNG::NORMAL,0.f,1.f);
	// c
	cv::Mat matUbyte20 = cv::Mat(20,1,CV_8UC1,cv::Scalar(0));
	rng.fill(matUbyte20,cv::RNG::UNIFORM,0,255);
	// d
	cv::Mat matColor20 = cv::Mat(20,1,CV_8UC3,cv::Scalar(0));
	rng.fill(matColor20,cv::RNG::UNIFORM,0,255);

	/************************************************************************/
	/* 3.  Using the cv::RNG random number generator, create an array of 100 three-byte
	objects such that:
	a.  The first and second dimensions have a Gaussian distribution, centered at 64
	and 192, respectively, each with a variance of 10.
	b.  The third dimension has a Gaussian distribution, centered at 128 and with a
	variance of 2.
	c.  Using the cv::PCA object, compute a projection for which maxComponents=2.
	d.  Compute the mean in both dimensions of the projection; explain the result.                                                                     */
	/************************************************************************/
	cv::Mat matInt100 = cv::Mat(100,1,CV_32FC3,cv::Scalar(0));
	// a
	std::vector<cv::Mat> planes;
	cv::split(matInt100,planes);
	rng.fill(planes[0],cv::RNG::NORMAL,64,10);
	rng.fill(planes[1],cv::RNG::NORMAL,192,10);
	// b
	rng.fill(planes[2],cv::RNG::NORMAL,128,2);
	// c 
	cv::PCA pca(planes[0],cv::Mat(),CV_PCA_DATA_AS_ROW,2);
	planes[0] = pca.project(planes[0]);
	pca(planes[1],cv::Mat(),CV_PCA_DATA_AS_ROW,2);
	planes[1] = pca.project(planes[1]);
	pca(planes[2],cv::Mat(),CV_PCA_DATA_AS_ROW,2);
	planes[2] = pca.project(planes[2]);
	//d
	f1 = 0;
	f2 = 0;
	f3 = 0;
	for (int i = 0;i<100;i++)
	{
		f1 += planes[0].at<float>(i,0);
		f2 += planes[1].at<float>(i,0);
		f3 += planes[2].at<float>(i,0);
	}
	f1 = f1/100;
	f2 = f2/100;
	f3 = f3/100;
	/************************************************************************/
	/* 4.  page 206 at 《leanring Opencv 3.0》                                                            
	/************************************************************************/
	cv::Matx32d AX(1, 1,
		       0, 1,
		      -1 ,1); 
	cv::Mat A = static_cast<cv::Mat>(AX);
	cv::Mat U, W, V;
	cv::SVD::compute(A, W, U, V);

	cv::waitKey();
	std::getchar();
	return 0;

}