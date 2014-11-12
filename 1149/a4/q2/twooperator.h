#ifndef __TWOOPERATOR_H__
#define __TWOOPERATOR_H__
class TwoOperator: public Expression {
    char oper; // one of '+', '-', '*', '/' 
    Expression* lhs;
    Expression* rhs;
public:
	TwoOperator(Expression* lhs, Expression* rhs, char oper);
	~TwoOperator();

	virtual int interpret();
	virtual std::string print();
};
#endif
