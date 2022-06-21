#pragma once
#include "EntityCreator.h"

class CampCreator :
    public EntityCreator
{
protected:
	Entity* create(const sf::Vector2<Uint16>& pos);
};

