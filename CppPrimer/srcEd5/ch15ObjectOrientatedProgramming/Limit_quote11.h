#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include"Quote11.h" // inherit from this

#include<string>
#include<cstddef>

class Limit_quote : public Quote
{
public:

  Limit_quote() = default;
  Limit_quote(const std::string&, double, std::size_t, std::size_t, double);

  // overrides the base version in order to implement the bulk purchase
  // discount policy
  double net_price(std::size_t) const override;
  
  std::ostream& printstate(std::ostream& os = std::cout) const override;

  virtual auto debug(std::ostream& os = std::cout) const->std::ostream& override final;

private:
  std::size_t min_qty = 0; // minimum purchase for the discount to apply
  std::size_t max_qty = 0; // minimum purchase for the discount to apply
  double discount = 0.0; // fractional discount to apply
};




#endif

