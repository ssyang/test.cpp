#pragma once

#include <iostream>
#include <memory>

#include "ct1.h"

class ct2
{
public:
	static ct2& get_instance()
	{
		static ct2 obj;
		static ct1::ptr_ct11 ptr_obj1(ct1::get_instance());
		ptr_obj1->info();
		return obj;
	}

public:
	void info()
	{
		std::wcout << L"ct2::info()" << std::endl;
	}

	~ct2()
	{
		std::wcout << L"~ct2()" << std::endl;

		ct1::ptr_ct11 ptr_obj1(ct1::get_instance());
		if(ptr_obj1)
			ptr_obj1->detail();
	}

private:
	ct2() : m_s_data(L"-C2-")
	{
		std::wcout << L"ct2()" << std::endl;
	}

	std::wstring m_s_data;
private:
	ct2(const ct2&);
	ct2& operator=(const ct2&);

};

