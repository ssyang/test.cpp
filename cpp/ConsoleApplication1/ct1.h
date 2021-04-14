#pragma once

#include <iostream>

class ct1
{
public:
	typedef	std::shared_ptr<ct1>	ptr_ct11;

public:
	static ptr_ct11 get_instance()
	{
		static ptr_ct11 obj(new ct1());
		return obj;
	}

public:

	void info()
	{
		std::wcout << L"ct1::info()" << std::endl;
	}
	void detail()
	{
		std::wcout << L"ct1::detail()" << m_s_data << std::endl;
	}

	~ct1()
	{
		std::wcout << L"~ct1()" << std::endl;
	}

private:
	ct1() : m_s_data(L"-C1-")
	{
		std::wcout << L"ct1()" << std::endl;
	}

	std::wstring m_s_data;
private:
	ct1(const ct1&);
	ct1& operator=(const ct1&);
};

