#include "Enemy.h"

Enemy::Enemy(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file):
    Entity(pos, health), m_hbar(this)
{
    m_texture.loadFromFile(texture_file);
    m_rect.setTexture(&m_texture);
}



void Enemy::think()
{
    // TODO: chase player
}

void Enemy::render(sf::RenderWindow* window)
{
    default_render(window);

    m_hbar.render(window);
}
