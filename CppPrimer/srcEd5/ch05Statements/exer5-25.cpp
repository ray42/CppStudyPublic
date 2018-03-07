#include<iostream>
using std::cout; using std::endl; using std::cin;

#include<stdexcept>
using std::domain_error;

// Exercise 5.25: Revise your program from the previous exercise to use a 
// try block to catch the exception. The catch clause should print a message
// to the user and ask them to supply a new number and repeat the code 
// inside the try .
int main()
{
  int i=0, j = 0;

  while(cin>>i>>j)
  {
    try{
      if(j == 0) throw domain_error("zero denominator");
      cout << i/j << endl;
    }catch(domain_error err){
      cout << err.what() << endl;
      char c;
      cout << "Try again? y/n" << endl;
      cin >> c;
      if(!cin || c == 'n')
        break; // break out of while if not successful read or no.
    }
  }
  return 0;
}
