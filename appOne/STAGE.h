#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
#include "SCENE.h"
class STAGE :
    public SCENE
{
public:
    struct DATA {
        float textSize = 0;
        COLOR textColor;
        VECTOR2 pos;
        char str[16];
        int charaHp = 1;
        int count = 0;
        int maxCount = 3;
        int backImg = 0;
        int stageClearImg = 0;
        int gameOverImg = 0;
        int flag = 0;
        COLOR backColor;
        COLOR gameOverColor;

        COLOR stageClearColor;

        int bgm1 = 0;
        int bgm2 = 0;
        int bgmFlag = 1;
        int bgm = 0;
        int jump = 0;
        int knock = 0;
        int recover = 0;
        int damage = 0;
        int dead = 0;
    };
private:
    DATA Stage;
    void backGround();
    void logo(int img, const COLOR& color);
public:
    STAGE(class GAME* game) :SCENE(game) {}
    void draw();
    void nextScene();
    void create();
    void init();
    void update();
    int count() { return Stage.count; }
    int flag() { return Stage.flag; }
    void sound();
    void setBgmFlag(int flag) {
        Stage.bgmFlag = flag;
    }
    void setBgm(int bgm) {
        Stage.bgm = bgm;
    }
};

