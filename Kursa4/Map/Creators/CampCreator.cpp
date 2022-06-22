#include "CampCreator.h"

Entity* CampCreator::create(const sf::Vector2<Uint16>& pos)
{
    return new Camp(pos, 100, 100, 1, 1, m_texture_path);
}
