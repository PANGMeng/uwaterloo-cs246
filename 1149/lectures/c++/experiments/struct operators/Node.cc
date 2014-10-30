#include "Node.h"

// struct Node {
// 	int data;
// 	Node* next;
// 	Node();
// 	Node(int n);
// 	Node(Node *n);
// 	~Node();
// };

Node::Node(): data(0) {
	next = 0;
}
Node::Node(int n) {
	data = n;
	next = 0;
}
Node::Node(Node *n) {
	if (0 == n->next) {
		next = 0;
	} else {
		next = new Node(n->next);
	}
}
Node::~Node(){
	if (0 != next) {
		delete next;
	}
}

inline Node& operator=(Node &lhs, const Node &rhs) {
	delete lhs.next;
	lhs.data = rhs.data;
	lhs.next = new Node(rhs.next);
}