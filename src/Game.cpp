//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "Game.h"

bool Game::playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag){
	return true;
}

// Plays a game between a player of type p0 and p1. Chips is the number of chips each player
//respectively has at start and end of the game. reportFlag is just a flag to turn on and off I/O
//within the game (so you can do Monte Carlo runs without a lot of output). The method returns
//true if someone wants to quit the program.


void Game::createDeck() {
	for(int j = 0; j < 4; j++) {
		for(int i = 1; i <= 13; i++) {
			if(i == 1) {
				deck.emplace_back(Card("Ace", i));
			} else if(i >= 2 && i <= 10) {
				deck.emplace_back(Card(std::to_string(i), i));
			} else if(i == 11) {
				deck.emplace_back(Card("Jack", i));
			} else if(i == 12) {
				deck.emplace_back(Card("Queen", i));
			} else {
				deck.emplace_back(Card("King", i));
			}
		}
	}
}

void Game::printDeck() {
	for(auto &i: deck) {
		printf("Card: %s %i\n", i.getName().c_str(), i.getValue());
	}

	printf("\n%i\n", (int)deck.size());
}