#include "CampCreator.h"

Entity* CampCreator::create(const sf::Vector2u& pos)
{
    if (m_exit)
        return  new Camp(pos, 100, m_texture_path, true);
    return new Camp(pos, 100, m_texture_path);
}

void CampCreator::setExit()
{
    m_exit = true;
    setCount(1);
}
