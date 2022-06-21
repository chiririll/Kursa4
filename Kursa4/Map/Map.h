#pragma once
#include <vector>
#include <algorithm>

#include "../Entities/Entity.h"

typedef unsigned short Uint16;
typedef unsigned char Uint8;

class Map
{
private:
	Uint16 m_width;
	Uint16 m_height;

	std::vector<Entity*> m_ents;

public:
	Map();
	Map(Uint16 width, Uint16 height);
	Map(Uint16 width, Uint16 height, Uint16 block_count);
	virtual ~Map() = default;

	void generate(Uint8 settings);
	bool checkBlock(Uint16 x, Uint16 y, Uint16 untill = -1);
};

