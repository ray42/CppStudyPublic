#include<iostream>
#include<vector>
#include<string>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::vector;
using std::string;
using std::to_string;

int main()
{
  // Read a set of integers into a vector. Print the sum of each pair of 
  // adjacent elements. 
  int currentint;
  vector<int> intvec;
  cout << "Please enter a list of integers" << endl;
  while(cin >> currentint)
    intvec.push_back(currentint);

  // Now print the sum of each pair. We need at least two numbers.
  if(intvec.size() < 2)
  {
    cerr << "Please supply at least two numbers" << endl;
  }

  // We go from position 0 to position size-1 and add the current and next
  // value
  for(auto it = intvec.cbegin(); it != (intvec.cend()-1); ++it)
  {
    cout << (*it) + *(it+1) << " ";
  }
  cout << endl;

  // Change your program so that it prints the sum of the first and last
  // elements, followed by the sum of the second and second-to-last, and so 
  // on.
  for(auto lhs=intvec.cbegin(), rhs=intvec.cend()-1; 
      lhs<=rhs; ++lhs,--rhs)
  {
    cout << *lhs + *rhs << " ";
  }
  return 0;
}
