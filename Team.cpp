#include "Team.h"

Team::Team(QString name)
{
    _name = name;
}

void Team::add(Charakter* charakter)
{
    _charakters.push_back(charakter);
}

QVector <Charakter*> Team::getCharakter()
{
    return _charakters;
}

QString Team::getName()
{
    return _name;
}

bool Team::checkBelonging(Charakter* charakter)
{
    if(_charakters.contains(charakter))
    {
        return true;
    }
    return false;
}

bool Team::defeat()
{
    for(int i = 0; i < _charakters.size(); i++)
    {
        if(_charakters[i]->isAlive())
        {
            return false;
        }
    }
    return true;
}


