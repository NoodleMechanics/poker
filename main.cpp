// Author: Gino Di Gregorio
// Class: CSCI 477


#include <iostream>
#include "src/Game.h"

int main() {
	bool flag;
	int pChips0 = 1000, pChips1 = 1000;

	// start game
	Game g;

	g.playGame(HUMAN, ALPHA, pChips0, pChips1, flag);

	if(pChips0 > pChips1) {
		printf("Player 0 Wins!\n");
	} else if(pChips0 < pChips1) {
		printf("Player 1 Wins!\n");
	} else {
		printf("Game is a Draw\n");
	}

	return 0;
}