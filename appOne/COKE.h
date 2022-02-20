#pragma once
#include "CHARACTER.h"
class COKE :
    public CHARACTER
{
public:
    COKE(class GAME*game):CHARACTER(game) {}
    void create();
};

