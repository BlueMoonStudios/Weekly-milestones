#include "Player.hpp"
#include "Card.hpp"

Player::Player()
{
    health = 40;
}

Card Player::getCard(int whichCard)
{
    return deck[whichCard];
}

void Player::damage(int damage)
{
    health-=damage;
}

void Player::regenerate(int heal)
{
    health+=damage;
}
