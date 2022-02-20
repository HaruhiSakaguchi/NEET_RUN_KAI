#pragma once
#include"SCENE.h"
#include"VECTOR2.h"
#include"COLOR.h"
const int limmit = 26;
class PROLOGUE :
	public SCENE
{
public:
	struct DATA {
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
		const char* text = 0; 
		const char* text2 = 0;
		float charaNameTextSize = 0;
		const char* charactername = "新都";
		const char* Text=0;
		const char* iTextNormal = "                 ";
		const char* iText1 = "                      ";
		const char* iText2 = "                      ";
		const char* iText3 = "んぅ？キター！";
		const char* iText4 = "やぁ～っぱ、新台は最高なり～";
		const char* iText5 = "はっ、うれしすぎて語尾が変に...";
		const char* iText6 = "でもまじでホクホクだわ。";
		const char* iTextc = "ワンチャンもう一回行けるか？           ";
		const char* iText7 = "　　　　　　　　　　　";
		const char* iText8 = "ん？";
		const char* iText9 = "　　　　　　　　　　　　";
		const char* iText10 = "　　　　　　　　　　　　　";
		const char* iText11 = "うへぇ、なんだこのライン";
		const char* iText12 = "って、あぁ今日母ちゃんの誕生日か…";
		const char* iText13 = "ガキじゃあるまいし、何だこのテンション";
		const char* iText14 = "...";
		const char* iText15 = "......";
		const char* iText16 = ".........";
		const char* iText17 = "............";
		const char* iText18 = "...............しょうがねぇな　　";
		const char* iText19 = "";
		const char* iText20 = "";
		const char* itextLast = "";

	};
private:
	DATA Prologue;
public:
	PROLOGUE(class GAME* game) : SCENE(game) {}
	void create();
	void draw();
	void update();
	void nextScene();
	void init();
	
};

