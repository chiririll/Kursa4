#include "TreeCreator.h"

Entity* TreeCreator::create(const sf::Vector2<Uint16>& pos)
{
    return new Tree(pos, 100, 100, 1, 1, m_texture_path);
}