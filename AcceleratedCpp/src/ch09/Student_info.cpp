#include <algorithm>

// source file for Student_info-related functions
#include "Student_info.h"

#include "grade.h"


using std::istream; using std::vector;
using std::find;

Student_info::Student_info():midterm(0),final(0){}


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
  return x.name() < y.name();
}

istream& Student_info::read(istream& in)
{
  // read and store the student's name and midterm and final exam grades
  in >> this->n >> this->midterm >> this->final;

  // read and store all the student's homework grades
  read_hw(in,homework);
  return in;
}

double Student_info::grade() const
{
  return ::grade(midterm,final,homework);
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
