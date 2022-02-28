#pragma once
#include"LOADING.h"
#include"PROLOGUE.h"
#include"TITLE.h"
#include"STORY.h"
#include"STAGE.h"
#include"STAGE_CLEAR.h"
#include"GAME_OVER.h"
#include"ENDING.h"
#include"COUNT_DOWN.h"
#include"MAP.h"
#include"FADE.h"
#include"HP_GAUGE.h"
#include"MESSAGE.h"
#include"BUTTON.h"
#include"PLAYER.h"
#include"PLAYER_BULLET.h"
#include"ENEMY_BULLET.h"
#include"CAT.h"
#include"HOLE.h"
#include"ENEMY.h"
#include"ONISAN.h"
#include"MENHERA.h"
#include"CHINPIRA.h"
#include"BEAR.h"
#include"EBIFURAI.h"
#include"RYMAN.h"
#include"CHARACTER_MANAGER.h"
class CONTAINER
{
private:
	struct ALL_DATA {
		//シーン
		LOADING::DATA loading;
		PROLOGUE::DATA prologue;
		TITLE::DATA title;
		STORY::DATA story;
		STAGE::DATA stage;
		STAGE_CLEAR::DATA stageClear;
		GAME_OVER::DATA gameOver;
		ENDING::DATA ending;
		COUNT_DOWN::DATA cd;

		FADE::DATA fade;
		MAP::DATA map;
		HP_GAUGE::DATA hpGauge;
		MESSAGE::DATA message;
		BUTTON::DATA button;
		//キャラクターの実体
		PLAYER::DATA player;
		PLAYER_BULLET::DATA playerBullet;
		ENEMY::DATA enemy;
		ONISAN::DATA onisan;
		MENHERA::DATA menhera;
		CHINPIRA::DATA chinpira;
		EBIFURAI::DATA ebifurai;
		ENEMY_BULLET::DATA enemyBullet;
		CAT::DATA cat;
		HOLE::DATA hole;
		//キャラクタークラス用
		CHARACTER::DATA playerChara;
		CHARACTER::DATA playerBulletChara;
		CHARACTER::DATA enemyChara;
		CHARACTER::DATA onisanChara;
		CHARACTER::DATA menheraChara;
		CHARACTER::DATA chinpiraChara;
		CHARACTER::DATA pumpkinChara;
		CHARACTER::DATA enemyBulletChara;
		CHARACTER::DATA catChara;
		CHARACTER::DATA batBulletChara;
		CHARACTER::DATA holeChara;


		CHARACTER::DATA cokeChara;
		CHARACTER::DATA tipsChara;
		CHARACTER::DATA ramenChara;
		CHARACTER::DATA bearChara;
		CHARACTER::DATA ebifuraiChara;
		CHARACTER::DATA rymanChara;
		//キャラクターマネージャー
		CHARACTER_MANAGER::DATA charaMng;

	};
	ALL_DATA Data;
	void CreateData();
	void LoadGraphics();
public:
	~CONTAINER();
	void load();
	const ALL_DATA& data() { return Data; }
};


