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

Calc::Calc() {
	error = false;
	display = 0;
	oper = ' ';
	result = 0;
	memory = 0;
}

Calc::Calc(const Calc &other) {
	error = other.error;
	display = other.display;
	oper = other.oper;
	result = other.result;
	memory = other.memory;
}

void Calc::digit(int digit) {
	display = display*10+digit;
}

int main() {
	return 0;
}