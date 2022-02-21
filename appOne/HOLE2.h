#pragma once
#include "CHARACTER.h"
class HOLE2 :
    public CHARACTER
{
public:
    struct DATA {
        float curx = 0;
    };
private:
    DATA Hole2;
public:
    HOLE2(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    float px() { return Chara.wx; }
};

