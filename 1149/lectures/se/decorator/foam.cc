#include "foam.h"
using namespace std;
double Foam::cost(){return c.cost() + 0.15;}
string Foam::desc(){return c.desc() + ", foamed milk";}