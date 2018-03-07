#ifndef GUARD_PERSON_H
#define GUARD_PERSON_H

#include<string>
#include<iostream>

class Person
{

public:
  Person():name(""),address(""){}
  Person(const std::string &n, const std::string& a):name(n),address(a){}
  Person(std::istream &is){read(is,*this);}


  std::string get_name() const
  {
    return name;
  }

  std::string get_address() const
  {
    return address;
  }


  std::string name;
  std::string address;
};

std::ostream& print(std::ostream&, const Person&);
std::istream& read(std::istream&, Person&);

std::ostream& print(std::ostream& os, const Person& p)
{
  os << p.get_name() << " " << get_address();
  return os;
}

std::istream& read(std::istream is, Person& p)
{
  is >> p.name >> address;
  return is;
}


#endif
