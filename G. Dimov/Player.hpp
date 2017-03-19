#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Deck.hpp"
#include "Card.hpp"

class Player
{
public:

    enum Hero
    {
        Fighter,
        Arcanist,
        Scoundrel,
        Necromancer,
        //...
    };

    Player();

    void setHero(Hero);

    Hero getHero();

    void damage(int);

    &Card drawCard();

    void usàble(int, int);

    void unusable{int, int};

    bool isUsable(int, int);

private:

    int health;
    bool alive;

    Deck deck;
    Hero whoAmI;

    bool usable[4][5];

    void initDeck();
};

#endif // PLAYER_HPP
