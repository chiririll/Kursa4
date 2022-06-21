#pragma once
#include "Entity.h"

class Enemy :
    public Entity
{
private:
    sf::Texture m_texture;

public:
    Enemy(sf::Vector2<Uint16> pos, Uint32 health, Uint32 max_health, float w, float h, std::string texture_file);

    void think() override;
};

