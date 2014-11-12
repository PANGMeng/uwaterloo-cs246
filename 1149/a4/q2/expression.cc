#include <iostream>

#include "expression.h"

class Expression { // virtual class presenting common interface elements for all Expression subclasses
public:
	virtual int interpret() = 0; // pure virtual
	virtual std::string print() = 0; // pure virtual
};
