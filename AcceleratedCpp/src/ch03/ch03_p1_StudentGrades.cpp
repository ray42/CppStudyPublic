#include<iomanip> // setprecision
#include<ios> // streamsize
#include<iostream> // cin, cout and endl, endl is a manipulator but it's 
// definition is in iostream because it's used so often.
#include<string> // std::string

using std::cin;  using std::setprecision;
using std::cout;  using std::string;
using std::endl;  using std::streamsize;

// NOTE: I know that I don't have to qualify names with the namespace std
// but it's good practice for me at the moment.
int main()
{
  // ask for and read the student's name
  std::cout << "Please enter your first name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name << "!" << std::endl;

  // ask for and read the midterm and final grades
  std::cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  std::cin >> midterm >> final;

  // ask for the homework grades
  std::cout << "Enter all your homework grades, "
               "followed by end-of-file: ";

  // the number and sum of grades read so far
  int count = 0;
  double sum = 0.0;

  // a variable into which to read
  double x;

  // invariant:
  // we have read count (number of) grades so far, and
  // sum is the sum of the first count grades
  //
  // RRR: Because cin has type istream, which is a part of the standard 
  // library, we must look to the definition of istream for the meaning of
  // if(cin) or while(cin).
  while(std::cin >> x)
  {
    ++count;
    sum+=x;
  } // while

  // write stuff
  std::streamsize prec = std::cout.precision();
  std::cout << "Your final grade is " << std::setprecision(3)
            << 0.2*midterm+0.4*final+0.4*sum/count
            << std::setprecision(prec) << std::endl;

  return 0;
} // main
