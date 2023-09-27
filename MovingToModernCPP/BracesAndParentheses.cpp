#include "BracesAndParentheses.h"
#include <iostream>
#include "../Introduction/Widget.h"
#include <vector>
#include "CTest.h"


void BracesAndParentheses::Example1()
{
	int x(0);
	std::cout << "Initialize x: int x(0): " << x;

	int y = 1;
	std::cout << "\t Initialize y: int y = 1: " << y;

	int z{ 2 };
	std::cout << "\t Initialize z: int z{2}: " << z;
	
	int t = { 3 };
	std::cout << "\tInitialize t: int t = {3}: " << t;

	std::vector<int> v{ 1,3,5 };
	std::cout << "\tInitialize vector<int> v{1,3,5}, size: " << v.size();

	std::cout << "\n";
}

void BracesAndParentheses::Example2()
{
	std::cout << "When i define Widget w: ";
	Widget w;

	std::cout << "When i define Widget w1 = w: ";
	Widget w1 = w;

	std::cout << "When i assign w = w1: ";
	w = w1;

	w.Display();

	std::cout << "\nAnd uncopyable object like atomic maybe intitialize use braces or parentheses, but not '='";
	std::cout << "\n std::atomic<int> ai1{0}; is fine";
	std::cout << "\n std::atomic<int> ai1(0); is fine";
	std::cout << "\n std::atomic<int> ai1 = 0; is error";

	std::cout << "\n\n";
}

void BracesAndParentheses::Example3()
{
	std::cout << "\n Case intitialize use braces or '=', but not parentheses: ";
	std::cout << "\n class Widget { \n...";

	std::cout << "\nprivate:";
	std::cout << "\n  int x{0}; is fine";
	std::cout << "\n  int y = 0; is fine";
	std::cout << "\n  int z(0); error";

	std::cout << "\n }";

	std::cout << "\n\n";
}

void BracesAndParentheses::Example4()
{
	double x = 1, y = 2, z = 3;

	//int sum1{ x + y + z };
	std::cout << "\nbraced initialization is that it prohibits implicit narrowing conversions among built - in types ";
	std::cout << "\ndouble x = 1, y = 2, z = 3;";
	std::cout << "\n int sumt1{x + y + z}; error";

	int sum2(x + y + z);
	std::cout << "\n int sum2(x + y + z): " << sum2;

	int sum3 = x + y + z;
	std::cout << "\n int sum3 = x + y + z: " << sum3;

	std::cout << "\n\n";
}

void BracesAndParentheses::Example5()
{
	std::cout << "\nCall CTest constructor with argument 1 'CTest c1(1)': ";
	CTest c1(1);

	std::cout << "\nDeclare function named c2 'CTest c2()' that return CTest: ";
	CTest c2();

	std::cout << "\n\nCall CTest default constructor 'CTest c3': ";
	CTest c3;

	std::cout << "Or you can call like this 'CTest c4{}': ";
	CTest c4{};

	std::cout << "\n\n";
}

void BracesAndParentheses::Example6()
{
	std::cout << "\nSome special case: ";

	std::cout << "\n'CTest c'Call default constructor: ";
	CTest c;	// 10 and 5.0 convert to long double

	std::cout << "\n'CTest c1{10, 5.0}'Call std::initializer_list constructor: ";
	CTest c1{ 10, 5.0 };	// 10 and 5.0 convert to long double

	std::cout << "\n'CTest c2(c1)' call copy constructor: ";
	CTest c2(c);

	std::cout << "\n'CTest c3{c1}' the book told: ' call std::initializer_list constructor (c1 convert to float, float convert to long double) ', but result: ";
	CTest c3{ c };

	std::cout << "\n\n\n";

	std::cout << "c3 + 2.0 = " << c3 + 2.0 << "\n\n\n";

	std::cout << "\n'CTest c4(std::move(c3))' call move constructor: ";
	CTest c4(std::move(c3));

	std::cout << "\n'CTest c5{ std::move(c3) }'  the book told: it same reason as c3, but result: ";
	CTest c5{ std::move(c3) };

	std::cout << "\n\n'CTest c6{ c4, c5 }' call std::initializer_list constructor: ";
	CTest c6{ c4, c5 };

	std::cout << "\n /////////// This ERROR CAUSED BY COMPILER: clang++, g++ still true ///////////";
	std::cout << "\n /////////// for more infor: https://stackoverflow.com/questions/35273025/c-copy-constructor-gets-called-instead-of-initializer-list ";

	std::cout << "\n\n";
}






