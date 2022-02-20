#pragma once
#include"input.h"
class GAME
{
private:
	class CONTAINER* Container = 0;
public:
	class CONTAINER* container() { return Container; }
public:
	enum SCENE_ID {
		LOADING_ID,
		PROLOGUE_ID,
		TITLE_ID,
		STORY_ID,
		COUNT_DOWN_ID,
		STAGE_ID,
		STAGE_CLEAR_ID,
		GAME_OVER_ID,
		ENDING_ID,
		NUM_SCENES
	};
	enum STATE_ID {
		FIRST,
		SECOND,
		THIRD,
		FOURTH,
		FIFTH,
		END,
		NUM_STATES
	};
	enum TEXT_ID {
		text_1,
		text_2,
		text_3,
		text_4,
		text_5,
		text_6,
		text_7,
		text_8,
		text_9,
		text_10,
		text_11,
		text_12,
		text_13,
		text_14,
		text_15,
		text_16,
		text_17,
		text_18,
		text_19,
		text_20,
		text_Last,
		NUM_TEXTS
	};
	enum PTEXT_ID {
		t1,
		t2,
		t3,
		t4,
		t5,
		t6,
		t7,
		t8,
		t9,
		t10,
		t11,
		t12,
		t13,
		t14,
		t15,
		t16,
		t17,
		t18,
		t19,
		t20,
		Plast,
		textNum
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId = LOADING_ID;

	class SCENE* CurScene = nullptr;
	class FADE* Fade = nullptr;
	class MESSAGE* Message;
	class HP_GAUGE* HpGauge;
	class BUTTON* Button;
	class MAP* Map = nullptr;
	class LOADING* Loading = nullptr;
	class PROLOGUE* Prologue = nullptr;
	STATE_ID CurStateId = FIRST;
	TEXT_ID CurTextId = text_1;
	PTEXT_ID CurPTextId = t1;
	class CHARACTER_MANAGER* CharacterManager = nullptr;
public:
	class MAP* map() { return Map; }
	class FADE* fade() { return Fade; }
	class CHARACTER_MANAGER* characterManager() { return CharacterManager; }
	class HP_GAUGE* hpGauge() { return HpGauge; }
	class MESSAGE* message() { return Message; }
	class BUTTON* button() { return Button; }
	class LOADING* loading() { return Loading; }
	class PROLOGUE* prologue() { return Prologue; }
public:
	void changeScene(SCENE_ID sceneId);
	void changeState(STATE_ID stateId);
	void changeText(TEXT_ID textId);
	void settextNum(PTEXT_ID textNum);
	SCENE_ID curSceneId() { return CurSceneId; }
	STATE_ID curStateId() { return CurStateId; }
	TEXT_ID curTextId() { return CurTextId; }
	PTEXT_ID curPTextId() { return CurPTextId; }
	

//ゲームマネージャー
public:
	GAME();
	~GAME();
	void run();
};

