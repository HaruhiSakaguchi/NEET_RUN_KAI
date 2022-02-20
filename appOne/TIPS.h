#include "CHARACTER.h"
class TIPS :
    public CHARACTER
{
public:
    TIPS(class GAME* game) :CHARACTER(game) {}
    void create();
};
