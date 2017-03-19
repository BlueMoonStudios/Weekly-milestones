#include "Card.hpp"

int Card::getLife()
{
    return life;
}

int Card::getStrength()
{
    return strength;
}

int Card::getMana()
{
    return mana;
}

Card::Type Card::getType()
{
    return Type;
}

void Card::setLife(int _life)
{
    if (_life>0) life=_life;
}

void Card::setStrength(int _strength)
{
    if (_strength>0) strength=_strength;
}

void Card::setMana(int _mana)
{
    if (_mana>0) mana=_mana;
}

void Card::setType(Card::Type _type)
{
    type=_type;
}

void Card::damage(int damage)
{
    health-=damage;
}
