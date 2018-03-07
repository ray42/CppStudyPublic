#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<ios>
#include<iomanip>
#include<stdexcept>



#include "Core.h"
#include "Grad.h"
//#include "Student_info.h"
#include "Handle.h"

using std::cout; using std::endl; using std::cin;
using std::vector;
using std::string;
using std::istringstream;
using std::max; using std::sort;
using std::streamsize;
using std::setprecision;
using std::domain_error;


int main(int argc, char** argv)
{

  cout << "\n";

  // First check Core class
  // Recall that to construct a Core object, it must take an istream 
  // which has the following: name, midterm, final, homework...

  // Test default constructor:
  cout << "Test1: Core default constructor" << endl;
  Core c1;
  cout << "c1 str: " << c1.to_string() << endl;
  cout << "\n";

  // Core stream constructor
  cout << "Test2: Core istream constructor" << endl;
  string str = "A 1 2 3 4 5 6 7 8";
  istringstream iss;
  iss.str(str);
  Core c2(iss);
  cout << "c2 str: " << c2.to_string() << endl;
  cout << "\n";

  // The grade is worked out by this formula:
  // 0.2*midterm, 0.4*final + 0.4*(median(hw))
  // So for the above, it should be:
  // 0.2*1 + 0.4*2 + 0.4*median(3 4 5 6 7 8) = 0.2*1+0.4*2+0.4*5.5 = 3.2
  cout << "Test3: Core::grade()" << endl;
  cout << "c2grade: " << c2.grade() << endl;
  cout << "\n";

  //////////////////////////////////////////////////////////////////////////
  
  // Do the same thing for Grad
  cout << "Test4: Grad default constructor" << endl;
  Grad g1;
  cout << "g1 str: " << g1.to_string() << endl;
  cout << "\n";
  
  cout << "Test5: Grad stream constructor" << endl;
  iss.str(str);
  Grad g2(iss);
  cout << "g2 str: " << g2.to_string() << endl;
  cout << "\n";

  cout << "Test6: Grad::grade()" << endl;
  cout << "g2grade: " << g2.grade() << endl;
  cout << "\n";
  

  //////////////////////////////////////////////////////////////////////////
  // Testing the Handle class
  
  // 1) Testing default constructor
  cout << "Test7: Handle default constructor" << endl;
  Handle<Core> handle1;
  cout << "\n";

  // Testing copy constructor
  cout << "Test8: Handle copy constructor" << endl;
  Handle<Core> handle2(handle1);
  cout << "\n";

  // testing assignment
  cout << "Test9: Handle assignment constructor\n"
       << "T& Handle<T>::operator=(const Handle& rhs)" << endl;
  Handle<Core> handle3 = handle2;
  cout << "\n";

  // testing Handle<T>(T*) constructor
  cout << "Test10: Handle pointer constructor" << endl;
  iss.str(str);
  Handle<Core> handle4(new Grad(iss));
  cout << "\n";

  // testing * operator
  cout << "Test11: T& Handle<T>::operator*()" 
       << endl;
  cout << (*handle4).name() << endl;
  cout << "\n";

  // testing operator->
  cout << "Test12: T* Handle<T>::operator->()" << endl;
  cout << handle4->name() << endl;
  cout << "\n";

  //////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////
  // Okay, now on to the main program from the book, p358
  vector<Handle<Core> > students; // changed type

  cout << "Creating Handle<Core> using default constructor" << endl;
  Handle<Core> record; // changed type
  cout << "\n";
  char ch;
  string::size_type maxlen = 0;

  // read and store the data
  while(cin >> ch)
  {
    if(ch == 'U')
    {
      cout << "Creating Core and assigning it to Handle<Core>" << endl;
      record = new Core; // allocate a Core object
      cout << "DONE Core\n" << endl;
    }
    else
    {
      cout << "Creating Grad and assigning it to Handle<Core>" << endl;
      record = new Grad; // allocate a Grad object
      cout << "DONE Grad\n" << endl;
    }

    record->read(cin); // Handle<T>::->, then virtual call to read
    maxlen = max(maxlen, record->name().size()); // Handle<T>::->

    cout << "vector<Handle<Core> >::push_back(Handle<Core>)" << endl;
    students.push_back(record);
    cout << "\n";
  }

  // compare must be rewritten to work on const Handle<Core>&
  sort(students.begin(),students.end(),Handle<Core>::compare_Core_handles);

  // write the names and grades
  for(vector<Handle<Core> >::size_type i=0;
      i != students.size(); ++i){
    // students[i] is a Handle, which we dereference to call the functoins
    cout << students[i]->name()
         << string(maxlen + 1 - students[i]->name().size(),' ');
    try{
      double final_grade = students[i]->grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
           << setprecision(prec) << endl;
    } catch(domain_error e){
      cout << e.what() << endl;
    } // try/catch
    // no delete statement
  } // for


  cout << "Got to end of ch14_1" << endl;
  return 0;
}



