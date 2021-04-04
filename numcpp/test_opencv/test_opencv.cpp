// test_opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifdef _DEBUG
#pragma comment(lib,"aded.lib")
#pragma comment(lib,"IlmImfd.lib")
#pragma comment(lib,"ippicvmtd.lib")
#pragma comment(lib,"ippiwd.lib")

#pragma comment(lib,"ittnotifyd.lib")
#pragma comment(lib,"libjpeg-turbod.lib")
#pragma comment(lib,"libopenjp2d.lib")
#pragma comment(lib,"libpngd.lib")
#pragma comment(lib,"libprotobufd.lib")
#pragma comment(lib,"libtiffd.lib")
#pragma comment(lib,"libwebpd.lib")

#pragma comment(lib,"opencv_alphamat451d.lib")
#pragma comment(lib,"opencv_aruco451d.lib")
#pragma comment(lib,"opencv_bgsegm451d.lib")
#pragma comment(lib,"opencv_bioinspired451d.lib")
#pragma comment(lib,"opencv_calib3d451d.lib")
#pragma comment(lib,"opencv_ccalib451d.lib")
#pragma comment(lib,"opencv_core451d.lib")
#pragma comment(lib,"opencv_datasets451d.lib")
#pragma comment(lib,"opencv_dnn_objdetect451d.lib")
#pragma comment(lib,"opencv_dnn_superres451d.lib")
#pragma comment(lib,"opencv_dnn451d.lib")
#pragma comment(lib,"opencv_dpm451d.lib")
#pragma comment(lib,"opencv_face451d.lib")
#pragma comment(lib,"opencv_features2d451d.lib")
#pragma comment(lib,"opencv_flann451d.lib")
#pragma comment(lib,"opencv_fuzzy451d.lib")
#pragma comment(lib,"opencv_gapi451d.lib")
#pragma comment(lib,"opencv_hfs451d.lib")
#pragma comment(lib,"opencv_highgui451d.lib")
#pragma comment(lib,"opencv_img_hash451d.lib")
#pragma comment(lib,"opencv_imgcodecs451d.lib")
#pragma comment(lib,"opencv_imgproc451d.lib")
#pragma comment(lib,"opencv_intensity_transform451d.lib")
#pragma comment(lib,"opencv_line_descriptor451d.lib")
#pragma comment(lib,"opencv_mcc451d.lib")
#pragma comment(lib,"opencv_ml451d.lib")
#pragma comment(lib,"opencv_objdetect451d.lib")
#pragma comment(lib,"opencv_optflow451d.lib")
#pragma comment(lib,"opencv_phase_unwrapping451d.lib")
#pragma comment(lib,"opencv_photo451d.lib")
#pragma comment(lib,"opencv_plot451d.lib")
#pragma comment(lib,"opencv_quality451d.lib")
#pragma comment(lib,"opencv_rapid451d.lib")
#pragma comment(lib,"opencv_reg451d.lib")
#pragma comment(lib,"opencv_rgbd451d.lib")
#pragma comment(lib,"opencv_saliency451d.lib")
#pragma comment(lib,"opencv_shape451d.lib")
#pragma comment(lib,"opencv_stereo451d.lib")
#pragma comment(lib,"opencv_stitching451d.lib")
#pragma comment(lib,"opencv_structured_light451d.lib")
#pragma comment(lib,"opencv_superres451d.lib")
#pragma comment(lib,"opencv_surface_matching451d.lib")
#pragma comment(lib,"opencv_text451d.lib")
#pragma comment(lib,"opencv_tracking451d.lib")
#pragma comment(lib,"opencv_video451d.lib")
#pragma comment(lib,"opencv_videoio451d.lib")
#pragma comment(lib,"opencv_videostab451d.lib")
#pragma comment(lib,"opencv_xfeatures2d451d.lib")
#pragma comment(lib,"opencv_ximgproc451d.lib")
#pragma comment(lib,"opencv_xobjdetect451d.lib")
#pragma comment(lib,"opencv_xphoto451d.lib")

#pragma comment(lib,"quircd.lib")
#pragma comment(lib,"zlibd.lib")

#else
//#pragma comment(lib,"ade.lib")
#pragma comment(lib,"IlmImf.lib")
#pragma comment(lib,"ippicvmt.lib")
#pragma comment(lib,"ippiw.lib")

#pragma comment(lib,"ittnotify.lib")
#pragma comment(lib,"libjpeg-turbo.lib")
#pragma comment(lib,"libopenjp2.lib")
#pragma comment(lib,"libpng.lib")
#pragma comment(lib,"libprotobuf.lib")
#pragma comment(lib,"libtiff.lib")
#pragma comment(lib,"libwebp.lib")

