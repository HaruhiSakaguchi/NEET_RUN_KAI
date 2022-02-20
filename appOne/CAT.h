#pragma once
#include "CHARACTER.h"
class CAT :
    public CHARACTER
{
public:
    CAT(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
};

