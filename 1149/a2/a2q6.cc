#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isNumber(string str) {
  stringstream ss(str);
  char c;
  bool first = true;
  while(ss.get(c)) {
    if (first) {
      if ((c < '0' || c > '9') && (c != '-')) {
        return false;
      }
      first = false;
    } else {
      if (c < '0' || c > '9') {
        return false;
      }
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

void printIntArray(const IntArray& ia);

void addToArray(int num, IntArray& array) {
  #ifdef DEBUG
    cout << "Trying to add: " << num << endl;
  #endif
  if (array.capacity == 0) {
    array.capacity = 5;
    array.contents = new int [5];
    #ifdef DEBUG
      cout << "\tCapacity: 0" << endl << "\tSetting Capacity to: 5" << endl;
    #endif
  }
  if (array.capacity <= array.size) { // Reallocate to a bigger array
    #ifdef DEBUG
      cout << "\tCapacity: " << array.capacity << endl;
      cout << "\tSize: " << array.size << endl;
      cout << "\tSetting Capacity to: " << (array.capacity)*2 << endl;
    #endif
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
    array.capacity *= 2;
  }
  array.contents[array.size] = num;
  array.size++;
  #ifdef DEBUG
    cout << "Potentially successful add. Printing for verification..." << endl;
    printIntArray(array);
  #endif
}

IntArray readIntArray() {
  int input;
  int keepgoing = 0;
  IntArray llama;
  llama.size = 0;
  llama.capacity = 0;
  llama.contents = 0;
  while(keepgoing <= 1) {
    if (cin >> input) {
      addToArray(input, llama);
    } else {
      cin.clear();
      cin.ignore();
      keepgoing++;
    }
  }
  return llama;
};

void addToIntArray(IntArray& ia) {
  int input;
  int keepgoing = 0;
  while(keepgoing <= 1) {
    if (cin >> input) {
      addToArray(input, ia);
    } else {
      cin.clear();
      cin.ignore();
      keepgoing++;
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
      #ifdef DEBUG
      case 'e':
        IntArray e;
        e.size = 3;
        e.capacity = 5;
        e.contents = new int [5];
        e.contents[0] = 3;
        e.contents[1] = 2;
        e.contents[2] = 9;
        printIntArray(e);
        cout << "Capacity: " << e.capacity << endl;
        break;
      #endif
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}
