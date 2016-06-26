#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#include "textbook.h"
#include "comic.h"
#include "catalogue.h"
#include "BookVisitor.h"

using namespace std;

int main() {
  vector<Book*> collection;

  collection.push_back(new Book("War and Peace", "Tolstoy", 5000));
  collection.push_back(new Book("Peter Rabbit", "Potter", 50));
  collection.push_back(new TextBook("Programming for Beginners", "??", 200, "BASIC"));
  collection.push_back(new TextBook("Programming for Big Kids", "??", 200, "C++"));
  collection.push_back(new TextBook("Annotated Reference Manual", "??", 200, "C++"));
  collection.push_back(new Comic("Knightfall", "Various", 20, "Batman"));
  collection.push_back(new Comic("Deadpool Volume 1", "Way and Dilon", 20, "Deadpool"));
  collection.push_back(new Comic("The Widening Gyre", "Kevin Smith", 20, "Batman"));

  vector<Book*>::iterator i;

  CatalogueVisitor v;

  for (i = collection.begin(); i != collection.end(); ++i)
    (*i)->accept(v);

  map<string, int> m = v.getResult();

  for (map<string, int>::iterator j = m.begin(); j != m.end(); ++j)
   cout << j->first << " " << j->second << endl;

  for (i = collection.begin(); i != collection.end(); ++i) delete (*i);
}
