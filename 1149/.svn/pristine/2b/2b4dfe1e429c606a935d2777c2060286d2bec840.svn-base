#ifndef __BETTER_H__
#define __BETTER_H__
#include <string>
#include "observer.h"
#include "horserace.h"

class Bettor: public Observer {
	//keep track of concrete subject
	HorseRace *subject;
  
	//Bettor's name
	const std::string name;

	//horse Bettor is betting on
	const std::string myHorse;

	public:
	//constructor will call attach on HorseRace to subscribe 
	Bettor(HorseRace *hr, std::string name, std::string horse);
	
	//called by subject, better reacts 
	void notify();
	
	~Bettor();
};

#endif
