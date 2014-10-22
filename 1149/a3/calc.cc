#ifndef __CALC_H__
#include "calc.h"
#endif


// struct Calc {
// 	Calc();
// 	Calc(const Calc &other);

// 	bool error;
// 	int display;
// 	char oper;
// 	int result;
// 	int memory;

// 	void digit(int digit);
// 	void op(char oper);
// 	void equals();
// 	void memPlus();
// 	void memClear();
// 	void memRecall();
// 	bool isError() const;
// 	void allClear();
// };

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
				res = result / display;
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
	oper = ' '; // remember to check if oper is ' '
	// couldn't think of a better "blank" character
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

