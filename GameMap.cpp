#include "GameMap.h"
#include <QString>
#include <QVector>
#include <QtDebug>

QVector <QVector <Tile>>* GameMap::getMap()
{
    return &_gameMap;
}
void GameMap::generateMap()
{
    //Mapa 9x5
    QVector <QString> stringMap;
    QString row1 = "GGGGGGGGGG";
    QString row2 = "GGGGGGGGGG";
    QString row3 = "GGGGGGGGGG";
    QString row4 = "GGGGGGGGGG";
    QString row5 = "GGGGGGGGGG";
    QString row6 = "GGGGGGGGGG";

    stringMap.push_back(row1);
    stringMap.push_back(row2);
    stringMap.push_back(row3);
    stringMap.push_back(row4);
    stringMap.push_back(row5);
    stringMap.push_back(row6);

    for(int j = 0; j < _height; j++)
    {
        QVector <Tile> vecTmp;
        for(int i = 0; i < _width; i++)
        {
            Tile tileTmp;
            tileTmp.point.x = i;
            tileTmp.point.y = j;
            tileTmp.tileSymbol = stringMap[j].at(i);
            tileTmp.occupied = false;
            vecTmp.push_back(tileTmp);
        }
        _gameMap.push_back(vecTmp);
    }
}

void GameMap::printMap()
{
    for(int j = 0; j < _height; j++)
    {
        QString tmp = "";
        for(int i = 0; i < _width; i++)
        {
            tmp.append(_gameMap[j][i].tileSymbol);
            tmp.append(" ");
        }

    }
}

bool GameMap::isTileOccupied(TilePoint position)
{
    return _gameMap[position.y][position.x].occupied;
}

void GameMap::releaseTile(TilePoint position)
{
    _gameMap[position.y][position.x].occupied = false;
}

void GameMap::occupyTile(TilePoint position)
{
    _gameMap[position.y][position.x].occupied = true;
}

void GameMap::setWidth(int width)
{
    _width = width;
}

int GameMap::getHeight()
{
    return _height;
}

void GameMap::setHeight(int height)
{
    _height = height;
}

int GameMap::getWidth()
{
    return _width;
}


