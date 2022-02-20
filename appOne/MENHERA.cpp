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
    //ジャンプ
    jump();
    launch();
    if (Chara.hp > 0) {
        Chara.stamina -= Menhera.staminaDamage;
    }
    //左右移動
    // 移動ベクトルを決定

    Menhera.speed = 3.4f * 6.0f * Chara.stamina / 10;
    Chara.vx = Menhera.speed * delta;
    if (Chara.stamina <= 1) Chara.stamina = 1;
    Chara.animId = Menhera.rightAnimId;


    //  移動前に現在のChara.wxをMenhera.curWxにとっておく
    Menhera.curWx = Chara.wx;
    //  移動
    if (Chara.vx != 0.0f) {//左右キー入力あり
        //とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
        //あとで、マップに食い込んでいたら、元のMenhera.curWxに戻す
        Chara.wx += Chara.vx;
    }
    else {//左右キー入力がないとき
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void MENHERA::CollisionWithMap() {
    MAP* map = game()->map();
    // マップチップとキャラの右
    if (Chara.animId == Menhera.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //移動予定位置がマップに食い込んでいるので現在の位置に戻す
            Chara.wx = Menhera.curWx;
        }
    }
    // マップチップとキャラの左
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //または、ウィンドウの左にぶつかったか
            ) {
            Chara.wx = Menhera.curWx;
        }
    }
    // マップチップとキャラの上
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Menhera.initVecDown;//落ちていく初速度
    }
    // マップチップとキャラの下
    if (map->collisionCharaBottom(Menhera.curWx, Chara.wy)) {
        //--「マップチップに食い込んでいる」
        // または「上に立っているとき」もここを通る--
        //ジャンプ（落下）処理の停止
        Menhera.jumpFlag = 0;
        Chara.vy = 0.0f;
        //強制的に上に立っている位置にする
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Menhera.jumpFlag = 1;//落ちてくトリガー。このフラッグを立てるだけで落ちていく。
    }
}
void MENHERA::launch() {
    //弾発射----------------------------------------------------------------
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



