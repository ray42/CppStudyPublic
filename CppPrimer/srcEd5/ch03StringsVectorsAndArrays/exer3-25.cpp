#include<iostream>
#include<vector>
#include<sstream>

using std::cout; using std::endl; using std::cin;
using std::vector;
using std::istringstream;

int main()
{
  // Rewrite the grade clustering program from § 3.3.3 (p. 142) (listing 3.1
  // (p. 144)) using iterators instead of subscripts.

  istringstream iss("42 65 95 100 39 67 95 76 88 76 83 92 76 93");

  // count the number of grades by clusters of ten:
  // 0--9, 10--19, ... 90--99, 100
  vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
  unsigned grade;
  while (iss >> grade) {
  //read the grades
  if (grade <= 100)
  //handle only valid grades
  ++*(scores.begin()+( grade/10));
  }

  for(auto i : scores)
  {
    cout << i << " ";
  }
  cout << endl;

  // Output should be: 0 0 0 1 1 0 2 3 2 4 1
  return 0;
}



