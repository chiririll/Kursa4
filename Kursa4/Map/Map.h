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
	Uint32 m_width;
	Uint32 m_height;

	// Blocks
	sf::Texture m_bg_texture;
	sf::RectangleShape m_bg;

	// Entities
	Player* m_player;
	std::list<Entity*> m_ents;
	std::vector<EntityCreator*> m_creators;

public:
	Map();
	Map(const sf::Vector2u& size, const std::string& path = "res/map/grass.png");
	Map(Uint32 width, Uint32 height, const std::string& path = "res/map/grass.png");
	virtual ~Map();

	void addPlayer(Player* player);
	void addCreator(EntityCreator* creator);
	Entity* getEntity(const sf::Vector2u& pos);
	bool checkBlock(const sf::Vector2u& pos);

	void generate();
	
	// Updaters
	void update();
	void render(sf::RenderWindow* window);

	// Getters
	Uint32 width();
	Uint32 height();

};

