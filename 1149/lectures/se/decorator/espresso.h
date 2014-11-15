#ifndef __ESPRESSO_H__
#define __ESPRESSO_H__
#include "coffee.h"
class Espresso : public Coffee{
public:
  double cost();
  std::string desc();
};
#endif