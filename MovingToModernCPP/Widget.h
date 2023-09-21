#ifndef WIDGET_H
#define WIDGET_H

class Widget
{
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
};


#endif 



