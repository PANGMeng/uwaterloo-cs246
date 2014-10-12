#include <iostream>

using namespace std;

int main(){
	// variables
	int x = 42;
	int y = 73;
	const int z = 9001;
	const int *a = &x;
	int * const b = &x;
	const int * const c = &x;


	*a = 20;
	cout << "a dereferences to " << *a << endl;
	a = &y;
	cout << "a dereferences to " << *a << endl;
	a = &z;
	cout << "a dereferences to " << *a << endl;
	*b = 10;
	cout << "b dereferences to " << *b << endl;
	b = &y;
	cout << "b dereferences tp " << *b << endl;
	b = &z;
	cout << "b dereferences to " << *b << endl;
	*c = 35;
	cout << "c dereferences to " << *c << endl;
	c = &y;
	cout << "c dereferences to " << *c << endl;
	c = &z;
	cout << "c dereferences to " << *c << endl;
}
