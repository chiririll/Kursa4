#include <SFML/Graphics.hpp>

#include "Game.h"
#include "States/MenuState.h"

int main()
{
	Game game;
	game.pushState(new MenuState(&game));

	game.run();

	return 0;
}

