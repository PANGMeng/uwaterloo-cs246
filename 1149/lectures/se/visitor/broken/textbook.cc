#include "textbook.h"
#include <string>
#include "BookVisitor.h"

using namespace std;

TextBook::TextBook(string title, string author, int numPages, string topic):
  Book(title, author, numPages), topic(topic) {}

bool TextBook::isItHeavy() { return getNumPages() > 400; }
string TextBook::getTopic() { return topic; }

// Favourite text books are C++ books
bool TextBook::favourite() { return topic == "C++"; }

void TextBook::accept(BookVisitor &v) { return v.visit(*this); }

