#include"String18.h"
#include<algorithm>
#include<iostream>
using std::cout; using std::endl;
#include<iterator>


std::allocator<char> String::alloc;
bool String::raydebug = false;

////////////////////////////////////////////////////////////////////////////
//Private helpers

// Allocate and copy range [b, e)
std::pair<char*,char*>
String::alloc_n_copy(const char*b, const char*e)
{
  auto str = alloc.allocate(e-b);
  return{str,std::uninitialized_copy(b,e,str)};
}

// Calls alloc_n_copy and also sets the elements and end pointers.
void String::range_initializer(const char*first, const char* last)
{
  auto newstr = alloc_n_copy(first,last);
  elements = newstr.first;
  one_past_end = newstr.second;
}

////////////////////////////////////////////////////////////////////////////
// Constructors.
String::String(const char* s)
: elements(nullptr), one_past_end(nullptr)
{
  const char *s1 = s;
//  char *s1 = const_cast<char*>(s);

  // increment s1 until the null terminal, i.e. 
  // 0 1 2 3 4 5  6
  // H e l l o \0
  //           ^ s1 will be here.
  while(*s1) 
  {
//    cout << *s1 <<", " << s1-s << endl;
    ++s1;
  }

  // right now, s1-s = 5-0 = 5. 
  // This is enough to hold the word, but we need one past the end.
  // So we postfix increment s1.
  range_initializer(s,++s1);
}

////////////////////////////////////////////////////////////////////////////
//Big five:

// copy constructor
String::String(const String& s)
:elements(nullptr),one_past_end(nullptr)
{
  if(raydebug)
  {
    std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
  }
  range_initializer(s.elements,s.one_past_end);
}

// copy assignment op
String& String::operator=(const String& rhs)
{
  if(raydebug)
  {
    std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
  }

  auto newstr = alloc_n_copy(rhs.elements, rhs.one_past_end);
  free();
  elements = newstr.first;
  one_past_end = newstr.second;
  return *this;
}

String::String(String&& s) noexcept
:elements(s.elements), one_past_end(s.one_past_end)
{
  if(raydebug)
  {
    std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
  }

  s.elements=s.one_past_end=nullptr;
}

String& String::operator=(String&& rhs) noexcept
{
  if(this != &rhs)
  {
    free();
    elements = rhs.elements;
    one_past_end = rhs.one_past_end;

    rhs.elements = rhs.one_past_end = nullptr;
  }
  return *this;
}


void String::free()
{
  if(elements)
  {
    std::for_each(elements,one_past_end,
        [](char&c)
        {
          alloc.destroy(&c);
        });
  }
}


String::~String()
{
  free();
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const String & s)
{
  std::transform(s.elements,s.one_past_end,std::ostream_iterator<char>(os,""),
      [](char& c)
      {
        return c;
      });
  return os;
}

bool operator==(const String& lhs, const String& rhs)
{
  // better way to compare two ranges, from moophy:
  return (lhs.size() == rhs.size()) 
         && std::equal(lhs.elements, lhs.one_past_end, rhs.elements);
//  if(lhs.size() != rhs.size())
//    return false;
//  else
//  {
//    for(const char *lhsc = lhs.elements, *rhsc = rhs.elements;
//        lhsc != lhs.one_past_end; ++lhsc, ++rhsc)
//    {
//      if(*lhsc != *rhsc)
//      {
//        return false;
//      }
//    }
//    return true;
//  }
}

bool operator!=(const String& lhs, const String& rhs)
{
  return !(lhs == rhs);
}

// exer14-18 relational operators
bool operator<(const String&lhs, const String&rhs)
{
  return std::lexicographical_compare(lhs.elements,lhs.one_past_end,
                                      rhs.elements,rhs.one_past_end);  
}

bool operator>(const String&lhs, const String&rhs)
{
  return rhs < lhs;
}

bool operator<=(const String&lhs, const String&rhs)
{
  // lhs<=rhs == !(lhs>rhs) == !(rhs<lhs)
  return !(rhs<lhs);
}

bool operator>=(const String&lhs, const String&rhs)
{
  // lhs>=rhs == !(lhs<rhs)
  return !(lhs<rhs);
}
