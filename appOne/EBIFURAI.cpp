#include"EBIFURAI.h"
#include"window.h"
#include"GAME.h"
#include"MAP.h"
#include"CONTAINER.h"
void EBIFURAI::create() {
	Chara = game()->container()->data().ebifuraiChara;
	Ebifurai = game()->container()->data().ebifurai;
}
void EBIFURAI::appear(float wx, float wy, float vx, float vy) {
	Chara.hp = 1;
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.vx = vx;
	Chara.vy = vy;
    Ebifurai.jumpFlag = 0;
}
void EBIFURAI::jump() {
	if (Ebifurai.jumpFlag == 0) {
		Chara.vy = Ebifurai.initVecUp;
		Ebifurai.jumpFlag = 1;
	}
	if (Ebifurai.jumpFlag == 1) {
		Chara.vy += Ebifurai.gravity * delta;
		Chara.wy += Chara.vy * 60 * delta;
	}
}
void EBIFURAI::update() {
    Ebifurai.curWx = Chara.wx;
	Chara.vx = Chara.speed * delta;
	Chara.wx += Chara.vx;
    CollisionWithMap();
	jump();
	if (Chara.wx < game()->map()->wDispLeft()) {
		Chara.hp = 0;
	} 
	
}
void EBIFURAI::CollisionWithMap() {
    MAP* map = game()->map();
    // �}�b�v�`�b�v�ƃL�����̉E
    
    if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
         //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
        Chara.wx = Ebifurai.curWx;
    }
    
    // �}�b�v�`�b�v�ƃL�����̍�
    
    if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
        Chara.wx < map->wx() //�܂��́A�E�B���h�E�̍��ɂԂ�������
        ) {
        Chara.wx = Ebifurai.curWx;
    }
    
    // �}�b�v�`�b�v�ƃL�����̏�
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Ebifurai.initVecDown;//�����Ă��������x
    }
    // �}�b�v�`�b�v�ƃL�����̉�
    if (map->collisionCharaBottom(Ebifurai.curWx, Chara.wy)) {
        //--�u�}�b�v�`�b�v�ɐH������ł���v
        // �܂��́u��ɗ����Ă���Ƃ��v��������ʂ�--
        //�W�����v�i�����j�����̒�~
        Ebifurai.jumpFlag = 0;
        Chara.vy = 0.0f;
        //�����I�ɏ�ɗ����Ă���ʒu�ɂ���
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Ebifurai.jumpFlag = 1;//�����Ă��g���K�[�B���̃t���b�O�𗧂Ă邾���ŗ����Ă����B
    }
}
