// DeducingTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <array>

#define RED     12
#define DEFAULT 15
#define BLUE    9

#define stringify( name ) #name

enum class TEST
{
    T1,
    T2,
    T3,
    T4,
    T5,
    T6,
    T7,
    T8,
    T9,
    T10
};

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T(&)[N]) noexcept
{
    return N;
}

#pragma region Template Function
template<typename T>
void Function1(T& param)
{
    std::cout << "\tAddress in function: " << &param << '\n';
}

template<typename T>
void Function2(const T& param)
{
    std::cout << "\tAddress in function: " << &param << "\n";
}

template<typename T>
void Function3(T* param) // param were a pointer instead of a reference, but it work essentially the same way
{
    std::cout << "\tAddress of pointer pointing in function: " << param << "\n";
}

template<typename T>
void Function4(T&& param) // param were a pointer instead of a reference, but it work essentially the same way
{
    std::cout << "\tAddress of pointer in function: " << &param << "\n";
}

template<typename T>
void Function5(T param) // param were a pointer instead of a reference, but it work essentially the same way
{
    std::cout << "\tAddress of pointer in function: " << &param << "\n";
}

template<typename T>
void Function6(T someFunc)
{
    std::cout << "\tAddress of pointer in function: " << &someFunc << "\n";
}

void Function7(void (&someFunc)(int, double))
{
    std::cout << "\tAddress of pointer in function: " << &someFunc << "\n";
}

#pragma endregion

void someFunction(int, double);

void Test(TEST type)
{
    switch (type)
    {
    case TEST::T1:
    {
        int x = 5;
        std::cout << "Address in main: " << &x;
        Function1(x);   // paramType is int&

        const int cx = x;
        std::cout << "Address in main: " << &cx;
        Function1(cx);  // paramType is const int&

        const int& rx = x;
        std::cout << "Address in main: " << &rx;
        Function1(rx);  // paramType is const int&
    }

        break;

    case TEST::T2:
    {
        int x = 5;
        std::cout << "Address in main: " << &x;
        Function2(x);   // paramType is const int&

        const int cx = x;
        std::cout << "Address in main: " << &cx;
        Function2(cx);  // paramType is const int&

        const int& rx = x;
        std::cout << "Address in main: " << &rx;
        Function2(rx);  // paramType is const int&
    }

        break;

    case TEST::T3:
    {
        int x = 5;
        std::cout << "Address in main: " << &x;
        Function3(&x);   // paramType is int*

        const int* px = &x;
        std::cout << "Address in main: " << &px;
        Function3(px);  // paramType is const int*

    }

        break;

    case TEST::T4:
    {
        int x = 5;
        std::cout << "Address in main: " << &x;
        Function4(x);   // paramType is int&

        const int cx = x;
        std::cout << "Address in main: " << &cx;
        Function4(cx);  // paramType is const int&

        const int& rx = x;
        std::cout << "Address in main: " << &rx;
        Function4(rx);  // paramType is const int&

        Function4(27);  // 27 is rvalue, paramType is int&&
    }

        break;

    case TEST::T5:
    {
        int x = 5;
        std::cout << "Address in main: " << &x;
        Function5(x);   // paramType is int

        const int cx = x;
        std::cout << "Address in main: " << &cx;
        Function5(cx);  // paramType is int

        const int& rx = x;
        std::cout << "Address in main: " << &rx;
        Function5(rx);  // paramType is int
    }

    break;

    case TEST::T6:
    {
        const int* const ptr = new int(5);
        std::cout << "Address in main: " << &ptr;
        Function5(ptr); // paramType is const int*
    }

    break;

    case TEST::T7:
    {
        const char name[] = "Thien Nguyen";
        std::cout << "Address in main: " << (&name);
        std::cout << "\tlength = " << arraySize(name);
        Function5(name);    // decay rule, become const char*, this way can't get length of array

        Function1(name);    // still origin array, this way can get length of array
    }

    break;

    case TEST::T8:
    {
        std::cout << "Address in main: " << (&someFunction);

        Function6(someFunction);    // pass by pointer
        Function7(someFunction);    // pass by value
    }

    break;


    }

    std::cout << '\n';
}

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Case 1: ParamType is a Reference or Pointer, but not a Universal Reference
    int k = RED;
    SetConsoleTextAttribute(hConsole, k);

    std::cout << "CASE 1: ParamType is a Reference or Pointer, but not a Universal Reference\n";

    k = DEFAULT;
    SetConsoleTextAttribute(hConsole, k);

    Test(TEST::T1);
    Test(TEST::T2);
    Test(TEST::T3);

    // Case2: ParamType is a Universal Reference
    k = RED;
    SetConsoleTextAttribute(hConsole, k);

    std::cout << "CASE 2: ParamType is a Universal Reference\n";

    k = DEFAULT;
    SetConsoleTextAttribute(hConsole, k);

    Test(TEST::T4);

    // Case3: ParamType is Neither a Pointer nor a Reference
    k = RED;
    SetConsoleTextAttribute(hConsole, k);

    std::cout << "CASE 3: ParamType is Neither a Pointer nor a Reference\n";

    k = DEFAULT;
    SetConsoleTextAttribute(hConsole, k);

    std::cout << "Normal: ";
    Test(TEST::T5);

    std::cout << "Special: ";
    Test(TEST::T6);


    // ARRAY ARGUMENTS
    k = BLUE;
    SetConsoleTextAttribute(hConsole, k);

    std::cout << "\nARRAY ARGUMENTS: \n";

    k = DEFAULT;
    SetConsoleTextAttribute(hConsole, k);

    Test(TEST::T7);
    // but as a modern c++ developer, prefer std::array to a built-in array

    // FUNCTION ARGUMENTS
    k = BLUE;
    SetConsoleTextAttribute(hConsole, k);

    std::cout << "\nFUNCTION ARGUMENTS: \n";

    k = DEFAULT;
    SetConsoleTextAttribute(hConsole, k);

    Test(TEST::T8);
}


void someFunction(int a, double b)
{

}