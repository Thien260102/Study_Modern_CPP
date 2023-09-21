#include "Widget.h"
#include <iostream>

Widget::Widget()
{
	std::cout << "Default constructor" << "\n";
}

Widget::Widget(const Widget& wid)
{
	std::cout << "Copy constructor" << "\n";
}

Widget::Widget(Widget&& widMove) noexcept
{
	std::cout << "Move constructor" << "\n";
}

Widget& Widget::operator=(const Widget& widget)
{
	std::cout << "Operator = called\n";
	return *this;
}

void Widget::Display()
{
	std::cout << "You cannot non static fields in class like this: int x(0);";
	std::cout << "\tBut int x{0}; or int x = 0; still fine\n";
}

Widget::~Widget()
{
	std::cout << "Destructor" << "\n";
}