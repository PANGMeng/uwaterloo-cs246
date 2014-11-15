#ifndef __FOAM_H__
#define __FOAM_H__
#include "topping.h"
class Foam : public Topping{
public:
  Foam(Coffee& c) : Topping(c) {}
  double cost();
  std::string desc();
};
#endif