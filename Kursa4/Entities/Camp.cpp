#include "Camp.h"

Camp::Camp(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file) :
    Entity(pos, health)
{
    m_texture.loadFromFile(texture_file);
    m_rect.setTexture(&m_texture);
}