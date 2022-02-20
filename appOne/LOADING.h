#pragma once
#include"SCENE.h"
#include"ANIM.h"
class LOADING :public SCENE
{
public:
    struct DATA {
        //単体アニメーション
        class ANIM* anim = nullptr;
        ANIM_DATA animData;
        float goToTitleTime = 0;
    };
private:
    DATA Loading;
public:
    LOADING(class GAME* game):SCENE(game){}
    void init();
    void create();
    void draw();
    void update();
    void nextScene();
};

