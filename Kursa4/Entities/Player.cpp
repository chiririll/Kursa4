#include "Player.h"

Player::Player(Uint16 x, Uint16 y, Uint32 health, std::string texture_file):
	Player(sf::Vector2<Uint16>(x, y), health, texture_file)
{}

Player::Player(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file):
	Entity(pos, health)
{
	m_texture.loadFromFile(texture_file);
	m_rect.setTexture(&m_texture);
}
