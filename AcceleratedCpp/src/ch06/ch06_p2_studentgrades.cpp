#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::cin; using std::setprecision;
using std::cout; using std::sort; using std::ostream;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;
using std::list;

// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
  return grade(s) < 60;
}

// returns true if s's grade is more than 60.
// i.e. returns true if pass.
bool pgrade(const Student_info& s)
{
  return !fgrade(s);
}

// This is 6.3 - classifying students re-visited
vector<Student_info>
extract_fails(vector<Student_info>&students)
{
  vector<Student_info> fail;

  // All the pass grades are removed, and the rest is copied into
  // fail.
  remove_copy_if(students.begin(),students.end(),back_inserter(fail),pgrade);

  // Okay, this is easy to understand, read p170.
  // remove_if copies each element for which the predicate is false to the 
  // beginning of students , and left the rest of the elements alone. Thus,
  // all pass grades are at the front now.
  //
  // remove_if returns an iterator that refers to one 
  // past the last element that it did not "remove". Thus we can use it to
  // erase from that, until the end.
  students.erase(remove_if(students.begin(),students.end(),fgrade),
    students.end());
  
  return fail;
}

// READ p171, this is neat. Partitions are neat!
vector<Student_info>
extract_fails_with_partition(vector<Student_info>& students)
{
  vector<Student_info>::iterator iter = 
    stable_partition(students.begin(),students.end(),pgrade);
  vector<Student_info> fail(iter,students.end());
  students.erase(iter,students.end());
  return fail;
}

// version 4: use list instead of vector
list<Student_info> extract_fails(list<Student_info>& students)
{
  list<Student_info> fail;
  list<Student_info>::iterator iter = students.begin();

  while(iter != students.end())
  {
    if(fgrade(*iter))
    {
      fail.push_back(*iter);
      iter = students.erase(iter);
    }
    else
    {
      ++iter;
    }
  }
  return fail;
}

double grade_aux(const Student_info& s)
{
  try{
    return grade(s);
  }catch(domain_error)
  {
    return grade(s.midterm,s.final,0);
  }
}


double median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;

  transform(students.begin(),students.end(),
      back_inserter(grades),grade_aux);

  return median(grades);
}

double average_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(),students.end(),
      back_inserter(grades),average_grade);
  return median(grades);
}

// median of the nonzero elements of s.homework, or 0 if no such element
// exist
double optimistic_median(const Student_info& s)
{
  vector<double> nonzero;
  remove_copy(s.homework.begin(),s.homework.end(),
      back_inserter(nonzero),0);

  if(nonzero.empty())
  {
    return grade(s.midterm,s.final,0);
  }
  else
  {
    return grade(s.midterm,s.final,median(nonzero));
  }
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(),students.end(),
      back_inserter(grades),optimistic_median);
  return median(grades);
}


void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did) <<
    ", median(didnt)=" << analysis(didnt) << endl;
}


int main()
{
  // students who did and didn't do all their homework
  vector<Student_info> did,didnt;


  // read all the record, separating them based on whether all homework was
  // done
  Student_info student;
  while(read(cin,student))
  {
    if(did_all_hw(student))
      did.push_back(student);
    else
      didnt.push_back(student);
  }

  // check that both groups contain data
  if(did.empty())
  {
    cout << "No student did all the homework!" << endl;
    return 1;
  }

  if(didnt.empty())
  {
    cout << "Every student did all the homework!" << endl;
    return 1;
  }

  // do the analyses
  write_analysis(cout,"median",median_analysis,did,didnt);
  write_analysis(cout,"average",average_analysis,did,didnt);
  write_analysis(cout,"median of homework turned in",
      optimistic_median_analysis,did,didnt);

  cout << "Hello from Student Grades" << endl;


//  vector<Student_info> students;
//  Student_info record;
//  string::size_type maxlen=0; // length of the longest name
//
//  // read and store all the students data.
//  // Invariant: students contains all the student records so far
//  // maxlen constains the length of the longest name in students
//  while(read(cin,record))
//  {
//    // find length of longest name
//    maxlen = max(maxlen,record.name.size());
//    students.push_back(record);
//  }
//
//  // alphabetize the student records
//  sort(students.begin(),students.end(),compare);
//
//  // write the names and grades
//  for(vector<Student_info>::size_type i = 0;
//      i != students.size(); ++i)
//  {
//    // write the name, padded on the right to maxlen+1 characters
//    cout << students[i].name
//      << string(maxlen+1 - students[i].name.size(),' ');
//
//    // compute and write the grade
//    try{
//      double final_grade = grade(students[i]);
//      streamsize prec = cout.precision();
//      cout << setprecision(3) << final_grade
//        << setprecision(prec);
//    }catch(domain_error e){
//      cout << e.what();
//    }
//    cout << endl;
//  } // for

  // Successful return
  return 0;
}
