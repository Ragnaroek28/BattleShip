//
//  Core.hpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#ifndef CORE_HPP
#define CORE_HPP

#include <stdio.h>
#include <iostream>

class Player;
class Map;


class Game {
private:
	std::vector<Player*> players;
	int currentPlayer;
	bool isGameOver;
public:
	Game();
	~Game();
	
	void init();
	void config();
	void run();
	
	void printMap(Map *map);
};

#endif /* Core_hpp */
