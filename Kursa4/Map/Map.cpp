#include "Map.h"

// Constructors & destructors
Map::Map(): Map(32, 32)
{}

Map::Map(Uint16 w, Uint16 h) : Map(w, h, w)
{}

Map::Map(Uint16 width, Uint16 height, Uint16 count) : 
    m_width(width), m_height(height)
{
    count = std::min(width * height, (int)count);
    m_ents.resize(count);
}


bool Map::checkBlock(Uint16 x, Uint16 y, Uint16 untill)
{
    for (int i = 0; i < std::min((Uint16)m_blocks.size(), untill); i++)
        if (m_blocks[i].x == x && m_blocks[i].y == y)
            return true;

    return false;
}

// Generator
void Map::generate(Uint8 settings)
{
    Uint16 x;
    Uint16 y;
    for (int i = 0; i < m_blocks.size(); i++) {
        do {
            x = rand() % m_width;
            y = rand() % m_height;
        } while (checkBlock(x, y, i));

        m_blocks[i].type = 
    }

    int x = 0;
    int y = 0;
    int randomv;
    while (y < 5000) {
        while (x < 5000) {
            randomv = rand() % 4;
            if (randomv != 0) {
                map[x][y].type = "grass1";
            }
            else {
                map[x][y].type = "tree1";
            }
            if (rand() % 100 == 0) {
                map[x][y].type = "enemy1";
            }
            x++;
        }
        x = 0;
        y++;
    }
}
