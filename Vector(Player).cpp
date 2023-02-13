#include "Vector(Player).h"

TilePoint Player::getDirection()
{
    return _direction;
}

void Player::setDiretion(TilePoint newDirection)
{
    _direction = newDirection;
}
