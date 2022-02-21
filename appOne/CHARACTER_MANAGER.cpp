#include"GAME.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"ENEMY.h"
#include"CHINPIRA.h"
#include"MENHERA.h"
#include"PLAYER.h"
#include"PLAYER_BULLET.h"
#include"ENEMY_BULLET.h"
#include"CAT.h"
#include"HOLE.h"
#include"HOLE2.h"
#include"HOLE3.h"
#include"COKE.h"
#include"TIPS.h"
#include"RAMEN.h"
#include"BEAR.h"
#include"RYMAN.h"
#include"EBIFURAI.h"
#include<vector>
#include"CHARACTER_MANAGER.h"
CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game) :
    GAME_OBJECT(game) {
}
CHARACTER_MANAGER::~CHARACTER_MANAGER() {
    for (int i = 0; i < Total; i++) {
        delete Characters[i];
    }
    delete[] Characters;
}
void CHARACTER_MANAGER::create() {
    CharaMng = game()->container()->data().charaMng;

    Total = 0;
    Total += CharaMng.numPlayers;
    Total += CharaMng.numEnemies;
    Total += CharaMng.numMenhera;
    Total += CharaMng.numChinpira;
    Total += CharaMng.numOnisan;
    Total += CharaMng.numPlayerBullets;
    Total += CharaMng.numEnemyBullets;
    Total += CharaMng.numCats;
    Total += CharaMng.numHoles;
    Total += CharaMng.numCokes;
    Total += CharaMng.numTips;
    Total += CharaMng.numRamens;
    Total += CharaMng.numBears;
    Total += CharaMng.numRymans;
    Total += CharaMng.numEbifurais;

    Characters = new CHARACTER * [Total];

    Player = new PLAYER(game());
    Enemy = new ENEMY(game());
    Onisan = new ONISAN(game());
    Menhera = new MENHERA(game());
    Chinpira = new CHINPIRA(game());
    Hole1 = new HOLE(game());
    Hole2 = new HOLE2(game());
    Hole3 = new HOLE3(game());

    int i, j = 0;
    for (i = 0; i < CharaMng.numPlayers; i++)       Characters[j++] = Player;
    for (i = 0; i < CharaMng.numEnemies; i++)      Characters[j++] = Enemy;
    for (i = 0; i < CharaMng.numOnisan; i++)      Characters[j++] = Onisan;
    for (i = 0; i < CharaMng.numMenhera; i++)      Characters[j++] = Menhera;
    for (i = 0; i < CharaMng.numChinpira; i++)      Characters[j++] = Chinpira;
    for (i = 0; i < CharaMng.numPlayerBullets; i++)    Characters[j++] = new PLAYER_BULLET(game());
    for (i = 0; i < CharaMng.numEnemyBullets; i++)    Characters[j++] = new ENEMY_BULLET(game());
    for (i = 0; i < CharaMng.numCats; i++)          Characters[j++] = new CAT(game());
    for (i = 0; i < CharaMng.numCokes; i++)    Characters[j++] = new COKE(game());
    for (i = 0; i < CharaMng.numTips; i++)    Characters[j++] = new TIPS(game());
    for (i = 0; i < CharaMng.numHoles1; i++)    Characters[j++] = Hole1;
    for (i = 0; i < CharaMng.numHoles2; i++)    Characters[j++] = Hole2;
    for (i = 0; i < CharaMng.numHoles3; i++)    Characters[j++] = Hole3;
    for (i = 0; i < CharaMng.numRamens; i++)    Characters[j++] = new RAMEN(game());
    for (i = 0; i < CharaMng.numBears; i++)    Characters[j++] = new BEAR(game());
    for (i = 0; i < CharaMng.numRymans; i++)    Characters[j++] = new RYMAN(game());
    for (i = 0; i < CharaMng.numEbifurais; i++)    Characters[j++] = new EBIFURAI(game());


    for (int i = 0; i < Total; i++) {
        Characters[i]->create();
    }
}
void CHARACTER_MANAGER::init() {
    for (int i = 0; i < Total; i++) {
        Characters[i]->init();
    }
}
void CHARACTER_MANAGER::appear(char charaId, float wx, float wy, float vx, float vy) {
    // charaIdで指定されたキャラを出現させる
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->charaId() == charaId) {
            if (Characters[i]->hp() <= 0) {
                Characters[i]->appear(wx, wy, vx, vy);
                break;
            }
        }
    }
}
void CHARACTER_MANAGER::update() {
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->update();
        }
    }
    //キャラとキャラの当たり判定---------------------------------------------------
    for (int i = 0; i < Total - 1; i++) {
        if (Characters[i]->hp() == 0) {
            continue;// ←ここでi++に戻る
        }
        for (int j = i + 1; j < Total; j++) {
            if (Characters[j]->hp() == 0) {
                continue;// ←ここでj++に戻る
            }
            //仲間どうしは当たり判定しない
            if (Characters[i]->groupId() == Characters[j]->groupId()) {
                continue;// ←ここでj++に戻る
            }
            //当たり判定
            if (Characters[i]->wLeft() < Characters[j]->wRight() &&
                Characters[j]->wLeft() < Characters[i]->wRight() &&
                Characters[i]->wTop() < Characters[j]->wBottom() &&
                Characters[j]->wTop() < Characters[i]->wBottom()) {
                //当たった
                //プレイヤーの当たり判定
                if (Characters[i]->charaId() == 'a') {
                    if (Characters[j]->charaId() == 'c') {
                        Characters[i]->Sdamage();
                        Characters[j]->Ddamage();
                    }
                    if (Characters[j]->charaId() == 'd') {
                        Characters[i]->Sdamage();
                    }
                    if (Characters[j]->charaId() == 'g' || Characters[j]->charaId() == 'e' || Characters[j]->charaId() == 'n' || Characters[j]->charaId() == 'o') {
                        if (game()->curStateId() != GAME::FIFTH) {
                            Characters[i]->Ddamage();
                        }
                        else {
                            Characters[i]->noDamage();
                            Characters[i]->caught();
                        }
                    }

                    if (Characters[j]->charaId() == 'f') {
                        Characters[i]->fall();
                    }
                    if (Characters[j]->charaId() == 'p') {
                        Characters[i]->fall2();
                    }
                    if (Characters[j]->charaId() == 'q') {
                        Characters[i]->fall3();
                    }
                    if (Characters[j]->charaId() == 'e') {
                        Characters[i]->Srecover();
                    }

                    if (Characters[j]->charaId() == 'h') {
                        Characters[i]->Srecover();
                        Characters[j]->Ddamage();

                    }

                    if (Characters[j]->charaId() == 'i') {
                        Characters[i]->Mrecover();
                        Characters[j]->Ddamage();

                    }

                    if (Characters[j]->charaId() == 'j') {
                        Characters[i]->Lrecover();
                        Characters[j]->Ddamage();

                    }

                    if (Characters[j]->charaId() == 'k') {
                        Characters[1]->knock();
                        Characters[0]->Lrecover();
                        Characters[j]->Ddamage();

                    }

                    if (Characters[j]->charaId() == 'l') {
                        Characters[i]->Ldamage();

                    }
                    if (Characters[j]->charaId() == 'm') {
                        Characters[i]->Mdamage();
                    }


                }
                if (Characters[i]->charaId() == 'g' || Characters[i]->charaId() == 'e' || Characters[i]->charaId() == 'n' || Characters[i]->charaId() == 'o') {
                    if (Characters[j]->charaId() == 'd') {
                        Characters[i]->Sdamage();
                    }
                    if (Characters[j]->charaId() == 'h') {
                        Characters[i]->Srecover();
                        Characters[j]->Ddamage();
                    }
                    if (Characters[j]->charaId() == 'i') {
                        Characters[i]->Mrecover();
                        Characters[j]->Ddamage();
                    }
                    if (Characters[j]->charaId() == 'j') {
                        Characters[i]->Lrecover();
                        Characters[j]->Ddamage();
                    }
                    if (Characters[j]->charaId() == 'k') {
                        Characters[0]->knock();
                        Characters[1]->Lrecover();
                        Characters[j]->Ddamage();
                    }
                    if (Characters[j]->charaId() == 'l') {
                        Characters[i]->Ldamage();

                    }
                    if (Characters[j]->charaId() == 'm' || Characters[j]->charaId() == 'b') {
                        Characters[i]->Mdamage();
                    }

                }
            }

        }
    }

}

void CHARACTER_MANAGER::draw() {
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->draw();
        }
    }
}
