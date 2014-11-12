#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

class Expression { // virtual class presenting common interface elements for all Expression subclasses
public:
	virtual int interpret();
	// the purpose of the "interpret" function is to return the integer value of the expression
	virtual std::string print();
	// the purpose of the "print" function is to print to standard output the unsimplified version
};

#endif
