#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double average(string &s){
	int total = 0;
	int numInts = 0;
	int num;
	stringstream ss(s);
	while (ss >> num){
		total += num;
		++numInts;
	}
	return (double) total/numInts;
}

int main(){
	while ( ! cin.fail()){
		string s;
		getline(cin, s);
		cout << average(s) << endl;
	}
}
