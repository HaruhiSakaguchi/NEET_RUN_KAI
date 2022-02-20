#include"HP_GAUGE.h"
#include"CONTAINER.h"
#include"graphic.h"
#include"input.h"
#include"PLAYER.h"
#include"GAME.h"
void HP_GAUGE::create() {
	HpGauge = game()->container()->data().hpGauge;
}
void HP_GAUGE::draw() {
	COLOR color;
	COLOR normalColor = COLOR(0,255,0);
	COLOR attentionColor = COLOR(255,255,0);
	COLOR dangerColor = COLOR(255,0,0);
	float normal = game()->container()->data().playerChara.maxStamina * HpGauge.zoom * 0.50f ;
	float attention = game()->container()->data().playerChara.maxStamina * HpGauge.zoom * 0.20f;
	float danger = game()->container()->data().playerChara.maxStamina * HpGauge.zoom * 0.10f ;


	if (normal <= game()->characterManager()->player()->PlayerSta() * HpGauge.zoom && attention < game()->characterManager()->player()->PlayerSta() * HpGauge.zoom) {
		color = normalColor;
	}
	else if (attention <= game()->characterManager()->player()->PlayerSta() * HpGauge.zoom && danger < game()->characterManager()->player()->PlayerSta() * HpGauge.zoom) {
		color = attentionColor;
	}
	else color = dangerColor;
	
	rectMode(CORNER);
	fill(128);
	rect(0, 0, game()->container()->data().playerChara.maxStamina*HpGauge.zoom+2.5f, 25);
	fill(color);
	rect(2.5f,2.5f, game()->characterManager()->player()->PlayerSta() * HpGauge.zoom, 20);
}


