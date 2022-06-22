#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../settings.h"

class Entity
{
private:

protected:
	// Transform
	sf::Vector2<Uint16> m_map_pos;
	sf::Vector2f m_size;

	// Health
	bool m_alive = true; // For cleanup
	Uint32 m_max_hp;
	Uint32 m_hp;

	// Rectangle
	sf::RectangleShape m_rect;

	// Default render
	void default_render(sf::RenderWindow* window);

public:
	// Constructors & Destructors
	Entity();
	Entity(sf::Vector2<Uint16> pos, Uint32 health);
	virtual ~Entity() = default;

	// Setters
	void setRenderPos(const sf::Vector2f& pos);
	void setRenderPos(float x, float y);
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
	Uint32 getHealth() const;
	Uint32 getMaxHealth() const;
	bool isAlive() const;
	sf::Vector2<Uint16> pos() const;
	Uint16 x() const;
	Uint16 y() const;
	sf::Vector2f getRenderPos() const;

	// Render
	sf::RectangleShape& rect();

	// Render position
	void updateRenderPos(const sf::RenderWindow* window, const Entity* player);
	void updateRenderPos(const sf::Vector2u& player_pos, const sf::Vector2i& offset, const Entity* player);
	void updateRenderPos(const sf::Vector2f& render_pos);
};

