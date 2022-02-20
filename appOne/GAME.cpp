#include"framework.h"
#include"graphic.h"
#include"window.h"
#include"CONTAINER.h"
#include"LOADING.h"
#include"PROLOGUE.h"
#include"TITLE.h"
#include"STORY.h"

#include"STAGE.h"
#include"STAGE_CLEAR.h"
#include"GAME_OVER.h"
#include"ENDING.h"
#include"COUNT_DOWN.h"
#include"FADE.h"
#include"MAP.h"
#include"MESSAGE.h"
#include"HP_GAUGE.h"
#include"BUTTON.h"
#include"CHARACTER_MANAGER.h"

#include"GAME.h"
GAME::GAME() {
	//コンテナ
	Container = new CONTAINER();
	//シーケンス
	Scenes[LOADING_ID] = new LOADING(this);
	Scenes[PROLOGUE_ID] = new PROLOGUE(this);
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STORY_ID] = new STORY(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[STAGE_CLEAR_ID] = new STAGE_CLEAR(this);
	Scenes[GAME_OVER_ID] = new GAME_OVER(this);
	Scenes[ENDING_ID] = new ENDING(this);
	Scenes[COUNT_DOWN_ID] = new COUNT_DOWN(this);
	HpGauge = new HP_GAUGE(this);
	Message = new MESSAGE(this);
	Button = new BUTTON(this);
	Fade = new FADE(this);
	Map = new MAP(this);
	CharacterManager = new CHARACTER_MANAGER(this);
}
GAME::~GAME() {
	delete CharacterManager;

	delete Map;
	delete Fade;
	delete HpGauge;
	delete Message;
	delete Button;
	delete Loading;

	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
	delete Container;
}
void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
	CurScene->init();
}
void GAME::changeState(STATE_ID stateId) {
	CurStateId = stateId;
}
void GAME::changeText(TEXT_ID textId) {
	CurTextId = textId;
}
void GAME::settextNum(PTEXT_ID textId) {
	CurPTextId = textId;
}
void GAME::run() {
	window(1050, 590, full);
	hideCursor();

	Container->load();

	for (int i = 0; i < NUM_SCENES; i++) {
		Scenes[i]->create();
		CurScene = Scenes[i];
	}


	Fade->create();
	Map->create();
	HpGauge->create();
	Message->create();
	Button->create();
	CharacterManager->create();

	CurScene = Scenes[5];
	CurScene->init();
	initDeltaTime();
	while (notQuit) {
		setDeltaTime();
		Scenes[CurSceneId]->proc();
	}
}
