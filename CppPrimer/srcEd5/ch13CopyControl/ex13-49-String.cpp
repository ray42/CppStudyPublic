#include"ex13-49-String.h"
#include<algorithm>
#include<iostream>


std::allocator<char> StringTwo::alloc;

std::pair<char*,char*>
StringTwo::alloc_n_copy(const char*b, const char*e)
{
  auto str = alloc.allocate(e-b);
  return{str,std::uninitialized_copy(b,e,str)};
}

void StringTwo::range_initializer(const char*first, const char* last)
{
  auto newstr = alloc_n_copy(first,last);
  elements = newstr.first;
  end = newstr.second;
}

StringTwo::StringTwo(const char* s)
: elements(nullptr), end(nullptr)
{
  char *s1 = const_cast<char*>(s);
  while(*s1)
    ++s1;
  range_initializer(s,++s1);
}

StringTwo::StringTwo(StringTwo&& s) noexcept
: elements(s.elements), end(s.end)
{
  std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
  s.elements = s.end = nullptr;
}

StringTwo& StringTwo::operator=(StringTwo&& rhs) noexcept
{
  std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
  if(this != &rhs)
  {
    free();
    elements = rhs.elements;
    end = rhs.end;
    rhs.elements = rhs.end = nullptr;
  }

  return *this;
}


StringTwo::StringTwo(const StringTwo&rhs)
:elements(nullptr),end(nullptr)
{
  std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
  range_initializer(rhs.elements,rhs.end);
}

void StringTwo::free()
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

StringTwo::~StringTwo()
{
  free();
}

StringTwo& StringTwo::operator=(const StringTwo& rhs)
{
  std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
  auto newstr = alloc_n_copy(rhs.elements, rhs.end);
  free();
  elements = newstr.first;
  end = newstr.second;
  return *this;
}
