#pragma once
#include "CHARACTER.h"
class HOLE :
    public CHARACTER
{
public:
    struct DATA {
        float curx = 0;
    };
private:
    DATA Hole;
public:
    HOLE(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    float px() { return Chara.wx; }
};

