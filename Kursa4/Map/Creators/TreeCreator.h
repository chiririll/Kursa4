#pragma once
#include "EntityCreator.h"
#include "../../Entities/Tree.h"

class TreeCreator : public EntityCreator
{
private:
	const std::string m_texture_path = "res/tree.png";

protected:
	Entity* create(const sf::Vector2<Uint16>& pos);
};

