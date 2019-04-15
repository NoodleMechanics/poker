//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() = default;

HumanPlayer::HumanPlayer(int pId, int &pChips) {
	id = pId;
	chips = pChips;
}


int HumanPlayer::getBet(Hand opponent, BetHistory &bh, int bet2Player, bool canRaise, int &pot) {
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
	printf("\nThe pot is: %i\n", pot);

	do{
		if(bet2Player == 0) {
			printf("Enter amount between 1-10 to bet or enter 0 to check: ");
		} else {
			printf("Enter %i to call, -10 to fold, or amount between %i-%i to raise: ", bet2Player, bet2Player + 1, bet2Player + 10);
		}
		std::cin >> betValue;
	} while(betValue != -1 && !checkBet(betValue, bet2Player));

	if(betValue > 0) {
		chips -= betValue;
		pot += betValue;

		bh.addBet(Bet(betValue, id));
	}

	return betValue;
}
