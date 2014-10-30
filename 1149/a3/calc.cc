#ifndef __CALC_H__
#include "calc.h"
#endif

Calc::Calc() { // constructor
	allClear();
}

Calc::Calc(const Calc &other) { // copy constructor
	error = other.error;
	display = other.display;
	oper = other.oper;
	result = other.result;
	memory = other.memory;
}

void Calc::digit(int digit) { // Adds digit to the end of the display
	display = display*10+digit;
}

void Calc::op(char oper) { // Simulates press of 'oper' operator key
	if (this->oper == '+' or this->oper == '-' or this->oper == '*' or this->oper == '/') {
		equals();
	}
	else {
		result = display;
	}
	if (!error) {
		display = 0;
		this->oper = oper;
	}
}

void Calc::equals() {
	if (error) {
		display = 0;
		result = 0;
		return;
	}
	int res = display; // default result value
	switch(oper) {
		case '+':
			res = result + display;
			break;
		case '-':
			res = result - display;
			break;
		case '*':
			res = result * display;
			break;
		case '/':
			if (display != 0) {
				#ifdef DEBUG
					std::cerr << "Result: " << result << std::endl;
					std::cerr << "Display: " << display << std::endl;
					std::cerr << "r\%d: " << result%display << std::endl;
					std::cerr << "r - r\%d: " << (result - result%display) << std::endl;
				#endif
				res = (result - result%display)/display;
			} else {
				error = true;
			}
			break;
	}
	oper = ' ';
	result = res;
	display = res;
}

void Calc::memPlus() { // Simulates M+ press
	memory += display;
}

void Calc::memClear() { // Simulates MC press
	memory = 0;
}

void Calc::memRecall() { // Simulates MR press
	display = memory;
}

bool Calc::isError() const { // returns error flag
	return error;
}

void Calc::allClear() {
	error = false;
	display = 0;
	oper = ' '; // "blank" character
	result = 0;
	memory = 0;
}

std::ostream &operator<<(std::ostream &out, const Calc &c) {
	out << c.display;
	if (c.memory != 0) {
		out << " M: " << c.memory;
	}
	if (c.error == true) {
		out << " E";
	}
	return out;
}

