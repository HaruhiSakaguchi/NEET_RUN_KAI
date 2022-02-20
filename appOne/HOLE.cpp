#include"GAME.h"
#include"CONTAINER.h"
#include "HOLE.h"
void HOLE::create() {
	Chara = game()->container()->data().holeChara;
}
void HOLE::appear(float wx, float wy, float vx, float vy) {
	Chara.hp = game()->container()->data().holeChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Hole.curx = Chara.wx;
}


