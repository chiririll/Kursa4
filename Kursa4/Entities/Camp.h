#pragma once
#include "Entity.h"

class Camp : public Entity
{
private:
    sf::Texture m_texture;

public:
    Camp(sf::Vector2<Uint16> pos, Uint32 health, Uint32 max_health, float w, float h, std::string texture_file);
};

