#include <iostream>
#include <string>
#include <random>
#include <stdlib.h>

#include "Game.h"

using namespace std;

int main()
{
	Game game;
	game.DisplayStats();

	game.StartGame();
}