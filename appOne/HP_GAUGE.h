#pragma once
#include"GAME_OBJECT.h"
#include"VECTOR2.h"
#include"COLOR.h"
class HP_GAUGE :
    public GAME_OBJECT
{
public:
    struct DATA {
        VECTOR2 hpPos1;
        VECTOR2 hpPos2;
        COLOR color;
        float zoom = 2.5f;
    };
private:
    DATA HpGauge;
public:
    HP_GAUGE(class GAME* game):GAME_OBJECT(game) {}
    void create();
    void draw();
};

