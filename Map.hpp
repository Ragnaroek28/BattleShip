//
//  Map.hpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#ifndef MAP_HPP
#define MAP_HPP

#include <stdio.h>
#include <iostream>

struct Cell;
class Ship;

class Map {
private:
	std::vector<std::vector<Cell>> cells;
	int width, height;
public:
	Map();
	~Map();
	std::vector<std::vector<std::string> >*  print();
	Cell* getCell(int x, int y);
	bool placeShip(Ship* ship, int x, int y, bool horizontal, bool traditional);
	bool checkSurrounding(Ship* ship, int x, int y, bool horizontal);
	void attack(int x, int y);
	int getWidth();
	int getHeight();
	std::vector<std::vector<Cell>>& getMap();
};

#endif /* Map_hpp */
