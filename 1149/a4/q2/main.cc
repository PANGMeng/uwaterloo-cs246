#include <iostream>
#include <string>
#include <sstream>
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
		#ifdef DEBUG
		for (int i = 0; i < 10; ++i) {
			if (NULL != e[i]) {
				cerr << i << ": " << e[i]->print() << endl;
			} else {
				cerr << i << ": NULL" << endl;
			}
		}
		#endif // DEBUG
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
		#ifdef DEBUG
			cerr << "firstNull is now: " << firstNull << endl;
		#endif // DEBUG
		return 0;
	}

	void setTwoOper(char op) {// effectively "add +-*/ to stack"
		#ifdef DEBUG
			cerr << "trying to add '" << op << "' to stack" << endl;
		#endif // DEBUG
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
			#ifdef DEBUG
				cerr << "root is now: " << root->print() << endl;
			#endif // DEBUG
		}
		#ifdef DEBUG
			cerr << "firstNull is now: " << firstNull << endl;
		#endif // DEBUG
	}

	void setOneOper(string op) {// effectively "add NEG/ABS"
		if (0 < firstNull) {
			Expression* ex = e[firstNull-1];
			e[firstNull-1] = new OneOperator(ex, op);
		} else if (0 == firstNull) {
			Expression* ex = root;
			root = new OneOperator(ex, op);
		}
		#ifdef DEBUG
			cerr << "firstNull is now: " << firstNull << endl;
		#endif // DEBUG
	}

	void write() {// called at the end of the program to indicate the result
		cout << root->print() << endl;
		cout << "= " << root->interpret() << endl;
	}
};

int main() {
	// input capture variables
	int ii;
	string inp;

	StackInterface s;

	while (true) { // ends when eof is reached
		if (cin >> inp) {
			stringstream ss(inp);
			ss >> ii;
			if (!ss.fail()) { // ii is an integer
				if (1 == s.addInt(ii)) {
					return 0; // if there's a stack overflow, abort
				}
			} else { // inp is a string
				#ifdef DEBUG
					cerr << "trying to interpret the string: '" << inp << "'" << endl;
				#endif // DEBUG
				if ("+" == inp) {
					#ifdef DEBUG
						cerr << "YES Thing?" << endl;
					#endif // DEBUG
					s.setTwoOper('+');
				}
				if ("*" == inp) {
					s.setTwoOper('*');
				}
				if ("/" == inp) {
					s.setTwoOper('/');
				}
				if ("-" == inp) {
					s.setTwoOper('-');
				}
				if ("ABS" == inp) {
					s.setOneOper("ABS");
				}
				if ("NEG" == inp) {
					s.setOneOper("NEG");
				}
			}
		} else {
			if (cin.eof()) {// if the end of the file is reached, break the loop
				break;
			} else { // the input is unreadable somehow, and should be skipped
				#ifdef DEBUG
					cerr << "impossible input - ABORT" << endl;
				#endif // DEBUG
				cin.clear();
				cin.ignore();
			}
		}
	}

	s.write();
	
	return 0;
}