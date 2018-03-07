#ifndef GUARD_grade_h
#define GUARD_grade_h
// grade.h
#include <vector>
#include "Student_info.h"

double grade(const double& midterm, const double& final, 
             const double& homework);
double grade(const double& midterm, const double& final,
             const std::vector<double>& hw);
double grade(const Student_info& s);

#endif

