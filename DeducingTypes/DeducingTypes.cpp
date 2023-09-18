// DeducingTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define stringify( name ) #name

enum class FUNCTION
{
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10
};

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

void Test(FUNCTION type)
{
    switch (type)
    {
    case FUNCTION::F1:
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

    case FUNCTION::F2:
    {
        int x = 5;
        std::cout << "Address in main: " << &x;
        Function2(x);   // paramType is int&

        const int cx = x;
        std::cout << "Address in main: " << &cx;
        Function2(cx);  // paramType is const int&

        const int& rx = x;
        std::cout << "Address in main: " << &rx;
        Function2(rx);  // paramType is const int&
    }

        break;

    case FUNCTION::F3:
    {
        int x = 5;
        std::cout << "Address in main: " << &x;
        Function3(&x);   // paramType is int*

        const int* px = &x;
        std::cout << "Address in main: " << &px;
        Function3(px);  // paramType is const int*

    }

        break;

    case FUNCTION::F4:
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

    case FUNCTION::F5:
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

    case FUNCTION::F6:
    {
        const int* const ptr = new int(5);
        std::cout << "Address in main: " << &ptr;
        Function5(ptr); // paramType is const int*
    }

    break;

    case FUNCTION::F7:
    {
        const char name[] = "J. P. Briggs";
        std::cout << "Address in main: " << (&name);
        Function5(name);
        //std::cout << name;
    }

    break;

    }

    std::cout << '\n';
}

int main()
{
    // Case 1: ParamType is a Reference or Pointer, but not a Universal Reference
    std::cout << "CASE 1: ParamType is a Reference or Pointer, but not a Universal Reference\n";
    Test(FUNCTION::F1);
    Test(FUNCTION::F2);
    Test(FUNCTION::F3);

    // Case2: ParamType is a Universal Reference
    std::cout << "CASE 2: ParamType is a Universal Reference\n";
    Test(FUNCTION::F4);

    // Case3: ParamType is Neither a Pointer nor a Reference
    std::cout << "CASE 3: ParamType is Neither a Pointer nor a Reference\n";
    std::cout << "Normal: ";
    Test(FUNCTION::F5);

    std::cout << "Special: ";
    Test(FUNCTION::F6);

    // Array arguments
    //std::cout << "Array arguments: \n";
    //Test(FUNCTION::F7);
}
