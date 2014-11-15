#ifndef __BEER_H__
#define __BEER_H__
#include "topping.h"
class Beer : public Topping{
public:
  Beer(Coffee& c) : Topping(c) {}
  double cost();
  std::string desc();
};
#endif