#include"NumCpp.hpp"
#include"boost/filesystem.hpp"

#include<iostream>

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

    auto a3 = nc::random::randFloat<double>({ 10, 10 }, 0, 1);
    std::wcout << L"matrix generated a3 : " << std::endl;
    a3.print();

	return 0;
}
