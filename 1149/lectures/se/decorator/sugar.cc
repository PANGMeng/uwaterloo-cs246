#include "sugar.h"
using namespace std;
double Sugar::cost(){return c.cost() + 0.10;}
string Sugar::desc(){return c.desc() + ", sugar";}