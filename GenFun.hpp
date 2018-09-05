// Holds General Purpose Function declarations


#pragma once

#include <iosfwd>
#include <list>
#include "Stock.hpp"
#include "Business.hpp"

char isValid();
void sellBack(std::list<Business> &);


void market(std::list<Stock> &, std::list<Business> &, std::list<Business> &);
void doodad();
void small(std::list<Stock> &, std::list<Business> &); // small deal
void big(std::list<Business> &);  // big deal
void bankruptcySellBack(std::list<Business> &, std::list<Business> &);
