//
// Created by Gino Di Gregorio on 2019-04-14.
//

#include "Player.h"

Player::Player() = default;

Player::Player(int pId, int &pChips) {
	id = pId;
	chips = pChips;
}


int Player::getBet(Hand opponent, BetHistory &bh, int bet2Player, bool canRaise, int &pot) {
	return 0;
}

int Player::getId() {
	return id;
}

void Player::clearHand() {
	playerHand.clear();
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

int Player::getChips() {
	return chips;
}

bool Player::checkBet(int value, int bet2Player) {
	int maxBet = 10;
	if(bet2Player == 0) {
		return value >= 0 && value <= maxBet;
	} else {
		if(value == 0 || value == bet2Player) {
			return true;
		} else if(value < bet2Player + 1) {
				return false;
		} else if(value > bet2Player + maxBet) {
			return false;
		} else {
			return true;
		}
	}
}

void Player::showHand() {
	playerHand.show();

	for(int i = 0; i < playerHand.getCount(); i++) {
		printf("%s ", playerHand.getCard(i).getName().c_str());
	}

	printf("\n");
}