#include "Camp.h"

Camp::Camp(const sf::Vector2u& pos, Uint32 health, std::string texture_file, bool exit) :
    Entity(pos, health), m_exit(exit)
{
    m_texture.loadFromFile(texture_file);
    m_rect.setTexture(&m_texture);
}

void Camp::interact(Game* game)
{
    if (m_exit)
        game->popState();
    game->pushState(new GameState(game, sf::Vector2u(16, 16), false));
}
