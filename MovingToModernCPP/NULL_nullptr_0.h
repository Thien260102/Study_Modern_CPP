#ifndef NULL_NULLPTR_0_H
#define NULL_NULLPTR_0_H

#include <iostream>
#include <mutex>

class NULL_nullptr_0
{

public:
	void function(int);

	void function(bool);

	void function(void*);

	int function1(std::shared_ptr<int> spi);

	double function2(std::unique_ptr<int> upi);

	bool function3(int* pi);

	void Example1();

	void Example2();
};

#endif

