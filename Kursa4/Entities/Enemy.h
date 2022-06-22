#pragma once
#include "Entity.h"

class Enemy : public Entity
{
private:
    sf::Texture m_texture;

public:
    Enemy(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file);

    void think() override;
};

