#pragma once
#include "Cords.h"


sf::Vector2u cords::screen2map(sf::Vector2i screen_pos, const sf::RenderWindow* window)
{
	auto map_pos = window->mapPixelToCoords(screen_pos);
	return sf::Vector2u(map_pos.x / BLOCK_SIZE, map_pos.y / BLOCK_SIZE);
}
