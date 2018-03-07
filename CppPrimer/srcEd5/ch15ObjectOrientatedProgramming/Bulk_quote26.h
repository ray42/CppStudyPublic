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

  Bulk_quote(const std::string&, double, std::size_t, double);

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
