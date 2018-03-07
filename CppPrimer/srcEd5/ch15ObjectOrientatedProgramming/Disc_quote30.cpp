/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */

#include "Disc_quote30.h"
#include"./../common/rr.h"

auto Disc_quote::debug(std::ostream& os) const ->std::ostream&
{
  Quote::debug(os) << std::endl;
  os << "DQ: quantity " << quantity << ", discount " << discount;
  return os;
}

