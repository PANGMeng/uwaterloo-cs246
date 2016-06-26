#ifndef __TEXTBOOK_H__
#define __TEXTBOOK_H__
#include <string>

#include "book.h"
#include "BookVisitor.h"

class TextBook: public Book {
  std::string topic;
 public:
  TextBook(std::string title, std::string author, int numPages, std::string topic);
  bool isItHeavy();
  std::string getTopic();

  bool favourite();

  void accept(BookVisitor &v);
};

#endif
