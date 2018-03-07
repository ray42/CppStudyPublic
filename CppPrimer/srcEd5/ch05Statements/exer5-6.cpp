/*
 * =========================================================================
 *        Zwei
 * =========================================================================
 */
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;
using std::istringstream;

int main()
{
  vector<string> scores = {"F","D","C","B","A","A++"};
  
  unsigned grade(0);

  istringstream ss("0 59 60 69 70 79 80 89 90 99 100");

  while(ss >> grade)
  {
    string lettergrade= grade < 60? scores[0] : scores[(grade-50)/10];

    // Now determine if we need a + or - (or nothing)
    // We only have + or - for grades between [60,100)
    (grade >= 60 && grade < 100)? lettergrade +=
    {
      (grade % 10 > 7)? "+": 
      ((grade % 10 < 3)? "-": "")
    }
      
      :"" ;
        
    cout << "Score: " << grade << ", grade: " << lettergrade << endl;
  }
  return 0;
}
