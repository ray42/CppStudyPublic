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
    string lettergrade;
    if(grade < 60)
    {
      lettergrade=scores[0];
    }
    else
    {
      lettergrade = scores[(grade-50)/10];

      if (grade != 100)
      {
        if(grade % 10 >7)
        {
          lettergrade += "+";
        }
        else if(grade % 10 < 3)
        {
          lettergrade +="-";
        }
      }
    }
    cout << "Score: " << grade << ", grade: " << lettergrade << endl;
  }
  return 0;
}
