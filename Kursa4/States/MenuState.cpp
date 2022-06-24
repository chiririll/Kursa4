#include "MenuState.h"

MenuState::MenuState(Game* game) :
	State(game), m_bg_texture(), m_bg_rect()
{
	m_game->view()->zoom(1);

	m_bg_texture.loadFromFile(m_texture_path);

	m_bg_rect.setSize(m_game->view()->getSize());
	m_bg_rect.setTexture(&m_bg_texture);
}

void MenuState::render()
{
	m_game->window()->draw(m_bg_rect);
}

void MenuState::update()
{

}

void MenuState::handleMouseClick(sf::Event& e)
{
	// TODO: Check button position
	m_game->pushState(new GameState(m_game, sf::Vector2u(32, 32)));
}
