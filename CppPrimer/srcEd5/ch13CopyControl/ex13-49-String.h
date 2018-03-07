#ifndef EX13_49_RAYSTRING_H
#define EX13_49_RAYSTRING_H

#include<memory>
#include<utility>

class StringTwo
{
public:
  // default constructor calls StringTwo(const char*)?
  StringTwo():StringTwo(""){}
  StringTwo(const char*);
  StringTwo(const StringTwo&);
  StringTwo& operator=(const StringTwo&);
  ~StringTwo();

  StringTwo(StringTwo&&) noexcept;
  StringTwo& operator=(StringTwo&&) noexcept;

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



#endif


