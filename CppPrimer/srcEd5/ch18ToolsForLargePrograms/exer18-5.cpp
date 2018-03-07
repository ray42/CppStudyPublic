/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl; using std::cerr;

#include<cstdlib>
using std::abort;

#include<stdexcept>
#include<exception>

//overflow_error
//underflow_error
//range_error
//
//domain_error
//invalid_argument
//out_of_range
//length_error
//
//
//bad_alloc
//logic_error
//runtime_error
//bad_cast
//
//exception

int main()
{
  static unsigned i = 0;
labeltry:
  try{
    // use of the C++ stdlib goes here
    if(i == 0)
    {
      // Defines a type of object to be thrown as exception. It can be used
      // to report arithmetic overflow errors (that is, situations where a 
      // result of a computation is too large for the destination type)
      throw std::overflow_error("Length error what message");
    }
    else if(i==1)
    {
      // Defines a type of object to be thrown as exception. It may be used 
      // to report arithmetic underflow errors (that is, situations where 
      // the result of a computation is a subnormal floating-point value)
      throw std::underflow_error("Underflow error what message");
    }
    else if(i==2)
    {
      // Defines a type of object to be thrown as exception. It can be used 
      // to report range errors (that is, situations where a result of a 
      // computation cannot be represented by the destination type)
     throw std::range_error("Range error what message");
    }
    else if(i==3)
    {
      // Defines a type of object to be thrown as exception. It may be used 
      // by the implementation to report domain errors, that is, situations 
      // where the inputs are outside of the domain on which an operation is
      // defined.
      throw std::domain_error("Domain error what message");
    }

    // need to do for:
    //invalid_argument: Defines a type of object to be thrown as exception. 
    //It reports errors that arise because an argument value has not been 
    //accepted.
    //
    //out_of_range: Defines a type of object to be thrown as exception. It
    //reports errors that are consequence of attempt to access elements out
    //of defined range.
    //
    //length_error: Defines a type of object to be thrown as exception. It reports errors that are consequence of attempt to exceed implementation defined length limits for some object.
    //
    //
    //bad_alloc std::bad_alloc is the type of the object thrown as exceptions by the allocation functions to report failure to allocate storage.
    
    //logic_error: Defines a type of object to be thrown as exception. It reports errors that are a consequence of faulty logic within the program such as violating logical preconditions or class invariants and may be preventable.

    //runtime_error: Defines a type of object to be thrown as exception. It reports errors that are due to events beyond the scope of the program and can not be easily predicted.
    //
    //bad_cast: An exception of this type is thrown when a dynamic_cast to a reference type fails the run-time check (e.g. because the types are not related by inheritance), and also from std::use_facet if the requested facet does not exist in the locale.
    //
    // exception: Provides consistent interface to handle errors through the throw expression.


  }
  catch(const std::overflow_error &e)
  {
    cerr << "What is: " << e.what() << endl;
    ++i; goto labeltry;
  }
  catch(const std::underflow_error &e)
  {
    cerr << "What is: " << e.what() << endl;
    ++i; goto labeltry;
  }
  catch(const std::range_error &e)
  {
    cerr << "What is: " << e.what() << endl;
    ++i; goto labeltry;
  }
  catch(const std::doamin_error &e)
  {
    cerr << "What is: " << e.what() << endl;
    ++i; goto labeltry;
  }
  catch(const std::exception& e)
  {
    cerr << "Got into final exception" << endl;
    abort();
  }


  return 0;
}

