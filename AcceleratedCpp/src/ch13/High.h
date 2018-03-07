#ifndef HEADER_HIGH_H
#define HEADER_HIGH_H

#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

class High: public Grad
{
public:
  High():thesis(0)
  {
    std::cout << "High default constructor" << std::endl;
  }

  High(std::istream& is)
  {
    read(is);
    std::cout << "High stream constructor" << std::endl;
  }

  double grade() const; // this is virtual

  std::istream& read(std::istream&); // this is virtual

  std::string to_string() const
  {
    std::ostringstream ss;
    ss << "n: " << this->name()
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

private:
  double thesis;
};


std::istream& High::read(std::istream& in)
{
  Core::read_common(in);
  in>>thesis;
  Core::read_hw(in);
  return in;
}

double High::grade() const
{
  std::cout << "Got into High::grade()" << std::endl;
  return std::min(Grad::grade(),thesis);
//  return 0;
}


#endif





