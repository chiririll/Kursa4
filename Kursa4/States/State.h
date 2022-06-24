#pragma once
#include <list>

#include "../Game.h"
#include "../Entities/Entity.h"

class Game;

class State
{
protected:
	// Game pointer
	Game* m_game;

public:
	State(Game* game);
	virtual ~State();

	// Updaters
	virtual void render() = 0;
	virtual void update() = 0;

	// Events
	virtual void handleMouseClick(sf::Event& e) {};
};
