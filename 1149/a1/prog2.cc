#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  int x;
  int argument = 1;
  if (argc == 2) {
	stringstream ss(argv[1]);
	if (! (ss >> argument)) {
		cerr << "Argument must be a number." << endl;
		return 1;
	}
  }
  if (argc > 2 ){
		cerr << "Only takes in one argument." << endl;
		return 1;
  }
  cin >> x;
  cout << x + argument << endl;
  return 0;
}
