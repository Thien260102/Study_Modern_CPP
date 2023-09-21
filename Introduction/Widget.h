#pragma once

#include <iostream>

class Widget
{
#pragma region Fields
private:
	int number;					// field definition
#pragma endregion

#pragma region Methods
public:
	// default constructor
	Widget();					// method declaration

	// copy constructor
	Widget(const Widget& wid);

	// move constructor
	Widget(Widget&& widMove) noexcept;

	Widget& operator=(const Widget& widget);

	void Display();

	~Widget();

#pragma endregion
};

