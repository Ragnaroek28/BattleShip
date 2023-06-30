//
//  Ship.hpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#ifndef SHIP_HPP
#define SHIP_HPP

#include <stdio.h>
#include <iostream>
#include <random>


class Map;

class Ship
{
private:
	bool alive;
	int size;
	int hits;
public:
	Ship(int size);
	~Ship();
	void place(Map *map);
	bool isAlive();
	bool hit();
	int getSize();
};

#endif /* Ship_hpp */
