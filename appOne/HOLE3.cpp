#include"GAME.h"
#include"CONTAINER.h"
#include "HOLE3.h"
void HOLE3::create() {
	Chara = game()->container()->data().holeChara;
}
void HOLE3::appear(float wx, float wy, float vx, float vy) {
	Chara.hp = game()->container()->data().hole3Chara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Hole3.curx = Chara.wx;
}


