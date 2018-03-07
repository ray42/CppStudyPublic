#ifndef STUDENT_INFO_HEADER
#define STUDENT_INFO_HEADER

#include<iostream>
#include<stdexcept>
#include "Core.h"
//#include "Grad.h"
#include "Handle.h"


class Student_info
{
public:

  // constructors and copy control
  Student_info(){}
  Student_info(std::istream& is){read(is);}

  // copy constructor
  //Student_info(const Student_info&);

  // assignment operator
  //Student_info& operator=(const Student_info&);

  // destructor
  //~Student_info(){delete cp; cp = 0;}

  // operations
  std::istream& read(std::istream&);

  std::string name() const
  {
    if(cp) return cp->name();
    else
      throw std::runtime_error("Uninitialized Student");
  }

  double grade() const
  {
    if(cp) return cp->grade();
    else throw std::runtime_error("Uninitialized Student");
  }

  static bool compare_names(const Student_info& s1,
      const Student_info& s2)
  {
    return s1.name()<s2.name();
  }

private:
  Handle<Core> cp;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// read in
std::istream& Student_info::read(std::istream& is)
{
  char ch;
  is >> ch; // get record type

  // allocate new object of the appropriate type
  // use Handle<T>(T*) to build a Handle<Core> from the pointer to that object
  // call Handle<T>::operator= to assign the Handle<Core> to the lhs
  if(ch == 'U'){
    cp = new Core(is);
  }else{
    cp=new Grad(is);
  }
  return is;
}

////////////////////////////////////////////////////////////////////////////
// copy constructor
Student_info::Student_info(const Student_info& s):cp(0)
{
  if(s.cp)cp=s.cp->clone();
}

////////////////////////////////////////////////////////////////////////////
// assignment operator
Student_info& Student_info::operator=(const Student_info& s)
{
  if(&s != this)
  {
    delete cp;
    
    if(s.cp)
      cp = s.cp->clone();
    else
      cp=0;
  }

  return *this;
}

#endif



