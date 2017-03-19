#ifndef CARD_HPP
#define CARD_HPP

#include <SFML/Graphics.hpp>

class Card
{
public:

Card();

int getID();

protected:

    int cardID;

    sf::Texture image;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text name;

    void setTexture(sf::String);

    void setName(sf::String);
};

#endif // CARD_HPP
