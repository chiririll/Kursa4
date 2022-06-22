#pragma once
#include "Entity.h"

class Tree : public Entity
{
private:
    sf::Texture m_texture;

public:
    Tree(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file);
};

