#include "Card.h"
#include <assert.h>
#include <iostream>

using namespace std;

Card::Card()
{
    attack_ = 0;
	damage_ = 0;
	health_ = 0;
}

void copyMembers(const Card& other)
{
    name_ = new char[strlen(other.name_) + 1];
    strcpy(name_,other.name_);

    attack_ = other.attack_;
    damage_ = other.damage_;
    health_ = other.health_;
}

Card(const char* name, int attack = 100, int damage = 100, int health = 100) : attack_(attack), damage_(damage), health_(health)
 {
     name_ = new char[strlen(name) + 1];
     assert(name_!=NULL);
     strcpy(name_,name);
}

Card(const Card& other)
{
    void copyMembers(other);
}

Card& operator=(const Card& other)
{
    if (this != &other)
    {
        delete name_;

        void copyMembers(other);
    }
    return *this;
}

void Card::setAttack(int attack)
{
    attack_ = attack;
}

void Card::setDamage(int damage)
{
    damage_ = damage;
}

void Card::setHealth(int health)
{
    health_ = health;
}

char* Card::getName() const
{
    return name_;
}

int Card::getAttack() const
{
    return attack_;
}

int Card::getDamage() const
{
    return damage_;
}

int Card::getHealth() const
{
    return health_;
}

Card::~Card()
{
    delete name_;
}
