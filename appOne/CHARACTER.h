#pragma once
#include"GAME_OBJECT.h"
#include"COLOR.h"
#include"ANIMS.h"
class CHARACTER :
    public GAME_OBJECT
{
public:
    struct DATA {
        //複数アニメor単体アニメor静止画を使用する
        //複数アニメーション
        class ANIMS* anims = nullptr;
        int animId = 0;
        //単体アニメーション
        class ANIM* anim = nullptr;
        ANIM_DATA animData;
        //静止画
        int img = 0;
        int img1 = 0;
        int img2 = 0;
        int img3 = 0;
        int img4 = 0;
        int img5 = 0;
        //合成色
        COLOR color;

        char charaId = 0;
        int groupId = 0;
        float wx = 0;
        float wy = 0;
        float vx = 0;
        float vy = 0;
        float speed = 0;
        float angle = 0;

        float damageTime = 0;
        float stamina = 0;
        float maxStamina = 0;
        float damageInterval = 0;

        float knockBackVx = 0;
        float knockBackVy = 0;


        int hp = 0;
        float offsetLeft = 0;
        float offsetTop = 0;
        float offsetRight = 0;
        float offsetBottom = 0;
    };
protected:
    DATA Chara;
public:
    CHARACTER(class GAME* game);
    virtual void create();
    virtual void init();
    virtual void appear(float wx, float wy, float vx, float vy);
    virtual void update();
    virtual void draw();
    virtual void Ddamage();
    virtual void Srecover();
    virtual void Mrecover();
    virtual void Lrecover();
    virtual void Sdamage();
    virtual void Mdamage();
    virtual void Ldamage();
    virtual void knock();
    virtual void fall();
    virtual void fall2();
    virtual void fall3();
    virtual void caught();
    virtual void noDamage();
    virtual void drawRectArea(float px, float py, float Left, float Top, float Right, float Bottom);
    int   hp() { return Chara.hp; }
    int   groupId() { return Chara.groupId; }
    char  charaId() { return Chara.charaId; }
    float wLeft() { return Chara.wx + Chara.offsetLeft; }
    float wTop() { return Chara.wy + Chara.offsetTop; }
    float wRight() { return Chara.wx + Chara.offsetRight; }
    float wBottom() { return Chara.wy + Chara.offsetBottom; }
    void setImgIdx(int i) { Chara.animData.imgIdx = i; }
    float px() { return Chara.wx; }
    void setHp(int hp) {
        Chara.hp = hp;
    }
};

