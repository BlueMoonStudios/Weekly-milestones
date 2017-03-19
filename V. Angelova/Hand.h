#ifndef HAND_H
#define HAND_H

#include "Card.hpp"
#include "Player.hpp"
#include "MagicCard.hpp"

class Hand()
{
public:
    Player getPlayer();
    void setPlayer(Player);
    void addMonster(Card);
    void addSpell(MagicCard);
    Card getMonster(int);
    MagicCard getSpell(int);

private:
    int fullM;
    int fullS;

    Card monsters[5];
    MagicCard spells[2];
    Player player;
};

#endif // HAND_H
