//
// Created by Gino Di Gregorio on 2019-04-14.
//

#pragma once


#include <vector>
#include "Bet.h"

class BetHistory {
private:
	std::vector<Bet> history;

public:
	void clearHistory();
	void addBet(Bet bet);
	int getCount();
	Bet getBet(int n);
};



