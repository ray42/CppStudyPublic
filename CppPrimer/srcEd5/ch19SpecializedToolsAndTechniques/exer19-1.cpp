/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<cstdlib>
using std::malloc; using std::free;

#include<new>
using std::bad_alloc;

#include<string>
using std::string;


void *operator new(size_t size)
{
  cout << "Using custom operator new" << endl;
  if(void *mem = malloc(size))
    return mem;
  else
    throw bad_alloc();
}

void operator delete(void *mem)noexcept
{
  cout << "Using custom operator delete" << endl;
  free(mem);
}

int main()
{
  string *sp = new string("Hello World");
  delete sp;
  return 0;
}
