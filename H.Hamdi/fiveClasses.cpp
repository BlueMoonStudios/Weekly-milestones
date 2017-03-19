#include<iostream>

using namespace std;

class Card
{
private:
	char name_[20];
	int attack_;
	int damage_;
	int health_;

public:
	Card()
	{
		attack_ = 0;
		damage_ = 0;
		health_ = 0;
	}

	void getName()
	{
		cout << name_ << endl;
	}

	void setAttack(int attack)
	{
		attack_ = attack;
	}

	int getAttack()
	{
		return attack_;
	}

	void setDamage(int damage)
	{
		damage_ = damage;
	}

	int getDamage()
	{
		return damage_;
	}

	void setHealth(int health)
	{
		health_ = health;
	}
	
	int getHealth()
	{
		return health_;
	}

	~Card()
	{
	}

};

class PackOfCards
{	
private:
	Card deck_[30];
	
public:
	PackOfCards()
	{
	}

	Card takeACard()
	{
		return deck_[rand() % 20];
	}
		
	void returnACard(Card card, Card deck[], int i)
	{
		deck[rand() % 20] = card;
	}
	~PackOfCards()
	{
	}
};


class Player
{
public:
	enum Hero { Warrior, Mage, Archer, Rogue };

	Player()
	{
		health_ = 40;
	}

	Card drawCard()
	{
		return deck.takeACard();
	}

	void damage(int dmg)
	{
		health_ -= dmg;
	}

	~Player()
	{
	}

private:
	int health_;
	Hero type;
	PackOfCards deck;
	
};

class Battlefield
{
private:
	Player player1;
	Player player2;
	Card field_[4][5];
	
public:
	Battlefield()
	{
	}

	void putACardOnTheField(Card field[4][5], Card card,unsigned int i, unsigned int j)
	{
		field_[i][j] = card;
	}

	Card takeACardFromTheField(Card card, unsigned int i, unsigned int j)
	{
		return field_[i][j]; 
	}

	Card takeACardFromTheDeck(int player)
	{
		if (player == 1) return player1.drawCard();
		else if (player == 2) return player2.drawCard();
	}

	void damage_(int player, int dmg)
	{
		if (player == 1) player1.damage(dmg);
		else if (player == 2) player2.damage(dmg);
	}
	Battlefield()
	{
	}
};

class Battle : public Battlefield
{
private:
	int turn_;
	Player player1;
	Player player2;
	Card field_[4][5];

public:
	Battle()
	{
		turn_ = 1;
	}
	void switchTurn(Player activePlayer)
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
	~Battle()
	{
	}
};
