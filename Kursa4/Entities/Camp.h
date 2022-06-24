#pragma once
#include "Entity.h"
#include "../Game.h"
#include "../States/GameState.h"

class Camp : public Entity
{
private:
    sf::Texture m_texture;
    bool m_exit;

public:
    Camp(const sf::Vector2u& pos, Uint32 health, std::string texture_file, bool exit = false);

    void interact(Game* game) override;
};

