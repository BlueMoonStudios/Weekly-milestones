#include "Deck.hpp"
#include "Card.hpp"

void shuffle()
{
    //Random sort
}

&Card Card::drawCard()
{
    for (int i=0; i<30; i++)
    {
        if(deck[i].getID()!=0)
        {
            return &deck[i];
        }
    }
}
