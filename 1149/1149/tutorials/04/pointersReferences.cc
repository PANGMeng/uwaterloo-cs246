#include <iostream>

using namespace std;

int main(){
	int x = 42;
	int *y = &x;
	int &z = x;
	if ( x == z )
		cout << "x == z" << endl;
	else
		cout << "x != z" << endl;
	if ( x == y )
		cout << "x == y" << endl;
	else
		cout << "x != y" << endl;
	if ( z == y )
		cout << "z == y" << endl;
	else
		cout << "z != y" << endl;
	if ( &x == y )
		cout << "&x == y" << endl;
	else
		cout << "&x != y" << endl;
	if ( &x == &z )
		cout << "&x == &z" << endl;
	else
		cout << "&x != &z" << endl;
}
