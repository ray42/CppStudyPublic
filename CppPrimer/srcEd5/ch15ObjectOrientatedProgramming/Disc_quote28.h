/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include"Quote28.h"
#include"./../common/rr.h"
#include<cstddef>
#include<string>
#include<iostream>

class Disc_quote : public Quote
{
public:
  // constructor
  Disc_quote()
  {rr::greet(__PRETTY_FUNCTION__,this);}

  Disc_quote(const std::string& book, double price,
             std::size_t qty, double disc):
    Quote(book,price), quantity(qty), discount(disc) // remember to CHAIN.
  {rr::greet(__PRETTY_FUNCTION__,this);}

  // copy c-tor, assign op - remember to CHAIN.
  Disc_quote(const Disc_quote& dq)
    :Quote(dq),quantity(dq.quantity), discount(dq.discount)
  {
    rr::greet(__PRETTY_FUNCTION__,this);
  }
  Disc_quote& operator=(const Disc_quote& rhs)
  {
    rr::greet(__PRETTY_FUNCTION__,this);
    if(this != &rhs)
    {
      Quote::operator=(rhs);
      quantity = rhs.quantity;
      discount = rhs.discount;
    }
    return *this;
  }

  // move c-tor, assign op - remember to CHAIN.
  Disc_quote(Disc_quote&& dq) noexcept
  : Quote::Quote(std::move(dq)), quantity(std::move(dq.quantity)), 
    discount(std::move(dq.discount))
  {
    rr::greet(__PRETTY_FUNCTION__,this);
  }

  Disc_quote& operator=(Disc_quote&& rhs) noexcept
  {
    rr::greet(__PRETTY_FUNCTION__,this);
    if(this != &rhs)
    {
      Quote::operator=(std::move(rhs));
      quantity = std::move(rhs.quantity);
      discount = std::move(rhs.discount);
    }
    return *this;
  }
  
  // destructor
  virtual ~Disc_quote() // no need to chain
  {
    rr::greet(__PRETTY_FUNCTION__,this);
  }



  virtual double net_price(std::size_t)const = 0;

  virtual auto debug(std::ostream& os=std::cout) const ->std::ostream& override;

protected:
  std::size_t quantity = 0; // purchase size for the discount to apply
  double discount = 0.0; // fractional discount to apply
};
#endif
