#include"StringTwo.h"
#include<algorithm>
#include<iostream>
#include<iterator>


std::allocator<char> String::alloc;

std::pair<char*,char*>
String::alloc_n_copy(const char*b, const char*e)
{
  auto str = alloc.allocate(e-b);
  return{str,std::uninitialized_copy(b,e,str)};
}

void String::range_initializer(const char*first, const char* last)
{
  auto newstr = alloc_n_copy(first,last);
  elements = newstr.first;
  end = newstr.second;
}

String::String(const char* s)
: elements(nullptr), end(nullptr)
{
  char *s1 = const_cast<char*>(s);
  while(*s1)
    ++s1;
  range_initializer(s,++s1);
}

String::String(const String&rhs)
:elements(nullptr),end(nullptr)
{
  std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
  range_initializer(rhs.elements,rhs.end);
}

void String::free()
{
  if(elements)
  {
    std::for_each(elements,end,
        [this](char&c)
        {
          alloc.destroy(&c);
        });
  }
}

String::~String()
{
  free();
}

String& String::operator=(const String& rhs)
{
  std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
  auto newstr = alloc_n_copy(rhs.elements, rhs.end);
  free();
  elements = newstr.first;
  end = newstr.second;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const String & s)
{
  std::transform(s.elements,s.end,std::ostream_iterator<char>(os,""),
      [](char c)
      {
        return c;
      });
  return os;
}
