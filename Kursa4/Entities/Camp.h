#pragma once
#include "Entity.h"

class Camp : public Entity
{
private:
    sf::Texture m_texture;

public:
    Camp(sf::Vector2<Uint16> pos, Uint32 health, std::string texture_file);
};

