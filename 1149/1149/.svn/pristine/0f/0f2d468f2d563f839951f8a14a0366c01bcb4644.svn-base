#include <iostream>

using namespace std;

int foo(int &x, const int& y){
	x = x + y;
	return x;
}

int main(){
	int a = 42;
	foo(a,a);
	cout << a << endl;
	foo(a, 10);
	cout << a << endl;
	foo(43, a);
	cout << a << endl;
	foo(43, 43);
	cout << a << endl;
}
