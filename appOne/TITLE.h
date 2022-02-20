#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        float textSize = 0;
        int image = 0;
        int image2 = 0;
        int flag = 0;
        int helpFlag = 0;
        int chapter = 0;
        int helpImage = 0;
        COLOR textColor;
        COLOR backColor;
        VECTOR2 pos;
        char str[16];
        float buttonRadius = 0;
        float buttonNameTextSize = 40;
        float charaNum = 7.5f;
        VECTOR2 buttonPos;
        float buttonW = buttonNameTextSize * charaNum;
        float buttonH = buttonNameTextSize * 3;
        COLOR color1;
        COLOR color2;
        const char* text1 = "�Q�[���X�^�[�g";

    };
private:
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void create();
    void draw();
    void update();
    void nextScene();
    void init();
    void chapter();
    void setChapter(int capter);
    void setFlag(int flag);
    void setHelp(int flag) {
        Title.helpFlag = flag;
    }
};

