#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../settings.h"

namespace cords 
{
	sf::Vector2u screen2map(sf::Vector2i screen_pos, const sf::RenderWindow* window);
}
