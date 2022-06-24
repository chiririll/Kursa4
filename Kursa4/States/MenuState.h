#pragma once
#include "State.h"
#include "GameState.h"

class MenuState : public State
{
private:
	const std::string m_texture_path = "res/backgrounds/menu.jpg";

	sf::RectangleShape m_bg_rect;
	sf::Texture m_bg_texture;

public:
	MenuState(Game* game);
	virtual ~MenuState() = default;

	// Updaters
	void render();
	void update();

	// Events
	virtual void handleMouseClick(sf::Event& e);
};

