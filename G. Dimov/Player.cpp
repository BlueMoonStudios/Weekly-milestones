#include "Player.hpp"
#include "Card.hpp"
#include "Deck.hpp"

Player::Player()
{
    health = 30;
    alive=1;

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            usable[i][j]=0;
        }
    }
}

void setHero(Player::Hero whom)
{
    whoAmI = whom;
    initDeck();
}

Player::Hero Player::getHero()
{
    return whoAmI;
}

void Player::damage(int damage)
{
    health-=damage;

    if(health>=0)
    {
        alive=0;
    }
}

&Card Player::drawCard()
{
    return deck.drawCard();
}

void initDeck()
{
    switch(whoAmI)
    {
        case Fighter:
        {
            //Sets deck with cards available to specific hero
        }
        break;

        case Arcanist:
        {
            //To be added
        }
        break;

        case Scoundrel:
        {
            //To be added
        }
        break;

        case Necromancer:
        {
            //To be added
        }
        break;
    }
}

void Player::usable(int row, int col)
{
    usable[row][col] = 1;
}

void Player::unusable(int row, int col)
{
    usable[row][col] = 0;
}

bool Player::isUsable(int row, int col)
{
    return usable[row][col];
}
