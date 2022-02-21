#include"GAME.h"
#include"CONTAINER.h"
#include "HOLE2.h"
void HOLE2::create() {
	Chara = game()->container()->data().hole2Chara;
}
void HOLE2::appear(float wx, float wy, float vx, float vy) {
	Chara.hp = game()->container()->data().hole2Chara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Hole2.curx = Chara.wx;
}


