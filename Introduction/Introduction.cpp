// Introduction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Widget.h"

extern int a;               // declaration
int b;                      // definition

int a = 1;                  // definition

void function(Widget wid);  // declaration

int main()
{
    std::cout << a << "\n";

    std::cout << b << "\n";

    std::cout << "Hello World!\n";

    Widget widget;
    
    function(widget);

    function(std::move(widget));
}

void function(Widget wid)   // definition, wid is pass by value
{

}

