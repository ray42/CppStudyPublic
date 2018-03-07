#include<iostream>
#include<vector>

using std::cout; using std::endl; 

using std::vector;

int main()
{
  // C++ Primer says:
  // c.insert(p,il)} - il is a braced list of element values. 
  // Inserts the given values before the element denoted by iterator p. 
  // Returns an iterator to the first inserted element.
  //
  // I wondered, what's the first element inserted if I was to insert
  // {1,2,3}, let's find out!

  vector<int> v{4,5,6};
  
  //auto it = v.insert(v.begin(),{-3,-2,-1});
  //Oh no! error: ‘void it’ has incomplete type

  // Maybe auto is confused, let's do it manually:
  //vector<int>::iterator it = v.insert(v.begin(),{-3,-2,-1});
  //Oh no... 
  //error: conversion from ‘void’ to non-scalar type ‘std::vector<int>::iterator

  // I don't understand what's gone wrong. Let's just insert and print it 
  // out.
//  v.insert(v.begin(),{-3,-2,-1});
  for(auto i:v)
    cout << i << " ";

  // Hmmm, this seems to work, output is:
  // -3 -2 -1 4 5 6
  // Ho hum...
  
  return 0;
}
