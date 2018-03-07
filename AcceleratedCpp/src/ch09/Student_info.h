#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include<iostream>
#include<string>
#include<vector>

class Student_info
{
public:
  // constructors:
  Student_info(); // construct an empty Student_info object
  Student_info(std::istream&); // construct one by reading a stream


  std::string name() const { return n; }
  bool valid() const {return !homework.empty();}

  // interface goes here
  std::istream& read(std::istream&);  // must change definition
  double grade() const;

private:
  // implementation goes here
  std::string n;
  double midterm, final;
  std::vector<double> homework;
};



// Check whether a student has done all the homework.
bool did_all_hw(const Student_info& s);

bool compare(const Student_info&, const Student_info&);

std::istream& read_hw(std::istream&,std::vector<double>&);

#endif
