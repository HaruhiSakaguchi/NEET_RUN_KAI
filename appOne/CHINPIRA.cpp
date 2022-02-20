#include"window.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"STAGE.h"
#include"ENEMY_BULLET.h"
#include"CHINPIRA.h"
void CHINPIRA::create() {
    Chara = game()->container()->data().chinpiraChara;
    Chinpira = game()->container()->data().chinpira;
}
void CHINPIRA::init() {
    Chara.hp = 0;
    Chara.stamina = Chara.maxStamina;
    Chinpira.triggerCnt = game()->container()->data().chinpira.triggerCnt;
}
void CHINPIRA::appear(float wx, float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().enemyChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.stamina = Chara.maxStamina;
    Chinpira.jumpFlag = 0;
    Chinpira.triggerCnt = game()->container()->data().chinpira.triggerCnt;
    EStateId = ESTATE_ID::STRUGGLING;

}
void CHINPIRA::update() {
    if (game()->container()->data().stage.count == 0 || game()->container()->data().stage.flag == 0) {
        Move();
    }
    if (Chara.damageTime > 0) {
        Chara.damageTime -= delta;
        Chara.color = Chinpira.damageColor;
    }
    else {
        Chara.color = Chinpira.normalColor;
    }
    CollisionWithMap();
    checkState();

}
void CHINPIRA::jump() {
    if (Chinpira.jumpFlag == 0) {
        Chara.vy = Chinpira.initVecUp;
        Chinpira.jumpFlag = 1;
    }
    if (Chinpira.jumpFlag == 1) {
        Chara.vy += Chinpira.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
}
void CHINPIRA::checkState() {
    if (Chara.wx > game()->map()->wDispRight()) {
        EStateId = ESTATE_ID::SURVIVED;
        Chara.hp = 0;
    }

}
void CHINPIRA::Move() {
    //�W�����v
    jump();
    launch();
    if (Chara.hp > 0) {
        Chara.stamina -= Chinpira.staminaDamage;
    }
    //���E�ړ�
    // �ړ��x�N�g��������

    Chinpira.speed = 3.4f * 6.0f * Chara.stamina / 10;
    Chara.vx = Chinpira.speed * delta;
    if (Chara.stamina <= 1) Chara.stamina = 1;
    Chara.animId = Chinpira.rightAnimId;


    //  �ړ��O�Ɍ��݂�Chara.wx��Chinpira.curWx�ɂƂ��Ă���
    Chinpira.curWx = Chara.wx;
    //  �ړ�
    if (Chara.vx != 0.0f) {//���E�L�[���͂���
        //�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.wx���X�V���Ă���
        //���ƂŁA�}�b�v�ɐH������ł�����A����Chinpira.curWx�ɖ߂�
        Chara.wx += Chara.vx;
    }
    else {//���E�L�[���͂��Ȃ��Ƃ�
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void CHINPIRA::CollisionWithMap() {
    MAP* map = game()->map();
    // �}�b�v�`�b�v�ƃL�����̉E
    if (Chara.animId == Chinpira.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
            Chara.wx = Chinpira.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̍�
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //�܂��́A�E�B���h�E�̍��ɂԂ�������
            ) {
            Chara.wx = Chinpira.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̏�
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Chinpira.initVecDown;//�����Ă��������x
    }
    // �}�b�v�`�b�v�ƃL�����̉�
    if (map->collisionCharaBottom(Chinpira.curWx, Chara.wy)) {
        //--�u�}�b�v�`�b�v�ɐH������ł���v
        // �܂��́u��ɗ����Ă���Ƃ��v��������ʂ�--
        //�W�����v�i�����j�����̒�~
        Chinpira.jumpFlag = 0;
        Chara.vy = 0.0f;
        //�����I�ɏ�ɗ����Ă���ʒu�ɂ���
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Chinpira.jumpFlag = 1;//�����Ă��g���K�[�B���̃t���b�O�𗧂Ă邾���ŗ����Ă����B
    }
}
void CHINPIRA::launch() {
    //�e����----------------------------------------------------------------
    Chinpira.elapsedTime += delta;
    float vx = 0.0f;
    if (game()->curStateId() != GAME::FIFTH) {
        vx = 1.0f;
    }
    else vx = -1.0f;
    if (Chinpira.elapsedTime >= Chinpira.interval) {
        Chinpira.elapsedTime -= Chinpira.interval;
        ++Chinpira.triggerCnt %= Chinpira.triggerInterval;
        if (Chinpira.triggerCnt == Chinpira.trigger1st ||
            Chinpira.triggerCnt == Chinpira.trigger2nd ||
            Chinpira.triggerCnt == Chinpira.trigger3rd ||
            Chinpira.triggerCnt == Chinpira.trigger4th) {
            Chara.animId = game()->container()->data().enemyBullet.leftAnimId;
            game()->characterManager()->appear(Chinpira.bulletCharaId,
                Chara.wx + Chinpira.bulletOffsetX, Chara.wy, vx, 0);
        }
    }
}
bool CHINPIRA::survived() {
    return EStateId == ESTATE_ID::SURVIVED;
}

