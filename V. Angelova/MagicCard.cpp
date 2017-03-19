#include "MagicCard.hpp"

int MagicCard::getMana()
{
    return mana;
}

void MagicCard::setMana(int _mana)
{
    if(mana>0)
    {
        mana=_mana;
    }
}

MagicCard::Effect MagicCard::getEffect()
{
    return effect;
}

void MagicCard::setEffect(MagicCard::Effect _effect)
{
    effect=_effect;
}
