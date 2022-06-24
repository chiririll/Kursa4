#pragma once
#include <cstdlib>

#include "../../Entities/Entity.h"

typedef unsigned int Uint32;

/* === DEBUG === */
#include <iostream>
using std::cout;
using std::endl;
/* ============= */

class EntityCreator
{
private:
	Uint32 m_count;

protected:
	virtual Entity* create(const sf::Vector2u& pos) = 0;

public:
	EntityCreator();
	EntityCreator(Uint32 count);
	virtual ~EntityCreator() = default;

	// Initializators
	void setCount(Uint32 count);
	void setCount(Uint32 min, Uint32 max);

	// Getters
	Uint32 count() { return m_count; };

	// Greators
	Entity* createEntity(const sf::Vector2u& pos);
};

