//
// Created by Gino Di Gregorio on 2019-04-14.
//

#pragma once


#include <vector>
#include "Card.h"

class Hand {
private:
	std::vector<Card> hand;

public:
	void clear();
	void addCard(Card card);
	int getCount();
	Card getCard(int n);
	Hand getVisable();
	int evaluate();
	void show();
};



