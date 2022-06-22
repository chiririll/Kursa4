#include "Camp.h"

Camp::Camp(sf::Vector2<Uint16> pos, Uint32 health, Uint32 max_health, float w, float h, std::string texture_file) :
    Entity({ 100.0f, 100.0f }, pos, health, max_health)
{
    m_texture.loadFromFile(texture_file);
    m_rect.setTexture(&m_texture);
}