//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "BetHistory.h"

void BetHistory::clearHistory() {
	history.clear();
}

void BetHistory::addBet(Bet bet) {
	history.push_back(bet);
}

int BetHistory::getCount() {
	return (int)history.size();
}

Bet BetHistory::getBet(int n) {
	return history[n];
}