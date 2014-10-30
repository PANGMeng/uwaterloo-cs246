#ifndef __NODE_H__
#define __NODE_H__
#include <string>
#include <sstream>
#include <fstream>

struct Node {
  std::string name;
  Node *opponent1;
  Node *opponent2;

  Node(const std::string &s);
  ~Node(); 
  
};

void AddPlayer(std::string name, Node * firstPlayer);
Node * FindPlayer(std::string name, Node * firstPlayer);
void Match(std::string name1, std::string name2, std::string winner, Node * firstPlayer, Node * &firstMatch);
void PrintUndefeated(Node* firstPlayer);
void PrintMatches(std::string name, Node* firstMatch);
void Cheat(std::string name, Node* firstPlayer, Node* firstMatch);
void parseLine(std::string line, Node * firstPlayer, Node * firstMatch);

#endif

