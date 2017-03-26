#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"

class Battle: public Battlefield
{
public:
    Battle();

	void switchTurn(Player);

	~Battle();


private:
	int turn_;
	Player player1;
	Player player2;
	Card field_[4][5];

};

#endif // BATTLE_H
