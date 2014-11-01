#include "node.h"
#include <iostream>
#include <sstream>
#include <fstream>

// I decided to use a linked list approach to the node classes instead of a binary tree.

// For a node class, opponent 2 points to the next node in the list. 
// The main program keeps the first Node. When a Node is deleted it deletes the next node

// Nodes can be used in one of two contexts here:
// 1) As a Player
// 2) As a game

Node::Node(const std::string &s): name(s) {
	opponent1 = NULL;
	opponent2 = NULL;
}

Node::~Node() {
	if (NULL != opponent2) {
		delete opponent2;
	}
	#ifdef DEBUG
	std::cout << "Deleted " << name << std::endl;
	#endif
}

// For Players stored in Nodes:
// 
// name = Player's Name
// opponent1 = pointer to Game node that the player Lost (if NULL, then player hasn't lost anything)
// opponent2 = Next Player

void AddPlayer(std::string name, Node * &firstPlayer) { // Add a Player Node to the list of Players. Retains order
	Node * tmp = firstPlayer;
	if (NULL == tmp) {
		firstPlayer = new Node(name);
	} else {
		while(NULL != tmp->opponent2) {
			tmp = tmp->opponent2;
			#ifdef DEBUG
			std::cout << "Looking at " << tmp->name << std::endl;
			#endif
		}
		tmp->opponent2 = new Node(name);
		#ifdef DEBUG
		std::cout << "Added " << name << " after " << tmp->name << std::endl;
		#endif
	}
}

Node * FindPlayer(std::string name, Node * firstPlayer) {
	Node * tmp = firstPlayer;
	while(tmp != NULL && name != tmp->name) {
		tmp = tmp->opponent2;
	}
	return tmp;
}

// For Matches stored in Nodes:
// 
// name = Winner's name
// opponent1 = Loser
// opponent2 = Next Match

void Match(std::string name1, std::string name2, std::string winner, Node * firstPlayer, Node * &firstMatch) {
	Node * p1 = FindPlayer(name1, firstPlayer);
	Node * p2 = FindPlayer(name2, firstPlayer);
	if(NULL == p1 || NULL == p2) {} else {
		Node * win;
		if (winner == name1) {
			win = new Node(name1);
			p2->opponent1 = p1;
			win->opponent1 = p2;
		} else {
			win = new Node(name2);
			p1->opponent1 = p2;
			win->opponent1 = p1;
		}
		Node * tmp = firstMatch;
		if (NULL == firstMatch) {
			firstMatch = win;
		} else {
			while(NULL != tmp->opponent2) {
			    tmp = tmp->opponent2;
			}
			tmp->opponent2 = win;
		}
	}
}

void PrintUndefeated(Node* firstPlayer) { // Goes through linked list and prints the names of all those with a NULL opponent1 field - meaning they are undefeated
	Node * tmp = firstPlayer;
	while(NULL != tmp) {
		#ifdef DEBUG
		std::cout << "Looking at " << tmp->name << std::endl;
		#endif
		if (NULL == tmp->opponent1) {
			std::cout << tmp->name << std::endl;
		}
		tmp = tmp->opponent2;
	}
	#ifdef DEBUG
	std::cout << "Done Looking" << std::endl;
	#endif
}

void PrintMatches(std::string name, Node* firstMatch) { // Walks through linked list of Matches and prints match details of any matches with the name field "name"
	Node * tmp = firstMatch;
	while(NULL != tmp) {
		#ifdef DEBUG
		std::cout << "Looking at " << tmp->name << std::endl;
		#endif
		if (name == tmp->name) {
			std::cout << tmp->name << " vs " << tmp->opponent1->name << std::endl;
		} else {
			#ifdef DEBUG
			std::cout << "Winner was " << tmp->name << " and not " << name << std::endl;
			#endif
		}
		tmp = tmp->opponent2;
	}
}

void Cheat(std::string name, Node* firstPlayer, Node* firstMatch) { // executes functionality of '-' command
	Node * tmp = firstMatch;
	while(NULL != tmp && tmp->name != name) {
		tmp = tmp->opponent2;
	}
	if (tmp != NULL) {
		std::string s = tmp->name;
		Node * winner = tmp->opponent1;
		tmp->opponent1 = FindPlayer(s, firstPlayer);
		tmp->opponent1->opponent1 = tmp;
		tmp->name = winner->name;
		winner->opponent1 = NULL;
	}
}

void parseLine(std::string line, Node * firstPlayer, Node * firstMatch) { // Given one line of input, will decide which Node function to call
	std::stringstream ss;
	ss << line;
	char s;
	std::string a1, a2, a3;
	ss >> s;
	switch (s) {
		case '!': 
			#ifdef DEBUG
			std::cout << "Adding ";
			#endif
			ss >> a1;
			#ifdef DEBUG
			std::cout << a1 << std::endl;
			#endif
			AddPlayer(a1, firstPlayer);
			break;
		case '*':
			ss >> a1 >> a2 >> a3;
			Match(a1, a2, a3, firstPlayer, firstMatch);
			break;
		case '?': 
			#ifdef DEBUG
			std::cout << "Querying ";
			#endif
			if (ss >> a1) {
				#ifdef DEBUG
				std::cout << a1 << "'s matches" << std::endl;
				#endif
				PrintMatches(a1, firstMatch);
			} else {
				#ifdef DEBUG
				std::cout << "undefeated players" << std::endl;
				#endif
				PrintUndefeated(firstPlayer);
			}
			break;
		case '-':
			ss >> a1;
			Cheat(a1, firstPlayer, firstMatch);
			break;
		case 'i':
			#ifdef DEBUG
			// std::cout << "Added " << name << " after " << tmp->name << std::endl;
			#endif
			ss >> a1;
			std::string s;
			std::ifstream myfile;
			myfile.open(a1.c_str());
			while(getline(myfile,s)) {

				#ifdef DEBUG
				std::cout << "Line: " << s << std::endl;
				#endif
				parseLine(s, firstPlayer, firstMatch);
			}
			myfile.close();
			break;
	}
}


