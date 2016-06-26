#include "catalogue.h"
#include "book.h"
#include "textbook.h"
#include "comic.h"
using namespace std;

map<string, int> CatalogueVisitor::getResult() { return theCatalogue; }

void CatalogueVisitor::visit(Book &b) {
  theCatalogue[b.getAuthor()]++;
}

void CatalogueVisitor::visit(Comic &cb) {
  theCatalogue[cb.getProtagonist()]++;
}

void CatalogueVisitor::visit(TextBook &csb) {
  theCatalogue[csb.getTopic()]++;
}

