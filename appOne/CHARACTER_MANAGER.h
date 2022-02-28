#pragma once
#include "GAME_OBJECT.h"
class CHARACTER_MANAGER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int numPlayers = 0;
        int numEnemies = 0;
        int numChinpira = 0;
        int numOkan = 0;
        int numMenhera = 0;
        int numOnisan = 0;
        int numPlayerBullets = 0;
        int numEnemyBullets = 0;
        int numCats = 0;
        int numHoles = 0;
        int numCokes = 0;
        int numTips = 0;
        int numRamens = 0;
        int numBears = 0;
        int numRymans = 0;
        int numEbifurais = 0;
    };
private:
    int Total = 0;
    DATA CharaMng;
    class CHARACTER** Characters = nullptr;
    class PLAYER* Player = nullptr;
    class ENEMY* Enemy = nullptr;
    class ONISAN* Onisan = nullptr;
    class MENHERA* Menhera = nullptr;
    class CHINPIRA* Chinpira = nullptr;
   

public:
    CHARACTER_MANAGER(class GAME* game);
    ~CHARACTER_MANAGER();
    void create();
    void init();
    void appear(char charaId, float wx, float wy, float vx = 0, float vy = 0);
    void update();
    void draw();
    class PLAYER* player() { return Player; }
    class ENEMY* enemy() { return Enemy; }
    class ONISAN* onisan() { return Onisan; }
    class MENHERA* menhera() { return Menhera; }
    class CHINPIRA* chinpira() { return Chinpira; }
   

};
