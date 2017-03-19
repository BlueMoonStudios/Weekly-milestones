#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MonsterCard.hpp"

//MonsterCard::MonsterCard();

MonsterCard::MonsterCard(int _cardID)
{
    cardID = _cardID;
    atk = 0;
    hp = 0;
    mana = 0;
    alive = 1;

    font.loadFromFile("Augusta.ttf");
    image.loadFromFile("blackcolor.png");
    image.setSmooth(true);
    sprite.setTexture(image);

    atkNum.setFont(font);
    hpNum.setFont(font);
    manaNum.setFont(font);

    std::stringstream atkText, hpText, manaText;
    atkText << atk;
    hpText << hp;
    manaText << mana;

    atkNum.setString(atkText.str());
    hpNum.setString(hpText.str());
    manaNum.setString(manaText.str());

    atkNum.setCharacterSize(32);
    hpNum.setCharacterSize(32);
    manaNum.setCharacterSize(32);

    atkNum.setFillColor(sf::Color::White);
    hpNum.setFillColor(sf::Color::Red);
    manaNum.setFillColor(sf::Color::Blue);

    atkNum.setOrigin(atkNum.getGlobalBounds().width/2, atkNum.getGlobalBounds().height);
    hpNum.setOrigin(hpNum.getGlobalBounds().width/2, hpNum.getGlobalBounds().height);
    manaNum.setOrigin(manaNum.getGlobalBounds().width/2, manaNum.getGlobalBounds().height);

    atkNum.setPosition(sprite.getPosition().x + 15, sprite.getPosition().y + 225);
    hpNum.setPosition(sprite.getPosition().x + 165, sprite.getPosition().y + 225);
    manaNum.setPosition(sprite.getPosition().x + 15, sprite.getPosition().y + 15);

    MonsterCard::setID(cardID);
}

void MonsterCard::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
    atkNum.setPosition(x + 15, y + 225);
    hpNum.setPosition(x + 165, y + 225);
    manaNum.setPosition(x + 15, y + 15);
}

void MonsterCard::setPosition(sf::Vector2f vec)
{
    sprite.setPosition(vec);
    atkNum.setPosition(vec.x + 15, vec.y + 225);
    hpNum.setPosition(vec.x + 165, vec.y + 225);
    manaNum.setPosition(vec.x + 15, vec.y + 15);
}

sf::Vector2f MonsterCard::getPosition() const
{
    return sprite.getPosition();
}

void MonsterCard::setTexture(sf::String name)
{
    image.loadFromFile(name);
    sprite.setTexture(image);
}

bool MonsterCard::contains(sf::Vector2f vec)
{
    return sprite.getGlobalBounds().contains(vec);
}

void MonsterCard::setStats(int _atk, int _hp, int _mana)
{
    atk = _atk;
    hp = _hp;
    mana = _mana;

    std::stringstream atkText, hpText, manaText;
    atkText << atk;
    hpText << hp;
    manaText << mana;

    atkNum.setString(atkText.str());
    hpNum.setString(hpText.str());
    manaNum.setString(manaText.str());

    atkNum.setOrigin(atkNum.getGlobalBounds().width/2, atkNum.getGlobalBounds().height);
    hpNum.setOrigin(hpNum.getGlobalBounds().width/2, hpNum.getGlobalBounds().height);
    manaNum.setOrigin(manaNum.getGlobalBounds().width/2, manaNum.getGlobalBounds().height);
}

int MonsterCard::getAtk() const
{
    return atk;
}

void MonsterCard::damage(int dmg)
{
    hp-=dmg;

    if(hp<1)
    {
        alive=0;
    }

    else
    {
        std::stringstream hpText;
        hpText<<hp;
        hpNum.setString(hpText.str());
        hpNum.setOrigin(hpNum.getGlobalBounds().width/2, hpNum.getGlobalBounds().height);
    }
}

bool MonsterCard::isAlive() const
{
    return alive;
}

MonsterCard::Class MonsterCard::getClass() const
{
    return RPGclass;
}

void MonsterCard::setClass(MonsterCard::Class choice)
{
    RPGclass = choice;
}

void MonsterCard::setID(int _cardID)
{
    cardID = _cardID;

    switch(_cardID%10)
    {
        case (0):
        {
            RPGclass = Warrior;
        }
        break;

        case (1):
        {
            RPGclass = Rogue;
        }
        break;

        case (2):
        {
            RPGclass = Archer;
        }
        break;

        case (3):
        {
            RPGclass = Mage;
        }
        break;
    }

    _cardID /= 10;

    //To be made into case switch
    if (MonsterCard::getClass()==Warrior)
    {
        switch(_cardID%10)
        {
            case (0):
            {
                MonsterCard::setStats(0, 0, 0);
            }
            break;

            case (1):
            {
                image.loadFromFile("Cards/Warrior/1.jpg");
                //name.setString("..."); for all cases
                MonsterCard::setStats(1, 2, 1);
            }
            break;

            case (2):
            {
                image.loadFromFile("Cards/Warrior/2.jpg");
                MonsterCard::setStats(2, 2, 2);
            }
            break;

            case (3):
            {
                image.loadFromFile("Cards/Warrior/3.jpg");
                MonsterCard::setStats(2, 4, 3);
            }
            break;

            case (4):
            {
                image.loadFromFile("Cards/Warrior/4.jpg");
                MonsterCard::setStats(6, 2, 4);
            }
            break;

            case (5):
            {
                image.loadFromFile("Cards/Warrior/5.jpg");
                MonsterCard::setStats(4, 6, 5);
            }
            break;

            case (6):
            {
                image.loadFromFile("Cards/Warrior/6.jpg");
                MonsterCard::setStats(5, 8, 7);
            }
            break;

            case (7):
            {
                image.loadFromFile("Cards/Warrior/7.jpg");
                MonsterCard::setStats(7, 7, 8);
            }
            break;

            case (8):
            {
                image.loadFromFile("Cards/Warrior/8.jpg");
                MonsterCard::setStats(15, 1, 9);
            }
            break;

            case (9):
            {
                image.loadFromFile("Cards/Warrior/9.jpg");
                MonsterCard::setStats(12, 10, 10);
            }
            break;
        }
    }

    else if (MonsterCard::getClass()==Rogue)
    {
        //To be added
    }

    else if (MonsterCard::getClass()==Archer)
    {
        //To be added
    }

    else if (MonsterCard::getClass()==Mage)
    {
        //To be added
    }
}
