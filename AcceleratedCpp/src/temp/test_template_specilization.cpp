#include<iostream>

#include "test.h"

// note: to be compiled in conjunction with the definitions of Foo above

int main(int argc, char *argv[])
{
    char c = 'c';
    std::string r0, r1, r2, r3;
    // let the compiler resolve the call
    r0 = Foo(c);
    // explicitly specify which function to call
    r1 = Foo<std::string>(c);
    r2 = Foo<std::string, char>(c);
    r3 = Foo<std::string, char>(&c);
    // generate output
    std::cout << r0 << " " << r1 << " " << r2 << " " << r3 << std::endl;
    return 0;
}



