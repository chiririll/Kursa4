#include "Map.h"

// Constructors & destructors
Map::Map(): Map(32, 32)
{}

Map::Map(Uint16 width, Uint16 height) : 
    m_width(width), m_height(height)
{}

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
    
    for (int i = 0; i < m_creators.size(); ) {
        if (m_creators[i]->count() <= 0) {
            i++; continue;
        }

        // Randomizing position
        do {
            pos.x = rand() % m_width;
            pos.y = rand() % m_height;
        } while (checkBlock(pos));
        
        cout << "Pos: " << pos.x << " " << pos.y << endl;

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
    const Uint16 BLOCK_SIZE = 100;

    // Rendering entities
    for (auto ent : m_ents) {
        // TODO: Check in view
        auto& rect = ent->rect();
        rect.setPosition(ent->x() * BLOCK_SIZE, ent->y() * BLOCK_SIZE);
        ent->render(window);
    }
    // Rendering map
    // TODO
}
