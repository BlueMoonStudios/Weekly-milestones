#include "Hand.hpp"

Hand::Hand()
{
    fullM=0;
    fullS=0;
}

Player Hand::getPlayer()
{
    return player;
}

void Hand::setPlayer(Player _player)
{
    player=_player;
}

void Hand::addMonster(Card Mcard)
{
    if (fullM<5)
    {
        monsters[fullM]=Mcard;
        fullM++;
    }
}

void Hand::addSpell(MagicCard Scard)
{
    if (fullS<2)
    {
        spells[fullS]=Scard;
        fullS++;
    }
}

Card Hand::getMonster(int which)
{
    if (which>=0 && which<=fullM)
    {
        return monsters[which];
    }
}

MagicCard Hand::getSpell(int which)
{
    if(which>=0 & which<=fullS)
    {
        return spells[which];
    }
}
