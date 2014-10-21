#ifndef __NODE_H__
#define __NODE_H__
#include <string>

struct Node {
  std::string name;
  Node *opponent1;
  Node *opponent2;

  Node(const std::string &s);
  ~Node(); 
  
};

#endif

