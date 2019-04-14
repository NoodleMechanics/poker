//
// Created by Gino Di Gregorio on 2019-04-14.
//

#pragma once

#include <iostream>

class Card {
private:
	std::string name;
	int value;
	bool faceUp;

public:
	Card(std::string n, int v);

	std::string getName();
	int getValue();
	bool isFaceUp();
	void setFaceUp(bool i);
};



