/*
* =========================================================================
* Copyright (c) 2017, Raymon White - All Rights Reserved
* Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
* Code for the exercises from C++ Primer 5th Edition
* =========================================================================
*/

#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include"Disc_quote26.h"
#include"./../common/rr.h"

#include<string>
#include<cstddef>

class Bulk_quote : public Disc_quote
{
public:
  // constructor
  Bulk_quote()
  {rr::greet(__PRETTY_FUNCTION__,this);}

  // changed the below to the inherited constructor for ex15.27.
  // rules:  1. only inherit from the direct base class.
  //         2. default, copy and move constructors can not inherit.
  //         3. any data members of its own are default initialized.
  //         4. the rest details are in the section section 15.7.4.
    
  //Bulk_quote(const std::string&, double, std::size_t, double);
  using Disc_quote::Disc_quote;

  // copy c-tor, assign op - remember to chain
  Bulk_quote(const Bulk_quote& bq):Disc_quote(bq)
  {rr::greet(__PRETTY_FUNCTION__,this);}

  Bulk_quote& operator=(const Bulk_quote& rhs)
  {
    rr::greet(__PRETTY_FUNCTION__,this);
    Disc_quote::operator=(rhs);
    return *this;
  }

  // move c-tor, assign op - remember to chain
  Bulk_quote(Bulk_quote&& bq) noexcept
  : Disc_quote(std::move(bq))
  {rr::greet(__PRETTY_FUNCTION__,this);}

  Bulk_quote& operator=(Bulk_quote&& rhs) noexcept
  {
    rr::greet(__PRETTY_FUNCTION__,this);
    Disc_quote::operator=(std::move(rhs));
    return *this;
  }

  // destructor - no need to chain
  virtual ~Bulk_quote()
  {rr::greet(__PRETTY_FUNCTION__,this);}


  // overrides the base version in order to implement the bulk purchase
  // discount policy
  double net_price(std::size_t) const override;
  
//  std::ostream& printstate(std::ostream& os = std::cout) const override;

  virtual auto debug(std::ostream& os=std::cout) const ->std::ostream& 
    override final;
};




#endif
