#include "beer.h"
#include "coffee.h"
#include "coldmilk.h"
#include "cream.h"
#include "drip.h"
#include "espresso.h"
#include "foam.h"
#include "instant.h"
#include "milk.h"
#include "steamedmilk.h"
#include "sugar.h"
#include "topping.h"
#include "water.h"
#include "whisky.h"
#include <iostream>
using namespace std;

int main(){
  Coffee* cp;

  cp = new Espresso;
  cout << "Cost of espresso: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";

  cp = new Water(*cp);
  cout << "Cost of americano: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";
  delete cp;

  cp = new SteamedMilk(*new Espresso);
  cout << "Cost of latte: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";

  cp = new Foam(*cp);
  cout << "Cost of cappuccino: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";
  delete cp;

  cp = new Drip;
  cout << "Cost of plain Timmies: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";

  cp = new Sugar(*cp);
  cout << "Cost of Timmies with one sugar: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";

  cp = new Cream(*cp);
  cout << "Cost of a Timies regular: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";

  cp = new Sugar(*cp);
  cout << "Cost of a Timmies two by one: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";

  cp = new Cream(*cp);
  cout << "Cost of Timies double double: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";
  delete cp;

  cp = new Instant;
  cout << "Cost of instant swill: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";

  cp = new Whisky(*cp);
  cout << "Cost of hair of the dog: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";
  delete cp;

  cp = new Beer(*new Espresso);
  cout << "Cost of capbeercino: $" << cp->cost() << ". Ingredients: " << cp->desc() << "\n\n";
  delete cp;
}