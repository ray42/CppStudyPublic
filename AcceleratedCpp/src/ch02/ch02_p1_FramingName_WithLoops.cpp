#include <iostream>
#include <string>

int main()
{
  // ask for the person's name
  std::cout << "Please enter your first name.";
  
  // read the name
  std::string name;
  std::cin >> name;

  // build the message that we intend to write
  std::string greeting = "Hello, " + name + "!";

  // we have to rewrite this part...


  // the number of blanks surrounding the greeting
  const int pad = 1;

  // total number of rows to write
  const int rows = pad*2+3;

  //RRR Now write the rows:
  
  // separate the output from the input
  std::cout << std::endl;

  // write rows (the number) rows of output
  int r = 0;

  //invariant: we have written r rows so far
  while(r != rows)
  {
    // write a row of output
    const std::string::size_type cols = greeting.size() + pad*2+2;

    std::string::size_type c = 0;

    // invariant: we have written c characters so far in the current row
    while(c!=cols)
    {
      // write one or more characters


      // adjust the value of c to maintain the invariant.
      // NOTE: We have to ensure that the total number of characters we
      // write on this row is exactly cols.
      if(r == 0 || r == rows-1 || c == 0 || c == cols-1)
      {
        std::cout << "*";
        c++;
      }
      else
      {
        // write one or more nonborder characters
        // adjust the value of c to maintain the invariant
        if(r == pad+1 && c== pad+1)
        {
          std::cout << greeting;
          // The invariant is now false, make it true again
          c+=greeting.size();
        }
        else
        {
          // Invariant is now false. Make it true again.
          std::cout << " ";
          c++;
        } // if
      } // else
    } // while c!=cols

    std::cout << std::endl;

    // We have finished writing the row. Loop invariant is now false.
    // Make it true again.
    ++r;
  }


  return 0;
}



