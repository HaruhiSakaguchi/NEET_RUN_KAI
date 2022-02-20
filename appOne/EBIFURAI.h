#pragma once
#include "CHARACTER.h"
class EBIFURAI :
    public CHARACTER
{
public:
    struct DATA {
        int jumpFlag = 0;
        float initVecUp = 0;
        float initVecDown = 0;
        float gravity = 0;
        float curWx = 0;
    };
private:
    DATA Ebifurai;
public:
    EBIFURAI(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void jump();
    void CollisionWithMap();
};

