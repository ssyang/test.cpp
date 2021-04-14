#pragma once

#include <iostream>
#include <memory>

class ct3
{
public:
	static ct3& get_instance()
	{
		static ct3 obj;
		return obj;
	}

public:
	void info()
	{
		std::wcout << L"ct3::info()" << std::endl;
	}

	~ct3()
	{
		std::wcout << L"~ct3()" << std::endl;
	}

private:
	ct3() : m_s_data(L"-C3-")
	{
		std::wcout << L"ct3()" << std::endl;
	}

	std::wstring m_s_data;
private:
	ct3(const ct3&);
	ct3& operator=(const ct3&);

};