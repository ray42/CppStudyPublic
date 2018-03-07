#ifndef EMPLOYEE_HEADER
#define EMPLOYEE_HEADER

#include<string>


class Employee
{
public:
  Employee();
  Employee(const std::string&);

  // copy constructor
  Employee(const Employee&) = delete;
  // copy assignment operator
  Employee& operator=(const Employee&) = delete;

  const std::string& name() const;
  const unsigned& id() const;

  std::string print() const;

private:
  std::string Name;
  unsigned Id;

  static unsigned ID;
};




#endif

