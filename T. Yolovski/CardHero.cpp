#include "CardHero.h"
#include <iostream>

///Card::Card(int mana, int life, int attack, int deffence) : _mana(mana), _life(life), _attack(attack), _deffence(deffence){};


Card::Card(int mana, int life, int attack, int deffence) 
{
	mana = 3;
	life = 5;
	attack = 2;
	deffence = 3;
}
Card::Card() //Default Constructor
{
};


int Card::get_attack() const
{
	return _attack;
}

int Card::get_mana() const
{
	return _mana;
}

int Card::get_deffence() const
{
	return _deffence;
}

int Card::set_life(int damage)
{
	return _life = _life - damage;
}