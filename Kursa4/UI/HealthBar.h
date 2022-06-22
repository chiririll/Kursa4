#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../Entities/Entity.h"

typedef unsigned int Uint32;

class HealthBar
{
private:
	// Entity data
	const Entity* m_ent;
	// const Uint32* m_hp;
	// const Uint32* m_max_hp;

	// Healthbar
	sf::RectangleShape m_hbar;
	sf::RectangleShape m_hbar_bg;

public:
	HealthBar(const Entity* entity);
	HealthBar(const Entity* entity, sf::Color color);

	
	void render(sf::RenderWindow* window);
	void updatePos();
};

