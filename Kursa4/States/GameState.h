#pragma once
#include "State.h"
#include "../Map/Map.h"
#include "../Map/Creators/CampCreator.h"
#include "../Map/Creators/EnemyCreator.h"
#include "../Map/Creators/TreeCreator.h"

class GameState : public State
{
private:
	const std::string m_player_texture = "res/entities/player.png";

	bool m_generate_camps;

	Map m_map;
	Player m_player;

public:
	GameState(Game* game, sf::Vector2u map_size, bool gen_camps = true);
	virtual ~GameState();

	// Initializers
	void initMap();

	// Updaters
	void render();
	void update();

	// Events
	virtual void handleMouseClick(sf::Event& e);
};

