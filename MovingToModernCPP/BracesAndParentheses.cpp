#include "BracesAndParentheses.h"
#include <iostream>
#include "../Introduction/Widget.h"
#include <vector>


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







