//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "Player.h"

Player::Player() = default;

Player::Player(int pId, int &pChips) {
	id = pId;
	chips = pChips;
}


int Player::getBet(Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int pot) {
	return 0;
}

void Player::dealCard(Card c) {
	playerHand.addCard(c);
}

Hand Player::getHand() {
	return playerHand;
}

void Player::addChips(int num) {
	chips += num;
}