#include <iostream>
#include <string>
#include "book.h"
#include "textbook.h"
#include "comic.h"

using namespace std;

int main() {
  Comic cb("The Widening Gyre", "Kevin Smith", 40, "Batman");
  Book b = cb;

  cout << "The comic book: " << cb.getTitle() << "; " << cb.getAuthor()
       << "; " << (cb.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "The book: " << b.getTitle() << "; " << b.getAuthor()
       << "; " << (b.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << endl << "Through pointers: " << endl;

  Comic *pcb = new Comic("The Widening Gyre", "Kevin Smith", 40, "Batman");
  Book *pb = pcb;

  cout << "The comic book ptr: " << pcb->getTitle() << "; " << pcb->getAuthor()
       << "; " << (pcb->isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "The book ptr: " << pb->getTitle() << "; " << pb->getAuthor()
       << "; " << (pb->isItHeavy() ? "heavy" : "not heavy") << endl;
  delete pcb;
}

