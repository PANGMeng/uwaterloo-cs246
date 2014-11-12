#ifndef __INTEXPRESSION_H__
#define __INTEXPRESSION_H__

class IntExpression: public Expression { // representing single integer expressions
    int value; // the integer
public:
	IntExpression(int value);
	~IntExpression();
	virtual int interpret();
	virtual std::string print();
};

#endif
