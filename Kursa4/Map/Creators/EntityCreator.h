#pragma once
#include <cstdlib>

#include "../../Entities/Entity.h"

typedef unsigned int Uint32;

class EntityCreator
{
private:
	Uint32 m_count;

protected:
	virtual Entity* create(const sf::Vector2<Uint16>& pos) = 0;

public:
	EntityCreator() = default;
	EntityCreator(Uint32 count);
	virtual ~EntityCreator() = default;

	// Initializators
	void setCount(Uint32 count);
	void setCount(Uint32 min, Uint32 max);

	// Getters
	Uint32 count() { return m_count; };

	// Greators
	Entity* createEntity(const sf::Vector2<Uint16>& pos);
};

