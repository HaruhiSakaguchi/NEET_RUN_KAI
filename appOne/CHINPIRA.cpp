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
    //ジャンプ
    jump();
    launch();
    if (Chara.hp > 0) {
        Chara.stamina -= Chinpira.staminaDamage;
    }
    //左右移動
    // 移動ベクトルを決定

    Chinpira.speed = 3.4f * 6.0f * Chara.stamina / 10;
    Chara.vx = Chinpira.speed * delta;
    if (Chara.stamina <= 1) Chara.stamina = 1;
    Chara.animId = Chinpira.rightAnimId;


    //  移動前に現在のChara.wxをChinpira.curWxにとっておく
    Chinpira.curWx = Chara.wx;
    //  移動
    if (Chara.vx != 0.0f) {//左右キー入力あり
        //とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
        //あとで、マップに食い込んでいたら、元のChinpira.curWxに戻す
        Chara.wx += Chara.vx;
    }
    else {//左右キー入力がないとき
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void CHINPIRA::CollisionWithMap() {
    MAP* map = game()->map();
    // マップチップとキャラの右
    if (Chara.animId == Chinpira.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //移動予定位置がマップに食い込んでいるので現在の位置に戻す
            Chara.wx = Chinpira.curWx;
        }
    }
    // マップチップとキャラの左
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //または、ウィンドウの左にぶつかったか
            ) {
            Chara.wx = Chinpira.curWx;
        }
    }
    // マップチップとキャラの上
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Chinpira.initVecDown;//落ちていく初速度
    }
    // マップチップとキャラの下
    if (map->collisionCharaBottom(Chinpira.curWx, Chara.wy)) {
        //--「マップチップに食い込んでいる」
        // または「上に立っているとき」もここを通る--
        //ジャンプ（落下）処理の停止
        Chinpira.jumpFlag = 0;
        Chara.vy = 0.0f;
        //強制的に上に立っている位置にする
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Chinpira.jumpFlag = 1;//落ちてくトリガー。このフラッグを立てるだけで落ちていく。
    }
}
void CHINPIRA::launch() {
    //弾発射----------------------------------------------------------------
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

