#ifndef __ONEOPERATOR_H__
#define __ONEOPERATOR_H__
class OneOperator: public Expression {
    std::string op; // Either "NEG" or "ABS"
    Expression* expr;
public:
	OneOperator(Expression* expr, std::string op);
	~OneOperator();

	virtual int interpret();
	virtual std::string print();
};
#endif
