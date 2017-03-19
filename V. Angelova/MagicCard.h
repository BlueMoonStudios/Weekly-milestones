#ifndef MAGICCARD_H
#define MAGICCARD_H

class MagicCard
{
public:
    enum Effect { FreezeMonster, KillMonster, SetTrap, RemoveTrap, ReviveMonster};

    int getMana();
    void setMana(int);
    Effect getEffect();
    void setEffect(Effect);

private:
    int mana;
    Effect effect;
};

#endif // MAGICCARD_H
