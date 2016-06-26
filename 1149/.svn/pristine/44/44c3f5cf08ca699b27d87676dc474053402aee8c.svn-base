#ifndef __BOOKVISITOR_H__
#define __BOOKVISITOR_H__
#include "book.h"
#include "textbook.h"
#include "comic.h"

class BookVisitor {
  public:
    virtual void visit(Book &b) = 0;
    virtual void visit(TextBook &csb) = 0;
    virtual void visit(Comic &cb) = 0;
    virtual ~BookVisitor();
};

#endif
