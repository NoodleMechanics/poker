//
// Created by Gino Di Gregorio on 2019-04-14.
//

#pragma once


class Bet {
private:
	int amount;
	int player;

public:
	Bet(int a, int p);

	int getPlayer();	// player who made the bet (0 or 1)
	int getAmount();	// amount of bet if it is a raise

};



