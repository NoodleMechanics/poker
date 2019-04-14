//
// Created by Gino Di Gregorio on 2019-04-14.
//

#pragma once


#include "Hand.h"
#include "BetHistory.h"

class Player {

protected:
	int id;
	int chips;
	Hand playerHand;

public:
	Player();
	Player(int pId, int &pChips);

	virtual int getBet(Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int pot); //// This is abstract
	int getId();
	void clearHand();
	void dealCard(Card c);
	Hand getHand();
	void addChips(int num); // add or sub chips from player
	int getChips();


};
