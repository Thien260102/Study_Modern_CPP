#include "NULL_nullptr_0.h"
#include <iostream>

std::mutex f1m, f2m, f3m;
using MuxGuard = std::lock_guard<std::mutex>;

template<typename FuncType,
	typename MuxType,
	typename PtrType>
	auto LockAndCall(FuncType func, MuxType& mutex, PtrType ptr) -> decltype(func(ptr))
{
	MuxGuard g(mutex);
	return func(ptr);
}

void NULL_nullptr_0::function(int)
{
	std::cout << "function(int) called\n";
}

void NULL_nullptr_0::function(bool)
{
	std::cout << "function(bool) called\n";
}

void NULL_nullptr_0::function(void*)
{
	std::cout << "function(void*) called\n";
}

int NULL_nullptr_0::function1(std::shared_ptr<int> spi)
{
	std::cout << "function1 called\n";
	return 0;
}

double NULL_nullptr_0::function2(std::unique_ptr<int> upi)
{
	std::cout << "function2 called\n";
	return 0.0;
}

bool NULL_nullptr_0::function3(int *pi)
{
	std::cout << "function3 called\n";
	return false;
}

void NULL_nullptr_0::Example1()
{
	std::cout << "You have 3 overloads of function: function(int), function(bool), function(void*):";

	std::cout << "\n call function(0): ";
	function(0);

	std::cout << "\n call function(NULL): ";
	function(NULL);

	std::cout << "\n But you want to call function(void*), so just call function(nullptr): ";
	function(nullptr);
}

bool function4(int* ip)
{
	std::cout << "function4 called\n";
	return true;
}

void NULL_nullptr_0::Example2()
{
	std::cout << "You have 3 functions: function1(std::share_ptr<int>), function2(std::unique_ptr<int>), function3(int*):";

	std::cout << "\n do { MuxGuard g(f1m); auto result = function1(0): ";
	{
		MuxGuard g(f1m);
		auto result = function1(0);
	}

	std::cout << " do { MuxGuard g(f2m); auto result = function2(NULL): ";
	{
		MuxGuard g(f2m);
		auto result = function2(NULL);
	}

	std::cout << "\nYou have:\ntemplate<typename FuncType, typename MuxType, typename PtrType>";
	std::cout << "\ndecltype(auto) LockAndCall(FuncType func, MuxType& mutex, PtrType ptr)";
	std::cout << "\n{\n\tMuxGuard g(mutex);\n\treturn func(ptr);\n}\n";

	std::cout << "\nYou only can call LockAndCall(function4, f3m, nullptr): ";
	auto result3 = LockAndCall(function4, f3m, nullptr);

	std::cout << "\n\n Conclude : \n";
	std::cout << "Prefer nullptr to 0 and NULL\n";
	std::cout << "Avoid overloading on integral and pointer types.\n";
}
