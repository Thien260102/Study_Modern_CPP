#include "Widget.h"

Widget::Widget() :number{}
{
	std::cout << "Default constructor" << "\n";
}

Widget::Widget(const Widget& wid)
{
	number = wid.number;

	std::cout << "Copy constructor" << "\n";
}

Widget::Widget(Widget&& wid)
{
	number = std::move(wid.number);
	std::cout << "Move constructor" << "\n";
}

void Widget::Display()
{
	std::cout << number << "\n";
}

Widget::~Widget()
{
	std::cout << "Destructor" << "\n";
}