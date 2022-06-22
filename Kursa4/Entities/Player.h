#pragma once
#include "Entity.h"
#include "../UI/HealthBar.h"

class Player : public Entity
{
private:
	sf::Texture m_texture;
	HealthBar m_hbar;

public:
	Player(Uint16 x, Uint16 y, Uint32 health, std::string texture_file);
	Player(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file);

	void render(sf::RenderWindow* window) override;
};

