#include <iostream>

#include "expression.h"
#include "intexpression.h"


IntExpression::IntExpression(int value): value(value) {}
virtual int IntExpression::Interpret() {
	return value;
}
virtual std::string IntExpression::print() {
	return std::stoi(value);
}

