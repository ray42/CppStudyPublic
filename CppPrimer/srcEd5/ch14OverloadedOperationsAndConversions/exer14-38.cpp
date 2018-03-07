/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl; using std::cin;

#include<ios>
using std::streamsize;

#include<cstddef>

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<fstream>
using std::ifstream;

#include<algorithm>
using std::for_each;

#include <limits>

//#include<functional> // for bind
//using std::bind;
//using namespace std::placeholders; // for _1, _2, etc....


//exer:14-38
//Write a class that tests whether the length of a given string matches
//a given bound. Use that object to write a program to report how many words
//in an input file are of sizes 1 through 10 inclusive.
//exer:14-39
//Revise the previous program to report the count of words that are sizes 1
//through 9 and 10 or more.
//
//I'm a bit confused by all of this. What I'll do is return a bool to true 
//if the size of the string is within a given inclusive range.
class isBounded
{
public:

  isBounded(size_t l = 0, size_t u = 0):lower_(l),upper_(u)
  { /* empty */ }

  bool operator()(const string& s) const
  {
    return (s.size() >= lower_) && (s.size() <= upper_);
  }

  void printbounds() const
  {
    cout << "lower: " << lower_ << ", upper: " << upper_ << endl;
  }

private:
  std::size_t lower_;
  std::size_t upper_;
};


int main()
{
  size_t lower = 1;
  size_t upper = 16;
  vector<isBounded> bounds;
  vector<unsigned> results(upper,0);
  for(size_t i = 1; i <= upper; ++i)
  {
    bounds.push_back(isBounded(lower,i));
  }

//  bounds[0].printbounds();
//  bounds[1].printbounds();
//  bounds[2].printbounds();
//  bounds[3].printbounds();
//  bounds[4].printbounds();
//  bounds[5].printbounds();
//  bounds[6].printbounds();
//  bounds[7].printbounds();


//  cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

  ifstream ifs;
  ifs.open("./../common/loremipsum-9para.txt");

  if(!ifs.is_open()) return 1;

  string word;
  while(ifs >> word)
  {

    for(size_t i = 0; i < upper; ++i)
    {
      if(bounds[i](word))
      {
        ++results[i];
      }
    }
  }

  for_each(results.begin(),results.end(),
      [](const unsigned i)
      {
        cout << i << " ";
      });
  cout << endl;



  return 0;
}

