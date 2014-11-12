#include <iostream>

#include "expression.h"
#include "intexpression.h"


IntExpression::IntExpression(int value): value(value) {}

IntExpression::~IntExpression() {}

int IntExpression::interpret() {
	return value;
}
std::string IntExpression::print() {
	return std::to_string(value);
}

