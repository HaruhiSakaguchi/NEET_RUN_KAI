#pragma once
#include "CHARACTER.h"
class BEAR :
    public CHARACTER
{
public:
    BEAR(class GAME* game) :CHARACTER(game) {}
    void create();
};

