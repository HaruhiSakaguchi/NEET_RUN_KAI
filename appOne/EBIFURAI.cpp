#include"EBIFURAI.h"
#include"window.h"
#include"GAME.h"
#include"MAP.h"
#include"CONTAINER.h"
void EBIFURAI::create() {
	Chara = game()->container()->data().ebifuraiChara;
	Ebifurai = game()->container()->data().ebifurai;
}
void EBIFURAI::appear(float wx, float wy, float vx, float vy) {
	Chara.hp = 1;
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.vx = vx;
	Chara.vy = vy;
    Ebifurai.jumpFlag = 0;
}
void EBIFURAI::jump() {
	if (Ebifurai.jumpFlag == 0) {
		Chara.vy = Ebifurai.initVecUp;
		Ebifurai.jumpFlag = 1;
	}
	if (Ebifurai.jumpFlag == 1) {
		Chara.vy += Ebifurai.gravity * delta;
		Chara.wy += Chara.vy * 60 * delta;
	}
}
void EBIFURAI::update() {
    Ebifurai.curWx = Chara.wx;
	Chara.vx = Chara.speed * delta;
	Chara.wx += Chara.vx;
    CollisionWithMap();
	jump();
	if (Chara.wx < game()->map()->wDispLeft()) {
		Chara.hp = 0;
	} 
	
}
void EBIFURAI::CollisionWithMap() {
    MAP* map = game()->map();
    // マップチップとキャラの右
    
    if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
         //移動予定位置がマップに食い込んでいるので現在の位置に戻す
        Chara.wx = Ebifurai.curWx;
    }
    
    // マップチップとキャラの左
    
    if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
        Chara.wx < map->wx() //または、ウィンドウの左にぶつかったか
        ) {
        Chara.wx = Ebifurai.curWx;
    }
    
    // マップチップとキャラの上
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Ebifurai.initVecDown;//落ちていく初速度
    }
    // マップチップとキャラの下
    if (map->collisionCharaBottom(Ebifurai.curWx, Chara.wy)) {
        //--「マップチップに食い込んでいる」
        // または「上に立っているとき」もここを通る--
        //ジャンプ（落下）処理の停止
        Ebifurai.jumpFlag = 0;
        Chara.vy = 0.0f;
        //強制的に上に立っている位置にする
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Ebifurai.jumpFlag = 1;//落ちてくトリガー。このフラッグを立てるだけで落ちていく。
    }
}
