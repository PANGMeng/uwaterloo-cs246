#include "node.h"
#include <iostream>
#include <sstream>

Node::Node(const std::string &s): name(s) {
	opponent1 = NULL;
	opponent2 = NULL;
}

Node::~Node() {
	if (NULL != opponent2) {
		delete opponent2;
	}
}

// For Players stored in Nodes:
// 
// name = Player's Name
// opponent1 = Match Lost (if NULL, then player hasn't lost anything)
// opponent2 = Next Player

void AddPlayer(std::string name, Node * &firstPlayer) {
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

void PrintUndefeated(Node* firstPlayer) {
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

void PrintMatches(std::string name, Node* firstMatch) {
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

void Cheat(std::string name, Node* firstPlayer, Node* firstMatch) {
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

void parseLine(std::string line, Node * firstPlayer, Node * firstMatch) {
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
		// case 'i':
		// 	ss >> a1 >> a2;
		// 	// std::string s;
		// 	// ifstream myfile (a2, ios::binary);
		// 	// while(getline(myfile,s)) {
		// 	// 	parseLine(s, firstPlayer, firstMatch);
		// 	// }
		// 	// myfile.close();\
		// 	break;
	}
}


