#pragma once
#include "SCENE.h"
#include"COLOR.h"
#include"VECTOR2.h"
class STAGE_CLEAR :
    public SCENE
{
public:
    struct DATA {
        float textSize = 0;
        int goFlag = 0;
        int returnFlag = 0;
        COLOR textColor;
        COLOR backColor;
        VECTOR2 pos;
        char str[16];
        int img = 0;
        int nextButtonImg = 0;
        int nextButtonImg2 = 0;
        int gotoTitleButtonImg = 0;
        int gotoTitleButtonImg2= 0;
        VECTOR2 backToTitlePos;
        VECTOR2 nextPos;
        float buttonNameTextSize = 30;
        float charaNum = 8;
        float buttonW = buttonNameTextSize * charaNum;
        float buttonH = buttonNameTextSize * 2.0f;
        const char* nextText=0;
        const char* backToTitleText=0;
    };
private:
    DATA StageClear;
public:
    STAGE_CLEAR(class GAME* game);
    ~STAGE_CLEAR();
    void draw();
    void nextScene();
    void create();
    void init();
    void setGoFlag(int flag);
    void setReturnFlag(int flag);
};

