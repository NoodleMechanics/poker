//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "AlphaPlayer.h"

AlphaPlayer::AlphaPlayer() = default;

AlphaPlayer::AlphaPlayer(int pId, int &pChips) {
	id = pId;
	chips = pChips;
}


int AlphaPlayer::getBet(Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int pot) {
	return 2;
}