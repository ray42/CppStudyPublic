/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<cstddef> // size_t

#include<sstream>
using std::istringstream;

void resizeArray(char *&orig, size_t &size)
{
  cout << "Resize from " << size << " to " << 2*size << endl;
  size*=2;
  char * resized = new char[size*2];
  for(size_t i = 0; i < size; ++i)
  {
    resized[i] = orig[i];
  }
  delete [] orig;
  orig = resized;
}


int main()
{
  istringstream iss("123456789qwertyuiop");
  size_t size = 1;
  size_t numC = 0;
  char * c_ptr = new char[size];

  char c;
  while(iss >> c)
  {
    if(numC == size)
      resizeArray(c_ptr,size);

    c_ptr[numC++] = c;
  }

  cout << c_ptr << endl;
  delete [] c_ptr;

  return 0;
}
