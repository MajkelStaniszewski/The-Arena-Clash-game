#include "Postacie.h"

#include <QString>
#include <QDebug>

Postacie::Postacie(int health, int aB, int armor, Dices* dices, TilePoint tp, GUI* gui)
{
    _health = health;
    _attackBonus = aB;
    _armor = armor;

    _dices = dices;
    _position = tp;
    _player = NULL;
    _gui = gui;
}

void Postacie::attack(Postacie* enemy)
{
    qInfo() << "Basic Postacie class attack function";
}

TilePoint Postacie::move()
{
    qInfo() << "Basic Postacie class move funtion";
}

void Postacie::attacked(int attackRoll, int dmg)
{
    if(!_block(attackRoll))
    {
        _gui->addToLogger("Zadano łącznie ", false);
        _gui->addToLogger(QString::number(dmg), true);
        _health = _health - dmg;
    }
}

bool Postacie::isAlive()
{
    if(_health <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

TilePoint Postacie::getPosition()
{
    return _position;
}

void Postacie::setPosition(TilePoint position)
{
    _position = position;
}

bool Postacie::_block(int attackRoll)
{
    if(attackRoll >= _armor)
    {
        _gui->addToLogger("Atak zablokowany", true);
        return false;
    }
    else
    {
        _gui->addToLogger("Blok nieudany", true);
        return true;
    }
}

Player* Postacie::getPlayer()
{
    return _player;
}
void Postacie::setPlayer(Player* player)
{
    _player = player;
}

int Postacie::getHealth()
{
    return _health;
}
