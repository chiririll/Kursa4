#include "Player.h"

Player::Player(Uint16 x, Uint16 y, Uint32 health, std::string texture_file):
	Player(sf::Vector2<Uint16>(x, y), health, texture_file)
{}

Player::Player(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file):
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