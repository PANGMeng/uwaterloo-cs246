#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string s;
	int num = 5;
	cin >> s;
	cout << s << endl;
	stringstream ss(s);
	if (ss >> num){
		cout << "Int: " << num  << endl;
	}
	else {
		ss.clear();
		ss >> s;
		cout << "String: " <<  s <<  endl;
		cout << "Int: " << num  << endl;
	}
}
