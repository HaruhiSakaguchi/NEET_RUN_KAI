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
		VECTOR2 windowPos;//�E�B���h�E�̈ʒu
		VECTOR2 textPos; //�e�L�X�g�̈ʒu
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
		const char* charactername = "�V�s";
		const char* Text=0;
		const char* iTextNormal = "                 ";
		const char* iText1 = "                      ";
		const char* iText2 = "                      ";
		const char* iText3 = "�񂣁H�L�^�[�I";
		const char* iText4 = "�₟�`���ρA�V��͍ō��Ȃ�`";
		const char* iText5 = "�͂��A���ꂵ�����Č�����ς�...";
		const char* iText6 = "�ł��܂��Ńz�N�z�N����B";
		const char* iTextc = "�����`�����������s���邩�H           ";
		const char* iText7 = "�@�@�@�@�@�@�@�@�@�@�@";
		const char* iText8 = "��H";
		const char* iText9 = "�@�@�@�@�@�@�@�@�@�@�@�@";
		const char* iText10 = "�@�@�@�@�@�@�@�@�@�@�@�@�@";
		const char* iText11 = "���ւ��A�Ȃ񂾂��̃��C��";
		const char* iText12 = "���āA���������ꂿ���̒a�������c";
		const char* iText13 = "�K�L���Ⴀ��܂����A�������̃e���V����";
		const char* iText14 = "...";
		const char* iText15 = "......";
		const char* iText16 = ".........";
		const char* iText17 = "............";
		const char* iText18 = "...............���傤���˂��ȁ@�@";
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

