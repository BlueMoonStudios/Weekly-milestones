#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Card.hpp"

class Game
{
public:

    Card *field[4][5];

    bool full[4][5];

    Game();

    void setPlayer1(Player);

    void setPlayer2(Player);

    void switchTurn();

private:

    int turn;
    int mana;

    Player player1;
    Player player2;

    Player* activePlayer;
    Player* opponent;
};

#endif // GAME_HPP
