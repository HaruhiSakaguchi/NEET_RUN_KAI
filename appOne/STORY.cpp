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
	game()->fade()->inTrigger();
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




#ifdef _DEBUG
	/*int i = 0;
	if (game()->curStateId() == GAME::FIRST) {
		i = 1;
	}
	else if (game()->curStateId() == GAME::SECOND) {
		i = 2;
	}
	else if (game()->curStateId() == GAME::THIRD) i = 3;
	else if (game()->curStateId() == GAME::FOURTH)i = 4;
	else if (game()->curStateId() == GAME::FIFTH)i = 5;
	else if (game()->curStateId() == GAME::END)i = 6;
	fill(Story.textColor);
	textSize(Story.textSize);
	text(i, 750, 400);
	fill(255, 255, 255);
	textSize(30);
	text("SPACEで進行 テキストを表示し終えたらステージへ　Zキーでスキップ", 30, 30);*/
#endif

	//stroke(Story.backColor);
	//textSize(Story.textSize);
	//fill(Story.textColor);
	//text(Story.str, Story.pos.x, Story.pos.y);


	if (Story.Flag == 1) {
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
			}
			else if (game()->curStateId() == GAME::END)
				game()->changeScene(GAME::ENDING_ID);
		}
	}


	if (Story.Flag == 0 && ((isTrigger(KEY_Z) || isTrigger(MOUSE_RBUTTON)) ||
		(game()->button()->collisionRect(Story.skipButtonPos, Story.skipButtonW, Story.skipButtonH) && isTrigger(MOUSE_LBUTTON)))) {
		setAttentinonFlag(1);
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
		}
		else if (game()->curStateId() == GAME::END)
			game()->changeScene(GAME::ENDING_ID);
	}
}
void STORY::setAttentinonFlag(int flag) {
	Story.Flag = flag;
}
void STORY::update() {
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


