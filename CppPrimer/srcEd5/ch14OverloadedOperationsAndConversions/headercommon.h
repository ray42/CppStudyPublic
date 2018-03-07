#ifndef TESTHEADER_H
#define TESTHEADER_H

#include<iostream>
#include<string>

namespace foonamespace
{
  extern bool debug;
  
  std::ostream& greet(std::ostream& os = std::cout);
}
#endif
