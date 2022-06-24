#include "Enemy.h"

Enemy::Enemy(const sf::Vector2u& pos, Uint32 health, std::string texture_file):
    Entity(pos, health), m_hbar(this)
{
    m_texture.loadFromFile(texture_file);
    m_rect.setTexture(&m_texture);
}

void Enemy::interact(Game* game)
{
    takeDamage(10);
}


void Enemy::think()
{
    // TODO: chase player
}

void Enemy::render(sf::RenderWindow* window)
{
    if (m_alive) {
        default_render(window);
        m_hbar.render(window);
    }
}
