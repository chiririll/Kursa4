#pragma once
#include "Entity.h"
#include "../UI/HealthBar.h"

class Player : public Entity
{
private:
	sf::Texture m_texture;
	HealthBar m_hbar;

public:
	Player(Uint32 x, Uint32 y, Uint32 health, std::string texture_file);
	Player(const sf::Vector2u& pos, Uint32 health, std::string texture_file);

	void render(sf::RenderWindow* window) override;
};

