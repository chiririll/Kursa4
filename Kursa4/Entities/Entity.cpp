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
	if (m_hp > 0)
		window->draw(m_rect);
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


// Render position
void Entity::updateRenderPos(const sf::RenderWindow* window, const Entity* player)
{
	auto screen_size = window->getSize();
	sf::Vector2u player_pos(screen_size.x / 2 - BLOCK_SIZE / 2, screen_size.y / 2 - BLOCK_SIZE / 2);
	sf::Vector2i offset(BLOCK_SIZE - player_pos.x % BLOCK_SIZE, BLOCK_SIZE - player_pos.y % BLOCK_SIZE);

	updateRenderPos(player_pos, offset, player);
}

void Entity::updateRenderPos(const sf::Vector2u& player_pos, const sf::Vector2i& offset, const Entity* player)
{
	sf::Vector2f render_pos(
		(m_map_pos.x + player->x()) * BLOCK_SIZE - offset.x,
		(m_map_pos.y + player->y()) * BLOCK_SIZE - offset.y
	);

	updateRenderPos(render_pos);
}

void Entity::updateRenderPos(const sf::Vector2f& render_pos)
{
	m_rect.setPosition(render_pos);
}
