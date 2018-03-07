/*
* =========================================================================
* Copyright (c) 2017, Raymon White - All Rights Reserved
* Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
* Code for the exercises from C++ Primer 5th Edition
* =========================================================================
*/
#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include"Disc_quote16.h" // inherit from this

#include<string>
#include<cstddef>

class Limit_quote : public Disc_quote
{
public:

  Limit_quote() = default;
  Limit_quote(const std::string&, double, std::size_t, std::size_t, double);

  // overrides the base version in order to implement the bulk purchase
  // discount policy
  double net_price(std::size_t) const override;
  
//  std::ostream& printstate(std::ostream& os = std::cout) const override;

  virtual auto debug(std::ostream& os = std::cout) const->std::ostream& override final;

private:
  std::size_t max_qty = 0; // minimum purchase for the discount to apply
};




#endif

