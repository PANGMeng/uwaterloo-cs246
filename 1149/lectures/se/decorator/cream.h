#ifndef __CREAM_H__
#define __CREAM_H__
#include "topping.h"
class Cream : public Topping{
public:
  Cream(Coffee& c) : Topping(c) {}
  double cost();
  std::string desc();
};
#endif