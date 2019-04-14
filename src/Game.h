//
// Created by Gino Di Gregorio on 2019-04-14.
//

#pragma once

#include <vector>
#include "PlayerType.h"
#include "Card.h"


class Game {
private:
	std::vector<Card> deck;

public:
	bool playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag);

	void createDeck();
	void printDeck();
};



