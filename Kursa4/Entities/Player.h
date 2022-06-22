#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	sf::Texture m_texture;

public:
	Player(Uint16 x, Uint16 y, Uint32 health, std::string texture_file);
	Player(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file);
};

