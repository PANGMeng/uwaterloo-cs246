#ifndef __BOOKVISITOR_H__
#define __BOOKVISITOR_H__

class Book;
class TextBook;
class Comic;

class BookVisitor {
  public:
    virtual void visit(Book &b) = 0;
    virtual void visit(TextBook &csb) = 0;
    virtual void visit(Comic &cb) = 0;
    virtual ~BookVisitor();
};

#endif
