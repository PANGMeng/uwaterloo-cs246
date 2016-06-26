#ifndef __COMIC_H__
#define __COMIC_H__
#include <string>

#include "book.h"
class BookVisitor;

class Comic: public Book {
  std::string protag;
 public:
  Comic(std::string title, std::string author, int numPages, std::string hero);
  bool isItHeavy();
  std::string getProtagonist();

  bool favourite();

  void accept(BookVisitor &v);
};

#endif
