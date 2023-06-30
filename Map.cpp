//
//  Map.cpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//



#include "Map.hpp"
#include "Cell.hpp"
#include "Ship.hpp"

Map::Map() : width(10), height(10) {
	cells.resize(height, std::vector<Cell>(width));
	for(int y = 0; y < this->height; y++) {
		for(int x = 0; x < this->width; x++) {
			this->cells[x][y] = Cell();
		}
	}
}

Map::~Map() {
	delete this;
}


Cell* Map::getCell(int x, int y) {
	Cell *cell = &cells[x][y];
	return cell;
}

bool Map::checkSurrounding(Ship* ship, int x, int y, bool horizontal) {
	
	
	return false;
}

bool Map::placeShip(Ship *ship, int x, int y, bool horizontal, bool traditional) {
	if((horizontal && (x + ship->getSize()) > this->width) || (!horizontal && (y + ship->getSize()) > this->height)) {
		return false;
	}
	if(traditional) {
		for(int j = 0; j < 3; j++) {
			for(int i = 0 - (j % 2); i < ship->getSize() + (j % 2); i++) {
				if(horizontal) {
					if(x + i >= this->width || x + i < 0 || y - 1 + j >= this->height || y - 1 + j < 0
					   || cells[x + i][y - 1 + j].getShip() != nullptr) {
						return false;
					}
				}
				else {
					if(x - 1 + j >= this->width || x - 1 + j < 0 || y + i >= this->height || y + i < 0
					   || cells[x - 1 + j][y + i].getShip() != nullptr) {
						return false;
					}
				}
			}
		}
	}
	else {
		if(cells[x][y].getShip() == nullptr) {
			for(int i = 1; i < ship->getSize(); i++) {
				if(horizontal) {
					if(cells[x + i][y].getShip() != nullptr) {
						return false;
					}
				}
				else {
					if(cells[x][y + i].getShip() != nullptr) {
						return false;
					}
				}
			}
		}
		else {
			return false;
		}
	}
	for(int i = (horizontal)? x : y; i < ((horizontal)? x : y) + ship->getSize(); i++) {
		getCell((horizontal)? i : x, (horizontal)? y : i)->setShip(ship);
	}
	return true;
}

void Map::attack(int x, int y) {
	
}

std::vector<std::vector<Cell>>& Map::getMap() {
	return this->cells;
};

int	Map::getWidth() {
	return this->width;
}

int	Map::getHeight() {
	return this->height;
}
