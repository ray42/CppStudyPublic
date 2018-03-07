#include <iostream>
#include <string>

// say that standard-library names we use

using std::cin; using std::endl;
using std::cout;  using std::string;

int main()
{
  // ask for the person's name
  cout << "Please enter your first name: ";

  // read the name
  string name;
  cin >> name;

  // build the message that we intend to write
  const string greeting = "Hello, " + name + "!";

  // the number of blanks surrounding the greeting
  unsigned pad_side;
  unsigned pad_topbot;

  cout << "Supply two numbers for side and top/bot padding: ";

  // sweet, because the result is of type istream, also it's left 
  // associative. I really understand this now!
  cin >> pad_side >> pad_topbot;

  // the number of rows and columns to write
  // "3" for greeting row, top and bot asterisks
  const unsigned rows = pad_topbot*2+3;
  // "2" for left and right asterisks
  const string::size_type cols = greeting.size()+pad_side*2+2;

  // write a blank line to separate the output from the input
  cout << endl;

  // write rows number of rows of output
  // invariant: we have written r rows so far
  for(unsigned r = 0; r!=rows; ++r)
  {
    // counter for column
    string::size_type c = 0;
    
    // invariant: we have written c characters so far in the current row
    while (c != cols)
    {
      // is it time to write the greeting?
      if( r == pad_topbot+1 && c==pad_side+1)
      {
        cout << greeting;
        c+= greeting.size();
      }
      else
      {
        // are we on the border?
        if(r == 0 || r == rows-1 ||
           c == 0 || c == cols-1)
        {
          cout << "*";
        }
        else
        {
          cout << " ";
        }
        ++c;
      }
    }
    cout << endl;
  }
  return 0;
}
