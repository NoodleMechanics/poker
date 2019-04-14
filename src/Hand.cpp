//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "Hand.h"

void Hand::clear() {
	hand.clear();
}

void Hand::addCard(Card card) {
	hand.push_back(card);
}

int Hand::getCount() {
	return (int)hand.size();
}

Card Hand::getCard(int n) {
	return hand[n];
}

Hand Hand::getVisable() {
	Hand h;
	for(auto &i: hand) {
		if(i.isFaceUp()) {
			h.addCard(i);
		}
	}

	return h;
}

int Hand::evaluate() {
	int total = 0;
	for(auto &i: hand) {
		total += i.getValue();
	}

	return total;
}