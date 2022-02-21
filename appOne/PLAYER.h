#pragma once
#include "CHARACTER.h"
class PLAYER :
    public CHARACTER
{
public:
    struct DATA {
        int rightAnimId = 0;
        int leftAnimId = 1;
        int jumpFlag = 0;
        int deathFlag = 0;
        float speed = 0;
        float maxSpeed = 0;
        float curWx = 0;
        float initVecUp = 0;
        float initVecDown = 0;
        float gravity = 0;
        char bulletCharaId = 0;
        float staminaDamage = 0.03f;
        float interval = 0;
        float maxInterval = 50000.0f;
        float minIntSpeed = 100.0f * 2;
        COLOR damageColor;
        COLOR normalColor;


        float bulletOffsetX = 0;
    };
private:
    DATA Player;
    enum class STATE_ID { STRUGGLING, DIED, FALL, SURVIVED };
    STATE_ID StateId = STATE_ID::STRUGGLING;

public:
    PLAYER(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void init();
private:
    void Move();
    void CollisionWithMap();
    void CheckState();
    void Launch();
public:
    void fall();
    void fall2();
    void fall3();
    void Ddamage();
    bool died();
    bool survived();
    void caught();
    void setDeathFlag(int flag) {
        Player.deathFlag = flag;
    }
    float overCenterVx();


    STATE_ID stateId() { return StateId; }
    float PlayerSta() { return Chara.stamina; }
    float interval() { return Chara.damageTime; }

};
