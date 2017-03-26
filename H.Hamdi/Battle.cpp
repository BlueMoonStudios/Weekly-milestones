#include "Battle.h"
#include "Player.h"

Battle::Battle()
{
    turn_ = 1;
}
void Battle::switchTurn(Player activePlayer)//pred player?
{
    turn_ += 1;

    if (turn_ % 2 == 0)
    {
        activePlayer = player1;
    }
    else
    {
        activePlayer = player2;
    }
}
Battle::~Battle()
{
}
