#ifndef RAYSTRING_H
#define RAYSTRING_H

#include<memory>
#include<utility>
#include<iostream>

class String
{
friend std::ostream& operator<<(std::ostream&,const String&);

public:
  // default constructor calls String(const char*)?
  String():String(""){}
  String(const char*);
  String(const String&);
  String& operator=(const String&);
  ~String();

  const char * c_str() const
  {
    return elements;
  }

  size_t size() const
  {
    return end - elements;
  }

//  size_t length() const
//  {
//    return end-elements-1;
//  }

private:
  std::pair<char*,char*> alloc_n_copy(const char*, const char*);
  void range_initializer(const char*, const char*);
  void free();

private:
  char *elements;
  char* end;
  static std::allocator<char> alloc;
};

std::ostream& operator<<(std::ostream&,const String&);



#endif
