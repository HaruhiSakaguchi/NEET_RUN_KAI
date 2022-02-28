#pragma once
#include"graphic.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"GAME.h"
#include"GAME_OBJECT.h"
class ENEMY :
    public CHARACTER
{
public:
   struct DATA {
       float elapsedTime = 0;
       float interval = 0;
       int triggerCnt = 0;
       int triggerInterval = 0;
       int trigger1st = 0;
       int trigger2nd = 0;
       int trigger3rd = 0;
       int trigger4th = 0;
       float bulletOffsetX = 0;
       char bulletCharaId = 0;

       float speed = 0;
      
       int charaDamage = 0;
       int rightAnimId = 0;
       int leftAnimId = 1;

       int jumpFlag = 0;
       int jumpVFlag = 0;
       int recoverFlag = 0;
       int damageFlag = 0;
       int knockFlag = 0;
       
       float curWx = 0;
       float initVecUp = 0;
       float initVecDown = 0;
       float gravity = 0;
       
  
       float staminaDamage = 0.02f;
       COLOR color;
       COLOR damageColor;
       COLOR normalColor;
        };
private:
    DATA Enemy;
    enum class ESTATE_ID { STRUGGLING, DIED, FALL, SURVIVED };
    ESTATE_ID EStateId = ESTATE_ID::STRUGGLING;
public:
    ENEMY(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void launch();
    
private:
        void Move();
        void CollisionWithMap();
public:
    void init();
    void checkState();
    void jump();
    void setVJumpFlag(int flag) {
        Enemy.jumpVFlag = flag;
    }
    void setERecoverFlag(int flag) {
        Enemy.recoverFlag = flag;
    }
    void setEDamageFlag(int flag) {
        Enemy.damageFlag = flag;
    }
    void setKnockFlag(int flag) {
        Enemy.knockFlag = flag;
    }
    bool survived();
   
    int triggerCnt() { return Enemy.triggerCnt; }
    int trigger1st() { return Enemy.trigger1st; }
    int trigger2nd() { return Enemy.trigger2nd; }
    int trigger3rd() { return Enemy.trigger3rd; }
    int trigger4th() { return Enemy.trigger4th; }

    int EjumpFlag() { return Enemy.jumpVFlag; }
    int ErecoverFlag() { return Enemy.recoverFlag; }
    int EdamageFlag() { return Enemy.damageFlag; }
    int EknockFlag() { return Enemy.knockFlag; }

};
       

