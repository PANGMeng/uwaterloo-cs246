#include <iostream>

#include "expression.h"
#include "twooperator.h"


TwoOperator::TwoOperator(Expression* lhs, Expression* rhs, char oper): lhs(lhs), rhs(rhs), oper(oper) {}
TwoOperator::~TwoOperator() { // Deleting an Operator Expression deletes all sub-expressions
	delete lhs;
	delete rhs;
}

virtual int TwoOperator::interpret() {
	if (oper == '/') {
		int l, r;
		l = lhs->interpret();
		r = rhs->interpret();
		if (r == 0) {
			return 0;
		}
		return l / r;
	}
	if (oper == '+') {
		return lhs->interpret() + rhs->interpret();
	}
	if (oper == '-') {
		return lhs->interpret() - rhs->interpret();
	}
	if (oper == '*') {
		return lhs->interpret() * rhs->interpret();
	}
}

virtual std::string TwoOperator::print() {
	return "(" + lhs->print() + " " + oper + " " + rhs->print() + ")";
};

