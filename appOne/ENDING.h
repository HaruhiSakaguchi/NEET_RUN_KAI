#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
#include "SCENE.h"
class ENDING :
    public SCENE
{
public:
    struct DATA {
        float textSize = 0;
        COLOR textColor;
        COLOR backColor;
        VECTOR2 pos;
        char str[16];
        int img[6];
        int backImg = 0;
        float speed = 50.0f * 2;
        float interval = 0.0f;
        float maxInterval = 50000.0f;
    };
private:
    DATA Ending;
    enum ImageNum {
        E1, E2, E3, E4, E5
    };
    ImageNum curImageNum = E1;
public:
    ENDING(class GAME* game);
    ~ENDING();
    void create();
    void draw();
    void nextScene();
    void init();
    void update();
    void setImageNum(ImageNum imageNum)
    {
        curImageNum = imageNum;
    }
    void setInterval(float interval) {
        Ending.interval = interval;
    }
    void setImage();
    void toE2();
    void toE3();
    void toE4();
    void toE5();
};

