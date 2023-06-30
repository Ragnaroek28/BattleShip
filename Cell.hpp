//
//  Cell.hpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#ifndef CELL_HPP
#define CELL_HPP

#include <stdio.h>
#include <iostream>

class Ship;
struct BoolStruct;

struct Cell {
private:
	bool hit;
	Ship* ship;
	
public:
	Cell();
	BoolStruct getHit();
	bool isHit();
	void setShip(Ship* ship);
	Ship* getShip();
};

#endif /* Cell_hpp */
