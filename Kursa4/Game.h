#pragma once
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "Map/Map.h"
#include "Map/Creators/CampCreator.h"
#include "Map/Creators/EnemyCreator.h"
#include "Map/Creators/TreeCreator.h"

/* === Debug === */
#include <iostream>
using std::cout;
using std::endl;
/* ============= */

class Game
{
private:
	// Variables
	sf::RenderWindow m_window;
	sf::View m_view;
	Map m_global_map;

	// Initializers
	void initMap();
	void initRand();
	void initView();

	// Updaters
	void update();
	void render();

public:
	Game();
	virtual ~Game() = default;

	// Start stop
	void run();
	void stop();


};

