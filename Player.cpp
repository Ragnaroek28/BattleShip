//
//  Player.cpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#include <random>

#include "Player.hpp"
#include "Map.hpp"
#include "Cell.hpp"
#include "Ship.hpp"
#include "BoolStruct.h"

Player::Player(std::string name): name(name) {
	this->ships.resize(10);
	setup();
}

Player::~Player() {
	delete this;
}

void Player::setup() {
	this->ships[0] = new Ship(5);
	this->ships[1] = new Ship(4);
	this->ships[2] = new Ship(4);
	this->ships[3] = new Ship(3);
	this->ships[4] = new Ship(3);
	this->ships[5] = new Ship(3);
	this->ships[6] = new Ship(2);
	this->ships[7] = new Ship(2);
	this->ships[8] = new Ship(2);
	this->ships[9] = new Ship(2);
	
	this->ownMap = new Map();
	this->opponentMap = new Map();
	
	placeShips();
}

void Player::placeShips() {
	for(int i = 0; i < this->ships.size(); i++) {
		this->ships[i]->place(this->ownMap);
	}
}

BoolStruct Player::attack(Player *opponent) {
	bool nextFound = false;
	int x = 0, y = 0;
	
	for(x = 0; x < opponentMap->getWidth(); x++) {
		for (y = 0; y < opponentMap->getHeight(); y++) {
			if(!opponentMap->getCell(x, y)->isHit()) {
				nextFound = true;
				break;
			}
		}
		if(nextFound) {
			break;
		}
	}
	BoolStruct result = opponent->getAttacked(x, y);
	this->opponentMap->getCell(x, y)->getHit();
	return result;
}

BoolStruct Player::getAttacked(int x, int y) {
	BoolStruct result = ownMap->getCell(x, y)->getHit();
	return result;
}

bool Player::checkAlive() {
	for(int i = 0; i < ships.size(); i++) {
		if(ships[i]->isAlive()) {
			return true;
		}
	}
	return false;
}

Map* Player::getOwnMap() {
	return this->ownMap;
}
Map* Player::getOpponentMap() {
	return this->opponentMap;
}
std::string Player::getName() {
	return this->name;
}

