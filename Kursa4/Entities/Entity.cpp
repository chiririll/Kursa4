#include "Entity.h"

Entity::Entity() : Entity({ 0, 0 }, { 0, 0 }, 100)
{}

Entity::Entity(sf::Vector2f size, sf::Vector2<Uint16> pos, Uint32 health):
	Entity(size, pos, health, health)
{}

Entity::Entity(sf::Vector2f size, sf::Vector2<Uint16> pos, Uint32 health, Uint32 max_health):
    m_size(size), m_pos(pos), m_max_hp(max_health), m_hp(health), m_rect(size)
{}


void Entity::move(sf::Vector2<int> delta)
{
	m_pos.x += delta.x;
	m_pos.y += delta.y;
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

void Entity::render(sf::RenderWindow* window)
{
	if (m_hp > 0)
		window->draw(m_rect);
}

Uint32 Entity::GetHealth()
{
	return m_hp;
}

bool Entity::isAlive()
{
	return m_hp > 0;
}
