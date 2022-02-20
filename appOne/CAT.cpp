#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "CAT.h"
void CAT::create() {
    Chara = game()->container()->data().catChara;
}
void CAT::appear(float wx, float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().catChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
}
void CAT::update() {
    Chara.vx = Chara.speed * delta;
    Chara.wx += Chara.vx;
    // ウィンドウの外に出た
    if (Chara.wx < game()->map()->wDispLeft()) {
        Chara.hp = 0;
    }
}
