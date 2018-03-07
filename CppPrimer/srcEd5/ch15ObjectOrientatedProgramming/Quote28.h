/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 * =========================================================================
 */

#ifndef QUOTE_H
#define QUOTE_H

#include<string>
#include<cstddef>
#include<iostream>
#include"./../common/rr.h"





class Quote
{
public:
  // constructor
  Quote():bookNo("DefaultISBN"), price(1.99)
  {rr::greet(__PRETTY_FUNCTION__,this);}

  // @param: isbn, sale price
  Quote(const std::string &book, double sales_price):
    bookNo(book), price(sales_price){rr::greet(__PRETTY_FUNCTION__,this);}

  // destructor
  virtual ~Quote()
  {rr::greet(__PRETTY_FUNCTION__,this);}

  // c-tor c-assign
  Quote(const Quote& q):bookNo(q.bookNo), price(q.price)
  {rr::greet(__PRETTY_FUNCTION__,this);}

  Quote& operator=(const Quote& rhs)
  {
    rr::greet(__PRETTY_FUNCTION__,this);

    // manually do copy/swap... usually you would make a temp of the rhs
    // then copy the values over from the rhs. This is because if the rhs
    // and this points to the same object, and both manages memory, then
    // we do not want to deallocate memory in this before we copy stuff over
    // since the stuff we copy over will have it's space in memory 
    // deallocated!

    // but this is a simple class which does not manage memory, let's do it
    // a hacky way:
    if(this != &rhs)
    {
      bookNo = rhs.bookNo;
      price = rhs.price;
    }
    
    return *this;
  }

  // Move constructor
  Quote(Quote&& q)noexcept
  : bookNo(std::move(q.bookNo)), price(std::move(q.price))
  {
    rr::greet(__PRETTY_FUNCTION__,this);
    // No need to put q in valid state, nothing to do.
  }

  //  Move assignment operator
  Quote& operator=(Quote&& rhs) noexcept
  {
    rr::greet(__PRETTY_FUNCTION__,this);
    if(this != &rhs)
    {
      bookNo=std::move(rhs.bookNo);
      price=std::move(rhs.price);
      // no need to put rhs in valid state.
    }
    return *this;
  }


//  // NOTE!!!!!
//  // If we were to use h copy-swap idiom, it means we just define the 
//  // copy/move constructor, then define ONE assignment operator which takes
//  // a value. When the rhs is copied, it will either use the copy or move
//  // constructor. Thus, we DO NOT define:
//  // Quote& operator=(Quote& rhs);
//  // Quote& operator=(Quote&& rhs) noexcept;
//  // ONLY:
//  // Quote& operator=(Quote rhs)
//  //
//  // For the sake of this exercise, since I want to see, clearly, the path
//  // the program takes, I will not use this approach.
//  // used for copy/swap idiom
//  void swap(Quote& rhs)
//  {
//    using std::swap;
//    swap(bookNo,rhs.bookNo);
//    swap(price,rhs.price);
//  }
//  // using copy/swap idiom, note: no const and no reference in param, this
//  // is because we want a temp copy of it, so we can swap.
//  // NOTE: Because the rhs is copy-constructed, 
//  // 1) if the rhs is an lvalue, it will use the copy-constructor.
//  // 2) if it's an lvalue, it will use the move-assignment operator.
//  Quote& operator=(Quote rhs)
//  {
//    rr::greet(__PRETTY_FUNCTION__,this);
//    swap(rhs);
//    return *this;
//  }
//
//  // m-tor m-assign
//  Quote(Quote&& q) noexcept
//  : bookNo(std::move(q.bookNo)), price(std::move(q.price))
//  {
//    rr::greet(__PRETTY_FUNCTION__,this);
//    // Nothing to do to put q in a valid state
//  }



  

  std::string isbn() const{return bookNo;}

  // returns the total sales price for the specified number of items
  // derived classes will override and apply different discount algorithms
  virtual double net_price(std::size_t n) const
  {
    return n*price;
  }


//  virtual std::ostream& printstate(std::ostream& os = std::cout) const;

  // ex15-11 debug to display data members of respective class
  virtual auto debug(std::ostream& os=std::cout) const->std::ostream&;

private:
  std::string bookNo; // ISBN number for this item

protected:
  double price = 0.0; // normal, undiscounted price

};


// calculate and print the price for the given number of copies, 
// applying any discounts
double print_total(std::ostream &os,
                   const Quote &item, size_t n);


#endif
