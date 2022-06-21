#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

typedef unsigned short Uint16;
typedef unsigned int Uint32;

class Entity
{
private:

protected:
	// Transform
	sf::Vector2<Uint16> m_pos;
	sf::Vector2f m_size;

	// Health
	Uint32 m_max_hp;
	Uint32 m_hp;

	// Rectangle
	sf::RectangleShape m_rect;

public:
	// Constructors & Destructors
	Entity();
	Entity(sf::Vector2f size, sf::Vector2<Uint16> pos, Uint32 health);
	Entity(sf::Vector2f size, sf::Vector2<Uint16> pos, Uint32 health, Uint32 max_health);
	virtual ~Entity() = default;

	// Actions
	virtual void move(sf::Vector2<int> delta);
	virtual void heal(Uint32 amount);
	virtual void takeDamage(Uint32 damage);
	virtual void die() {};
	virtual void interact() {};

	// Updates
	virtual void think() = 0;
	virtual void render(sf::RenderWindow* window);

	// Variables
	Uint32 GetHealth();
	bool isAlive();
};

