#include <iostream>
#include <string>

#include "expression.h"
#include "oneoperator.h"


OneOperator::OneOperator(Expression* expr, std::string op): expr(expr), op(op) {}
OneOperator::~OneOperator() {
	delete expr;
}

virtual int OneOperator::interpret() {
	if (op = "ABS") {
		return abs(expr->interpret());
	}
	if (op = "NEG") {
		return -(expr->interpret());
	}
}
virtual std::string OneOperator::print() {
	if (op = "ABS") {
		return "|"+expr->interpret()+"|";
	}
	if (op = "NEG") {
		return "-"+expr->interpret();
	}
}

