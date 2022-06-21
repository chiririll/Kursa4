#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

typedef unsigned int Uint32;

class HealthBar
{
private:
	// Health data
	const Uint32* m_hp;
	const Uint32* m_max_hp;

	// Healthbar
	sf::RectangleShape m_hbar;
	sf::RectangleShape m_hbar_bg;

public:
	HealthBar(const Uint32* health, const Uint32* max_health);
	HealthBar(const Uint32* health, const Uint32* max_health, sf::Color color);

	void render(sf::RenderWindow* window);
};

