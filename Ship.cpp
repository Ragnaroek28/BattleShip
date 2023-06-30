//
//  Ship.cpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#include <cstdlib>
#include <ctime>

#include "Ship.hpp"
#include "Map.hpp"

Ship::Ship(int size) : size(size), hits(size), alive(true) {}

Ship::~Ship()
{
	delete this;
}

bool Ship::hit() {
	if(this->alive) {
		this->hits--;
		std::cout << this->hits << std::endl;
		if(this->hits == 0) {
			this->alive = false;
			return true;
		}
	}
	return false;
}

void Ship::place(Map *map) {
	bool horizontal = rand() % 2;
	
	int tryCount = 0;
	int x, y;
	do {
		x = rand() % map->getWidth();
		y = rand() % map->getHeight();
		tryCount++;
	} while(!map->placeShip(this, x, y, horizontal, false));
}

bool Ship::isAlive() {
	return this->alive;
}

int Ship::getSize() {
	return this->size;
}
