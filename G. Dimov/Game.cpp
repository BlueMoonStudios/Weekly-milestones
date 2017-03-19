#include "Game.hpp"
#include "Card.hpp"
#include "Player.hpp"

Game::Game()
{
    turn = 1;
    mana = 1;

    activePlayer = &player1;
    opponent = &player2;

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            full[i][j]=0;
        }
    }
}

void Game::setPlayer1(Player _player1)
{
    player1 = _player1;
}

void Game::setPlayer2(Player _player2)
{
    player2 = _player2;
}

void Game::switchTurn()
{
    ++turn;

    if(turn<=24)
    {
        if(turn&1)
        {
            mana = (turn+1)/2;
        }

        else
        {
            mana = turn/2;
        }
    }

    Player* swapP;

    swapP = activePlayer;
    activePlayer = opponent;
    opponent = swapP;
}
