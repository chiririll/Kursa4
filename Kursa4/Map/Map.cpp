#include "Map.h"

// Constructors & destructors
Map::Map(): Map(32, 32) {}

Map::Map(Uint16 width, Uint16 height, const std::string& path) : 
    m_width(width), m_height(height), m_bg({ BLOCK_SIZE, BLOCK_SIZE }),
    m_player(width / 2, height / 2, 100, "res/player.png")
{
    // Loading block texture
    m_bg_texture.loadFromFile(path);
    m_bg.setTexture(&m_bg_texture);
}

Map::~Map()
{
    // Deleting creators
    for (auto creator : m_creators)
        delete creator;

    // Deleting entities
    for (auto ent : m_ents)
        delete ent;
}


void Map::addCreator(EntityCreator* creator)
{
    if (creator != nullptr)
        m_creators.push_back(creator);
}


// Check if entity on block
bool Map::checkBlock(const sf::Vector2<Uint16>& pos)
{
    for (auto ent : m_ents)
        if (ent->pos() == pos)
            return true;

    return false;
}


// Generator
void Map::generate()
{
    sf::Vector2<Uint16> pos;
    
    Uint32 max_ents = m_width * m_height;
    for (int i = 0; i < m_creators.size(); ) {
        if (m_ents.size() >= max_ents)
            break;

        if (m_creators[i]->count() <= 0) {
            i++; continue;
        }

        // Randomizing position
        do {
            pos.x = rand() % m_width;
            pos.y = rand() % m_height;
        } while (checkBlock(pos));

        // Creating entity
        auto ent = m_creators[i]->createEntity(pos);
        if (ent != nullptr)
            m_ents.push_back(ent);
    }
}

void Map::update()
{
    // Updating entities
    for (auto it = m_ents.begin(); it != m_ents.end(); ) {
        auto ent = *it;
        if (ent->isAlive()) {
            ent->think();
            it++;
        }
        else
            it = m_ents.erase(it);
    }
}

void Map::render(sf::RenderWindow* window)
{
    // 
    auto screen_size = window->getSize();
    sf::Vector2u player_pos(screen_size.x / 2 - BLOCK_SIZE / 2, screen_size.y / 2 - BLOCK_SIZE / 2);
    sf::Vector2i offset(BLOCK_SIZE - player_pos.x % BLOCK_SIZE, BLOCK_SIZE - player_pos.y % BLOCK_SIZE);

    // Rendering map
    sf::Vector2u count(screen_size.x / BLOCK_SIZE + 2, screen_size.y / BLOCK_SIZE + 2);
    for (int y = 0; y < count.y; y++)
        for (int x = 0; x < count.x; x++) {
            m_bg.setPosition(x * BLOCK_SIZE - offset.x, y * BLOCK_SIZE - offset.y);
            window->draw(m_bg);
        }
       
    // Rendering entities
    for (auto ent : m_ents) {
        // TODO: Check in view
        ent->updateRenderPos(player_pos, offset, &m_player);
        ent->render(window);
    }

    // Rendering player
    m_player.rect().setPosition(player_pos.x, player_pos.y);
    m_player.render(window);
}
