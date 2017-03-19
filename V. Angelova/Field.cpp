#include "Field.hpp"

void Field::placeCard(int row, int col)
{
    placedCard[row][col]=1;
}

void Field::removeCard(int row, int col)
{
    placedCards[row][col]=0;
}

bool Field::isThereCard(int row, int col)
{
    return placedCards[row][col];
}

void Field::placeTrap(int row, int col)
{
    traps[row][col]=1;
}

void Field::removeTrap(int row, int col)
{
    traps[row][col]=0;
}

bool Field::isThereTrap(int row, int col)
{
    return traps[row][col];
}
