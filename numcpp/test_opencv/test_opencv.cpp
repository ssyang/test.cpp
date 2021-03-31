// test_opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifdef _DEBUG
#pragma comment(lib, "opencv_world451d.lib") 
#else
#pragma comment(lib, "opencv_world451.lib") 
#endif // _DEBUG
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	cout << "OpenCV Version : " << CV_VERSION << endl;
	namedWindow("img-raw", cv::WINDOW_AUTOSIZE);
	namedWindow("img-gray", cv::WINDOW_AUTOSIZE);
	namedWindow("img-canny", cv::WINDOW_AUTOSIZE);

	Mat rawimg, grayimg, cannyimg;
	rawimg = imread("my-neighbour-totoro-1108x0-c-default.jpg", IMREAD_COLOR);
	imshow("img-raw", rawimg);

	cvtColor(rawimg, grayimg, cv::COLOR_BGR2GRAY);
	Canny(grayimg, cannyimg, 10, 100, 3, true);
	imshow("img-gray", grayimg);
	imshow("img-canny", cannyimg);

	waitKey(0);
	destroyAllWindows();

	return 0;
}