#include "cream.h"
using namespace std;
double Cream::cost(){return c.cost() + 0.35;}
string Cream::desc(){return c.desc() + ", some half and half";}