#include "../../CoffeeCupEngine/src/game/entryPoint.h"

#include "gameExample.h"

Game* createGame()
{
    return new GameExample();
}