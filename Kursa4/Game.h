#pragma once
#include <vector>
#include <stack>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "Utils/Cords.h"
#include "States/State.h"
#include "Map/Map.h"

/* === Debug === */
#include <iostream>
using std::cout;
using std::endl;
/* ============= */

class State;

class Game
{
private:
	// Variables
	sf::RenderWindow m_window;
	sf::View m_view;
	
	// States
	std::stack<State*> m_states;

	// Initializers
	void initRand();
	void initView();

	// Updaters
	void update();
	void handleEvents();
	void render();

public:
	Game();
	virtual ~Game() = default;

	// States
	void pushState(State* state);
	void popState();

	// Start stop
	void run();
	void stop();

	// Getters
	sf::RenderWindow* window();
	sf::View* view();
};

