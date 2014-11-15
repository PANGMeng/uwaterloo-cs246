#ifndef __TOPPING_H__
#define __TOPPING_H__
#include "coffee.h"
class Topping : public Coffee {
protected:
  Coffee& c;
  Topping(Coffee& c) : c(c){}
  ~Topping(){ delete &c;}
};
#endif