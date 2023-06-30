//
//  Player.hpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdio.h>
#include <iostream>

class Map;
class Ship;
struct BoolStruct;

class Player {
private:
	std::string name;
	Map *ownMap;
	Map *opponentMap;
	std::vector<Ship*> ships;
public:
	Player(std::string name);
	~Player();
	void setup();
	void placeShips();
	BoolStruct attack(Player *opponent);
	BoolStruct getAttacked(int x, int y);
	bool checkAlive();
	
	// Getter
	Map* getOpponentMap();
	Map* getOwnMap();
	std::string getName();
};

#endif /* Player_hpp */
