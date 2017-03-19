#include <SFML/Graphics.hpp>
#include "Card.hpp"

Card::Card()
{
    cardID=0;
}

int Card::getID()
{
    return cardID;
}

void Card::setTexture(sf::String name)
{
    image.loadFromFile(name);
    sprite.setTexture(image);
}

void Card::setName(sf::String name)
{
    name.setString(name);
}
