#pragma once
#include "Entity.h"
#include "../UI/HealthBar.h"

class Enemy : public Entity
{
private:
    sf::Texture m_texture;
    HealthBar m_hbar;

public:
    Enemy(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file);

    void think() override;
    void render(sf::RenderWindow* window) override;
};

