#include "EntityCreator.h"

EntityCreator::EntityCreator() : EntityCreator(0)
{}

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

Entity* EntityCreator::createEntity(const sf::Vector2u& pos)
{
	if (m_count <= 0)
		return nullptr;
	
	m_count--;
	auto ent = create(pos);
	return ent;
}
