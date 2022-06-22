#pragma once
#include <vector>
#include <list>

#include "../settings.h"
#include "../Entities/Entity.h"
#include "../Entities/Player.h"
#include "Creators/EntityCreator.h"

/* === Debug === */
#include <iostream>
using std::cout;
using std::endl;
/* ============= */

class Map
{
private:
	// Size
	Uint16 m_width;
	Uint16 m_height;

	// Blocks
	sf::Texture m_bg_texture;
	sf::RectangleShape m_bg;

	// Entities
	std::list<Entity*> m_ents;
	std::vector<EntityCreator*> m_creators;

	// Player
	Player m_player;

public:
	Map();
	Map(Uint16 width, Uint16 height, const std::string& path = "res/grass.png");
	virtual ~Map();

	void addCreator(EntityCreator* creator);
	bool checkBlock(const sf::Vector2<Uint16>& pos);

	void generate();
	
	// Updaters
	void update();
	void render(sf::RenderWindow* window, sf::View* view);
};

