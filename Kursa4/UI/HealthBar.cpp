#include "HealthBar.h"


HealthBar::HealthBar(const Entity* ent) :
    HealthBar(ent, sf::Color(255, 0, 0)) 
{}

HealthBar::HealthBar(const Entity* ent, sf::Color color) :
    m_ent(ent)
{
    // Health bar
    m_hbar = sf::RectangleShape({ 0.8 * BLOCK_SIZE, 0.1 * BLOCK_SIZE });
    m_hbar.setFillColor(color);

    // Background
    m_hbar_bg = sf::RectangleShape({ 0.8 * BLOCK_SIZE, 0.1 * BLOCK_SIZE });
    m_hbar_bg.setFillColor({ 0, 0, 0 });
    m_hbar_bg.setOutlineThickness(2);
    m_hbar_bg.setOutlineColor({ 0, 0, 0 });
}

void HealthBar::render(sf::RenderWindow* window)
{
    // TODO
    float width = ((float)m_ent->getHealth() / (float)m_ent->getMaxHealth());
    updatePos();
    m_hbar.scale({ 1, 1 });
    window->draw(m_hbar_bg);
    window->draw(m_hbar);
}

void HealthBar::updatePos()
{
    auto ent_pos = m_ent->getRenderPos();

    m_hbar_bg.setPosition(ent_pos);
    m_hbar.setPosition(ent_pos);
}
