#include"window.h"
#include"input.h"
#include"graphic.h"
#include"GAME.h"
#include"MESSAGE.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"PROLOGUE.h"
void PROLOGUE::create() {
	Prologue = game()->container()->data().prologue;
}
void PROLOGUE::init() {
	game()->settextNum(GAME::t1);
	game()->fade()->inTrigger();
}
void PROLOGUE::draw() {
	switch (game()->curPTextId()) {
	case GAME::t1:
		Prologue.text = Prologue.iText1;
		Prologue.text2 = Prologue.iTextNormal;
		break;
	case GAME::t2:
		Prologue.text = Prologue.iText2;
		Prologue.text2 = Prologue.iTextNormal;
		break;
	case GAME::t3:
		Prologue.text = Prologue.iText3;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t4:
		Prologue.text = Prologue.iText4;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t5:
		Prologue.text = Prologue.iText5;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t6:
		Prologue.text = Prologue.iText6;
		Prologue.text2 = Prologue.iTextc;

		break;
	case GAME::t7:
		Prologue.text = Prologue.iText7;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t8:
		Prologue.text = Prologue.iText8;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t9:
		Prologue.text = Prologue.iText9;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t10:
		Prologue.text = Prologue.iText10;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t11:
		Prologue.text = Prologue.iText11;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t12:
		Prologue.text = Prologue.iText12;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t13:
		Prologue.text = Prologue.iText13;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t14:
		Prologue.text = Prologue.iText14;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t15:
		Prologue.text = Prologue.iText15;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t16:
		Prologue.text = Prologue.iText16;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t17:
		Prologue.text = Prologue.iText17;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t18:
		Prologue.text = Prologue.iText18;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t19:
		Prologue.text = Prologue.iText19;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::t20:
		Prologue.text = Prologue.iText20;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	case GAME::Plast:
		Prologue.text = Prologue.itextLast;
		Prologue.text2 = Prologue.iTextNormal;

		break;
	}
	game()->message()->RectWindow(Prologue.windowPos, Prologue.winW, Prologue.winH,
		Prologue.winColor, Prologue.edgeColor);
	textSize(Prologue.textSize);
	fill(Prologue.textColor);
	text(Prologue.text, Prologue.textPos.x+Prologue.textPosOfst.x, Prologue.textPos.y + Prologue.textPosOfst.y);
	text(Prologue.text2, Prologue.textPos.x + Prologue.textPosOfst.x, Prologue.textPos.y + Prologue.textPosOfst.y*2);
	textSize(Prologue.charaNameTextSize);
	if (game()->curPTextId() != GAME::Plast) {
		text(Prologue.charactername, Prologue.textPos.x - 30, Prologue.textPos.y + 10);
	}
	game()->fade()->draw();
}
void PROLOGUE::update() {
	//テキストが入力されていないなら、強制的にラストのテキストを表示する
	if (Prologue.text == "") {
		game()->settextNum(GAME::Plast);
	}
	//テキストのステートを次に進める
	else {
		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
			switch (game()->curPTextId()) {
			case GAME::t1:
				game()->settextNum(GAME::t2);
				break;
			case GAME::t2:
				game()->settextNum(GAME::t3);
				break;
			case GAME::t3:
				game()->settextNum(GAME::t4);
				break;
			case GAME::t4:
				game()->settextNum(GAME::t5);
				break;
			case GAME::t5:
				game()->settextNum(GAME::t6);
				break;
			case GAME::t6:
				game()->settextNum(GAME::t7);
				break;
			case GAME::t7:
				game()->settextNum(GAME::t8);
				break;
			case GAME::t8:
				game()->settextNum(GAME::t9);
				break;
			case GAME::t9:
				game()->settextNum(GAME::t10);
				break;
			case GAME::t10:
				game()->settextNum(GAME::t11);
				break;
			case GAME::t11:
				game()->settextNum(GAME::t12);
				break;
			case GAME::t12:
				game()->settextNum(GAME::t13);
				break;
			case GAME::t13:
				game()->settextNum(GAME::t14);
				break;
			case GAME::t14:
				game()->settextNum(GAME::t15);
				break;
			case GAME::t15:
				game()->settextNum(GAME::t16);
				break;
			case GAME::t16:
				game()->settextNum(GAME::t17);
				break;
			case GAME::t17:
				game()->settextNum(GAME::t18);
				break;
			case GAME::t18:
				game()->settextNum(GAME::t19);
				break;
			case GAME::t19:
				game()->settextNum(GAME::t20);
				break;
			case GAME::t20:
				game()->settextNum(GAME::Plast);
				break;
			}
		}
	}
}
void PROLOGUE::nextScene() {
	if (game()->curPTextId() == GAME::Plast) {
		game()->fade()->outTrigger();
	}
	if(game()->fade()->outEndFlag()) {
		game()->changeScene(GAME::TITLE_ID);
	}
	
}
