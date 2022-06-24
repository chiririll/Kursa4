#include "TreeCreator.h"

Entity* TreeCreator::create(const sf::Vector2u& pos)
{
    return new Tree(pos, 100, m_texture_path);
}