#include<iostream>
#include<vector>
#include<string>

#include "Pic.h"

using std::cout; using std::endl; using std::cin;


int main(int argc, char** argv)
{

  // Testing picture
//  Picture p; // empty picture
//
  std::vector<std::string> initstr;
  initstr.push_back("Hello");

  Picture p =initstr;
  Picture q = frame(p);
  Picture r = hcat(p, q) ;
  Picture s = vcat(q, r);
  // This doesn't work, Ii cba to make it work. Time for Primer!
//  cout << frame(hcat(s, vcat(r, q))) << endl;
  cout << "Got to the end of ch15_1" << endl;
  return 0;
}



