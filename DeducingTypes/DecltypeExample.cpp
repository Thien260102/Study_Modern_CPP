#include "DecltypeExample.h"

#include <iostream>
#include <vector>
#include "../Introduction/Widget.h"

template <typename T> std::string type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
    (
#ifndef _MSC_VER
        abi::__cxa_demangle(typeid(TR).name(), nullptr,
            nullptr, nullptr),
#else
        nullptr,
#endif
        std::free
    );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

void NormalCases()
{
	int i = 0;
	std::cout << "decltype of i: " << type_name<decltype(i)>();

	const int i1 = 1;
    std::cout << "\tdecltype of i1: " << type_name<decltype(i1)>();

    std::vector<int> v1;
    std::cout << "\tdecltype of v1[0]: " << type_name<decltype(v1[0])>();

    //Widget w;
    //const Widget& cw = w;

    //auto myWidget1 = cw;            //type is Widget

    //decltype(auto) myWidget2 = cw;  //type is const Widget&

}

void SpecialCases()
{
    int i = 0;
    std::cout << "\ndecltype of (i): " << type_name<decltype((i))>();

    const int i1 = 1;
    std::cout << "\tdecltype of (i1): " << type_name<decltype((i1))>();

    std::vector<int> v1;
    std::cout << "\tdecltype of (v1[0]): " << type_name<decltype((v1[0]))>();

}


decltype(auto) Decltype_F1()
{
    int x = 0;

    return x;
}

decltype(auto) Decltype_F2()
{
    int x = 0;

    return (x);
}