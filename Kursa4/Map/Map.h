#pragma once
#include <vector>
#include <list>
#include <algorithm>

#include "../Entities/Entity.h"
#include "Creators/EntityCreator.h"

typedef unsigned short Uint16;
typedef unsigned char Uint8;

/* === Debug === */
#include <iostream>
using std::cout;
using std::endl;
/* ============= */

class Map
{
private:
	Uint16 m_width;
	Uint16 m_height;

	std::list<Entity*> m_ents;
	std::vector<EntityCreator*> m_creators;

public:
	Map();
	Map(Uint16 width, Uint16 height);
	virtual ~Map();

	void addCreator(EntityCreator* creator);
	bool checkBlock(const sf::Vector2<Uint16>& pos);

	void generate();
	
	// Updaters
	void update();
	void render(sf::RenderWindow* window);
};

