#pragma once
#include"COLOR.h"
#include "SCENE.h"
class COUNT_DOWN :
    public SCENE
{
public:
    struct DATA {
        int count = 0;
        int image = 0;
        float textSize = 0.0f;
        float speed = 100*2;
        float interval = 0.0f;
        float maxInterval = 250.0f;
        COLOR imageColor;
    };
private:
    DATA CD;
    enum class STATE {
        FOUR,THREE,TWO,ONE,ZERO
    };
    STATE State = STATE::FOUR;
public:
    COUNT_DOWN(class GAME* game) :SCENE(game) {}
    void create();
    void init();
    void draw();
    void nextScene();
    void toThree();
    void toTwo();
    void toOne();
    void toZero();
   
};

