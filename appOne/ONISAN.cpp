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
    //ジャンプ
    jump();
    launch();
    if (Chara.hp > 0) {
        Chara.stamina -= Onisan.staminaDamage;
    }
    //左右移動
    // 移動ベクトルを決定

    Onisan.speed = 3.4f * 6.0f * Chara.stamina / 10;
    Chara.vx = Onisan.speed * delta;
    if (Chara.stamina <= 1) Chara.stamina = 1;
    Chara.animId = Onisan.rightAnimId;


    //  移動前に現在のChara.wxをOnisan.curWxにとっておく
    Onisan.curWx = Chara.wx;
    //  移動
    if (Chara.vx != 0.0f) {//左右キー入力あり
        //とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
        //あとで、マップに食い込んでいたら、元のOnisan.curWxに戻す
        Chara.wx += Chara.vx;
    }
    else {//左右キー入力がないとき
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void ONISAN::CollisionWithMap() {
    MAP* map = game()->map();
    // マップチップとキャラの右
    if (Chara.animId == Onisan.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //移動予定位置がマップに食い込んでいるので現在の位置に戻す
            Chara.wx = Onisan.curWx;
        }
    }
    // マップチップとキャラの左
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //または、ウィンドウの左にぶつかったか
            ) {
            Chara.wx = Onisan.curWx;
        }
    }
    // マップチップとキャラの上
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Onisan.initVecDown;//落ちていく初速度
    }
    // マップチップとキャラの下
    if (map->collisionCharaBottom(Onisan.curWx, Chara.wy)) {
        //--「マップチップに食い込んでいる」
        // または「上に立っているとき」もここを通る--
        //ジャンプ（落下）処理の停止
        Onisan.jumpFlag = 0;
        Chara.vy = 0.0f;
        //強制的に上に立っている位置にする
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Onisan.jumpFlag = 1;//落ちてくトリガー。このフラッグを立てるだけで落ちていく。
    }
}
void ONISAN::launch() {
    //弾発射----------------------------------------------------------------
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




