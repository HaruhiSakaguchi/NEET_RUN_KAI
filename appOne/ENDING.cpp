#include "ENDING.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include "TITLE.h"
ENDING::ENDING(class GAME* game) :
	SCENE(game) {

}
ENDING::~ENDING() {

}
void ENDING::create() {
	Ending = game()->container()->data().ending;
}
void ENDING::init() {
	curImageNum = ImageNum::E1;
	game()->fade()->inTrigger();
	game()->changeState(GAME::FIRST);
}
void ENDING::toE2() {
	if (curImageNum == ImageNum::E1) {
		curImageNum = ImageNum::E2;
	}
}
void ENDING::toE3() {
	if (curImageNum == ImageNum::E2) {
		curImageNum = ImageNum::E3;
	}
}
void ENDING::toE4() {
	if (curImageNum == ImageNum::E3) {
		curImageNum = ImageNum::E4;
	}
}
void ENDING::toE5() {
	if (curImageNum == ImageNum::E4) {
		curImageNum = ImageNum::E5;
	}
}
void ENDING::draw() {
	clear(Ending.backColor);
	image(Ending.backImg, 0, 0);
	game()->fade()->draw();
}
void ENDING::nextScene() {
	if (curImageNum == E5) {
		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::TITLE_ID);
			game()->changeState(GAME::FIRST);
			game()->changeText(GAME::text_1);
		}
	}
}
void ENDING::update() {
	Ending.interval -= Ending.speed * delta;
	switch (curImageNum) {
	case E1:
		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON) || Ending.interval <= 0) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			toE2();
		}
		game()->fade()->inTrigger();
		setInterval(Ending.maxInterval);
		break;
	case E2:


		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON) || Ending.interval <= 0) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			toE3();
		}
		game()->fade()->inTrigger();
		setInterval(Ending.maxInterval);

		break;
	case E3:


		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON) || Ending.interval <= 0) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {

			toE4();

		}
		game()->fade()->inTrigger();
		setInterval(Ending.maxInterval);
		break;
	case E4:


		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON) || Ending.interval <= 0) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			toE5();

		}
		game()->fade()->inTrigger();
		setInterval(Ending.maxInterval);
		break;
	default:
		break;
	}

	setImage();
}
void ENDING::setImage() {
	switch (curImageNum) {
	case E1:
		Ending.backImg = Ending.img[0];
		break;
	case E2:
		Ending.backImg = Ending.img[1];
		break;
	case E3:
		Ending.backImg = Ending.img[2];
		break;
	case E4:
		Ending.backImg = Ending.img[3];
		break;
	case E5:
		Ending.backImg = Ending.img[4];
		break;
	default:
		Ending.backImg = Ending.img[4];
		break;
	}
}
