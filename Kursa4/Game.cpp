#include "Game.h"

Game::Game() :
	m_window(sf::VideoMode(1280, 720), "Game title"),
	m_global_map(64, 32)
	// m_global_map(16, 16)
{
	initRand();
	initMap();
	initView();
}


// Initializers
void Game::initMap()
{
	// Camps
	auto camp_creator = new CampCreator();
	camp_creator->setCount(8, 16);
	m_global_map.addCreator(camp_creator);

	// Enemies
	auto enemy_creator = new EnemyCreator();
	enemy_creator->setCount(16, 24);
	m_global_map.addCreator(enemy_creator);
	
	// Trees
	auto tree_creator = new TreeCreator();
	tree_creator->setCount(12, 24);
	m_global_map.addCreator(tree_creator);

	// Generating map
	m_global_map.generate();
}

void Game::initRand()
{
	srand(time(nullptr));
}

void Game::initView()
{
	m_view = m_window.getDefaultView();
	m_view.zoom(1.2f);
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

	m_global_map.render(&m_window, &m_view);
	
	m_window.setView(m_view);

	m_window.display();
}
