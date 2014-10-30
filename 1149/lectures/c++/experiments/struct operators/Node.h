#ifndef __NODE_H__
#define __NODE_H__

struct Node {
	int data;
	Node* next;
	Node();
	Node(int n);
	Node(Node *n);
	~Node();
};

#endif // __NODE_H__


