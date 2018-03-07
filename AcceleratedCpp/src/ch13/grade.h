#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include<stdexcept>

//#include "Student_info.h"

#include "median.h"
#include "average.h"

double grade(const double& midterm, const double& final, 
             const double& homework)
{
  return 0.2*midterm+0.4*final+0.4*homework;
}


double median_grade(const double& midterm, const double& final,
                    const std::vector<double>& hw)
{
  if(hw.size()==0)
  {
    throw std::domain_error("student has done no homework");
  }
  return grade(midterm,final,median(hw));
}

double average_grade(const double& midterm, const double& final,
                     const std::vector<double>& hw)
{
  if(hw.size()==0)
  {
    throw std::domain_error("student has done no homework");
  }
  return grade(midterm,final,average(hw));
}

//double grade(const Student_info& s);

//double average_grade(const Student_info& s);


#endif

