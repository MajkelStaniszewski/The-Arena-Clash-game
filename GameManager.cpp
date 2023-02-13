#include "GameManager.h"
#include "Charakter.h"
#include "BigBen.h"
#include "Warrior.h"
#include "Mercenary.h"
#include "TilePoint.h"
#include <QtDebug>
#include <QtGlobal>

QGraphicsScene* GameManager::showMap()
{
    _gui.clearScene();
    _gui.showTiles(_gameMap.getMap(), _width, _height);
    _showCharakters();

    return _gui.getScene();
}
QString GameManager::getGuiLogger()
{
    return _gui.getLogger();
}

QString GameManager::getGuiInfo()
{
    return _gui.getInfoBar();
}

void GameManager::_showCharakters()
{
    for(int i = 0; i < _initiativeList.size(); i++)
    {
        Warrior* warrior = dynamic_cast<Warrior*>(_initiativeList[i]);
        Mercenary* mercenary = dynamic_cast<Mercenary*>(_initiativeList[i]);
        BigBen* bigBen = dynamic_cast<BigBen*>(_initiativeList[i]);

        if(warrior != NULL)
        {
            _gui.addCharakter(_initiativeList[i]->getPosition(), 'W');
        }
        if(mercenary != NULL)
        {
            _gui.addCharakter(_initiativeList[i]->getPosition(), 'M');
        }

        if(bigBen != NULL)
        {
            _gui.addCharakter(_initiativeList[i]->getPosition(), 'B');
        }
    }
}
void GameManager::startLevel()
{
    dynamic_cast <BigBen*>(_teams[1].getCharakter()[0])->setAi(_teams[0].getCharakter());
    _gui.clearInfoBar();

    _showHealth();
    _gameMap.printMap();

    emit showGui();
}

void GameManager::setPlayerDirection(TilePoint direction)
{
    _player.setDiretion(direction);
}

void GameManager::_removeDead()
{
    QVector <Charakter*> removing;

    for(int i = 0; i < _initiativeList.size(); i++)
    {
        if(!_initiativeList[i]->isAlive())
        {
            TilePoint deadCharakter = _initiativeList[i]->getPosition();
            _gameMap.releaseTile(deadCharakter);
            removing.push_back(_initiativeList[i]);
        }
    }

    for(int i = 0; i < removing.size(); i++)
    {
        _initiativeList.removeOne(removing[i]);
    }
}
GameManager::GameManager()
{
    _width = 10;
    _height = 6;

    _gameMap.setWidth(_width);
    _gameMap.setHeight(_height);

    listIteration = 0;
    _gameMap.generateMap();

    TilePoint tpWarrior1; tpWarrior1.x = 1; tpWarrior1.y = 1;
    _gameMap.occupyTile(tpWarrior1);
    Charakter* Warrior1 = new Warrior(130, 15, 13, &_dices, tpWarrior1, &_gui, &_gameMap);
    Warrior1->setPlayer(&_player);

    TilePoint tpMercenary1; tpMercenary1.x = 1; tpMercenary1.y = 4;
    _gameMap.occupyTile(tpMercenary1);
    Charakter* Mercenary1 = new Mercenary(110, 18, 8, &_dices, tpMercenary1, &_gui, &_gameMap);
    Mercenary1->setPlayer(&_player);

    TilePoint tpBigBen1; tpBigBen1.x = 7; tpBigBen1.y = 3;
    _gameMap.occupyTile(tpBigBen1);
    Charakter* BigBen1 = new BigBen(175, 25, 10, &_dices, tpBigBen1, &_gui);

    Team Alliance("Sojusz");
    Alliance.add(Warrior1);
    Alliance.add(Mercenary1);

    Team MasteroftheArena("Przeciwnik");
    MasteroftheArena.add(BigBen1);

    _teams.push_back(Alliance);
    _teams.push_back(MasteroftheArena);

    _initiativeList.push_back(Warrior1);
    _initiativeList.push_back(Mercenary1);
    _initiativeList.push_back(BigBen1);
}

GameManager::~GameManager()
{
    for(int i = 0; i < _initiativeList.size(); i++)
    {
        delete _initiativeList[i];
    }
}

