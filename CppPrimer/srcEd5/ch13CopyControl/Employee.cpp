#include<string>
using std::string;
#include<sstream>
using std::ostringstream;

#include "Employee.h"


unsigned Employee::ID = 0;


Employee::Employee():Name(""),Id(ID++){}
Employee::Employee(const string& n):Name(n),Id(ID++){}


const string& Employee::name()const{return Name;}
const unsigned& Employee::id()const{return Id;}

string Employee::print() const
{
  ostringstream oss;
  oss << "N: " << Name << ", Id: " << Id;
  return oss.str();
}
