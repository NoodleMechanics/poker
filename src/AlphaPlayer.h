//
// Created by Gino Di Gregorio on 2019-04-14.
//

#pragma once

#include "Player.h"

class AlphaPlayer: public Player {
public:
	AlphaPlayer();
	AlphaPlayer(int pId, int &pChips);

	int getBet(Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int pot) override;
};




