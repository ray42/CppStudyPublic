#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<ios>
#include<iomanip>
#include<stdexcept>

#include "Core.h"
#include "Grad.h"

#include "common_headers.h"

using std::cout; using std::endl; using std::cin;
using std::vector;
using std::max; using std::sort;
using std::string;
using std::streamsize;
using std::setprecision;
using std::domain_error;


namespace Ray
{
  bool Debug = true;
}


int main()
{
  vector<Core*> students; // read and process Core records
  Core* record;
  char ch;
  string::size_type maxlen = 0;

  // read and store the data
  while(cin >> ch){
    if(ch == 'U')
      record = new Core; // allocate a Core object
    else
      record = new Grad; // allocate a Grad object

    record->read(cin); // virtual call
    maxlen = max(maxlen,record->name().size()); // deference
    students.push_back(record);
  }

  // Testing the above.
  if(Ray::Debug)
  {
    cout << "Initial students:" << endl;
    for(vector<Core*>::const_iterator it = students.begin(); 
        it != students.end(); ++it)
    {
      cout << (*it)->to_string() << endl;
    }
  }

  // alphabetize the student records
  sort(students.begin(),students.end(),compare_names_ptrs);
  // Testing the above.
  if(Ray::Debug)
  {
    cout << "Sorted students:" << endl;
    for(vector<Core*>::const_iterator it = students.begin(); 
        it != students.end(); ++it)
    {
      cout << (*it)->to_string() << endl;
    }
  }

  // write the names and grades
  for(vector<Core*>::size_type i = 0; i != students.size(); ++i)
  {
    cout << students[i]->name()
      << string(maxlen+1-students[i]->name().size(),' ');
    try{
      double final_grade = students[i]->grade(); // Core::grade
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
        << setprecision(prec) << endl;
    }catch (domain_error e)
    {
      cout << e.what() << endl;
    }

    delete students[i]; // free the object allocated when reading
  }

  cout << "Got to end of ch 3.3" << endl;
  return 0;
}

















