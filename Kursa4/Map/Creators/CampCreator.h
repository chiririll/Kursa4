#pragma once
#include "EntityCreator.h"
#include "../../Entities/Camp.h"

class GameState;

class CampCreator : public EntityCreator
{
private:
	bool m_exit = false;
	const std::string m_texture_path = "res/entities/camp.png";

protected:
	Entity* create(const sf::Vector2u& pos);

public:
	void setExit();
};

