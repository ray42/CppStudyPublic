#ifndef GUARD_STR_H
#define GUARD_STR_H

#include<algorithm> // copy
#include<iterator> // back_inserter
#include<cstring> //  strlen
#include<string> // string
#include<sstream> // ostringstream
#include "Vec.h"


class Str
{
  friend std::istream& operator>>(std::istream&, Str&);

  public:
  typedef Vec<char>::size_type size_type;

  // default constructor
  Str(){}

  // create a Str containing n copies of c
  Str(size_type n, char c):data(n,c){}

  // create a Str from a null-terminated array of Char
  Str(const char* cp)
  {
    std::copy(cp,cp+std::strlen(cp),std::back_inserter(data));
  }

  // create a Sr from the range denoted by iterators b and e
  template<class In> Str(In b, In e)
  {
    std::copy(b,e,std::back_inserter(data));
  }

  char& operator[](size_type i)
  {
    return data[i];
  }
  
  const char& operator[](size_type i) const
  {
    return data[i];
  }

  size_type size() const
  {
    return data.size();
  }

  Str& operator+=(const Str& s)
  {
    std::copy(s.data.begin(), s.data.end(),
        std::back_inserter(data));
    return *this;
  }


  std::string to_string()
  {
    std::ostringstream ss;
    Vec<char>::const_iterator it_b = data.begin();
    Vec<char>::const_iterator it_e = data.end();

    while(it_b != it_e)
    {
      ss <<*(it_b++) << " ";
    }
    return ss.str();
  }


  private:
  Vec<char> data;
};

std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

std::ostream& operator<<(std::ostream& os, const Str& s)
{
  Vec<char>::size_type size = s.size();
  for(Str::size_type i = 0; i != size; ++i)
  {
    os << s[i];
  }
  return os;
}

std::istream& operator>>(std::istream& is, Str& s)
{
  // obliterate existing value(s)
  s.data.clear();

  // read and discord leading whitespace
  char c;
  while(is.get(c) && isspace(c))
    ; // nothing to do, except testing the condition

  // if still something to read, do so until next whitespace
  if(is)
  {
    do s.data.push_back(c); // compile error! data is private
    while(is.get(c) && !isspace(c));

    // if we read whitespace, then put it back on the stream
    if(is)
      is.unget();
  }
  return is;
}

Str operator+(const Str& s, const Str& t)
{
  Str r = s;
  r+=t;
  return r;
}

#endif






