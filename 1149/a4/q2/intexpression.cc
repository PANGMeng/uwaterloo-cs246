#include <iostream>
#include <sstream>

#include "expression.h"
#include "intexpression.h"


IntExpression::IntExpression(int value): value(value) {}

IntExpression::~IntExpression() {}

int IntExpression::interpret() {
	return value;
}
std::string IntExpression::print() {
	std::string d;
	std::ostringstream oss;
	oss << value;
	d = oss.str();
	return d;
}

