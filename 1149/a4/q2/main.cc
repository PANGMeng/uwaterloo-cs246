#include <iostream>
#include <string>
#include "expression.h"
#include "intexpression.h"
#include "twooperator.h"
#include "oneoperator.h"

using namespace std;

class StackInterface {
	Expression* e[10]; // array of pointers to the expressions on the stack
	int firstNull; // e[firstNull] should always = NULL

	Expression* root; // the expression tree that will eventually be evaluated
public:
	StackInterface() { // set everything to 0 or NULL
		for (int i = 0; i < 10; ++i) {
			if (NULL != e[i]) {
				e[i] = NULL;
			}
		}
		firstNull = 0;
		root = NULL;
	}
	~StackInterface() {// deallocate all expressions
		// Expressions are responsible for deallocating subexpressions when deallocated
		for (int i = 0; i < 10; ++i) {
			if (NULL != e[i]) {
				delete e[i];
			}
		}
		if (NULL != root) {
			delete root;
		}
	}

	int addInt(int x) { // effectively "add x to stack"
		if (9 <= firstNull) {// Check for stack overflow
			cerr << "Stack overflow" << endl;
			return 1;
		}
		if (NULL == root) {// if the root isn't yet set, set it to the integer
			root = new IntExpression(x);
		} else {// add int to end of stack
			e[firstNull] = new IntExpression(x);
			firstNull++;
		}
		return 0;
	}

	void setTwoOper(char op) {// effectively "add +-*/ to stack"
		if (firstNull > 1) {
			// operator is taking two expressions off the stack
			// operator replaces first expression on the stack
			Expression* ex1 = e[firstNull-2];
			Expression* ex2 = e[firstNull-1];
			e[firstNull-1] = NULL;
			e[firstNull-2] = new TwoOperator(ex1, ex2, op);
			firstNull -= 1;
		} else if (1 == firstNull && NULL != e[0]) {
			// root is set to operator
			// Assumption: e[0] != NULL
			Expression* ex1 = root;
			Expression* ex2 = e[0];
			e[0] = NULL;
			root = new TwoOperator(ex1, ex2, op);
			firstNull = 0;
		}
	}

	void setOneOper(string op) {// effectively "add NEG/ABS"
		if (0 < firstNull) {
			Expression* ex = e[firstNull-1];
			e[firstNull-1] = new OneOperator(ex, op);
		} else if (0 == firstNull) {
			Expression* ex = root;
			root = new OneOperator(ex, op);
		}
	}

	void write() {// called at the end of the program to indicate the result
		cout << root->interpret() << endl;
		cout << "= " << root->print() << endl;
	}
};

int main() {
	// input capture variables
	int ii;
	string ss;

	StackInterface s;

	while (true) {
		if (cin >> ii) {// if input is an integer:
			if (1 == s.addInt(ii)) {
				return 0; // if there's a stack overflow, abort
			}
		} else {
			if (cin.eof()) { // if the end of the file is reached, break the loop
				break;
			} else { // if input is not an integer:
				cin.clear();
				if (cin >> ss) {// if input is a string
					if ("+" == ss) {
						s.setTwoOper('+');
					}
					if ("*" == ss) {
						s.setTwoOper('*');
					}
					if ("/" == ss) {
						s.setTwoOper('/');
					}
					if ("-" == ss) {
						s.setTwoOper('-');
					}
					if ("ABS" == ss) {
						s.setOneOper("ABS");
					}
					if ("NEG" == ss) {
						s.setOneOper("NEG");
					}
				} else { // if input is not integer, string, or EOF, just move on
					cin.clear();
					cin.ignore();
				}
			}
		}
	}

	s.write();
	
	return 0;
}