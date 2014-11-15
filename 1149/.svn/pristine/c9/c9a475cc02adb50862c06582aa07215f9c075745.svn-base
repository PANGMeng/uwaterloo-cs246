#ifndef __HORSERACE_H__
#define __HORSERACE_H__
#include <fstream>
#include <string>
#include "subject.h"


class HorseRace: public Subject {
	std::fstream in; //source of data
	std::string lastWinner;

	public:
	//connect race to fstream 
	HorseRace(std::string source);
	~HorseRace();

	// Returns true if a race was successfully run.
	bool runRace(); 
	//returns the lastWinner
	std::string getState();
};

#endif
