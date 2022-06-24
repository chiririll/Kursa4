#include "Player.h"

Player::Player(Uint32 x, Uint32 y, Uint32 health, std::string texture_file):
	Player(sf::Vector2u(x, y), health, texture_file)
{}

Player::Player(const sf::Vector2u& pos, Uint32 health, std::string texture_file):
	Entity(pos, health), m_hbar(this, sf::Color(0, 255, 0))
{
	m_texture.loadFromFile(texture_file);
	m_rect.setTexture(&m_texture);
}

void Player::render(sf::RenderWindow* window)
{
	default_render(window);

	m_hbar.render(window);
}