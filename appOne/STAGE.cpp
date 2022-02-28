#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"HP_GAUGE.h"
#include"MAP.h"
#include"CHARACTER_MANAGER.h"
#include"PLAYER.h"
#include"ENEMY.h"
#include<Windows.h>
#include"STAGE.h"
void STAGE::create() {
	Stage = game()->container()->data().stage;
}
void STAGE::init() {
	game()->map()->init();
	setBgmFlag(1);
	game()->characterManager()->init();
	game()->fade()->inTrigger();
}
void STAGE::update() {
	if (game()->curStateId() != GAME::FIFTH) {
		setBgm(Stage.bgm1);
	}
	else {
		setBgm(Stage.bgm2);
	}
	game()->characterManager()->update();
	game()->map()->update();
	sound();
}
void STAGE::draw() {
	backGround();
	game()->map()->draw();
	fill(Stage.textColor);
	textSize(Stage.textSize);
	text(Stage.str, Stage.pos.x, Stage.pos.y);
#ifdef _DEBUG
	int stageNum = 0;
	if (game()->curStateId() == GAME::FIRST) {
		stageNum = 1;
	}
	else if (game()->curStateId() == GAME::SECOND) {
		stageNum = 2;
	}
	else if (game()->curStateId() == GAME::THIRD) stageNum = 3;
	else if (game()->curStateId() == GAME::FOURTH)stageNum = 4;
	else if (game()->curStateId() == GAME::FIFTH)stageNum = 5;

	fill(Stage.textColor);
	textSize(Stage.textSize);
	text(stageNum, Stage.pos.x + Stage.textSize*3, Stage.pos.y);
#endif
	game()->hpGauge()->draw();
	game()->characterManager()->draw();
	game()->fade()->draw();
}
void STAGE::backGround() {
	clear();
	rectMode(CORNER);
	imageColor(Stage.backColor);
	
	image(Stage.backImg, 0, 0);

}
void STAGE::logo(int img, const COLOR& color) {

}
void STAGE::nextScene() {
	if (game()->characterManager()->player()->survived()) {
		game()->fade()->outTrigger();
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::STAGE_CLEAR_ID);
			setBgmFlag(0);
			stopSound(Stage.bgm);
			init();
		}
	}
	if (game()->characterManager()->player()->died() || game()->characterManager()->enemy()->survived()) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		if (game()->curStateId()== GAME::FOURTH ) {
			if (game()->characterManager()->player()->died()||game()->characterManager()->enemy()->survived()){
				game()->changeScene(GAME::STAGE_CLEAR_ID);
			}
		}
		else if (game()->curStateId() == GAME::FIFTH) {
			if (game()->characterManager()->player()->died()) {
				game()->changeScene(GAME::STAGE_CLEAR_ID);
			}
			else if (game()->characterManager()->enemy()->survived()) {
				game()->changeScene(GAME::GAME_OVER_ID);
			}
		}
		else game()->changeScene(GAME::GAME_OVER_ID);
		setBgmFlag(0);
		stopSound(Stage.bgm);
		init();
	}
		
	
	if (game()->curStateId() == GAME::END) {
		game()->changeScene(GAME::STORY_ID);
		stopSound(Stage.bgm);
		setBgmFlag(0);
		init();
	}
}
void STAGE::sound() {
	if (game()->characterManager()->player()->PjumpFlag() == 1) {
		playSound(Stage.jump);
		game()->characterManager()->player()->setVjumpFlag(0);
	}
	if (game()->characterManager()->player()->PrecoverFlag() == 1) {
		playSound(Stage.recover);
		game()->characterManager()->player()->setPRecoverFlag(0);
	}
	if (game()->characterManager()->player()->PdamageFlag() == 1) {
		playSound(Stage.damage);
		game()->characterManager()->player()->setPDamageFlag(0);
	}
	if (game()->characterManager()->player()->PdeathFlag() == 1) {
		playSound(Stage.dead);
		game()->characterManager()->player()->setDeathFlag(0);
	}
	if (game()->characterManager()->player()->PknockFlag() == 1) {
		playSound(Stage.knock);
		game()->characterManager()->player()->setKnockFlag(0);
	}
	if (game()->characterManager()->enemy()->EjumpFlag() == 1) {
		playSound(Stage.jump);
		game()->characterManager()->enemy()->setVJumpFlag(0);
	}
	if (game()->characterManager()->enemy()->ErecoverFlag() == 1) {
		playSound(Stage.recover);
		game()->characterManager()->enemy()->setERecoverFlag(0);
	}
	if (game()->characterManager()->enemy()->EdamageFlag() == 1) {
		playSound(Stage.damage);
		game()->characterManager()->enemy()->setEDamageFlag(0);
	}
	if (Stage.bgmFlag == 1) {
			playLoopSound(Stage.bgm);
			setBgmFlag(0);
	}
	
}