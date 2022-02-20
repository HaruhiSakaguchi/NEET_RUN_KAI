#include"RYMAN.h"
#include"window.h"
#include"GAME.h"
#include"CONTAINER.h"
void RYMAN::create() {
	Chara = game()->container()->data().rymanChara;
}
void RYMAN::appear(float wx, float wy, float vx, float vy) {
	Chara.hp = 1;
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.vx = vx;
}
void RYMAN::update() {
	Chara.vx = Chara.speed * delta;
	Chara.wx += Chara.vx;
	if (Chara.wx < game()->map()->wDispLeft()) {
		Chara.hp = 0;
	}
}
