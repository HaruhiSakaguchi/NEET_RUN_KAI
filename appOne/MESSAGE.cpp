#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"STORY.h"
MESSAGE::MESSAGE(class GAME* game) :
	GAME_OBJECT(game) {}
MESSAGE::~MESSAGE() {
}
void MESSAGE::create() {
	Message = game()->container()->data().message;
}
void MESSAGE::draw() {

	switch (game()->curTextId()) {
		//テキストとステートのIdに応じたテキスト表示する
	case GAME::text_1:
		if (game()->curStateId() == 0) {
			Message.text = Message.text1_1;
			Message.text2 = Message.space;
			setCharaName(Message.space);
			setChara1Image(0);
			setChara2Image(0);
		}
		if (game()->curStateId() == 1) {
			Message.text = Message.text2_1;
			Message.text2 = Message.space;
			setCharaName(Message.space);
			setChara1Image(0);
			setChara2Image(0);
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_1;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetDlImg);
			setChara2Image(0);
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_1;
			Message.text2 = Message.space;
			setChara1Image(Message.neetPnImg);
			setChara2Image(0);
		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_1;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetDlImg);
			setChara2Image(0);
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_1;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetPnImg);
			setChara2Image(0);
		}
		break;
	case GAME::text_2:
		if (game()->curStateId() == 0) {
			Message.text = Message.text1_2;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_2;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetPnImg);
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_2;
			Message.text2 = Message.space;
			setCharaName(Message.space);
			setChara2Image(Message.menheraDefImg);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_2;
			Message.text2 = Message.space;
			setCharaName("？");
		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_2;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_2;
			Message.text2 = Message.space;
			setCharaName("店員");


		}
		break;
	case GAME::text_3:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_3;
			Message.text2 = Message.space;
			setCharaName(Message.okan);
			setChara1Image(Message.neetHpImg);
			setChara2Image(Message.okanHpImg);
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_3;
			Message.text2 = Message.space;
			setCharaName("上司");
			setChara1Image(Message.neetSpImg);
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_3;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_3;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetAngImg);

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_3;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_3;
			Message.text2 = Message.space;
			setCharaName(Message.okan);
			setChara2Image(Message.okanHpImg);

		}
		break;
	case GAME::text_4:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_4;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_4;
			Message.text2 = Message.space;
			setCharaName(Message.onisan);
			setChara2Image(Message.onisanDlImg);
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_4;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_4;
			Message.text2 = Message.space;
			setCharaName(Message.space);
			setChara2Image(Message.chinpiraDefImg);

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_4;
			Message.text2 = Message.space;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_4;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetSpImg);
		}
		break;
	case GAME::text_5:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_5;
			Message.text2 = Message.space;
			setCharaName(Message.neet);

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_5;
			Message.text2 = Message.space;
			setCharaName("上司");

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_5;
			Message.text2 = Message.space;
			setCharaName(Message.menhera);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_5;
			Message.text2 = Message.space;
			setCharaName(Message.chinpira);
			setChara1Image(Message.neetPnImg);
			setChara2Image(Message.chinpiraDlImg);
		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_5;
			Message.text2 = Message.space;
			setCharaName(Message.okan);
			setChara2Image(Message.okanDefImg);


		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_5;
			Message.text2 = Message.space;
			setCharaName(Message.okan);
		}
		break;
	case GAME::text_6:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_6;
			Message.text2 = Message.space;
			setCharaName(Message.okan);
			setChara1Image(Message.neetDefImg);

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_6;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetDlImg);
			setChara2Image(Message.onisanSpImg);
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_6;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetDefImg);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_6;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_6;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_6;
			Message.text2 = Message.space;
			setCharaName(Message.neet);

		}
		break;
	case GAME::text_7:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_7;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara2Image(Message.okanDefImg);

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_7;
			Message.text2 = Message.space;
			setChara2Image(Message.onisanHpImg);

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_7;
			Message.text2 = Message.text3_7_2;
			setCharaName(Message.menhera);
			setChara2Image(Message.menheraDlImg);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_7;
			Message.text2 = Message.space;
			setCharaName(Message.neet);


		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_7;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetSpImg);

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_7;
			Message.text2 = Message.space;
			setCharaName(Message.okan);
			setChara2Image(Message.okanDefImg);

		}
		break;
	case GAME::text_8:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_8;
			Message.text2 = Message.space;
			setCharaName(Message.okan);

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_8;
			Message.text2 = Message.space;
			setChara1Image(Message.neetPnImg);
			setChara2Image(Message.onisanDefImg);

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_8;
			Message.text2 = Message.space;
			setChara2Image(Message.menheraAngImg);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_8;
			Message.text2 = Message.space;
			setCharaName(Message.chinpira);
			setChara2Image(Message.chinpiraSpImg);

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_8;
			Message.text2 = Message.space;
			setCharaName(Message.okan);
			setChara2Image(Message.okanAngImg);
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_8;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_9:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_9;
			Message.text2 = Message.space;
			setCharaName(Message.okan);
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_9;
			Message.text2 = Message.space;
			setCharaName(Message.onisan);
			setChara2Image(Message.onisanAngImg);

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_9;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetSpImg);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_9;
			Message.text2 = Message.space;
			setCharaName(Message.neet);


		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_9;
			Message.text2 = Message.space;
			setChara2Image(Message.okanDefImg);
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_9;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetHpImg);
		}
		break;
	case GAME::text_10:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_10;
			Message.text2 = Message.space;
			setCharaName(Message.neet);

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_10;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_10;
			Message.text2 = Message.space;
			setCharaName(Message.menhera);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_10;
			Message.text2 = Message.space;
			setCharaName(Message.chinpira);
			setChara2Image(Message.chinpiraAngImg);
		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_10;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_10;
			Message.text2 = Message.space;
			setCharaName(Message.okan);
			setChara2Image(Message.okanAngImg);

		}
		break;
	case GAME::text_11:
		if (game()->curStateId() == 0) {
			Message.text = Message.text1_11;
			setCharaName(Message.okan);
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == 1) {
			Message.text = Message.text2_11;
			Message.text2 = Message.space;
			setCharaName(Message.neet);

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_11;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
			setChara1Image(Message.neetPnImg);
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_11;
			Message.text2 = Message.space;
			setCharaName(Message.space);
		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_11;
			Message.text2 = Message.space;
			setCharaName(Message.neet);
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_11;
			Message.text2 = Message.space;
			setCharaName(Message.space);
		}
		break;
	case GAME::text_12:
		if (game()->curStateId() == 0) {
			Message.text = Message.text1_12;
			Message.text2 = Message.space;
			setChara1Image(Message.neetSpImg);
			setChara2Image(Message.okanAngImg);
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_12;
			Message.text2 = Message.space;
			setCharaName(Message.space);

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_12;
			Message.text2 = Message.space;
			setCharaName(Message.menhera);
			setChara2Image(Message.menheraHpImg);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_12;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_12;
			Message.text2 = Message.space;
			setCharaName(Message.space);

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_12;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_13:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_13;
			Message.text2 = Message.space;
			setCharaName(Message.space);

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_13;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_13;
			Message.text2 = Message.space;
			setCharaName(Message.space);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_13;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_13;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_13;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_14:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_14;
			Message.charactername = Message.neet;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_14;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_14;
			Message.text2 = Message.space;
			setCharaName(Message.space);

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_14;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_14;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_14;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_15:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_15;
			Message.charactername = Message.okan;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_15;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_15;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_15;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_15;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_15;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_16:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_16;
			Message.charactername = Message.neet;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_16;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_16;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_16;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_16;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_16;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_17:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_17;
			Message.charactername = Message.okan;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_17;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_17;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_17;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_17;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_17;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_18:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_18;
			Message.charactername = Message.okan;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_18;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_18;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_18;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_18;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_18;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_19:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_19;
			Message.charactername = Message.space;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_19;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_19;

			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_19;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_19;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_19;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_20:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_20;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_20;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_20;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_20;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::FIFTH) {
			Message.text = Message.text5_20;
			Message.text2 = Message.space;

		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.textLast_20;
			Message.text2 = Message.space;

		}
		break;
	case GAME::text_Last:
		Message.text = Message.text_Last;
		Message.text2 = Message.space;
		setCharaName(Message.space);
		break;
	}
	disPlayCharaImg();

	RectWindow
	(
		Message.windowPos, Message.winW, Message.winH,
		Message.winColor, Message.edgeColor
	);
	fill(Message.textColor);
	textSize(Message.textSize);
	float i = 0.0f;
	if (Message.charactername == "" || game()->curTextId() == GAME::text_Last) {
		i = 0;
	}
	else i = Message.textPosOfst.y;
	text(Message.text, Message.textPos.x + Message.textPosOfst.x, Message.textPos.y + i);
	text(Message.text2, Message.textPos.x + Message.textPosOfst.x, Message.textPos.y + i * 2);
	textSize(Message.charaNameTextSize);
	if (game()->curTextId() != GAME::text_Last) {
		text(Message.charactername, Message.textPos.x - 30, Message.textPos.y + 10);
	}

}
void MESSAGE::RectWindow
(
	const VECTOR2& winPos,
	float winW, float winH,
	COLOR& winColor, COLOR& edgeColor)
{
	//メッセージウィンドウの表示
	VECTOR2 edgePos(winPos.x, winPos.y);
	float edgeH = winH + game()->container()->data().message.sw * 2;
	float edgeW = winW + game()->container()->data().message.sw * 2;

	rectMode(CENTER);
	fill(edgeColor);
	rect(edgePos.x, edgePos.y, edgeW, edgeH);
	fill(winColor);
	rect(winPos.x, winPos.y, winW, winH);
}
void MESSAGE::nextText() {
	//テキストが入力されていないなら、強制的にラストのテキストを表示する
	if (Message.text == "") {
		game()->changeText(GAME::text_Last);
	}
	//テキストのステートを次に進める
	else {
		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
			switch (game()->curTextId()) {
			case GAME::text_1:
				game()->changeText(GAME::text_2);
				break;
			case GAME::text_2:
				game()->changeText(GAME::text_3);
				break;
			case GAME::text_3:
				game()->changeText(GAME::text_4);
				break;
			case GAME::text_4:
				game()->changeText(GAME::text_5);
				break;
			case GAME::text_5:
				game()->changeText(GAME::text_6);
				break;
			case GAME::text_6:
				game()->changeText(GAME::text_7);
				break;
			case GAME::text_7:
				game()->changeText(GAME::text_8);
				break;
			case GAME::text_8:
				game()->changeText(GAME::text_9);
				break;
			case GAME::text_9:
				game()->changeText(GAME::text_10);
				break;
			case GAME::text_10:
				game()->changeText(GAME::text_11);
				break;
			case GAME::text_11:
				game()->changeText(GAME::text_12);
				break;
			case GAME::text_12:
				game()->changeText(GAME::text_13);
				break;
			case GAME::text_13:
				game()->changeText(GAME::text_14);
				break;
			case GAME::text_14:
				game()->changeText(GAME::text_15);
				break;
			case GAME::text_15:
				game()->changeText(GAME::text_16);
				break;
			case GAME::text_16:
				game()->changeText(GAME::text_17);
				break;
			case GAME::text_17:
				game()->changeText(GAME::text_18);
				break;
			case GAME::text_18:
				game()->changeText(GAME::text_19);
				break;
			case GAME::text_19:
				game()->changeText(GAME::text_20);
				break;
			case GAME::text_20:
				game()->changeText(GAME::text_Last);
				break;
			}
		}
	}
}
void MESSAGE::init() {
	game()->changeText(GAME::text_1);
}
/// <summary>
/// 注意書きを表示するウィンドウ
/// </summary>
/// <param name="text1"></param>
/// <param name="text2"></param>
/// <param name="text3"></param>
void MESSAGE::AttentionWindow(const char* text1, const char* text2, const char* text3) {
	COLOR tcolor;
	COLOR normalColor;
	COLOR collisionColor(200, 200, 200, 128);
	game()->button()->rectButton(Message.yesPos, Message.buttonColor, Message.attentionTextColor, text2, Message.buttonNameTextSize, Message.charaNum);
	game()->button()->rectButton(Message.noPos, Message.buttonColor, Message.attentionTextColor, text3, Message.buttonNameTextSize, Message.charaNum);

	RectWindow(Message.attentionWinPos,
		Message.attentionWinW, Message.attentionWinH,
		Message.attentionWinColor, Message.attentionWinEdgeColor);

	fill(Message.attentionTextColor);
	textSize(Message.attentionTextSize);
	text(text1, Message.attentionTextPos.x, Message.attentionTextPos.y);
	textSize(Message.attentionTextSize - 20);


	rectMode(CENTER);
	imageColor(normalColor);
	image(Message.yesImg1, Message.yesPos.x, Message.yesPos.y);

	rectMode(CENTER);

	if (game()->button()->game()->button()->collisionRect(Message.yesPos, Message.buttonW, Message.buttonH)) {
		tcolor = collisionColor;
	}
	else {
		tcolor = normalColor;
	}

	imageColor(tcolor);
	image(Message.yesImg2, Message.yesPos.x, Message.yesPos.y);

	imageColor(normalColor);
	image(Message.noImg1, Message.noPos.x, Message.noPos.y);

	rectMode(CENTER);

	if (game()->button()->game()->button()->collisionRect(Message.noPos, Message.buttonW, Message.buttonH)) {
		tcolor = collisionColor;
	}
	else {
		tcolor = normalColor;
	}

	imageColor(tcolor);
	image(Message.noImg2, Message.noPos.x, Message.noPos.y);

}
void MESSAGE::disPlayCharaImg() {
	rectMode(CORNER);
	if (Message.charaImg1 != 0)
	{
		image(Message.charaImg1, 100, -100);
	}
	if (Message.charaImg2 != 0)
	{
		image(Message.charaImg2, 600, -100);
	}
}