//#pragma comment(lib,"opencv_alphamat451.lib")
//#pragma comment(lib,"opencv_aruco451.lib")
//#pragma comment(lib,"opencv_bgsegm451.lib")
//#pragma comment(lib,"opencv_bioinspired451.lib")
//#pragma comment(lib,"opencv_calib3d451.lib")
//#pragma comment(lib,"opencv_ccalib451.lib")
#pragma comment(lib,"opencv_core451.lib")
//#pragma comment(lib,"opencv_datasets451.lib")
//#pragma comment(lib,"opencv_dnn_objdetect451.lib")
//#pragma comment(lib,"opencv_dnn_superres451.lib")
//#pragma comment(lib,"opencv_dnn451.lib")
//#pragma comment(lib,"opencv_dpm451.lib")
//#pragma comment(lib,"opencv_face451.lib")
//#pragma comment(lib,"opencv_features2d451.lib")
//#pragma comment(lib,"opencv_flann451.lib")
//#pragma comment(lib,"opencv_fuzzy451.lib")
//#pragma comment(lib,"opencv_gapi451.lib")
//#pragma comment(lib,"opencv_hfs451.lib")
#pragma comment(lib,"opencv_highgui451.lib")
//#pragma comment(lib,"opencv_img_hash451.lib")
#pragma comment(lib,"opencv_imgcodecs451.lib")
#pragma comment(lib,"opencv_imgproc451.lib")
//#pragma comment(lib,"opencv_intensity_transform451.lib")
//#pragma comment(lib,"opencv_line_descriptor451.lib")
//#pragma comment(lib,"opencv_mcc451.lib")
//#pragma comment(lib,"opencv_ml451.lib")

//#pragma comment(lib,"opencv_objdetect451.lib")
//#pragma comment(lib,"opencv_optflow451.lib")
//#pragma comment(lib,"opencv_phase_unwrapping451.lib")
//#pragma comment(lib,"opencv_photo451.lib")
//#pragma comment(lib,"opencv_plot451.lib")
//#pragma comment(lib,"opencv_quality451.lib")
//#pragma comment(lib,"opencv_rapid451.lib")
//#pragma comment(lib,"opencv_reg451.lib")
//#pragma comment(lib,"opencv_rgbd451.lib")
//#pragma comment(lib,"opencv_saliency451.lib")
//#pragma comment(lib,"opencv_shape451.lib")
//#pragma comment(lib,"opencv_stereo451.lib")
//#pragma comment(lib,"opencv_stitching451.lib")
//#pragma comment(lib,"opencv_structured_light451.lib")
//#pragma comment(lib,"opencv_superres451.lib")
//#pragma comment(lib,"opencv_surface_matching451.lib")
//#pragma comment(lib,"opencv_text451.lib")
//#pragma comment(lib,"opencv_tracking451.lib")
//#pragma comment(lib,"opencv_video451.lib")
//#pragma comment(lib,"opencv_videoio451.lib")
//#pragma comment(lib,"opencv_videostab451.lib")
//#pragma comment(lib,"opencv_xfeatures2d451.lib")
//#pragma comment(lib,"opencv_ximgproc451.lib")
//#pragma comment(lib,"opencv_xobjdetect451.lib")
//#pragma comment(lib,"opencv_xphoto451.lib")

//#pragma comment(lib,"quirc.lib")
#pragma comment(lib,"zlib.lib")
#endif // _DEBUG

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

void colorReduce(const cv::Mat& image, cv::Mat& result, int div)
{
	int nl = image.rows; // 행 개수
	std::cout << image.channels() << std::endl; // 이미지의 채널 수 확인, 컬러 영상인 경우 3, 흑백 영상인 경우 1. 
	// 각 행의 원소 총 개수
	int nc = image.cols * image.channels();

	for (int j = 0; j < nl; j++)
	{
		// j행의 주소 얻기
		const uchar* data_in = image.ptr<uchar>(j);
		uchar* data_out = result.ptr<uchar>(j);

		for (int i = 0; i < nc; i++)
		{
			// 각 화소 처리
			data_out[i] = data_in[i] / div * div + div / 2;
		}
	}
}

int main()
{
	std::cout << "OpenCV Version : " << CV_VERSION << std::endl;

	//opencv_highgui451.lib : namedWindow, imshow, destroyAllWindows, waitKey
	cv::namedWindow("img-raw", cv::WINDOW_AUTOSIZE);
	//cv::namedWindow("img-gray", cv::WINDOW_AUTOSIZE);
	//cv::namedWindow("img-canny", cv::WINDOW_AUTOSIZE);

	cv::Mat rawimg, grayimg, cannyimg, subimag;

	//opencv_imgcodecs451.lib : imread, imwrite
	rawimg = cv::imread("C:\\job\\test\\test.cpp\\numcpp\\test_opencv\\my-neighbour-totoro-1108x0-c-default.jpg", cv::IMREAD_COLOR);
	cv::imshow("img-raw", rawimg);
	
	//cv::split(rawimg, &subimag);

	subimag.create(rawimg.rows, rawimg.cols, rawimg.type());
	colorReduce(rawimg, subimag, 64);
	cv:imshow("subimag", subimag);
	
	//opencv_imgproc451.ib : cvtColor
	//cv::cvtColor(rawimg, grayimg, cv::COLOR_BGR2GRAY);
	//cv::Canny(grayimg, cannyimg, 10, 100, 3, true);
	//cv::imshow("img-gray", grayimg);
	//cv::imshow("img-canny", cannyimg);

	std::cout << "press any key !" << std::endl;
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}