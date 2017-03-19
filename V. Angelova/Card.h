#ifndef CARD_H
#define CARD_H

class Card
{
public:
    enum Type { Warrior, Healer, Wizard };

    int getLife();
    int getStrength();
    int getMana();
    Type getType();

    void setLife(int);
    void setStrength(int);
    void setMana(int);
    void setType(Type);
    void damage(int);

private:
    int life;
    int strength;
    int mana;
    Type type;
};

#endif // CARD_H
