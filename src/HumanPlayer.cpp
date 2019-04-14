//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() = default;

HumanPlayer::HumanPlayer(int pId, int &pChips) {
	id = pId;
	chips = pChips;
}


int HumanPlayer::getBet(Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int pot) {
	int betValue = 0;
	Hand oHand = opponent.getVisable();

	printf("Your hand is: ");
	for(int i = 0; i < playerHand.getCount(); i++) {
		printf("%s ", playerHand.getCard(i).getName().c_str());
	}
	printf("\nYour hand value is: %i\n", playerHand.evaluate());
	printf("The opponent is showing: ");
	for(int i = 0; i < oHand.getCount(); i++) {
		printf("%s ", oHand.getCard(i).getName().c_str());
	}
	printf("\n");

	printf("Enter amount to bet (enter 0 for check): ");
	std::cin >> betValue;

	return betValue;
}
