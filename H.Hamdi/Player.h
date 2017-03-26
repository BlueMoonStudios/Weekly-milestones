#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player
{
public:

	enum Hero
    {
        Warrior,
        Mage,
        Archer,
        Rogue
    };

	Player();

	Card drawCard() const;

	void damage(int);

	~Player();


private:
	int health_;
	Hero type;
	Deck deck;

};

#endif // PLAYER_H
