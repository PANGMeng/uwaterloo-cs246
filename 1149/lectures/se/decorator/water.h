#ifndef __WATER_H__
#define __WATER_H__
#include "topping.h"
class Water : public Topping{
public:
  Water(Coffee& c) : Topping(c) {}
  double cost();
  std::string desc();
};
#endif