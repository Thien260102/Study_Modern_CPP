#ifndef CTEST_H
#define CTEST_H
#include <iostream>

class CTest
{
public:
	CTest();

	CTest(int);

	CTest(int, bool);

	CTest(int, double);

	CTest(std::initializer_list<long double> il)
	{
		std::cout << "Constructor with argument (std::initializer_list)\n";
	}

	operator float()
	{
		return 1.0;
	}

	operator float() const;

	CTest(const CTest& c);

	// move constructor
	CTest(CTest&& ctest) noexcept;
};


#endif