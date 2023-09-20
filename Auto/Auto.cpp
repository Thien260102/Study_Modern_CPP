#include <Windows.h>
#include <iostream>
#include <functional>
#include <vector>
#include <unordered_map>


#define RED     12
#define DEFAULT 15
#define BLUE    9

template<typename It>
void dwim(It b, It e);

void Example1();

void Example2();

void Example3();

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, RED);

    std::cout << "Example 1: safer code\n";

    SetConsoleTextAttribute(hConsole, DEFAULT);

    Example1();


    SetConsoleTextAttribute(hConsole, RED);

    std::cout << "Example 2: more concise code\n";

    SetConsoleTextAttribute(hConsole, DEFAULT);

    Example2();


    SetConsoleTextAttribute(hConsole, RED);

    std::cout << "Example 3: more efficient code\n";

    SetConsoleTextAttribute(hConsole, DEFAULT);

    Example3();

    std::cout << "\n\n\n";
}

template<typename It>
void dwim(It b, It e)
{
    while (b != e)
    {
        auto currValue = *b;
        /// do something ....

        break;
    }
}

void Example1()
{
    int x;      // potentially uninitialized in some context. 
    x = 2;
    std::cout << "x: " << x;
    // auto x2; this will be error, so it will be safer.

    auto x3 = 0;
    std::cout << "\tx3: " << x3;

    std::cout << "\n\n";
}

void Example2()
{
    std::unique_ptr<int> p1 = std::unique_ptr<int>(new int(5));
    std::unique_ptr<int> p2 = std::unique_ptr<int>(new int(3));

    auto derefUPLess = [](const std::unique_ptr<int>& p1, const std::unique_ptr<int>& p2)
    {
        return *p1 < *p2;
    };

    // or you can use like this
    auto derefLess = [](const auto& p1, const auto& p2)
    {
        return *p1 < *p2;
    };

    std::cout << "derefUPLess(2, 3): " << derefUPLess(p1, p2);
    std::cout << "\tderefLess(2, 3): " << derefLess(p1, p2);
    std::cout << "\n\n";
}

void Example3()
{
    //Callable object can be: std::function, std::thread::thread, std::bind
    std::function<bool(const std::unique_ptr<int>&,
                       const std::unique_ptr<int>&)>
        derefUPLess = [](const std::unique_ptr<int>& p1,
                         const std::unique_ptr<int>& p2)
                        {
                            return *p1 < *p2;
                        };

    const auto derefLess = [](const auto& p1, const auto& p2)
                        {
                            return *p1 < *p2;
                        };

    // std::function will cost memory more than auto, because it instantiation of the std::function template
    // that have a fixed size for any give signature.
    // whereas auto declare variable holding a closure has a same type as the closure.
    // In other words, the std::function approach is generally biggerand slower than the auto approach, 
    // and it may yield out - of - memory exceptions, too.

    std::vector<int> v;
    unsigned sz = v.size();

    // On 32 - bit Windows, for example, both unsignedand std::vector<int>::size_type
    // are the same size, but on 64 - bit Windows, unsigned is 32 bits, 
    // while std::vector<int>::size_type is 64 bits.This means that code that works under 32 - bit
    // Windows may behave incorrectly under 64 - bit Windows, and when porting your
    // application from 32 to 64 bits, who wants to spend time on issues like that ?

    // so just use 
    auto size = v.size();

    // more example about the advantage of using auto type.
    std::unordered_map<std::string, int> m;

    for (const std::pair<std::string, int>& p : m)
    {
        // do some stuffs
    }

    // it seem perfect but has a problems.
    // remembering that the key part of a std::unordered_map is const
    // it isn't std::pair<std::string, int> "Wrong Type", it's std::pair<const std::string, int> "True Type"
    // so compilers will convert "True Type" to "Wrong Type"

    // so just use like this for better
    for (auto& p : m)
    {
        // do some stuffs
    }

    // it not only efficient, but also easier.
    
    /// <summary>
    /// auto variables must be initialized, are generally immune to type mismatches
    /// that can lead to portability or efficiency problems, can ease the process of
    /// refactoring, and typically require less typing than variables with explicitly
    /// specified types.
    /// auto - typed variables are subject to the pitfalls described in Items 2 and 6.
    /// </summary>

    std::cout << "\n\n";
}