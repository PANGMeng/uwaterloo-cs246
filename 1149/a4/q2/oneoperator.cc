#include <iostream>
#include <string>

#include "expression.h"
#include "oneoperator.h"


OneOperator::OneOperator(Expression* expr, std::string op): expr(expr), op(op) {}
OneOperator::~OneOperator() {
	delete expr;
}

int OneOperator::interpret() {
	if ("ABS" == op) {
		return abs(expr->interpret());
	}
	if ("NEG" == op) {
		return -(expr->interpret());
	}
	#ifdef DEBUG
	std::cerr << "oneoperator interpretation error: ambiguous operator '" << op << "'" << std::endl;
	#endif // DEBUG
	return expr->interpret();
}
std::string OneOperator::print() {
	if ("ABS" == op) {
		return "|"+expr->print()+"|";
	}
	if ("NEG" == op) {
		return "-"+expr->print();
	}
	#ifdef DEBUG
	std::cerr << "oneoperator printing error: ambiguous operator'" << op << "'" << std::endl;
	#endif // DEBUG
	return expr->print();
}

