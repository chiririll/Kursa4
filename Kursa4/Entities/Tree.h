#pragma once
#include "Entity.h"

class Tree : public Entity
{
private:
    sf::Texture m_texture;

public:
    Tree(sf::Vector2<Uint16> pos, Uint32 health, Uint32 max_health, float w, float h, std::string texture_file);
};

