#pragma once
#include "CHARACTER.h"
class RYMAN :
    public CHARACTER
{
public:
    RYMAN(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
};