void GameManager::turn()
{
    TilePoint nextMove = _initiativeList[listIteration]->move();
    bool hit = false;

    if(nextMove.x < 0 || nextMove.x >= _gameMap.getWidth())
    {
        qInfo() << "Próba ucieczki";
        _gui.addToLogger("Nie uciekaj, wracaj do walki!!", true);
        emit showGui();
        return;
    }
    if(nextMove.y < 0 || nextMove.y >= _gameMap.getHeight())
    {
        qInfo() << "Próba ucieczki";
        _gui.addToLogger("Nie uciekaj, wracaj do walki!!", true);
        emit showGui();
        return;
    }



    if(_gameMap.isTileOccupied(nextMove))
    {
        Charakter* charakter;

        for(int i = 0; i < _initiativeList.size(); i++)
        {
            int x = _initiativeList[i]->getPosition().x;
            int y = _initiativeList[i]->getPosition().y;

            if(nextMove.x == x && nextMove.y == y)
            {
                charakter = _initiativeList[i];
            }
        }

        bool controlCharakter = _teams[0].checkBelonging(_initiativeList[listIteration]);
        bool nextMoveCharakter = _teams[1].checkBelonging(charakter);

        if(controlCharakter == nextMoveCharakter)
        {
            _initiativeList[listIteration]->attack(charakter);
            hit = true;
        }
        else
        {
            _gui.addToLogger("Friendly fire jest wyłączone", true);
            emit showGui();
            return;
        }
    }

    if(!hit)
    {
        TilePoint currentPosition = _initiativeList[listIteration]->getPosition();
        _gameMap.releaseTile(currentPosition);
        _initiativeList[listIteration]->setPosition(nextMove);
        _gameMap.occupyTile(nextMove);
    }

    listIteration++;

    if(listIteration == _initiativeList.size())
    {
        listIteration = 0;
    }

    _showHealth();
    _gameMap.printMap();

    emit showGui();

    _removeDead();
    if(_teams[0].defeat())
    {
        _lose();
        return;
    }

    if(_teams[1].defeat())
    {
        _win();
        return;
    }

    if(_initiativeList[listIteration]->getPlayer() == NULL)
    {
        turn();
    }
}

void GameManager::_lose()
{
    _gui.addToLogger("Przegrana", true);
}

void GameManager::_win()
{
    _gui.addToLogger("Wygrana", true);
}

void GameManager::_showHealth()
{
    _gui.clearInfoBar();
    for(int i = 0; i < _teams.size(); i++)
    {
        _gui.addToInfoBar(_teams[i].getName(), false);
        _gui.addToInfoBar(":", true);
        _gui.addToInfoBar("", true);
        for(int j = 0; j < _teams[i].getCharakter().size(); j++)
        {
            QString tmp;
            Warrior* warrior = dynamic_cast<Warrior*>(_teams[i].getCharakter()[j]);
            Mercenary* mercenary = dynamic_cast<Mercenary*>(_teams[i].getCharakter()[j]);
            BigBen* bigBen = dynamic_cast<BigBen*>(_teams[i].getCharakter()[j]);

            if(warrior != NULL)
            {
                tmp.append("Warrior ");
                tmp.append(QString::number(j + 1));
                _gui.addToInfoBar(tmp, true);
                tmp.append(" Health: ");
                _gui.addToInfoBar("Punkty życia: ", false);
            }
            if(mercenary != NULL)
            {
                tmp.append("Mercenary ");
                tmp.append(QString::number(j + 1));
                _gui.addToInfoBar(tmp, true);
                tmp.append(" Health: ");
                _gui.addToInfoBar("Punkty życia: ", false);
            }

            if(bigBen != NULL)
            {
                tmp.append("BigBen ");
                tmp.append(QString::number(j + 1));
                _gui.addToInfoBar(tmp, true);
                tmp.append(" Health: ");
                _gui.addToInfoBar("Punkty życia: ", false);
            }

            _gui.addToInfoBar(QString::number(_teams[i].getCharakter()[j]->getHealth()), true);
            tmp.append(QString::number(_teams[i].getCharakter()[j]->getHealth()));

            _gui.addToInfoBar("(X,Y): ", false);
            TilePoint tp = _teams[i].getCharakter()[j]->getPosition();

            _gui.addToInfoBar(_gui.getPosString(tp), true);
            _gui.addToInfoBar("", true);

        }
    }
}




