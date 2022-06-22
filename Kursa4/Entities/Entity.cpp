#include "Entity.h"

Entity::Entity() : Entity({ 0, 0 }, 100)
{}

Entity::Entity(sf::Vector2<Uint16> pos, Uint32 health):
	m_map_pos(pos), m_max_hp(health), m_hp(health), m_rect({ BLOCK_SIZE, BLOCK_SIZE })
{}


// Setters
void Entity::setSize(sf::Vector2f size)
{
	m_rect.setSize(size);
}

void Entity::setHealth(Uint32 health)
{
	m_hp = health;
	// TODO: Check
}

void Entity::setMaxHealth(Uint32 max_health)
{
	m_max_hp = max_health;
	// TODO: Check
}


// Actions
void Entity::move(sf::Vector2<int> delta)
{
	m_map_pos.x += delta.x;
	m_map_pos.y += delta.y;
}

void Entity::heal(Uint32 amount)
{
	m_hp = amount > m_max_hp ? m_max_hp : m_hp + amount;
}

void Entity::takeDamage(Uint32 amount)
{
	m_hp = amount > m_hp ? 0 : m_hp - amount;
	if (m_hp == 0)
		die();
}

void Entity::die()
{
	m_alive = false;
}


// Renderers
void Entity::default_render(sf::RenderWindow* window)
{
	if (m_hp > 0) {
		m_rect.setPosition(m_map_pos.x * BLOCK_SIZE, m_map_pos.y * BLOCK_SIZE);
		window->draw(m_rect);
	}
}

void Entity::render(sf::RenderWindow* window)
{
	default_render(window);
}


// Variables
Uint32 Entity::getHealth() const
{
	return m_hp;
}

Uint32 Entity::getMaxHealth() const
{
	return m_max_hp;
}

bool Entity::isAlive() const
{
	return m_alive;
}

// Position
sf::Vector2<Uint16> Entity::pos() const
{
	return m_map_pos;
}

Uint16 Entity::x() const
{
	return m_map_pos.x;
}

Uint16 Entity::y() const
{
	return m_map_pos.y;
}

sf::Vector2f Entity::getRenderPos() const
{
	return m_rect.getPosition();
}

sf::RectangleShape& Entity::rect()
{
	return m_rect;
}
