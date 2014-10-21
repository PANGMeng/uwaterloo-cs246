#include <iostream>

using namespace std;

int main(){
	int x = 4;
	int y = 2;
	int *p1 = &x, *p2 = &y;
	int &r1 = x, &r2 = y;

	*p2 = ((*p1 + *p2) * (*p1 - *p2))/(*p2 - *p1);
	r2 = ((r1 + r2) * (r1 - r2))/(r2 - r1);
	cout << *p2 << endl;
	cout << r2 << endl;
}
