#include"window.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"STAGE.h"
#include"ENEMY_BULLET.h"
#include"MENHERA.h"
void MENHERA::create() {
    Chara = game()->container()->data().menheraChara;
    Menhera = game()->container()->data().menhera;
}
void MENHERA::init() {
    Chara.hp = 0;
    Chara.stamina = Chara.maxStamina;
    Menhera.triggerCnt = game()->container()->data().menhera.triggerCnt;
}
void MENHERA::appear(float wx, float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().enemyChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.stamina = Chara.maxStamina;
    Menhera.jumpFlag = 0;
    Menhera.triggerCnt = game()->container()->data().menhera.triggerCnt;
    EStateId = ESTATE_ID::STRUGGLING;

}
void MENHERA::update() {
    if (game()->container()->data().stage.count == 0 || game()->container()->data().stage.flag == 0) {
        Move();
    }
    if (Chara.damageTime > 0) {
        Chara.damageTime -= delta;
        Chara.color = Menhera.damageColor;
    }
    else {
        Chara.color = Menhera.normalColor;
    }
    CollisionWithMap();
    checkState();

}
void MENHERA::jump() {
    if (Menhera.jumpFlag == 0) {
        Chara.vy = Menhera.initVecUp;
        Menhera.jumpFlag = 1;
    }
    if (Menhera.jumpFlag == 1) {
        Chara.vy += Menhera.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
}
void MENHERA::checkState() {
    if (Chara.wx > game()->map()->wDispRight()) {
        EStateId = ESTATE_ID::SURVIVED;
        Chara.hp = 0;
    }

}
void MENHERA::Move() {
    //�W�����v
    jump();
    launch();
    if (Chara.hp > 0) {
        Chara.stamina -= Menhera.staminaDamage;
    }
    //���E�ړ�
    // �ړ��x�N�g��������

    Menhera.speed = 3.4f * 6.0f * Chara.stamina / 10;
    Chara.vx = Menhera.speed * delta;
    if (Chara.stamina <= 1) Chara.stamina = 1;
    Chara.animId = Menhera.rightAnimId;


    //  �ړ��O�Ɍ��݂�Chara.wx��Menhera.curWx�ɂƂ��Ă���
    Menhera.curWx = Chara.wx;
    //  �ړ�
    if (Chara.vx != 0.0f) {//���E�L�[���͂���
        //�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.wx���X�V���Ă���
        //���ƂŁA�}�b�v�ɐH������ł�����A����Menhera.curWx�ɖ߂�
        Chara.wx += Chara.vx;
    }
    else {//���E�L�[���͂��Ȃ��Ƃ�
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void MENHERA::CollisionWithMap() {
    MAP* map = game()->map();
    // �}�b�v�`�b�v�ƃL�����̉E
    if (Chara.animId == Menhera.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
            Chara.wx = Menhera.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̍�
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //�܂��́A�E�B���h�E�̍��ɂԂ�������
            ) {
            Chara.wx = Menhera.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̏�
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Menhera.initVecDown;//�����Ă��������x
    }
    // �}�b�v�`�b�v�ƃL�����̉�
    if (map->collisionCharaBottom(Menhera.curWx, Chara.wy)) {
        //--�u�}�b�v�`�b�v�ɐH������ł���v
        // �܂��́u��ɗ����Ă���Ƃ��v��������ʂ�--
        //�W�����v�i�����j�����̒�~
        Menhera.jumpFlag = 0;
        Chara.vy = 0.0f;
        //�����I�ɏ�ɗ����Ă���ʒu�ɂ���
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Menhera.jumpFlag = 1;//�����Ă��g���K�[�B���̃t���b�O�𗧂Ă邾���ŗ����Ă����B
    }
}
void MENHERA::launch() {
    //�e����----------------------------------------------------------------
    Menhera.elapsedTime += delta;
    float vx = 0.0f;
    if (game()->curStateId() != GAME::FIFTH) {
        vx = 1.0f;
    }
    else vx = -1.0f;
    if (Menhera.elapsedTime >= Menhera.interval) {
        Menhera.elapsedTime -= Menhera.interval;
        ++Menhera.triggerCnt %= Menhera.triggerInterval;
        if (Menhera.triggerCnt == Menhera.trigger1st ||
            Menhera.triggerCnt == Menhera.trigger2nd ||
            Menhera.triggerCnt == Menhera.trigger3rd ||
            Menhera.triggerCnt == Menhera.trigger4th) {
            Chara.animId = game()->container()->data().enemyBullet.leftAnimId;
            game()->characterManager()->appear(Menhera.bulletCharaId,
                Chara.wx + Menhera.bulletOffsetX, Chara.wy, vx, 0);
        }
    }
}
bool MENHERA::survived() {
    return EStateId == ESTATE_ID::SURVIVED;
}



