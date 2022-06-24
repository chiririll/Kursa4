#include "Game.h"

Game::Game() :
	m_window(sf::VideoMode(1280, 720), "Game title")
{
	initRand();
	initView();
}

void Game::pushState(State* state)
{
	m_states.push(state);
}

void Game::popState()
{
	// Leaving at least one state
	if (m_states.size() <= 1)
		return;
	
	delete m_states.top();
	m_states.pop();
}


// Initializers
void Game::initRand()
{
	srand(time(nullptr));
}

void Game::initView()
{
	m_view = m_window.getDefaultView();
	// m_view.zoom(1.2f);
}


// Start & Stop
void Game::run()
{
	while (m_window.isOpen()) 
	{
		handleEvents();
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

void Game::handleEvents()
{
	sf::Event e;
	while (m_window.pollEvent(e)) 
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::MouseButtonPressed:
			cout << "Click! ";
			m_states.top()->handleMouseClick(e);
			break;
		}
	}
}

void Game::render()
{
	m_window.clear();

	m_states.top()->render();
	
	m_window.setView(m_view);
	m_window.display();
}


// Getters
sf::RenderWindow* Game::window()
{
	return &m_window;
}

sf::View* Game::view()
{
	return &m_view;
}