#ifndef PLAYER_H
#define PLAYER_H

#include "Card.hpp"

class Player
{
public:
    Player();
    Card getCard(int);
    void damage(int);
    void regenerate(int);

private:
    int health;
    Card deck[30];
};

#endif // PLAYER_H
