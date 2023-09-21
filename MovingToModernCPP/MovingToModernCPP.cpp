#include <iostream>
#include <Windows.h>

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



    std::cout << " \n\n\n";
}

