#include "BigBen.h"
#include "TilePoint.h"
#include <QDebug>
#include <QtGlobal>

TilePoint BigBen::_Ai(QVector <Charakter*> enemies)
{
    int enemyDist;
    TilePoint enemyPoint = enemies[0]->getPosition();
    TilePoint attackerPoint = this->getPosition();

    enemyDist = _enemyDistance(enemyPoint, attackerPoint);

    for(int i = 0; i <  enemies.size(); i++)
    {
        int tmp = _enemyDistance(enemies[i]->getPosition(), attackerPoint);
        if(tmp > enemyDist)
        {
            enemyPoint = enemies[i]->getPosition();
            enemyDist = tmp;
        }
    }

    return enemyPoint;
}

TilePoint BigBen::move()
{
    _setTarget(_Ai(_enemies));
    _gui->addToLogger("!!WRÓG!! Tura Wielkiego Bena !!WRÓG!!", true);
    TilePoint currentPosition = this->getPosition();
    int deltaX = currentPosition.x - _target.x;
    int deltaY = currentPosition.y - _target.y;

    TilePoint destination;
    if(qAbs(deltaX) >= qAbs(deltaY))
    {
        if(currentPosition.x > _target.x)
        {
            destination.x = -1;
            destination.y = 0;
        }
        else
        {
            destination.x = 1;
            destination.y = 0;
        }
    }
    else
    {
        if(currentPosition.y > _target.y)
        {
            destination.x = 0;
            destination.y = -1;
        }
        else
        {
            destination.x = 0;
            destination.y = 1;
        }
    }
    currentPosition.x += destination.x;
    currentPosition.y += destination.y;

    return currentPosition;
}

void BigBen::attack(Charakter* enemy)
{
    _gui->addToLogger("Wielki Ben wykonuje zamach młotem", true);
    int attackRoll = _dices->diceRoll("d20") + this->_attackBonus;
    int dmg = _dices->diceRoll("d10");

    if(_dices->diceRoll("d100") > 90)
    {
        _gui->addToLogger("Wielki Ben uderza przeciwnika młotem, a następnie uderza przeciwnika pięścią w głowę!!", true);
        dmg += _dices->diceRoll("d6");
    }

    enemy->attacked(attackRoll, dmg);
}

void BigBen::_setTarget(TilePoint target)
{
    _target = target;
}

void BigBen::setAi(QVector <Charakter*> enemies)
{
    _enemies = enemies;
}


int BigBen::_enemyDistance(TilePoint enemyPoint, TilePoint attackerPoint)
{
    return qMin(qAbs(enemyPoint.x - attackerPoint.x), qAbs(enemyPoint.y - attackerPoint.y));
}
