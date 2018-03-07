#ifndef RAYSTRING_H
#define RAYSTRING_H

#include<memory>
#include<utility>
#include<iostream>

class String
{
friend std::ostream& operator<<(std::ostream&,const String&);
friend bool operator==(const String&, const String&);
friend bool operator!=(const String&, const String&);

public:
  static bool raydebug;

  using size_type = size_t;


  // default constructor calls String(const char*)?
  String():String(""){}
  String(const char*);

  // copy constructor
  String(const String&); // TODO
  // copy assign op
  String& operator=(const String&); // TODO
  // move c-tor
  String(String&&) noexcept; //TODO
  // move assign op
  String&operator=(String&&) noexcept; // TODO
  ~String(); // TODO

  const char * c_str() const { return elements; }

  // number of characters.
  // one_past_end-elements is 1 for the empty string.
  // we must minus 1 from it.
  size_type size() const { return one_past_end - elements-1; }

  std::ostream& printall(std::ostream& os = std::cout);

private:
  std::pair<char*,char*> alloc_n_copy(const char*, const char*);
  void range_initializer(const char*, const char*);
  void free();

private:
  char *elements;
  char* one_past_end;
  static std::allocator<char> alloc;
};

std::ostream& operator<<(std::ostream&,const String&);

bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);

#endif
