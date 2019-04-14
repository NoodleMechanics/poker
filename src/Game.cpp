//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "Game.h"

bool Game::playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag){
	// create the two players
	HumanPlayer player0;
	AlphaPlayer player1;
	BetHistory bh;

	if(p0 == HUMAN)
		player0 = HumanPlayer(0, chips0);

	if(p1 == ALPHA)
		player1 = AlphaPlayer(0, chips1);

	// run game for 20 hands
	//for(int i = 0; i < 20; i++) {
		createDeck();
		int pot = 0;

		// shuffle deck
		shuffleDeck(30);

		// each player buys into pot (10 chips)
		player0.addChips(-10);
		player1.addChips(-10);
		pot += 20;

		// deal starting cards one down each
		deck.back().setFaceUp(false);
		player0.dealCard(deck.back());
		deck.pop_back();

		deck.back().setFaceUp(false);
		player1.dealCard(deck.back());
		deck.pop_back();

		// deal rest of starting cards two up each
		for(int j = 0; j < 2; j++) {
			deck.back().setFaceUp(true);
			player0.dealCard(deck.back());
			deck.pop_back();

			deck.back().setFaceUp(true);
			player1.dealCard(deck.back());
			deck.pop_back();
		}

		// first betting round (player1 starts)
		printf("\nFIRST BETTING ROUND\n\n");
		player0.getBet(player1.getHand(), bh, 0, true, pot);

	//}

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
				deck.emplace_back(Card("Jack", 10));
			} else if(i == 12) {
				deck.emplace_back(Card("Queen", 10));
			} else {
				deck.emplace_back(Card("King", 10));
			}
		}
	}
}

void Game::shuffleDeck(int n) {
	srand(time(0));

	for (int i = 0; i < n; i++) {
		// Random for remaining positions.
		int r = i + (rand() % (52 - i));

		Card tmp = deck[i];
		deck[i] = deck[r];
		deck[r] = tmp;
	}
}

void Game::printDeck() {
	for(auto &i: deck) {
		printf("Card: %s %i\n", i.getName().c_str(), i.getValue());
	}

	printf("\n%i\n\n", (int)deck.size());
}