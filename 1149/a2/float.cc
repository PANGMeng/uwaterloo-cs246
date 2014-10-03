#include <iostream>
using namespace std;

int main () {
  float x = 0.0001;
  float y = 0;
  for (int i=0; i < 100; i++) {
    y += x;
  }
  cout << y << endl;
  return 0;
}
