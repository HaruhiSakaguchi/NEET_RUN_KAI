#include"STORY.h"
#include"GAME.h"
#include"graphic.h"
#include"input.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"MESSAGE.h"
#include"BUTTON.h"
STORY::STORY(class GAME* game) :
	SCENE(game) {
}
STORY::~STORY() {

}
void STORY::init() {
	//setBgm(Story.bgm1);
	game()->fade()->inTrigger();
	setBgmFlag(1);
}
void STORY::create() {
	Story = game()->container()->data().story;
}
void STORY::draw() {
	COLOR tcolor;
	COLOR normalColor;
	COLOR collisionColor(200, 200, 200, 128);
	clear(normalColor);
	game()->button()->rectButton(Story.skipButtonPos, game()->container()->data().message.buttonColor,
		game()->container()->data().message.textColor, Story.skipText, Story.skipTextSize, Story.skipCharaNum);
	backGround();
	game()->message()->draw();

	rectMode(CENTER);
	imageColor(normalColor);
	image(Story.skipImg, Story.skipButtonPos.x, Story.skipButtonPos.y);

	rectMode(CENTER);

	if (game()->button()->game()->button()->collisionRect(Story.skipButtonPos, Story.skipButtonW, Story.skipButtonH)) {
		tcolor = collisionColor;
	}
	else {
		tcolor = normalColor;
	}

	imageColor(tcolor);
	image(Story.skipImg2, Story.skipButtonPos.x, Story.skipButtonPos.y);

	if (Story.Flag == 1) {
		if (Story.otoFlag == 1) {
			playSound(game()->container()->data().title.decision);
			setOtoFlag(0);
		}
		game()->message()->AttentionWindow(Story.text, Story.text2, Story.text3);
	}

	game()->button()->drawCursor();
	game()->fade()->draw();
}
void STORY::nextScene() {
	if (game()->curTextId() == GAME::text_Last) {
		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			if (game()->curStateId() == GAME::FIRST ||
				game()->curStateId() == GAME::SECOND ||
				game()->curStateId() == GAME::THIRD ||
				game()->curStateId() == GAME::FOURTH ||
				game()->curStateId() == GAME::FIFTH
				) {
				game()->changeScene(GAME::STAGE_ID);
				game()->message()->init();
				setBgmFlag(0);
				stopSound(Story.bgm);
				init();
			}
			else if (game()->curStateId() == GAME::END) {
				game()->changeScene(GAME::ENDING_ID);
				setBgmFlag(0);
				stopSound(Story.bgm);
				init();
			}
		}
	}


	if (Story.Flag == 0 && ((isTrigger(KEY_Z) || isTrigger(MOUSE_RBUTTON)) ||
		(game()->button()->collisionRect(Story.skipButtonPos, Story.skipButtonW, Story.skipButtonH) && isTrigger(MOUSE_LBUTTON)))) {
		setAttentinonFlag(1);
		setOtoFlag(1);
	}
	else {
		if (
			(Story.Flag == 1) &&
			(
				isTrigger(KEY_Z) ||
				(
					(
						game()->button()->collisionRect
						(
							game()->container()->data().message.noPos, game()->container()->data().message.buttonW, game()->container()->data().message.buttonH
						) && isTrigger(MOUSE_LBUTTON))
					)
				)
			)
		{
			setAttentinonFlag(0);
		}
	}

	if (Story.Flag == 1) {
		if (isTrigger(KEY_SPACE) ||
			(
				game()->button()->collisionRect
				(
					game()->container()->data().message.yesPos, game()->container()->data().message.buttonW, game()->container()->data().message.buttonH
				) && isTrigger(MOUSE_LBUTTON))
			)
		{
			setOtoFlag(1);
			game()->fade()->outTrigger();
			setAttentinonFlag(0);
		}
	}

	if (game()->fade()->outEndFlag()) {
		if (game()->curStateId() == GAME::FIRST ||
			game()->curStateId() == GAME::SECOND ||
			game()->curStateId() == GAME::THIRD ||
			game()->curStateId() == GAME::FOURTH ||
			game()->curStateId() == GAME::FIFTH
			) {
			game()->changeScene(GAME::COUNT_DOWN_ID);
			game()->message()->init();
			setBgmFlag(0);
			stopSound(Story.bgm);
			init();
		}
		else if (game()->curStateId() == GAME::END) {
			game()->changeScene(GAME::ENDING_ID);
			setBgm(Story.bgm2);
			setBgmFlag(0);
			stopSound(Story.bgm);
			init();
		}
	}
}
void STORY::setAttentinonFlag(int flag) {
	Story.Flag = flag;
}
void STORY::update() {
	if (game()->curStateId() != GAME::END) {
		setBgm(Story.bgm1);
	}
	else setBgm(Story.bgm2);
	if (Story.bgmFlag == 1) {
		playLoopSound(Story.bgm);
		setBgmFlag(0);
	}
	if (Story.Flag == 0) {
		if (game()->button()->collisionRect(Story.skipButtonPos, Story.skipButtonW, Story.skipButtonH)) {
		}
		else {
			game()->message()->nextText();
		}
	}
}
void STORY::backGround() {
	clear();
	rectMode(CORNER);
	COLOR normalColor;
	switch (game()->curSceneId()) {
	case GAME::FIRST:
	case GAME::SECOND:
		Story.backImage = Story.backImg[0];
		break;
	case GAME::THIRD:
		Story.backImage = Story.backImg[1];
		break;
	case GAME::FOURTH:
		Story.backImage = Story.backImg[2];
		break;
	case GAME::FIFTH:
		Story.backImage = Story.backImg[3];
		break;
	case GAME::END:
		Story.backImage = Story.backImg[4];
		break;
	default:
		Story.backImage = Story.backImg[0];
		break;
	}
	imageColor(normalColor);
	image(Story.backImage, 0, 0);
}


