#ifndef MONSTERCARD_HPP
#define MONSTERCARD_HPP

#include <SFML/Graphics.hpp>
#include "Card.hpp"

class MonsterCard : public Card, public sf::Drawable, public sf::Transformable
{
public:

    enum Class
    {
        Warrior,
        Rogue,
        Archer,
        Mage
    };

    //MonsterCard();

    MonsterCard(int _cardID = 0);

    void setPosition(float, float);

    void setPosition(sf::Vector2f);

    sf::Vector2f getPosition() const;

    bool contains(sf::Vector2f);

    int getAtk() const;

    void damage(int);

    bool isAlive() const;

    Class getClass() const;

    void setID(int);

private:

    int cardID;
    int atk;
    int hp;
    int mana;
    bool alive;

    Class RPGclass;

    sf::Text atkNum;
    sf::Text hpNum;
    sf::Text manaNum;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if(alive)
        {
            states.transform *= getTransform();

            target.draw(sprite, states);
            target.draw(name, states);
            target.draw(atkNum, states);
            target.draw(hpNum, states);
            target.draw(manaNum, states);
        }
    }

    void setStats(int, int, int);

    void setClass(Class);
};

#endif // MONSTERCARD_HPP
