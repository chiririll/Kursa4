#pragma once
#include "EntityCreator.h"
#include "../../Entities/Enemy.h"

class EnemyCreator: public EntityCreator
{
private:
	const std::string m_texture_path = "vrag1.png";

protected:
	Entity* create(const sf::Vector2<Uint16>& pos);
};
