#ifndef __IOSTREAM__
#define __IOSTREAM__

#include <iostream>

#endif // __IOSTREAM__

#include "istring.cc"

using namespace std;

int main() {
	iString l;
	l.chars = new char[8];
	l.chars[0] = 'i';
	l.chars[1] = 'd';
	l.chars[2] = 'o';
	l.chars[3] = 'n';
	l.chars[4] = 't';
	l.chars[5] = 'k';
	l.length = 6;
	iString m("ohno");
	cout << "wow: " << l << endl;
	cout << "gr8: " << m << endl;
	iString n;
	n = "omg";
	cout << "omg: " << n << endl;
	iString g = n;
	#ifdef DEBUG
	cerr << "amsdok" << endl;
	#endif // DEBUG
	cout << "omf: " << g << endl;
	iString r = n+g;
	cout << "omh: " << r << endl;
	return 0;
}