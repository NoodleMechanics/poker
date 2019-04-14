// Author: Gino Di Gregorio
// Class: CSCI 477


#include <iostream>
#include "src/Game.h"

int main() {
	bool flag;
	int pChips0 = 1000, pChips1 = 1000;

	// start game
	Game g;

	g.createDeck();
	g.printDeck();
	g.playGame(HUMAN, ALPHA, pChips0, pChips1, flag);

	return 0;
}