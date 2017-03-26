#pragma once
#include "cardWithEffect.hpp"
#include "monsterCard.hpp"

class Deck
{
public:
	//constructor
	Deck();
	Deck(int _numOfCardsTotal);
	Deck(const Deck& other);
	~Deck();
	//accessors
	int get_numOfCardsTotal() const;
	int get_numOfCardsLeft() const;
	bool isCardAvailable(int index);
	//mutator
	void makeCardUnavailable(int index);
	//method
	void permuteDeck(); 
	int drawCard();
	//operator =
	Deck& operator =(const Deck &other);
private:
	void copyDeck(const Deck &other);
	int* deck;
	int numOfCardsTotal;
	int numOfCardsLeft;
	int* permutation;
	bool* cardsAvailable;
	
};