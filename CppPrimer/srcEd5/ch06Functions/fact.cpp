#include<iostream>
using std::cerr; using std::endl;

#include<stdexcept>
using std::domain_error;

#include "Chapter6.h"

unsigned fact(unsigned val)
{
  try{
    if(val > 12) throw domain_error("val! for val > 12 will overflow");

    unsigned ret = 1;
    while (val > 1)
    {
      ret *= val--;
    }
    return ret;

  } catch(domain_error err){
    std::cerr << "On no: " << err.what() << endl;
    throw domain_error("Please help.");
//    return -1;
  }
}


