#include "Charakter.h"
#include <QString>
#include <QDebug>

Charakter::Charakter(int health, int BA, int armor, Dices* dices, TilePoint tp, GUI* gui)
{
    _health = health;
    _attackBonus = BA;
    _armor = armor;

    _dices = dices;
    _position = tp;
    _player = NULL;
    _gui = gui;
}

void Charakter::attack(Charakter* enemy)
{
    // Metoda ataku do polimorfizmu
}

TilePoint Charakter::move()
{
    //Metoda poruszania do polimorfizmu
}

bool Charakter::_block(int attackRoll)
{
    if(attackRoll >= _armor)
    {
        _gui->addToLogger("Blok pomyślny", true);
        return false;
    }
    else
    {
        _gui->addToLogger("Blok nie powiódł się", true);
        return true;
    }
}

void Charakter::attacked(int attackRoll, int dmg)
{
    if(!_block(attackRoll))
    {
        _gui->addToLogger("Zadane obrażenia: ", false);
        _gui->addToLogger(QString::number(dmg), true);
        _health = _health - dmg;
    }
}

bool Charakter::isAlive()
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

TilePoint Charakter::getPosition()
{
    return _position;
}

void Charakter::setPosition(TilePoint position)
{
    _position = position;
}

Player* Charakter::getPlayer()
{
    return _player;
}
void Charakter::setPlayer(Player* player)
{
    _player = player;
}

int Charakter::getHealth()
{
    return _health;
}


