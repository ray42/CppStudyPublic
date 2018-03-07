/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include"Quote11.h"
#include<cstddef>
#include<string>

class Disc_quote : public Quote
{
public:
  Disc_quote() = default;
  virtual ~Disc_quote() = default;

  Disc_quote(const std::string& book, double price,
             std::size_t qty, double disc):
    Quote(book,price), quantity(qty), discount(disc){}

  double net_price(std::size_t) = 0;

protected:
  std::size_t quantity = 0; // purchase size for the discount to apply
  double discount = 0.0; // fractional discount to apply
}
#endif
