#include <iostream>
#include <Windows.h>

#include "Widget.h"
#include "BracesAndParentheses.h"

#define RED     12
#define DEFAULT 15
#define BLUE    9



int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, RED);
    std::cout << "DISTINGUISH BETWEEN () AND {}: \n";

    BracesAndParentheses example;

    SetConsoleTextAttribute(hConsole, BLUE);
    std::cout << "- Example 1: \n";

    SetConsoleTextAttribute(hConsole, DEFAULT);
    example.Example1();


    SetConsoleTextAttribute(hConsole, BLUE);
    std::cout << "- Example 2: \n";

    SetConsoleTextAttribute(hConsole, DEFAULT);
    example.Example2();

    SetConsoleTextAttribute(hConsole, BLUE);
    std::cout << "- Example 3: \n";

    SetConsoleTextAttribute(hConsole, DEFAULT);
    example.Example3();

    SetConsoleTextAttribute(hConsole, BLUE);
    std::cout << "\n ///////////// Conclude /////////////";
    std::cout << "\n // Only braces '{}' can use everywhere to initializing //\n";

    SetConsoleTextAttribute(hConsole, BLUE);
    std::cout << "\n- Example 4:";

    SetConsoleTextAttribute(hConsole, DEFAULT);
    example.Example4();

    SetConsoleTextAttribute(hConsole, BLUE);
    std::cout << "\n- Example 5:";

    SetConsoleTextAttribute(hConsole, DEFAULT);
    example.Example5();

    SetConsoleTextAttribute(hConsole, BLUE);
    std::cout << "\n- Example 6:";

    SetConsoleTextAttribute(hConsole, DEFAULT);
    example.Example6();

    std::cout << " \n\n\n";
}

