#ifndef HEADER_GRAD_H
#define HEADER_GRAD_H

#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

class Grad: public Core
{
public:
  Grad():thesis(0)
  {
    std::cout << "Grad default constructor" << std::endl;
  }

  Grad(std::istream& is)
  {
    read(is);
    std::cout << "Grad stream constructor" << std::endl;
  }

  // Note: grade and read are virtual by inheritance
  double grade() const;
  std::istream& read(std::istream&);

  std::string to_string() const;

protected:
  Grad* clone() const {return new Grad(*this);}


private:
  double thesis;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

std::istream& Grad::read(std::istream& in)
{
  Core::read_common(in);
  in>>thesis;
  Core::read_hw(in);
  return in;
}

double Grad::grade() const
{
  std::cerr << "Grad::grade() const" << std::endl;
  return std::min(Core::grade(),thesis);
}

std::string Grad::to_string() const
{
  std::ostringstream ss;
  ss << "Grad, n: " << this->name()
     << ", mid: " << this-> midterm
     << ", fin: " << this->final
     << ", the: " << this->thesis 
     << ", hw: ";

  for(std::vector<double>::const_iterator it = homework.begin();
      it != homework.end(); ++it)
  {
    ss << (*it) << " ";
  }
  return ss.str();
}
#endif
