#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
#include "GAME_OBJECT.h"
class MESSAGE :
	public GAME_OBJECT
{
public:
	struct DATA {
		//ストーリーで使用するウィンドウ
		VECTOR2 windowPos;//ウィンドウの位置
		VECTOR2 textPos; //テキストの位置
		VECTOR2 textPosOfst;
		float winH = 0;
		float winW = 0;
		float textSize = 0;
		float sw = 0; //strokeWight
		COLOR edgeColor;
		COLOR textColor;
		COLOR winColor;
		//注意書きに使用するウィンドウ
		VECTOR2 attentionTextPos;
		VECTOR2 attentionWinPos;
		float attentionWinW = 0;
		float attentionWinH = 0;
		float attentionTextSize = 0;
		COLOR attentionTextColor;
		COLOR attentionWinColor;
		COLOR attentionWinEdgeColor;

		int yesImg1 = 0;
		int yesImg2 = 0;
		int noImg1 = 0;
		int noImg2 = 0;
		//ストーリーで使用するテキスト
		const char* text = 0;
		const char* text2 = 0;

		const char* text1_1 = 0;
		const char* text1_2 = 0;
		const char* text1_3 = 0;
		const char* text1_4 = 0;

		const char* text1_5 = 0;
		const char* text1_6 = 0;
		const char* text1_7 = 0;
		const char* text1_8 = 0;
		const char* text1_9 = 0;

		const char* text1_10 = 0;
		const char* text1_11 = 0;
		const char* text1_12 = 0;
		const char* text1_13 = 0;

		const char* text1_14 = 0;
		const char* text1_15 = 0;
		const char* text1_16 = 0;
		const char* text1_17 = 0;
		const char* text1_18 = 0;
		const char* text1_19 = 0;
		const char* text1_20 = 0;

		const char* text2_1 = 0;
		const char* text2_2 = 0;
		const char* text2_3 = 0;
		const char* text2_4 = 0;
		const char* text2_5 = 0;
		const char* text2_6 = 0;
		const char* text2_7 = 0;
		const char* text2_8 = 0;
		const char* text2_9 = 0;
		const char* text2_10 = 0;
		const char* text2_11 = 0;
		const char* text2_12 = 0;
		const char* text2_13 = 0;
		const char* text2_14 = 0;
		const char* text2_15 = 0;
		const char* text2_16 = 0;
		const char* text2_17 = 0;
		const char* text2_18 = 0;
		const char* text2_19 = 0;
		const char* text2_20 = 0;

		const char* text3_1 = 0;
		const char* text3_2 = 0;
		const char* text3_3 = 0;
		const char* text3_4 = 0;
		const char* text3_5 = 0;
		const char* text3_6 = 0;
		const char* text3_7 = 0;
		const char* text3_7_2 = 0;
		const char* text3_8 = 0;
		const char* text3_9 = 0;
		const char* text3_10 = 0;
		const char* text3_11 = 0;
		const char* text3_12 = 0;
		const char* text3_13 = 0;
		const char* text3_14 = 0;
		const char* text3_15 = 0;
		const char* text3_16 = 0;
		const char* text3_17 = 0;
		const char* text3_18 = 0;
		const char* text3_19 = 0;
		const char* text3_20 = 0;

		const char* text4_1 = 0;
		const char* text4_2 = 0;
		const char* text4_3 = 0;
		const char* text4_4 = 0;
		const char* text4_5 = 0;
		const char* text4_6 = 0;
		const char* text4_7 = 0;
		const char* text4_8 = 0;
		const char* text4_9 = 0;
		const char* text4_10 = 0;
		const char* text4_11 = 0;
		const char* text4_12 = 0;
		const char* text4_13 = 0;
		const char* text4_14 = 0;
		const char* text4_15 = 0;
		const char* text4_16 = 0;
		const char* text4_17 = 0;
		const char* text4_18 = 0;
		const char* text4_19 = 0;
		const char* text4_20 = 0;

		const char* text5_1 = 0;
		const char* text5_2 = 0;
		const char* text5_3 = 0;
		const char* text5_4 = 0;
		const char* text5_5 = 0;
		const char* text5_6 = 0;
		const char* text5_7 = 0;
		const char* text5_8 = 0;
		const char* text5_9 = 0;
		const char* text5_10 = 0;
		const char* text5_11 = 0;
		const char* text5_12 = 0;
		const char* text5_13 = 0;
		const char* text5_14 = 0;
		const char* text5_15 = 0;
		const char* text5_16 = 0;
		const char* text5_17 = 0;
		const char* text5_18 = 0;
		const char* text5_19 = 0;
		const char* text5_20 = 0;

		const char* textLast_1 = 0;
		const char* textLast_2 = 0;
		const char* textLast_3 = 0;
		const char* textLast_4 = 0;
		const char* textLast_5 = 0;
		const char* textLast_6 = 0;
		const char* textLast_7 = 0;
		const char* textLast_8 = 0;
		const char* textLast_9 = 0;
		const char* textLast_10 = 0;
		const char* textLast_11 = 0;
		const char* textLast_12 = 0;
		const char* textLast_13 = 0;
		const char* textLast_14 = 0;
		const char* textLast_15 = 0;
		const char* textLast_16 = 0;
		const char* textLast_17 = 0;
		const char* textLast_18 = 0;
		const char* textLast_19 = 0;
		const char* textLast_20 = 0;

		const char* text_Last = 0;

		//会話シーンでキャラ名を表示するためのデータ
		float charaNameTextSize = 0;
		const char* charactername = 0;
		const char* space = 0;
		const char* neet = "新都";
		const char* okan = "おかん";
		const char* menhera = "モモ";
		const char* chinpira = "ヤンキーくん";
		const char* onisan = "おにいさん";


		float buttonNameTextSize = 30;
		float charaNum = 4;
		VECTOR2 buttonPos;
		float buttonW = buttonNameTextSize * charaNum;
		float buttonH = buttonNameTextSize * 1.5f;
		VECTOR2 yesPos;
		VECTOR2 noPos;
		COLOR buttonColor;
		int neetDefImg = 0;
		int neetAngImg = 0;
		int neetHpImg = 0;
		int neetSpImg = 0;
		int neetPnImg = 0;
		int neetDlImg = 0;

		int okanDefImg = 0;
		int okanAngImg = 0;
		int okanHpImg = 0;
		int okanSpImg = 0;
		int okanDlImg = 0;

		int onisanDefImg = 0;
		int onisanAngImg = 0;
		int onisanHpImg = 0;
		int onisanSpImg = 0;
		int onisanDlImg = 0;

		int menheraDefImg = 0;
		int menheraAngImg = 0;
		int menheraHpImg = 0;
		int menheraSpImg = 0;
		int menheraDlImg = 0;

		int chinpiraDefImg = 0;
		int chinpiraAngImg = 0;
		int chinpiraHpImg = 0;
		int chinpiraSpImg = 0;
		int chinpiraDlImg = 0;

		int charaImg1 = 0;
		int charaImg2 = 0;

	};

private:
	DATA Message;
public:
	MESSAGE(class GAME* game);
	~MESSAGE();
	void create();
	void draw();
	void nextText();
	void init();
	void RectWindow(
		const VECTOR2& winPos,
		float winW, float winH,
		COLOR& winColor, COLOR& edgeColor
	);
	void AttentionWindow(const char* text1, const char* text2, const char* text3);
	void disPlayCharaImg();
	void setChara1Image(int Img)
	{
		Message.charaImg1 = Img;
	}
	void setChara2Image(int Img)
	{
		Message.charaImg2 = Img;
	}
	void setCharaName(const char* name)
	{
		Message.charactername = name;
	}

};