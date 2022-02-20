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
	game()->characterManager()->init();
	game()->fade()->inTrigger();
	Stage.count = Stage.maxCount;
}
void STAGE::update() {
	Stage.flag = 0;
	//if (Stage.count != 0) {
	//	countDown();
	//}
	
	game()->characterManager()->update();
	game()->map()->update();

	//if (Stage.flag == 0 && isTrigger(MOUSE_RBUTTON)) {
	//	Stage.flag = 1;
	//}
	//if (Stage.flag == 1) {
	//	stagePause();
	//	if (isTrigger(MOUSE_RBUTTON)) { Stage.flag = 0; }
	//}
	//textSize(Stage.textSize);
	//text(Stage.flag, Stage.pos.x + Stage.textSize * 4, Stage.pos.y);
	

}
void STAGE::draw() {
	backGround();
	game()->map()->draw();
	fill(Stage.textColor);
	textSize(Stage.textSize);
	text(Stage.str, Stage.pos.x, Stage.pos.y);
	text(game()->characterManager()->player()->PlayerSta(), 100, 100);
	text(game()->characterManager()->player()->interval(), 100, 150);


	

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

	text(delta,700,100);


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
	}
		
	
	if (game()->curStateId() == GAME::END) {
		game()->changeScene(GAME::STORY_ID);
	}
}