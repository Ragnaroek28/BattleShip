//
//  Core.cpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#include <unistd.h>

#include "Core.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Cell.hpp"
#include "BoolStruct.h"


Game::Game() {
	init();
}

Game::~Game() {}

void Game::init() {
	players.clear();
	this->currentPlayer = rand() % 2;
	this->isGameOver = false;
	players.push_back(new Player("Player 1"));
	players.push_back(new Player("Player 2"));
}

void Game::run() {
	int count = 0;
	while(players[0]->checkAlive() && players[0]->checkAlive() && count < 10) {
		players[currentPlayer]->attack(players[(currentPlayer + 1) % 2]);
		currentPlayer = (currentPlayer + 1) % 2;
		printMap(players[currentPlayer]->getOwnMap());
		
		sleep(0);
		
		//count++;
	}
	for (int i = 0; i < players.size(); i++) {
		if(players[i]->checkAlive()) {
			std::cout << players[i]->getName() << std::endl;
		}
	}
}

void Game::printMap(Map *map) {
	using namespace std;
	
	// Printing the head of the map
	cout << endl;
	cout << "     /— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —\\" << endl;
	cout << "    //— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —\\\\" << endl;
	cout << "    ||                                                             ||" << endl;
	
	// printing the cells
	for(int y = map->getHeight(); y >= 0; y--) {
		// printing the line
		cout << y
			<< ((y > 9)? "  " : "   ")
			<< "||"
			<< " ";
		
		for(int x = 0; x < map->getWidth(); x++) {
			cout << "  ";
			Cell *cell = map->getCell(x, y);
			if(cell->getShip() != nullptr) {
				if(cell->isHit()) {
					cout << "\e[0;31mX\e[0m";
				}
				else {
					cout << "S";
				}
			}
			else {
				if(cell->isHit()) {
					cout << "X";
				}
				else {
					cout << "~";
				}
			}
			cout << "  " << ((x+1 == map->getWidth())? "" : "|");
		}
		
		cout << " ||" << endl;
		cout << "    ||                                                             ||" << endl;
	}
	
	// printing the foot of the map
	cout
		<< "    \\\\— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —//"
		<< endl
		<< "     \\— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —/"
		<< endl
		<< endl;
}
