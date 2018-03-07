#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<ios>
#include<iomanip>
#include<stdexcept>

#include "Student_info.h"


using std::cout; using std::endl; using std::cin;
using std::vector;
using std::string;
using std::max; using std::sort;
using std::streamsize;
using std::setprecision;
using std::domain_error;


int main(int argc, char** argv)
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // read and store the data
  while(record.read(cin))
  {
    maxlen = max(maxlen,record.name().size());
    students.push_back(record);
  }

  // alphabetize the student records
  sort(students.begin(),students.end(),Student_info::compare_names);

  // write the names and grades
  for(vector<Student_info>::size_type i = 0;
      i != students.size(); ++i)
  {
    cout << students[i].name()
      << string(maxlen+1 - students[i].name().size(),' ');
    try{
      double final_grade = students[i].grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
        << setprecision(prec) << endl;
    }
    catch(domain_error e){
      cout << e.what() << endl;
    }
  }

  cout << "Got to ch13.5 end" << endl;
  return 0;
}


