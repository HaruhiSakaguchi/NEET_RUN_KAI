#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
#include "GAME_OBJECT.h"
class BUTTON :
    public GAME_OBJECT
{
public:
    struct DATA {
        VECTOR2 buttonPos;
        float buttonH = 0;
        float buttonW = 0;
        float buttonR = 0;
        float buttonSize = 0;
        int buttonShape = 0;
        int rect = 0;
        int circle = 0;
        float radius = 0;
        float textSize = 0;
        float rectButtonNameTextSize = 0;
        float circleButtonNameTextSize = 0;
        float buttonFlag = 0;

        const char* buttonName;
        COLOR buttonColor = (255);
        COLOR buttonTextColor;
        VECTOR2 cursorPos;
    };
private:
    DATA Button;
public:
    BUTTON(class GAME* game);
    ~BUTTON();
    int collisionRect(VECTOR2 pos, float buttonW, float buttonH);
    int collisionCircle(VECTOR2 pos, float buttonR);
    void create();
    void rectButton(VECTOR2 pos, COLOR buttonColor,
        COLOR textColor, const char* buttonName, float buttonNameTextSize, float charaNum);
    void circleButton(VECTOR2 pos, float buttonR, COLOR buttonColor,
        COLOR textColor, const char* buttonName);
    void drawCursor();
    void selectButton(int buttonNum, VECTOR2 pos, float buttonR, COLOR buttonColor,
        COLOR textColor, const char* buttonName, float buttonNameTextSize, float charaNum);


};

