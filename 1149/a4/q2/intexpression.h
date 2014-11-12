#ifndef __INTEXPRESSION_H__
#define __INTEXPRESSION_H__

class IntExpression: public Expression { // representing single integer expressions
    int value; // the integer
public:
	IntExpression(int value);
	virtual int Interpret();
	virtual std::string print();
};

#endif
