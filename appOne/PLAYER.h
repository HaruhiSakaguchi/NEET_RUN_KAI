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
        int jumpVFlag = 0;
        int recoverFlag = 0;
        int damageFlag = 0;
        int knockFlag = 0;
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
    void setVjumpFlag(int flag) {
        Player.jumpVFlag = flag;
    }
    void setPRecoverFlag(int flag) {
        Player.recoverFlag = flag;
    }
    void setPDamageFlag(int flag) {
        Player.damageFlag = flag;
    }
    void setKnockFlag(int flag) {
        Player.knockFlag = flag;
    }
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
    int PjumpFlag() { return Player.jumpVFlag; }
    int PrecoverFlag() { return Player.recoverFlag; }
    int PdamageFlag() { return Player.damageFlag; }
    int PknockFlag() { return Player.knockFlag; }
    int PdeathFlag() { return Player.deathFlag; }
};
