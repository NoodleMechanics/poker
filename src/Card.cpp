//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "Card.h"

Card::Card(std::string n, int v) {
	name = n;
	value = v;
}

std::string Card::getName() {
	return name;
}

int Card::getValue() {
	return value;
}

bool Card::isFaceUp() {
	return faceUp;
}

void Card::setFaceUp(bool i) {
	faceUp = i;
}