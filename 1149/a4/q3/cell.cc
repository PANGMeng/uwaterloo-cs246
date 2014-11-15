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
	for (int i = 0; i < numNeighbours; ++i) {
		neighbours[i]->notify(state, prevState);
	}
}

void Cell::notify(const int & current, const int & previous) { 
	// called by neighbor when neighbor changes
	if (previous == state) {
		setState(current);
		for (int i = 0; i < numNeighbours; ++i) {
			neighbours[i]->notify(state, prevState);
		}
	}
}
