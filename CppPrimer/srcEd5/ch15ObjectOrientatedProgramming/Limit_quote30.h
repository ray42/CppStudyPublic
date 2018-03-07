/*
* =========================================================================
* Copyright (c) 2017, Raymon White - All Rights Reserved
* Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
* Code for the exercises from C++ Primer 5th Edition
* =========================================================================
*/
#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include"Disc_quote30.h" // inherit from this
#include"./../common/rr.h"

#include<string>
#include<cstddef>

class Limit_quote : public Disc_quote
{
public:
  // constructor
  Limit_quote()
  {rr::greet(__PRETTY_FUNCTION__,this);}
  Limit_quote(const std::string&, double, std::size_t, std::size_t, double);

  // copy c-tor, assign op
  Limit_quote(const Limit_quote& lq)
  : Disc_quote(lq), max_qty(lq.max_qty)
  {rr::greet(__PRETTY_FUNCTION__,this);}

  Limit_quote& operator=(const Limit_quote& rhs)
  {
    rr::greet(__PRETTY_FUNCTION__,this);
    if(this != &rhs)
    {
      Disc_quote::operator=(rhs);
      max_qty = rhs.max_qty;
    }
    return *this;
  }

  // move c-tor, assign op
  Limit_quote(Limit_quote&& lq) noexcept
  : Disc_quote(std::move(lq)), max_qty(std::move(lq.max_qty))
  { rr::greet(__PRETTY_FUNCTION__,this); }

  Limit_quote& operator=(Limit_quote&& rhs) noexcept
  {
    rr::greet(__PRETTY_FUNCTION__,this);
    if(this != &rhs)
    {
      Disc_quote::operator=(std::move(rhs));
      max_qty = std::move(rhs.max_qty);
    }
    return *this;
  }
  //destructor
  virtual ~Limit_quote()
  { rr::greet(__PRETTY_FUNCTION__,this); }

  //////////////////////////////////////////////////////////////////////////
  // exer15-30 virtual clone, both lvalue and rvalue.
  Limit_quote* clone() const &
  {
    return new Limit_quote(*this);
  }
  Limit_quote* clone() const &&
  {
    return new Limit_quote(std::move(*this));
  }



  //////////////////////////////////////////////////////////////////////////


  // overrides the base version in order to implement the bulk purchase
  // discount policy
  double net_price(std::size_t) const override;
  
//  std::ostream& printstate(std::ostream& os = std::cout) const override;

  virtual auto debug(std::ostream& os = std::cout) const->std::ostream& override final;

private:
  std::size_t max_qty = 0; // minimum purchase for the discount to apply
};




#endif

