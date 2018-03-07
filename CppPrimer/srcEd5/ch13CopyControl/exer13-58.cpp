/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector; using std::sort;

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    vector<int> data;
};

Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    std::cout << "&&" << std::endl; // debug
    return *this;
}

Foo Foo::sorted() const & {
    std::cout << "const &" << std::endl; // debug

    return Foo(*this).sorted(); // Exercise 13.57
}

int main()
{
  std::cout << "Calling && version" << std::endl;
  Foo().sorted(); // call "&&"
  Foo f;
  std::cout << "Calling & version" << std::endl;
  f.sorted(); // call "const &"
}
