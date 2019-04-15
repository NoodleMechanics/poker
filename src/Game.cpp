//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "Game.h"

bool Game::playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag) {
	// create the two players
	HumanPlayer player0;
	AlphaPlayer player1;
	BetHistory bh;
	int pot = 0;

	if (p0 == HUMAN)
		player0 = HumanPlayer(0, chips0);

	if (p1 == ALPHA)
		player1 = AlphaPlayer(0, chips1);

	// run game for 20 hands
	for (int i = 0; i < 20; i++) {
		createDeck();
		int currentBet = 0;

		player0.clearHand();
		player1.clearHand();

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
		for (int j = 0; j < 2; j++) {
			deck.back().setFaceUp(true);
			player0.dealCard(deck.back());
			deck.pop_back();

			deck.back().setFaceUp(true);
			player1.dealCard(deck.back());
			deck.pop_back();
		}

		// first betting round (player1 starts)
		printf("\nFIRST BETTING ROUND\n\n");

		int count = 0;
		do {
			if (count == 3)
				break;
			currentBet = player0.getBet(player1.getHand(), bh, currentBet, true, pot);
			if (currentBet == -1)
				return true; //// exit if player wants
			else if (currentBet == -10)
				break;
			currentBet = player1.getBet(player0.getHand(), bh, currentBet, true, pot);
			if (currentBet == -1)
				break;
			count++;
			printf("\n");
		} while (currentBet != 0);

		if (currentBet == -1) {
			// player 1 folded (end hand)
			printf("You won the hand! The pot was %i \n", pot);
			chips0 += pot;
			continue;
		} else if (currentBet == -10) {
			// player 0 folded (end hand)
			printf("You lost the hand! The pot was %i \n", pot);
			chips1 += pot;
			continue;
		}
		bh.clearHistory(); //// clear for each round???

		//// Deal next cards
		deck.back().setFaceUp(true);
		player0.dealCard(deck.back());
		deck.pop_back();

		deck.back().setFaceUp(true);
		player1.dealCard(deck.back());
		deck.pop_back();

		printf("SECOND BETTING ROUND\n\n");

		count = 0;
		do {
			if (count == 3)
				break;
			currentBet = player1.getBet(player0.getHand(), bh, currentBet, true, pot);
			if (currentBet == -1)
				break;
			currentBet = player0.getBet(player1.getHand(), bh, currentBet, true, pot);
			if (currentBet == -1)
				return true; //// exit if player wants
			else if (currentBet == -10)
				break;
			count++;
			printf("\n");
		} while (currentBet != 0);

		if (currentBet == -1) {
			// player 1 folded (end hand)
			printf("You won the hand! The pot was %i \n", pot);
			chips0 += pot;
			continue;
		} else if (currentBet == -10) {
			// player 0 folded (end hand)
			printf("You lost the hand! The pot was %i \n", pot);
			chips1 += pot;
			continue;
		}
		bh.clearHistory();

		deck.back().setFaceUp(true);
		player0.dealCard(deck.back());
		deck.pop_back();

		deck.back().setFaceUp(true);
		player1.dealCard(deck.back());
		deck.pop_back();

		printf("THIRD BETTING ROUND\n\n");

		count = 0;
		do {
			if (count == 3)
				break;
			currentBet = player1.getBet(player0.getHand(), bh, currentBet, true, pot);
			if (currentBet == -1)
				break;
			currentBet = player0.getBet(player1.getHand(), bh, currentBet, true, pot);
			if (currentBet == -1)
				return true; //// exit if player wants
			else if (currentBet == -10)
				break;
			count++;
			printf("\n");
		} while (currentBet != 0);

		if (currentBet == -1) {
			// player 1 folded (end hand)
			printf("You won the hand! The pot was %i \n", pot);
			chips0 += pot;
			continue;
		} else if (currentBet == -10) {
			// player 0 folded (end hand)
			printf("You lost the hand! The pot was %i \n", pot);
			chips1 += pot;
			continue;
		}
		bh.clearHistory();

		printf("\n\n\nPlayer0 shows: ");
		player0.showHand();
		printf("Player0 hand value: %i\n", player0.getHand().evaluate());

		printf("player1 shows: ");
		player1.showHand();
		printf("Player1 hand value: %i\n", player1.getHand().evaluate());

		int pH0 = player0.getHand().evaluate(), pH1 = player1.getHand().evaluate();
		if(pH0 > pH1) {
			// p0 wins
			printf("Player0 wins! Pot was: %i\n", pot);
			player0.addChips(pot);
			pot = 0;
		} else if(pH0 < pH1) {
			// p1 wins
			printf("Player1 wins! Pot was: %i\n", pot);
			player1.addChips(pot);
			pot = 0;
		} else {
			printf("Hand is a tie!\n");
		}

	}

	return true;
}

void Game::createDeck() {
	deck.clear();

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