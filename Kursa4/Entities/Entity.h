#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../settings.h"

class Entity
{
private:

protected:
	// Transform
	sf::Vector2<Uint16> m_pos;
	sf::Vector2f m_size;

	// Health
	bool m_alive = true; // For cleanup
	Uint32 m_max_hp;
	Uint32 m_hp;

	// Rectangle
	sf::RectangleShape m_rect;

public:
	// Constructors & Destructors
	Entity();
	Entity(sf::Vector2<Uint16> pos, Uint32 health);
	virtual ~Entity() = default;

	// Setters
	void setSize(sf::Vector2f size);
	void setHealth(Uint32 health);
	void setMaxHealth(Uint32 max_health);

	// Actions
	virtual void move(sf::Vector2<int> delta);
	virtual void heal(Uint32 amount);
	virtual void takeDamage(Uint32 damage);
	virtual void die();
	virtual void interact() {};

	// Updates
	virtual void think() {};
	virtual void render(sf::RenderWindow* window);

	// Variables
	Uint32 GetHealth();
	bool isAlive();
	sf::Vector2<Uint16> pos();
	Uint16 x();
	Uint16 y();

	// Render
	sf::RectangleShape& rect();
};

