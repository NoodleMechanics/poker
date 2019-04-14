//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "Bet.h"

Bet::Bet(int a, int p) {
	amount = a;
	player = p;
}

int Bet::getAmount() {
	return amount;
}

int Bet::getPlayer() {
	return player;
}