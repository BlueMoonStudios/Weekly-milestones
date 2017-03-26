#include "Player.h"
#include "Card.h"

Player::Player()
{
    health_ = 100;
}

Card Player::drawCard() const
{
    return deck.takeACard();
}

void Player::damage(int dmg)
{
    health_ -= dmg;
}

Player::~Player()
{
}
