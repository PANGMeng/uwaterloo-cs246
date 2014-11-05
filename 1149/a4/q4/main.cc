#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "textprocess.h"
#include "echo.h"

int main () {
  string s;

  while(1) {
    getline(cin,s);
    if (cin.fail()) break;
    istringstream iss(s);
    string fname;
    iss >> fname;
    istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());

    TextProcessor *tp = new Echo;
    string dec;
    while (iss >> dec) {
      if (dec == "l337") {
        // tp = ...
      }
      else if (dec == "lower") {
        // tp = ..
      }
      else if (dec == "doublecon") {
        // tp = ...
      }
      else if (dec == "caesar") {
        int n;
        iss >> n;
        // tp = ...
      }
   } 

   tp->setSource(in);

   string word;

   while (word = tp->getWord(), !tp->fail()) {
     cout << word << endl;
   }

   if (in != &cin) delete in;

   delete tp;
  }
}
