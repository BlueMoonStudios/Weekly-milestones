#pragma once
#include "cardWithEffect.hpp"
#include "monsterCard.hpp"

class Deck
{
public:
	//constructor
	Deck();
	Deck(int _numOfCardsTotal);
	//accessors
	int get_numOfCardsTotal() const;
	int get_numOfCardsLeft() const;
	bool isCardAvailable(int index);
	//mutator
	void makeCardUnavailable(int index);
	//method
	void permuteDeck();
	int drawCard();
	void deleteDeck();
private:
	int numOfCardsTotal;
	int numOfCardsLeft;
	int* permutation;
	bool* cardsAvailable;
};