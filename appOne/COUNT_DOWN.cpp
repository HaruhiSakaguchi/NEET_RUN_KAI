#include"CONTAINER.h"
#include"GAME.h"
#include"FADE.h"
#include"input.h"
#include"graphic.h"
#include"window.h"
#include "COUNT_DOWN.h"
void COUNT_DOWN::create() {
	CD = game()->container()->data().cd;
}
void COUNT_DOWN::init() {
	CD.interval = CD.maxInterval;
	game()->characterManager()->init();
	State = STATE::FOUR;
	game()->fade()->inTrigger();
}
void COUNT_DOWN::toThree() {
	if (State == STATE::FOUR) {
		State = STATE::THREE;
	}
}
void COUNT_DOWN::toTwo() {
	if (State == STATE::THREE) {
		State = STATE::TWO;
	}
}
void COUNT_DOWN::toOne() {
	if (State == STATE::TWO) {
		State = STATE::ONE;
	}
}
void COUNT_DOWN::toZero() {
	if (State == STATE::ONE) {
		State = STATE::ZERO;
	}
}
void COUNT_DOWN::draw() {
	rectMode(CORNER);
	image(CD.image, 0, 0);
	switch (State) {
	case STATE::FOUR:
		CD.count = 3;
		CD.interval -= CD.speed * delta;
		if (CD.interval <= 0) {
			CD.interval = CD.maxInterval;
			toThree();
		}
		break;
	case STATE::THREE:
		CD.count = 3;
		CD.interval -= CD.speed * delta;
		if (CD.interval <= 0) {
			CD.interval = CD.maxInterval;
			toTwo();
		}
		break;
	case STATE::TWO:
		CD.count = 2;
		CD.interval -= CD.speed * delta;
		if (CD.interval <= 0) {
			CD.interval = CD.maxInterval;
			toOne();
		}
		break;
	case STATE::ONE:
		CD.count = 1;
		CD.interval -= CD.speed * delta;
		if (CD.interval <= 0) {
			CD.interval = CD.maxInterval - 100.0f;
			toZero();
		}
		break;

	case STATE::ZERO:
		fill(255, 162, 100);
		textSize(CD.textSize);
		text("スタート！！", width / 2 - 200, height / 2);
		CD.interval -= CD.speed * delta;
		if (CD.interval <= 0)
			break;
	}
	if (State != STATE::ZERO) {
		textSize(CD.textSize);
		fill(255, 0, 0);
		text(CD.count, width / 2, height / 2);
	}
	game()->fade()->draw();
}
void COUNT_DOWN::nextScene() {
	if (State == STATE::ZERO && CD.interval <= 0) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		game()->changeScene(GAME::STAGE_ID);
		init();
	}
}

