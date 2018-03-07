#include <algorithm>

// source file for Student_info-related functions
#include "Student_info.h"



using std::istream; using std::vector;
using std::find;

// Check whether a student has done all the homework.
// This function looks in s.homework to see whether any of the values stored
// is 0. Because we give at least partial credit for any assignment that is
// turned in, a 0 grade means that the assignment was not submitted.
bool did_all_hw(const Student_info& s)
{
  return ((find(s.homework.begin(),s.homework.end(),0)) 
      == s.homework.end());
}


bool compare(const Student_info& x, const Student_info& y)
{
  return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
  // read and store the student's name and midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;

  // read and store all the student's homework grades
  read_hw(is,s.homework);
  return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
  if(in)
  {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while(in >> x)
    {
      hw.push_back(x);
    }

    // clear the stream so that input will work for the next student
    in.clear();
  }
  return in;
}
