#pragma once
class Card
{
public:

	Card(int mana, int life, int attack, int deffence);
	Card();



	int get_attack() const;
	int get_mana() const;
	int get_deffence() const;

	int set_life(int damage);





private:
	int _mana;
	int _attack;
	int _life;
	int _deffence;

};
