#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isNumber(string str) {
	stringstream ss(str);
	char c;
	while(ss.get(c)) {
		if (c < '0' || c > '9') {
			return false;
		}
	}
	return true;
}

int strToNumber(string str) {
	stringstream ss(str);
	int t;
	if (ss >> t) {
		return t;
	} else {
		return -1;
	}
}

int main()
{
	int fails = 0;
	string input;

	while(cin >> input) {
		if (isNumber(input)) {
			cout << strToNumber(input) << endl;
		}
	}

	return 0;
}