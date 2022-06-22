#include "EntityCreator.h"

EntityCreator::EntityCreator(Uint32 count) :
	m_count(count)
{}

void EntityCreator::setCount(Uint32 count)
{
	m_count = count;
}

void EntityCreator::setCount(Uint32 min, Uint32 max)
{
	setCount((rand() + min) % max);
}

Entity* EntityCreator::createEntity(const sf::Vector2<Uint16>& pos)
{
	if (m_count-- > 0)
		return create(pos);
	return nullptr;
}
