#include "comic.h"
#include <string>
#include "BookVisitor.h"

using namespace std;

Comic::Comic(string title, string author, int numPages, string protag):
  Book(title, author, numPages), protag(protag) {}

bool Comic::isItHeavy() { return getNumPages() > 30; }
string Comic::getProtagonist() { return protag; }

// My favourite comic books are Superman comics.
bool Comic::favourite() { return protag == "Superman"; }

void Comic::accept(BookVisitor &v) { return v.visit(*this); }

