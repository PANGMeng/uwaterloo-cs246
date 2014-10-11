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

struct IntArray {
  int size;
  int capacity;
  int *contents;
};

void addToArray(int num, IntArray array) {
  if (array.capacity <= array.size) { // Reallocate to a bigger array
    int * temp = new int [array.capacity*2];
    int * newptr = temp;
    int * oldptr = array.contents;
    for (int i = 0; i < array.size && i < array.capacity; i++) {
      *newptr = *oldptr;
      newptr++;
      oldptr++;
    }
    delete [] array.contents;
    array.contents = temp;
  }
  array.contents[array.size] = num;
  array.size++;
}

IntArray readIntArray() {
  string input;
  IntArray llama;
  llama.size = 0;
  llama.capacity = 4;
  llama.contents = new int [4];
  while(cin >> input) {
    if (isNumber(input)) {
      addToArray(strToNumber(input), llama);
    }
  }
  return llama;
};

void addToIntArray(IntArray& ia) {
  string input;
  while(cin >> input) {
    if (isNumber(input)) {
      addToArray(strToNumber(input), ia);
    }
  }
};

void printIntArray(const IntArray& ia) {
  for (int i = 0; i < ia.size; i++) {
    cout << ia.contents[i] << " ";
  }
  cout << endl;
};


// Do not change this function!

int main() {  // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4];
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = 0;

  while(!done) {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
                                 //                  +a, +b, +c, +d,
                                 //                  pa, pb, pc, pd, q
    cin >> c;  // Reads r, +, p, or q
    if (cin.eof()) break;
    switch(c) {
      case 'r':
        cin >> which;  // Reads a, b, c, or d
        delete [] a[which-'a'].contents;
        a[which-'a'].contents = 0;
        a[which-'a'] = readIntArray();
        break;
      case '+':
        cin >> which;  // Reads a, b, c, or d
        addToIntArray(a[which-'a']);
        break;
      case 'p':
        cin >> which;  // Reads a, b, c, or d
        printIntArray(a[which-'a']);
        cout << "Capacity: " << a[which-'a'].capacity << endl;
        break;
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}
