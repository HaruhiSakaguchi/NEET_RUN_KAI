#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"ENEMY.h"
#include"ENEMY_BULLET.h"
void ENEMY_BULLET::create() {
    Chara = game()->container()->data().enemyBulletChara;
    EnemyBullet = game()->container()->data().enemyBullet;
}
void ENEMY_BULLET::appear(float wx , float wy, float vx, float vy){
    switch (game()->curStateId()) {
    case GAME::FIRST:
        Chara.img = Chara.img1;
        Chara.angle = 0;
        break;
    case GAME::SECOND:
        Chara.img = Chara.img2;
        Chara.angle = 45;
        break;
    case GAME::THIRD:
        Chara.img = Chara.img4;
        Chara.angle = -90;
        break;
    case GAME::FOURTH:
        Chara.img = Chara.img3;
        Chara.angle = 30;
        break;
    default:
        Chara.img = Chara.img1;
        Chara.angle = 0;
        break;
    }
    Chara.hp = game()->container()->data().enemyBulletChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = EnemyBullet.initVecX;
    Chara.vy = EnemyBullet.initVecY;
    Chara.animId = EnemyBullet.leftAnimId;
   
    EnemyBullet.fallFlag = 0;
}
void ENEMY_BULLET::update(){
    Move();
    CollisionWithMap();
    ChangeColor();
}
void ENEMY_BULLET::Move(){
   
    
    //���݂̈ʒu���Ƃ��Ă���
    EnemyBullet.curWx = Chara.wx;
    Chara.angle+=0.1f;
    //���E�ɂ�����
    //Chara.wx += Chara.vx * (Chara.speed * delta);
    
    //�ړ�--------------------------------------------------------------------------
    //if (game()->characterManager()->enemy()->triggerCnt() == game()->characterManager()->enemy()->trigger1st()) {
        Chara.wx += Chara.vx * (Chara.speed * delta);
    //}
   // else if (game()->characterManager()->enemy()->triggerCnt() == game()->characterManager()->enemy()->trigger2nd()) {
        Chara.wx += Chara.vx * (Chara.speed * delta);
        Chara.wy += Chara.vy * (Chara.speed * delta);
    //}
    //�}�b�v------------------------------------------------------------------------
    // �e���A�}�b�v�`�b�v�ɓ��������A�܂��́A�E�B���h�E�̊O�ɏo��
    if (
        Chara.wx < game()->map()->wDispLeft() ||
        Chara.wx > game()->map()->wDispRight()) {
        Chara.hp = 0;
    }
    
}
void ENEMY_BULLET::CollisionWithMap(){
    MAP* map = game()->map();
    // �}�b�v�`�b�v�ɂԂ������������ς���
    if (EnemyBullet.fallFlag==0) {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            map->collisionCharaRight(Chara.wx, Chara.wy)) {
            Chara.animId = 1 - Chara.animId;
            Chara.vx = 0;
            Chara.wx = EnemyBullet.curWx;
        }
    }
    //����
    else if (EnemyBullet.fallFlag ==1) {
        Chara.vy += EnemyBullet.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
    // �ڒn�`�F�b�N�i�L�����̉��Ƀ}�b�v�`�b�v�����邩�ǂ����j
    if (map->collisionCharaBottom(EnemyBullet.curWx, Chara.wy)) {
        //�ڒn�܂��͖��܂��Ă���
        EnemyBullet.fallFlag = 0;
        Chara.vy = 0;
        //���܂�Ȃ��悤�ɍ�����␳����
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {//�ڒn���Ă��Ȃ�
        EnemyBullet.fallFlag = 1;//���Ƃ�
    }
    // �E�B���h�E�̊O�ɏo��
    if (Chara.wx < map->wDispLeft()) {
        Chara.hp = 0;
    }
}
void ENEMY_BULLET::ChangeColor(){
    //�_���[�W���󂯂���u�Ԃ����F��ς���
    if (EnemyBullet.damageTime > 0) {
        EnemyBullet.damageTime -= delta;
        Chara.color = EnemyBullet.damageColor;
    }
    else {
        Chara.color = EnemyBullet.normalColor;
    }
}
void ENEMY_BULLET::Ddamage(){
    if (Chara.hp > 0) {
        EnemyBullet.damageTime = EnemyBullet.damageInterval;
        Chara.hp--;
        //if (Chara.hp == 0) {
        //    game()->characterManager()->appear(Pumpkin.explosionCharaId, 
        //        Chara.wx, Chara.wy);
        //}
    }
}
