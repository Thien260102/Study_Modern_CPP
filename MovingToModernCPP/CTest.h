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

	CTest(std::initializer_list<long double> il);

	operator float()
	{
		std::cout << "Convert CTest to float\n";
		return static_cast<float>(1.0);
	}

	operator float() const
	{
		std::cout << "Convert CTest to float\n";
		return static_cast<float>(1.0);
	}

	//copy constructor
	CTest(const CTest& c);

	// move constructor
	CTest(CTest&& ctest) noexcept;
};


#endif