//
//  Cell.cpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#include "Cell.hpp"
#include "Ship.hpp"
#include "BoolStruct.h"

Cell::Cell(): hit(false), ship(nullptr) {};

BoolStruct Cell::getHit() {
	BoolStruct result = BoolStruct {ship != nullptr, false};
	if(!isHit()) {
		if(ship != nullptr && ship->hit()) {
			result.sunk = true;
		}
	}
	else {
		result.hit = false;
		result.sunk = false;
	}
	this->hit = true;
	return result;
};

void Cell::setShip(Ship* ship) {
	this->ship = ship;
};

Ship* Cell::getShip() {
	return this->ship;
};

bool Cell::isHit() {
	return hit;
}
