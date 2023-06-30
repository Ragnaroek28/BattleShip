//
//  Main.cpp
//  Battleship
//
//  Created by Janik Karafiat on 23.06.23.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Core.hpp"

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	Game game = Game();
	game.run();
	return 0;
}
