#pragma once
#include "EntityCreator.h"
#include "../../Entities/Camp.h"

class CampCreator : public EntityCreator
{
private:
	const std::string m_texture_path = "res/camp.png";

protected:
	Entity* create(const sf::Vector2<Uint16>& pos);
};

