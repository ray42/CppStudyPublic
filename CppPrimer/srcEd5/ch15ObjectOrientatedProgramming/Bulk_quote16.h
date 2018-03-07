/*
* =========================================================================
* Copyright (c) 2017, Raymon White - All Rights Reserved
* Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
* Code for the exercises from C++ Primer 5th Edition
* =========================================================================
*/

#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include"Disc_quote16.h"

#include<string>
#include<cstddef>

class Bulk_quote : public Disc_quote
{
public:

  Bulk_quote() = default;
  Bulk_quote(const std::string&, double, std::size_t, double);

  // overrides the base version in order to implement the bulk purchase
  // discount policy
  double net_price(std::size_t) const override;
  
//  std::ostream& printstate(std::ostream& os = std::cout) const override;

  virtual auto debug(std::ostream& os=std::cout) const ->std::ostream& 
    override final;
};




#endif
