#ifndef __STEAMEDMILK_H__
#define __STEAMEDMILK_H__
#include "milk.h"
class SteamedMilk : public Milk {
public:
  SteamedMilk(Coffee& c) : Milk(c) {}
  std::string desc();
};
#endif