#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error; using std::vector;

// definition for the grade functions
// compute a student's overall grade from midterm and final grades
// and homework grade
double grade(const double& midterm, const double& final,
             const double& homework)
{
  return 0.2*midterm+0.4*final+0.4*homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its arguments, because median does so for us.
double grade(const double& midterm, const double& final,
             const vector<double>& hw)
{
  if(hw.size()==0)
  {
    throw domain_error("student has done no homework");
  }
  return grade(midterm,final,median(hw));
}

double grade(const Student_info& s)
{
  return grade(s.midterm,s.final,s.homework);
}




