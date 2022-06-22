#include "Game.h"

Game::Game() :
	m_window(sf::VideoMode(1280, 720), "Game title"),
	m_global_map(16, 8)
{
	initRand();
	initMap();
}


// Initializers
void Game::initMap()
{
	// Camps
	auto camp_creator = new CampCreator();
	camp_creator->setCount(4, 8);
	m_global_map.addCreator(camp_creator);

	// Enemies
	auto enemy_creator = new EnemyCreator();
	enemy_creator->setCount(8, 10);
	m_global_map.addCreator(enemy_creator);
	
	// Trees
	auto tree_creator = new TreeCreator();
	tree_creator->setCount(10, 20);
	m_global_map.addCreator(tree_creator);

	// Generating map
	m_global_map.generate();
}

void Game::initRand()
{
	srand(time(nullptr));
}


// Start & Stop
void Game::run()
{
	while (m_window.isOpen()) 
	{
		update();
		render();
	}
}

void Game::stop()
{
	m_window.close();
}


// Updaters
void Game::update()
{
}

void Game::render()
{
	m_window.clear();

	m_global_map.render(&m_window);

	m_window.display();
}
