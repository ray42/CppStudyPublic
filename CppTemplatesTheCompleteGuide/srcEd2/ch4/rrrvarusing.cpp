/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include <string>
#include <unordered_set>

class Customer
{
private:
  std::string name;
public:
  Customer(std::string const& n) : name(n) { }
  std::string getName() const { return name; }
};

struct CustomerEq {
  bool operator() (Customer const& c1, Customer const& c2) const {
    cout << "CustomerEq" << endl;
    return c1.getName() == c2.getName();
  }
};

struct CustomerHash {
  std::size_t operator() (Customer const& c) const {
    cout << "CustomerHash" << endl;
    return std::hash<std::string>()(c.getName());
  }
};

// define class that combines operator() for variadic base classes:
template<typename... Bases>
struct Overloader : Bases...
{
  using Bases::operator()...; // OK since C++17
};

int main()
{
  // combine hasher and equality for customers in one type:
  using CustomerOP = Overloader<CustomerHash,CustomerEq>;
  Customer c{"Ray"};
  CustomerOP cop;
  cop(c,c);
  cop(c);
//  std::unordered_set<Customer,CustomerHash,CustomerEq> coll1;
//  std::unordered_set<Customer,CustomerOP,CustomerOP> coll2;
//  ...
}

