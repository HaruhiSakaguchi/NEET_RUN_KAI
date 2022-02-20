#pragma once
#include "CHARACTER.h"
class RAMEN :
    public CHARACTER
{
public:
    RAMEN(class GAME* game) :CHARACTER(game) {}
    void create();
};

