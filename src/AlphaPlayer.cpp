//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "AlphaPlayer.h"

AlphaPlayer::AlphaPlayer() = default;

AlphaPlayer::AlphaPlayer(int pId, int &pChips) {
	id = pId;
	chips = pChips;
}


int AlphaPlayer::getBet(Hand opponent, BetHistory &bh, int bet2Player, bool canRaise, int &pot) {
	Hand oHand = opponent.getVisable();
	int delta = playerHand.evaluate() - oHand.evaluate();
	int betValue = 0;

	if(playerHand.getCount() < 5) {
		if(bh.getCount() == 0) {
			if(delta > 10)
				betValue = 10;
			else if(delta > 5)
				betValue = 5;
			else if(delta > 1)
				betValue = 1;
		} else {
			int potFactor = pot / 10;

			if(bh.getBet(bh.getCount() - 1).getAmount() == 0) {
				if(delta > 5 - potFactor)
					betValue = 10;
				else if(delta > 0-potFactor)
					betValue = 1;
				else
					betValue = 0;
			} else if(bh.getBet(bh.getCount() - 1).getAmount() > 0 && bh.getBet(bh.getCount() - 1).getAmount() < 1 + potFactor * 2) {
				if(delta > 8 - potFactor)
					betValue = 10;
				else if(delta > -2 - potFactor)
					betValue = 1;
				else if(delta > -4 - potFactor)
					betValue = 0;
				else
					betValue = -1;
			} else {
				if (delta > 10 - potFactor)
					betValue = 10;
				else if (delta > 0 - potFactor)
					betValue = 1;
				else if (delta > -2 - potFactor)
					betValue = 0;
				else
					betValue = -1;
			}
		}
	} else {
		if(bh.getCount() == 0) {
			if(delta > 10)
				betValue = 10;
			else if(delta > 5)
				betValue = 5;
			else
				betValue = 0;
		} else {
			int potFactor = pot / 10;

			if(bh.getBet(bh.getCount() - 1).getAmount() == 0) {
				if(delta > 10 - potFactor)
					betValue = 10;
				else
					betValue = 0;
			} else if(bh.getBet(bh.getCount() - 1).getAmount() > 0 && bh.getBet(bh.getCount() - 1).getAmount() > 1 + potFactor * 2) {
				if(delta > 6 - potFactor)
					betValue = 10;
				else if(delta > 2)
					betValue = 0;
				else
					betValue = -1;
			} else {
				if(delta > 8 - potFactor)
					betValue = 10;
				else if(delta > 4)
					betValue = 0;
				else
					betValue = -1;
			}
		}
	}

	if(betValue == -1) {
		return betValue;
	}

	if(bet2Player != 0) {
		// call is not 0
		if(betValue == 0) {
			chips -= bet2Player;
			pot += bet2Player;
			bh.addBet(Bet(bet2Player, 1));

			return betValue;
		}
	} else {
		if(betValue == 0) {
			return betValue;
		}
	}

	if(betValue > 0) {
		chips -= betValue;
		pot += betValue;
		bh.addBet(Bet(betValue, 1));
	}

	return betValue;
}