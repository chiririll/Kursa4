#include "HealthBar.h"


HealthBar::HealthBar(const Uint32* health, const Uint32* max_health) :
	HealthBar(health, max_health, sf::Color(255, 0, 0))
{}

HealthBar::HealthBar(const Uint32* health, const Uint32* max_health, sf::Color color) :
    m_hp(health), m_max_hp(max_health)
{
    // Health bar
    m_hbar = sf::RectangleShape({ 50, 5 });
    m_hbar.setFillColor(color);

    // Background
    m_hbar_bg = sf::RectangleShape({ 50, 5 });
    m_hbar_bg.setFillColor({ 0, 0, 0 });
    m_hbar_bg.setOutlineThickness(2);
    m_hbar_bg.setOutlineColor({ 0, 0, 0 } );
}

void HealthBar::render(sf::RenderWindow* window)
{
    // TODO
    float width = (float)*m_hp / ((float)*m_max_hp / 100.0f) * 0.5;

    m_hbar.scale({ width, 1 });
    window->draw(m_hbar_bg);
    window->draw(m_hbar);
}
