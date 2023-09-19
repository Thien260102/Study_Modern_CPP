#include "AutoTypeDeduction.h"
#include <iostream>

void FunctionAuto()
{
	auto x = 27;
	std::cout << "Address of x: " << &x;

	const auto cx = x;
	std::cout << "\tAddress of cx: " << &cx;

	const auto& rx = x;
	std::cout << "\tAddress rx pointing: " << &rx;

	x = 5;

	std::cout << "\n";
	std::cout << "x: " << x << ", cx = " << cx << ", rx = " << rx;


	std::cout << "\n";

	auto&& uref1 = x;	// x is lvalue so uref1 is int&
	std::cout << "x: " << &x << ", uref1 = " << &uref1;

	auto&& uref2 = cx;	// cx is lvalue so uref2 is const int&
	std::cout << "\tcx: " << &cx << ", uref2 = " << &uref2;

	auto&& uref3 = 27;	// 27 is rvalue so uref3 is int&&

	std::cout << "\n";

	// ARRAY
	const char name[] = "Thien Nguyen";
	std::cout << "name: " << &name;

	auto arr1 = name;	//arr1 is const char*
	std::cout << "\tarr1: " << &arr1;

	auto& arr2 = name;	//arr2 is const char&[]
	std::cout << "\tarr2: " << &arr2;

	// FUNCTION
	std::cout << "\nfunction: " << (&Function);

	auto function1 = Function;	// function1 is void*
	std::cout << "\tfunction1: " << &function1;

	auto& function2 = Function;	// function2 is void&
	std::cout << "\tfunction2: " << &function2;

	// int x1 = 27
	// int x2(27)
	// int x3 = {27}
	// int x4{27}
	// all above are the same.
	// but
	auto x1 = 27;		// type int
	auto x2(27);		// type int

	auto x3 = { 27 };	// type std::initializer_list<int>
	auto x4{ 27 };		// type std::initializer_list<int>

	//auto x5 = { 1, 3, 5, 3.0 }; is false because 1 3 5 are int, but 3.0 is float, std::initializer_list<T>

}

void Function(int, double)
{

}