#include"window.h"
#include"input.h"
#include"graphic.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"HOLE.h"
#include"ENEMY.h"
#include"PLAYER.h"
void PLAYER::create() {
    Chara = game()->container()->data().playerChara;
    Player = game()->container()->data().player;
}
void PLAYER::init() {
    Chara.hp = 0;
    Chara.angle = 0;
    Chara.stamina = 0;
    Chara.damageTime = 0;
    Player.interval = Player.maxInterval;
    Chara.stamina = 0;
    Player.deathFlag = 0;
    Player.jumpFlag = 0;
    StateId = STATE_ID::STRUGGLING;

}
void PLAYER::appear(float wx, float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().playerChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Player.interval = Player.maxInterval;
    Chara.stamina = Chara.maxStamina;
    StateId = STATE_ID::STRUGGLING;
}
void PLAYER::update() {
    CheckState();
    //�_���[�W���󂯂��Ƃ�������Ƃ�������������------------------------------------
    if (Chara.damageTime > 0) {
        Chara.damageTime -= delta;
        Chara.color = Player.damageColor;
    }
    else {
        Chara.color = Player.normalColor;
    }
    if (StateId != STATE_ID::FALL) {
        if (Player.deathFlag == 0) {
            Move();
        }
        if (game()->curStateId() == GAME::FIFTH) {
            Launch();
        }
        CollisionWithMap();
    }

}
void PLAYER::Launch() {
    //�e����
    if (isTrigger(KEY_ENTER) || isTrigger(MOUSE_RBUTTON)) {
        float vx = 1.0f;
        if (Chara.animId == Player.leftAnimId) vx = -1.0f;
        float wx = Chara.wx + Player.bulletOffsetX * vx;
        float wy = Chara.wy;
        game()->characterManager()->appear(Player.bulletCharaId, wx, wy, vx);
    }
}
void PLAYER::Move() {
    if (Chara.hp > 0 || Chara.stamina <= 0) {
        Chara.stamina -= Player.staminaDamage;
    }
    if (Player.jumpFlag == 0 && (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON))) {
        Chara.vy = Player.initVecUp;
        Player.jumpFlag = 1;
        setVjumpFlag(1);
    }
    if (Player.jumpFlag == 1) {
        Chara.vy += Player.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
    //���E�ړ�
    // �ړ��x�N�g��������
    Player.speed = 3.4f * 6.0f * Chara.stamina / 10 * 2;
    Chara.vx = Player.speed * delta;
    if (Chara.stamina <= 10) Chara.stamina = 10;
    Chara.animId = Player.rightAnimId;

    //  �ړ��O�Ɍ��݂�Chara.wx��Player.curWx�ɂƂ��Ă���
    Player.curWx = Chara.wx;
    //  �ړ�
    if (Chara.vx != 0.0f) {//���E�L�[���͂���
        //�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.wx���X�V���Ă���
        //���ƂŁA�}�b�v�ɐH������ł�����A����Player.curWx�ɖ߂�
        Chara.wx += Chara.vx;
    }
    else {//���E�L�[���͂��Ȃ��Ƃ�
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void PLAYER::CollisionWithMap() {
    MAP* map = game()->map();
    // �}�b�v�`�b�v�ƃL�����̉E
    if (Chara.animId == Player.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
            Chara.wx = Player.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̍�
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //�܂��́A�E�B���h�E�̍��ɂԂ�������
            ) {
            Chara.wx = Player.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̏�
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Player.initVecDown;//�����Ă��������x
    }
    // �}�b�v�`�b�v�ƃL�����̉�
    if (map->collisionCharaBottom(Player.curWx, Chara.wy)) {
        //--�u�}�b�v�`�b�v�ɐH������ł���v
        // �܂��́u��ɗ����Ă���Ƃ��v��������ʂ�--
        //�W�����v�i�����j�����̒�~
        Player.jumpFlag = 0;
        Chara.vy = 0.0f;
        //�����I�ɏ�ɗ����Ă���ʒu�ɂ���
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Player.jumpFlag = 1;//�����Ă��g���K�[�B���̃t���b�O�𗧂Ă邾���ŗ����Ă����B
    }
}
void PLAYER::CheckState() {
    //��ʂ̉��ɗ�����
    if (Chara.wy > height + game()->map()->chipSize()) {
        StateId = STATE_ID::FALL;
        Chara.wy += Chara.vy;
        Chara.hp = 0;
        Player.interval = Player.maxInterval;
        return;
    }
    //�X�e�[�W�N���A����
    else if (Chara.wx > game()->map()->wDispRight()) {
        StateId = STATE_ID::SURVIVED;
        Chara.hp = 0;
        Player.interval = Player.maxInterval;
    }
    //����
    else if (Chara.hp == 0) {
        Chara.vy = Player.initVecDown;//�͂ˎn�߂̃g���K�[
        StateId = STATE_ID::DIED;
        Player.interval = Player.maxInterval;
    }
}
void PLAYER::fall() {
    //Chara.wx = game()->characterManager()->hole1()->px();
    Chara.wy = height;
    Chara.vy = 10;
    Player.interval = Player.maxInterval;
}
bool PLAYER::died() {
    if (StateId == STATE_ID::DIED) {
        //if(Chara.angle <=90)
        Chara.angle += 0.01f;
        //if (Chara.angle >= 90) {
           // Chara.angle = 90;
        return true;
        //}


    }
    else if (StateId == STATE_ID::FALL) {
        return true;
    }
    return false;
}
void PLAYER::Ddamage() {
    setDeathFlag(1);
    Chara.vx = 0;
    Chara.vy = 0;


    StateId = STATE_ID::DIED;





    //Player.interval = Player.maxInterval;
    //StateId = STATE_ID::STRUGGLING;
}
bool PLAYER::survived() {
    return StateId == STATE_ID::SURVIVED;
}
float PLAYER::overCenterVx() {
    //�}�b�v���X�N���[�������邽�߂̃x�N�g�������߂�
    float centerWx = (game()->map()->wx() + width / 2 - game()->map()->chipSize() / 2);
    float overCenterVx = Chara.wx - centerWx;
    if (overCenterVx < 0 || Chara.hp == 0)overCenterVx = 0;
    return overCenterVx;
}
void PLAYER::caught() {
    StateId = STATE_ID::SURVIVED;
}