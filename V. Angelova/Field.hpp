#ifndef FIELD_HPP
#define FIELD_HPP

class Field
{
public:

    Field();
    void placeCard(int, int);
    void removeCard(int, int);
    bool isThereCard(int, int);

    void placeTrap(int, int);
    void removeTrap(int, int);
    bool isThereTrap(int, int);

private:
    bool placedCards[4][5];
    bool traps[4][5];
};

#endif // FIELD_HPP
