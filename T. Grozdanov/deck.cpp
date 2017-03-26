#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "deck.hpp"
#include "cardWithEffect.hpp"
#include "monsterCard.hpp"

void Deck::copyDeck(const Deck& other)
{
	numOfCardsLeft = other.numOfCardsLeft;
	numOfCardsTotal = other.numOfCardsTotal;
	deck = new int[numOfCardsTotal];
	permutation = new int[numOfCardsTotal];
	cardsAvailable = new bool[numOfCardsTotal];
	for (int i = 0; i < numOfCardsTotal; i++)
	{
		permutation[i] = other.permutation[i];
		cardsAvailable[i] = other.cardsAvailable[i];
	}
}
void swap(int permutation[], int i1, int i2)
{
	int temp;
	temp = permutation[i1];
	permutation[i1] = permutation[i2];
	permutation[i2] = temp;
}
//constructor
Deck::Deck(int _numOfCardsTotal)
{
	numOfCardsTotal = _numOfCardsTotal;
	numOfCardsLeft = _numOfCardsTotal;
	permutation = new int[numOfCardsTotal];
	cardsAvailable = new bool[numOfCardsTotal];
} 
Deck::Deck()
{
	numOfCardsTotal= 10;
	numOfCardsLeft = 10;
	permutation = new int[10];
	cardsAvailable = new bool[10];
}
Deck::Deck(const Deck& other)
{
	copyDeck(other);	
}
Deck& Deck::operator=(const Deck &other)
{
	if (this != &other)
	{
		delete[] permutation;
		delete[] cardsAvailable;
		copyDeck(other);
	}
	return *this;
}
//accessors
int Deck::get_numOfCardsTotal() const
{
	return numOfCardsTotal;
}
int Deck::get_numOfCardsLeft() const
{
	return numOfCardsLeft;
}
bool Deck::isCardAvailable(int index)
{
	return cardsAvailable[index];
}
//mutators
void Deck::makeCardUnavailable(int index)
{
	assert(index >= 0 && index <= numOfCardsTotal);
	cardsAvailable[index] = false;
	--numOfCardsLeft;
}
//methods
void Deck::permuteDeck()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		permutation[i] = ((i + 1) * 7) % 10;
	for (int i = 0; i < numOfCardsTotal*2; i++)
	{
		int swap1, swap2;
		swap1 = rand() % 10; 
		swap2 = rand() % 10;
		if (swap1 != swap2)	
			swap(permutation, swap1, swap2);
	}
}
int Deck::drawCard()
{
	for (int i = 0; i < numOfCardsTotal; i++)
	{
		if (cardsAvailable [permutation[i]])
		{
			makeCardUnavailable(permutation[i]);
			return permutation[i];
		}
	}
	return numOfCardsTotal; //no such card, error code
}
Deck::~Deck()
{
	delete[] permutation;
	delete[] cardsAvailable;
}

