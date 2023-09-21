#include "UndesiredTypes.h"
#include <iostream>
#include <vector>

std::vector<bool> Features(const int i)
{
	return { true, false, true, true, false, false, false };
}

void ProcessInt(int i, bool highPriority)
{
	std::cout << "Process int do some stuffs\t";
}

double CalcEpsilon() { return 9.0; }

void UndesiredTypes::Example1()
{
	std::cout << "Example1: ";

	int i = 0;

	bool highPriority = Features(i)[5];
	ProcessInt(i, highPriority);

	auto highPriorityAuto = Features(i)[5];
	//ProcessInt(i, highPriorityAuto);		// this will throw error in runtime, very dangerous.
	
	// or use can use
	auto highPriorityAutoForce = static_cast<bool>(Features(i)[5]);

	std::cout << "\nYou therefore want to avoid code of this form:"
		<< "auto someVar = expression of 'invisible' proxy class type";

	auto a = static_cast<float>(CalcEpsilon());
	std::cout << "\n\n";
}