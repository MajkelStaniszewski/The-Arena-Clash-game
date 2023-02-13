#include "RPGDices.h"


int Dices::diceRoll(QString name)
{
    int value = _dicesMap[name];

    return _numberGenerator.bounded(value) + 1;
}

Dices::Dices()
{
   _dicesMap.insert("d100", 100);
   _dicesMap.insert("d20", 20);
   _dicesMap.insert("d12", 12);
   _dicesMap.insert("d10", 10);
   _dicesMap.insert("d8", 8);
   _dicesMap.insert("d6", 6);
   _dicesMap.insert("d4", 4);
}
