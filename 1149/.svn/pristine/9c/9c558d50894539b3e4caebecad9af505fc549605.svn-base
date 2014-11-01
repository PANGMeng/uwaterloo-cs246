#include <iostream>
#include <string>
#include "book.h"
#include "textbook.h"
#include "comic.h"

using namespace std;

int main() {
  Book b("The Eye of the World", "Robert Jordan", 1000);
  TextBook csb("Design and Evolution of C++", "Bjarme Stroustrup", 461, "C++");
  Comic cb("The Widening Gyre", "Kevin Smith", 40, "Batman");

  cout << "First book: " << b.getTitle() << "; " << b.getAuthor()
       << "; " << (b.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "Second book: " << csb.getTitle() << "; " << csb.getAuthor()
       << "; " << (csb.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "Third book: " << cb.getTitle() << "; " << cb.getAuthor()
       << "; " << (cb.isItHeavy() ? "heavy" : "not heavy") << endl;
}
