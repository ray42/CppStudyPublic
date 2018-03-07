#ifndef HEADER_CORE_H
#define HEADER_CORE_H

#include "grade.h"

#include<iostream>
#include<vector>
#include<sstream>
//#include "Student_info.h"

//      core: name, midterm, final,         homework....
//      grad: name, midterm, final, thesis, homework....
class Core
{
  friend class Student_info;

public:
  Core():midterm(0),final(0)
  {
    std::cout << "Core default constructor" << std::endl;
  }

  Core(std::istream& is)
  {
    read(is);
    std::cout << "Core stream constructor" << std::endl;
  }

  virtual ~Core(){}
  
  std::string name() const;

  virtual std::istream& read(std::istream&);

  virtual double grade() const;

//  // Check whether a student has done all the homework.
//  bool did_all_hw(const Student_info& s) const
//  {
//    return ((find(s.homework.begin(),s.homework.end(),0)) 
//        == s.homework.end());
//  }

  std::istream& read_hw(std::istream& in)
  {
    if(in)
    {
      // get rid of previous contents
      this->homework.clear();
  
      // read homework grades
      double x;
      while(in >> x)
      {
        this->homework.push_back(x);
      }
  
      // clear the stream so that input will work for the next student
      in.clear();
    }
    return in;
  }

  virtual std::string to_string() const;




protected:

  virtual Core* clone() const{return new Core(*this);}

  // accessible to derived classes
  std::istream& read_common(std::istream& in);

  double midterm, final;
  std::vector<double> homework;


private:
  // accessible only to Core
  std::string n;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

std::string Core::name() const
{
  std::cerr << "Core::name() const" << std::endl;
  return n;
}

double Core::grade() const
{
  std::cerr << "Core::grade() const" << std::endl;
  return ::median_grade(midterm,final,homework);
}

std::istream& Core::read_common(std::istream& in)
{
  // read and store the student's name and exam grades
  in >> n >> midterm >> final;
  return in;
}


std::istream& Core::read(std::istream& in)
{
  read_common(in);
  read_hw(in);
  return in;
}


std::string Core::to_string() const
{
  std::ostringstream ss;
  ss << "Core, n: " << this->name() 
     << ", mid: " << midterm 
     << ", fin: " << final << ", hw: ";
  for(std::vector<double>::const_iterator it = homework.begin();
      it != homework.end(); ++it)
  {
    ss << (*it) << " ";
  }

  return ss.str();
}


#endif


