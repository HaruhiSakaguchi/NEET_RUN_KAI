#pragma once
#include "SCENE.h"
class GAME_OVER :
    public SCENE
{
public:
    struct DATA {
        float textSize = 0;
        int retryFlag = 0;
        int returnFlag = 0;
        COLOR textColor;
        COLOR backColor;
        VECTOR2 pos;
        char str[16];

        int img = 0;
        int retryImg = 0;
        int retryImg2 = 0;
        int gotoTitleImg = 0;
        int gotoTitleImg2 = 0;
        VECTOR2 backToTitlePos;
        VECTOR2 continuePos;
        float buttonNameTextSize = 30;
        float charaNum = 8;
        float buttonW = buttonNameTextSize * charaNum;
        float buttonH = buttonNameTextSize * 2.0f;
        const char* continueText=0;
        const char* backToTitleText=0;
    };
private:
    DATA GameOver;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void create();
    void draw();
    void nextScene();
    void init();
    void setRetryFlag(int flag);
    void setReturnFlag(int flag);
};

