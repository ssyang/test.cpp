#include"NumCpp.hpp"
#include"boost/filesystem.hpp"

#include <include/opencv2/opencv.hpp>
#include <modules/highgui/include/opencv2/highgui.hpp>

#include<iostream>

#pragma comment(lib, "opencv_world451d.lib")

int main()
{
	std::wcout << L"start" << std::endl;

    // Containers
    nc::NdArray<int> a0 = { {1, 2}, {3, 4} };
    nc::NdArray<int> a1 = { {1, 2}, {3, 4}, {5, 6} };

    std::wcout << L"matrix a0 : " << std::endl;
    a0.print();
    
    std::wcout << L"matrix a1 : " << std::endl;
    a1.print();

    //
    a1.reshape(2, 3);
    std::wcout << L"matrix reshape a1 : " << std::endl;
    a1.print();

    a1 = a1.transpose();
    std::wcout << L"matrix transpose a1 : " << std::endl;
    a1.print();

    nc::NdArray<double> a2 = a1.astype<double>();
    std::wcout << L"matrix change type to double a1 : " << std::endl;
    a2.print();

    nc::random::seed(123);
    auto a3 = nc::random::rand<double>({ 3, 2 });
    std::wcout << L"matrix generated a3 : " << std::endl;
    a3.print();

    auto a4 = nc::random::choice(a3, 4);
    a4.reshape(2, 2);
    std::wcout << L"matrix a4 : " << std::endl;
    a4.print();

    nc::NdArray<int> a = { {1, 2}, {3, 4}, {5, 6} };
    nc::NdArray<int> b = a * 10;
    nc::NdArray<int> c = a * 100;

    std::wcout << L"matrix a : " << std::endl;
    a.print();
    std::wcout << L"matrix b : " << std::endl;
    b.print();
    std::wcout << L"matrix c : " << std::endl;
    c.print();

    std::vector< nc::NdArray<int> > v_a;
    v_a.push_back(nc::stack({ a, b, c }, nc::Axis::ROW));
    //std::wcout << L"matrix " << v_a.size() << " : " << std::endl;
    //v_a.back().print();

    v_a.push_back(nc::vstack({ a, b, c }));
    std::wcout << L"matrix " << v_a.size() << " : " << std::endl;
    v_a.back().print();

    v_a.push_back(nc::hstack({ a, b, c }));
    std::wcout << L"matrix " << v_a.size() << " : " << std::endl;
    v_a.back().print();

    v_a.push_back(nc::append(a, b, nc::Axis::COL));
    std::wcout << L"matrix " << v_a.size() << " : " << std::endl;
    v_a.back().print();

    auto tempDir = boost::filesystem::temp_directory_path();
    auto tempTxt = (tempDir / "temp.txt").string();
    std::cout << "path " << tempTxt << std::endl;
    v_a.back().tofile(tempTxt, "\n");


    ///////////////////////
    std::wcout << "OpenCV Version : " << CV_VERSION << std::endl;
    cv::namedWindow("img-raw", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("img-gray", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("img-canny", cv::WINDOW_AUTOSIZE);

    cv::Mat rawimg, grayimg, cannyimg;
    rawimg = imread("d:\\WAD-A64U.png", IMREAD_COLOR);
    imshow("img-raw", rawimg);

    cvtColor(rawimg, grayimg, cv::COLOR_BGR2GRAY);
    Canny(grayimg, cannyimg, 10, 100, 3, true);
    imshow("img-gray", grayimg);
    imshow("img-canny", cannyimg);

    waitKey(0);
    destroyAllWindows();
    //
	return 0;
}
