#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"

class Deck
{
public:

    void shuffle();

    &Card drawCard();
private:

    Card deck[30];
};

#endif // DECK_HPP
