/*
 * =========================================================================
 *         Zwei, quatrezwei@gmail.com
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

// Extend the program that assigned high pass, pass, and fail grades to also
// assign low pass for grades between 60 and 75 inclusive. 
//
// Write two versions:
// 1) One version that uses only conditional operators; 
// 2) the other should use one or more if statements. 
//
// Which version do you think is easier to understand and why?
int main()
{
  // h pass   pass     l pass  fail
  // [100 91] [90, 76] [75,60] [59,0]
  
  unsigned grade=0;
  cin >> grade;

  string finalgrade;

  // version 1
  finalgrade=(grade > 90) ? "high pass"
                          : (grade > 75)? "pass"
                                        : (grade>59)?"low pass"
                                                    :"fail";

  // version 2
  if(grade > 90)
    finalgrade = "high pass";
  else if(grade > 75)
    finalgrade = "pass";
  else if(grade > 59)
    finalgrade = "low pass";
  else
    finalgrade = "fail";

  cout << finalgrade << endl;

  return 0;
}
