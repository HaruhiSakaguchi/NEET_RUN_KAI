#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
#include "SCENE.h"
class STORY :
    public SCENE
{
public:
    struct DATA {
        char str[16];
        VECTOR2 pos;
        COLOR textColor;
        COLOR backColor;
        float textSize = 0;
        const char* text = 0;
        const char* text2 = 0;
        const char* text3 = 0;
        int Flag = 0;
        int backImage = 0;
        int backImg[5];
        int charaImg1 = 0;
        int charaImg2 = 0;
        int skipImg = 0;
        int skipImg2 = 0;
        float buttonNameTextSize = 40;
        float charaNum = 7;
        float buttonW = buttonNameTextSize * charaNum/2;
        float buttonH = buttonNameTextSize * 1.5f/2;
        float skipTextSize = 30;
        float skipCharaNum = 6;
        COLOR skipButtonColor;
        VECTOR2 skipButtonPos;
        float skipButtonW = skipTextSize * skipCharaNum;
        float skipButtonH = skipTextSize * 1.5f;
        const char* skipText = "  スキップ";

    };
private:
    DATA Story;
public:
    STORY(class GAME* game);
    ~STORY();
    void create();
    void draw();
    void nextScene();
    void init();
    void setAttentinonFlag(int flag = 0);
    void update();
    void backGround();

};

