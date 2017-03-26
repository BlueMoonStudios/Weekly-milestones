#include "Deck.h"
#include "Card.h"

Deck::Deck()
{
}

Card Deck::takeACard() const
{
    return deck_[rand() % 20];
}

void Deck::returnACard(Card card, Card deck[], int i)
{
    deck[rand() % 20] = card;
}

Deck::~Deck()
{
}

