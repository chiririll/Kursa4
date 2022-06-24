#include "Map.h"

// Constructors & destructors
Map::Map(): Map(32, 32) {}

Map::Map(const sf::Vector2u& size, const std::string& path) :
    Map(size.x, size.y, path)
{}

Map::Map(Uint32 width, Uint32 height, const std::string& path) : 
    m_width(width), m_height(height), m_bg({ BLOCK_SIZE, BLOCK_SIZE }), m_player()
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


void Map::addPlayer(Player* player)
{
    m_player = player;
}

void Map::addCreator(EntityCreator* creator)
{
    if (creator != nullptr)
        m_creators.push_back(creator);
}


// Get entity by cords
Entity* Map::getEntity(const sf::Vector2u& pos) 
{
    for (auto ent : m_ents)
        if (ent->pos() == pos)
            return ent;
    return nullptr;
}

// Check if entity on block
bool Map::checkBlock(const sf::Vector2u& pos)
{
    if (getEntity(pos))
        return true;

    if (pos == m_player->pos())
        return true;

    return false;
}


// Generator
void Map::generate()
{
    sf::Vector2u pos;
    
    Uint32 max_ents = m_width * m_height - 1;
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
    // Rendering map
    for (Uint32 y = 0; y < m_height; y++)
        for (Uint32 x = 0; x < m_width; x++) {
            m_bg.setPosition(x * (float)BLOCK_SIZE, y * (float)BLOCK_SIZE);
            window->draw(m_bg);
        }

    // Rendering entities
    for (auto ent : m_ents)
        ent->render(window);
}


// Getters
Uint32 Map::width()
{
    return m_width;
}

Uint32 Map::height()
{
    return m_height;
}
