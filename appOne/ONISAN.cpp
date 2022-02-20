#include"window.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"STAGE.h"
#include"ENEMY_BULLET.h"
#include "ONISAN.h"
void ONISAN::create() {
    Chara = game()->container()->data().onisanChara;
    Onisan = game()->container()->data().onisan;
}
void ONISAN::init() {
    Chara.hp = 0;
    Chara.stamina = Chara.maxStamina;
    Onisan.triggerCnt = game()->container()->data().onisan.triggerCnt;
}
void ONISAN::appear(float wx, float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().enemyChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.stamina = Chara.maxStamina;
    Onisan.jumpFlag = 0;
    Onisan.triggerCnt = game()->container()->data().onisan.triggerCnt;
    EStateId = ESTATE_ID::STRUGGLING;

}
void ONISAN::update() {
    Move();

    if (Chara.damageTime > 0) {
        Chara.damageTime -= delta;
        Chara.color = Onisan.damageColor;
    }
    else {
        Chara.color = Onisan.normalColor;
    }
    CollisionWithMap();
    checkState();

}
void ONISAN::jump() {
    if (Onisan.jumpFlag == 0) {
        Chara.vy = Onisan.initVecUp;
        Onisan.jumpFlag = 1;
    }
    if (Onisan.jumpFlag == 1) {
        Chara.vy += Onisan.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
}
void ONISAN::checkState() {
    if (Chara.wx > game()->map()->wDispRight()) {
        EStateId = ESTATE_ID::SURVIVED;
        Chara.hp = 0;
    }

}
void ONISAN::Move() {
    //�W�����v
    jump();
    launch();
    if (Chara.hp > 0) {
        Chara.stamina -= Onisan.staminaDamage;
    }
    //���E�ړ�
    // �ړ��x�N�g��������

    Onisan.speed = 3.4f * 6.0f * Chara.stamina / 10;
    Chara.vx = Onisan.speed * delta;
    if (Chara.stamina <= 1) Chara.stamina = 1;
    Chara.animId = Onisan.rightAnimId;


    //  �ړ��O�Ɍ��݂�Chara.wx��Onisan.curWx�ɂƂ��Ă���
    Onisan.curWx = Chara.wx;
    //  �ړ�
    if (Chara.vx != 0.0f) {//���E�L�[���͂���
        //�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.wx���X�V���Ă���
        //���ƂŁA�}�b�v�ɐH������ł�����A����Onisan.curWx�ɖ߂�
        Chara.wx += Chara.vx;
    }
    else {//���E�L�[���͂��Ȃ��Ƃ�
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void ONISAN::CollisionWithMap() {
    MAP* map = game()->map();
    // �}�b�v�`�b�v�ƃL�����̉E
    if (Chara.animId == Onisan.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
            Chara.wx = Onisan.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̍�
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //�܂��́A�E�B���h�E�̍��ɂԂ�������
            ) {
            Chara.wx = Onisan.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̏�
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Onisan.initVecDown;//�����Ă��������x
    }
    // �}�b�v�`�b�v�ƃL�����̉�
    if (map->collisionCharaBottom(Onisan.curWx, Chara.wy)) {
        //--�u�}�b�v�`�b�v�ɐH������ł���v
        // �܂��́u��ɗ����Ă���Ƃ��v��������ʂ�--
        //�W�����v�i�����j�����̒�~
        Onisan.jumpFlag = 0;
        Chara.vy = 0.0f;
        //�����I�ɏ�ɗ����Ă���ʒu�ɂ���
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Onisan.jumpFlag = 1;//�����Ă��g���K�[�B���̃t���b�O�𗧂Ă邾���ŗ����Ă����B
    }
}
void ONISAN::launch() {
    //�e����----------------------------------------------------------------
    Onisan.elapsedTime += delta;
    float vx = 1.0f;

    if (Onisan.elapsedTime >= Onisan.interval) {
        Onisan.elapsedTime -= Onisan.interval;
        ++Onisan.triggerCnt %= Onisan.triggerInterval;
        if (Onisan.triggerCnt == Onisan.trigger1st ||
            Onisan.triggerCnt == Onisan.trigger2nd ||
            Onisan.triggerCnt == Onisan.trigger3rd ||
            Onisan.triggerCnt == Onisan.trigger4th) {
            Chara.animId = game()->container()->data().enemyBullet.leftAnimId;
            game()->characterManager()->appear(Onisan.bulletCharaId,
                Chara.wx + Onisan.bulletOffsetX, Chara.wy, vx, 0);
        }
    }
}
bool ONISAN::survived() {
    return EStateId == ESTATE_ID::SURVIVED;
}




