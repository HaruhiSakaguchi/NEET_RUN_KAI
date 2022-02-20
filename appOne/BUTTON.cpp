#include"GAME.h"
#include"graphic.h"
#include"framework.h"
#include"CONTAINER.h"
#include "BUTTON.h"
BUTTON::BUTTON(class GAME* game) :
	GAME_OBJECT(game) {}
BUTTON::~BUTTON() {

}
int BUTTON::collisionCircle(VECTOR2 pos, float buttonR) {
	VECTOR2 mPos(mouseX, mouseY);
	float a = pos.x - mPos.x;
	float b = pos.y - mPos.y;
	float c = a * a + b * b;
	float d = (buttonR + Button.radius) * (buttonR + Button.radius);

	if (c <= d) {
		return 1;
	}
	else {
		return 0;
	}
}

int BUTTON::collisionRect(VECTOR2 pos, float buttonW, float buttonH) {
	VECTOR2 mPos(mouseX, mouseY);
	VECTOR2 Pos1(pos.x - (buttonW / 2), pos.y - (buttonH / 2));
	VECTOR2 Pos2(Pos1.x + buttonW, Pos1.y + buttonH);
	float r2 = Button.radius * Button.radius;
	float c = ((Pos1.x - mPos.x) * (Pos1.x - mPos.x)) + ((Pos1.y - mPos.y) * (Pos1.y - mPos.y));
	float d = ((Pos2.x - mPos.x) * (Pos2.x - mPos.x)) + ((Pos1.y - mPos.y) * (Pos1.y - mPos.y));
	float e = ((Pos2.x - mPos.x) * (Pos2.x - mPos.x)) + ((Pos2.y - mPos.y) * (Pos2.y - mPos.y));
	float f = ((Pos1.x - mPos.x) * (Pos1.x - mPos.x)) + ((Pos2.y - mPos.y) * (Pos2.y - mPos.y));
	float A = (mPos.x > Pos1.x) && (mPos.x < Pos2.x) && (mPos.x > (Pos1.y - Button.radius)) && (mPos.y < (Pos2.y + Button.radius));
	float B = (mPos.x > (Pos1.x - Button.radius)) && (mPos.x < (Pos2.x + Button.radius)) && (mPos.y > Pos1.y) && (mPos.y < Pos2.y);
	float C = c < r2;
	float D = d < r2;
	float E = e < r2;
	float F = f < r2;
	if ((A && B) || C || D || E || F) {
		return 1;
	}
	else {
		return 0;
	}
}
void BUTTON::create() {
	Button = game()->container()->data().button;
}
void BUTTON::rectButton(VECTOR2 pos, COLOR buttonColor,
	COLOR textColor, const char* buttonName, float buttonNameTextSize, float charaNum) {
	COLOR collisionColor(200, 200, 200, 128);
	COLOR color;
	COLOR tColor;
	float buttonW = buttonNameTextSize * charaNum;
	float buttonH = buttonNameTextSize * 3;

	if (collisionRect(pos, buttonW, buttonH)) {
		color = collisionColor;
		tColor = collisionColor;
	}
	else {
		color = buttonColor;
		tColor = textColor;
	}

	rectMode(CENTER);
	fill(buttonColor);
	rect(pos.x, pos.y, buttonW, buttonH);
	fill(color);
	rect(pos.x, pos.y, buttonW, buttonH);

	textSize(buttonNameTextSize);
	fill(textColor);
	text(buttonName, pos.x - buttonW / 2.0f, pos.y + buttonNameTextSize / 2);
	fill(tColor);
	text(buttonName, pos.x - buttonW / 2.0f, pos.y + buttonNameTextSize / 2);
}
void BUTTON::circleButton(VECTOR2 pos, float buttonR, COLOR buttonColor,
	COLOR textColor, const char* buttonName) {
	COLOR collisionColor(200, 200, 200, 128);
	COLOR color;
	COLOR tColor;

	Button.circleButtonNameTextSize = (buttonR - 20);
	if (Button.circleButtonNameTextSize > buttonR) {
		Button.circleButtonNameTextSize = buttonR / 2;
	}
	if (collisionCircle(pos, buttonR)) {
		color = collisionColor;
		tColor = collisionColor;
		//if (isTrigger(MOUSE_LBUTTON)) {
		//    function();
		//}
	}
	else {
		color = buttonColor;
		tColor = textColor;
	}
	fill(buttonColor);
	circle(pos.x, pos.y, buttonR * 2);
	fill(color);
	circle(pos.x, pos.y, buttonR * 2);
	textSize(Button.circleButtonNameTextSize);
	fill(textColor);
	text(buttonName, pos.x - Button.circleButtonNameTextSize, pos.y + Button.circleButtonNameTextSize / 2);
	fill(tColor);
	text(buttonName, pos.x - Button.circleButtonNameTextSize, pos.y + Button.circleButtonNameTextSize / 2);
}
void BUTTON::drawCursor() {
	Button.cursorPos = VECTOR2(mouseX, mouseY);
	fill(255,0,0,128);
	strokeWeight(5);
	noStroke();
	circle(Button.cursorPos.x, Button.cursorPos.y, Button.radius * 2);
}
void BUTTON::selectButton(int buttonNum, VECTOR2 pos, float buttonR, COLOR buttonColor,
	COLOR textColor, const char* buttonName, float buttonNameTextSize, float charaNum) {
	if (buttonNum == 0) {
		circleButton(pos, buttonR, buttonColor,
			textColor, buttonName);
		Button.buttonFlag = 0;
	}
	else if (buttonNum == 1) {
		rectButton(pos, buttonColor,
			textColor, buttonName, buttonNameTextSize, charaNum);
		buttonR = 0;
		Button.buttonFlag = 1;
	}
}

