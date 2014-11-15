#include "beer.h"
using namespace std;
double Beer::cost(){return c.cost() + 0.50;}
string Beer::desc(){return c.desc() + ", cheap beer";}