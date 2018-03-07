#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include"Quote3.h"

#include<string>
#include<cstddef>

class Bulk_quote : public Quote
{
public:

  Bulk_quote() = default;
  Bulk_quote(const std::string&, double, std::size_t, double);

  // overrides the base version in order to implement the bulk purchase
  // discount policy
  double net_price(std::size_t) const override;
  
  std::ostream& printstate(std::ostream& os = std::cout) const override;

private:
  std::size_t min_qty = 0; // minimum purchase for the discount to apply
  double discount = 0.0; // fractional discount to apply
};




#endif
