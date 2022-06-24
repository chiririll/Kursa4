#pragma once
#include "Entity.h"

class Tree : public Entity
{
private:
    sf::Texture m_texture;

public:
    Tree(const sf::Vector2u& pos, Uint32 health, std::string texture_file);
};

