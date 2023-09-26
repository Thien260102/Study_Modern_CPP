#include "CTest.h"

CTest::CTest()
{
	std::cout << "Default constructor\n";
}

CTest::CTest(int i)
{
	std::cout << "Constructor with argument (int)\n";
}

CTest::CTest(int i, bool b)
{
	std::cout << "Constructor with argument (int, bool)\n";
}

CTest::CTest(int i, double d)
{
	std::cout << "Constructor with argument (int, double)\n";
}

CTest::CTest(const CTest& c)
{
	std::cout << "Copy constructor called\n";
}

//CTest::CTest(std::initializer_list<long double> il)
//{
//	std::cout << "Constructor with argument (std::initializer_list)\n";
//}

CTest::CTest(CTest&& ctest) noexcept
{
	std::cout << "Move constructor" << "\n";
}


CTest::operator float() const
{
	std::cout << "Convert CTest to float\n";
	return 1.0;
}