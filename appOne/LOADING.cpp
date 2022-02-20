#include"window.h"
#include"input.h"
#include"graphic.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"SCENE.h"
#include"FADE.h"
#include"LOADING.h"
void LOADING::create() {
	Loading = game()->container()->data().loading;
}
void LOADING::init() {
	game()->fade()->inTrigger();
}
void LOADING::draw() {
	float px = 0;
	float py = 0;
	float angle = 0;
	float scale = 1;
	Loading.anim->draw(&Loading.animData,
		px, py, angle, scale);
	game()->fade()->draw();
}
void LOADING::nextScene() {
	if (Loading.goToTitleTime <= 0) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		game()->changeScene(GAME::PROLOGUE_ID);
	}
}
void LOADING::update() {
	Loading.goToTitleTime -= delta;
}
