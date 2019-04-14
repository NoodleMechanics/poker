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
	// stub
}

int Hand::evaluate() {
	// stub
}