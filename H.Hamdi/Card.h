#ifndef CARD_H
#define CARD_H

class Card
{
public:
    Card();

    Card(const char* name, int = 100, int = 100, int = 100);
    Card(const Card& other);
    Card& operator=(const Card&);

    void setAttack(int);
    void setDamage(int);
    void setHealth(int);

    char* getName() const;
    int getAttack() const;
    int getDamage() const;
    int getHealth() const;

    ~Card();


private:
	char* name_;
	int attack_;
	int damage_;
	int health_;

    void copyMembers(const Card& other)
    {
        name_ = new char[strlen(other.name_) + 1];
        strcpy(name_,other.name_);

        attack_ = other.attack_;
        damage_ = other.damage_;
        health_ = other.health_;
    }
};

#endif // CARD_H
