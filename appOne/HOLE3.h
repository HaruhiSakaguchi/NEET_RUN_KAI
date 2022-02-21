#pragma once
#include "CHARACTER.h"
class HOLE3 :
    public CHARACTER
{
public:
    struct DATA {
        float curx = 0;
    };
private:
    DATA Hole3;
public:
    HOLE3(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    float px() { return Chara.wx; }
};

