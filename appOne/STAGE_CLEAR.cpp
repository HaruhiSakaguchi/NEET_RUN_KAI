#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"BUTTON.h"
#include "STAGE_CLEAR.h"
STAGE_CLEAR::STAGE_CLEAR(class GAME* game) :
	SCENE(game) {
}
STAGE_CLEAR::~STAGE_CLEAR() {

}
void STAGE_CLEAR::create() {
	StageClear = game()->container()->data().stageClear;
}
void STAGE_CLEAR::init() {
	game()->fade()->inTrigger();
	setBgmFlag(1);
	playSound(StageClear.bgm);
}
void STAGE_CLEAR::draw() {
	clear(StageClear.backColor);
	rectMode(CORNER);
	game()->button()->rectButton(StageClear.backToTitlePos, game()->container()->data().message.buttonColor, game()->container()->data().message.textColor, StageClear.backToTitleText, StageClear.buttonNameTextSize, StageClear.charaNum);
	game()->button()->rectButton(StageClear.nextPos, game()->container()->data().message.buttonColor, game()->container()->data().message.textColor, StageClear.nextText, StageClear.buttonNameTextSize, StageClear.charaNum);

	COLOR ncolor;
	COLOR tcolor;
	COLOR normalColor;
	COLOR collisionColor(200, 200, 200, 128);
	rectMode(CORNER);
	imageColor(normalColor);
	if (game()->curStateId() != GAME::FOURTH)
		image(StageClear.img, 0, 0);
	else image(game()->container()->data().gameOver.img, 0, 0);
	
	if (game()->curStateId() != GAME::FOURTH) {
		rectMode(CENTER);

		if (game()->button()->game()->button()->collisionRect(StageClear.backToTitlePos, StageClear.buttonW, StageClear.buttonH)) {
			tcolor = collisionColor;
		}
		else {
			tcolor = normalColor;
		}
		imageColor(normalColor);

		image(StageClear.gotoTitleButtonImg, StageClear.backToTitlePos.x, StageClear.backToTitlePos.y);

		imageColor(tcolor);
		image(StageClear.gotoTitleButtonImg2, StageClear.backToTitlePos.x, StageClear.backToTitlePos.y);



		if (game()->button()->game()->button()->collisionRect(StageClear.nextPos, StageClear.buttonW, StageClear.buttonH)) {
			ncolor = collisionColor;
		}
		else {
			ncolor = normalColor;
		}
		imageColor(normalColor);

		image(StageClear.nextButtonImg, StageClear.nextPos.x, StageClear.nextPos.y);

		imageColor(ncolor);
		image(StageClear.nextButtonImg2, StageClear.nextPos.x, StageClear.nextPos.y);

	}


	game()->button()->drawCursor();
	game()->fade()->draw();
}
void STAGE_CLEAR::update() {
	if (StageClear.bgmFlag == 1) {
		if (game()->curStateId() != GAME::FOURTH) {
			playSound(StageClear.bgm);
		}
		else {
			playSound(game()->container()->data().gameOver.bgm);
		}
		setBgmFlag(0);
	}
}
void STAGE_CLEAR::nextScene() {
	if (game()->curStateId() != GAME::FOURTH) {
		if (StageClear.goFlag == 0) {
			if (isTrigger(KEY_SPACE) || (isTrigger(MOUSE_LBUTTON) && game()->button()->collisionRect(StageClear.nextPos, StageClear.buttonW, StageClear.buttonH))) {
				setGoFlag(1);
			}
		}
	}
	else if (game()->curStateId() == GAME::FOURTH) {
		if (StageClear.goFlag == 0) {
			if (isTrigger(KEY_SPACE)||isTrigger(MOUSE_LBUTTON)) {
				setGoFlag(1);
			}
		}
	}
	if(StageClear.returnFlag==0){
		if (isTrigger(KEY_Z)||(game()->button()->collisionRect(StageClear.backToTitlePos, StageClear.buttonW, StageClear.buttonH)&&isTrigger(MOUSE_LBUTTON))) {
			setReturnFlag(1);
		}
	}
	if (StageClear.goFlag == 1|| StageClear.returnFlag == 1) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		if (StageClear.goFlag == 1) {
			switch (game()->curStateId()) {
			case GAME::FIRST:
				game()->changeState(GAME::SECOND);
				break;
			case GAME::SECOND:
				game()->changeState(GAME::THIRD);
				break;
			case GAME::THIRD:
				game()->changeState(GAME::FOURTH);
				break;
			case GAME::FOURTH:
				game()->changeState(GAME::FIFTH);
				break;
			case GAME::FIFTH:
				game()->changeState(GAME::END);
				break;
			}

			game()->changeScene(GAME::STORY_ID);
			setGoFlag(0);
			init();
		}
		else if (StageClear.returnFlag == 1) {
		 game()->changeScene(GAME::TITLE_ID);
		 setReturnFlag(0);
		 setBgmFlag(0);
		 init();
		}
	
	}
}
void STAGE_CLEAR::setGoFlag(int flag) {
	StageClear.goFlag = flag;
}
void STAGE_CLEAR::setReturnFlag(int flag) {
	StageClear.returnFlag = flag;
}
