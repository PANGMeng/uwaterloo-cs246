#include "cell.h"

void Cell::notifyDisplay() {
	td->notify(r, c, '0'+state);
}

Cell::Cell() {// Default constructor
	// give default values to all variables to prevent terrible errors
	numNeighbours = 0;
	state = 0;
	prevState = 0;
	r = 0;
	c = 0;
}

int Cell::getState() { //getter for private state
	return state;
}

void Cell::setState(const int& change) { //setter for private state
	prevState = state;
	state = change;
	if (NULL != td) {
		td->notify(r,c, '0'+change);
	}
}

void Cell::setCoords(const int r, const int c) { //setter for private co-ordinates of cell
	this->r = r;
	this->c = c;
}

void Cell::setDisplay(TextDisplay * t) { //setter for TextDisplay
	td = t;
}

void Cell::addNeighbour(Cell *neighbour) { // adds a neighbouring cell
	neighbours[numNeighbours] = neighbour;
	numNeighbours++;
}

void Cell::notify( const int & change) { // run by 0,0 cell on change
	setState(change);
	#ifdef DEBUG
		std::cerr << "Cell::notify: notifying " << numNeighbours << " neighbours ...omg" << std::endl;
	#endif // DEBUG
	for (int i = 0; i < numNeighbours; ++i) {
		#ifdef DEBUG
			std::cerr << "Cell::notify: notifying neighbour #" << i << std::endl;
		#endif // DEBUG
		if (state != prevState) {
			neighbours[i]->notify(state, prevState);
		} else {
			neighbours[i]->notify(state, -1);
		}
	}
}

void Cell::notify(const int & current, const int & previous) { 
	// called by neighbor when neighbor changes
	#ifdef DEBUG
		std::cerr << "Cell::notify: notification to change to " << current << " from " << previous << std::endl;
		std::cerr << "\tAnd I am " << state << std::endl;
	#endif // DEBUG
	if (previous == state) {
		setState(current);
		for (int i = 0; i < numNeighbours; ++i) {
			neighbours[i]->notify(state, prevState);
		}
	}
}
