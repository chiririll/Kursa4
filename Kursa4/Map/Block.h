#pragma once
#include <string>

typedef unsigned short Uint16;

enum BlockType {
    Tree,
    Enemy
};

struct Block {
    Uint16 x;
    Uint16 y;
    BlockType type;

    Block() : Block(-1, -1, Tree) {};
    Block(Uint16 x, Uint16 y, BlockType type): x(x), y(y), type(type) {};
};
