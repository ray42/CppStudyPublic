/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */

#include "ex13-49-String.h"
#include <vector>
#include <iostream>

// Test reference to http://coolshell.cn/articles/10478.html

void foo(StringTwo x)
{
    std::cout << x.c_str() << std::endl;
}

void bar(const StringTwo& x)
{
    std::cout << x.c_str() << std::endl;
}

StringTwo baz()
{
    StringTwo ret("world");
    return ret;
}

int main()
{
    char text[] = "world";

    StringTwo s0;
    StringTwo s1("hello");
    StringTwo s2(s0);
    StringTwo s3 = s1;
    StringTwo s4(text);
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    StringTwo s5 = baz();

    std::cout << "\nCreating new vector<StringTwo>"<<std::endl;
    std::vector<StringTwo> svec;
    svec.reserve(8);
    std::cout << "\nPushback begins"<<std::endl;
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");

    std::cout << "\nPrinting out."<<std::endl;
    for (const auto &s : svec) {
        std::cout << s.c_str() << std::endl;
    }
}
