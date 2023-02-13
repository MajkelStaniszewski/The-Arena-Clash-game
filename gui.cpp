#include "gui.h"

#include <QPixmap>
#include <QGraphicsPixmapItem>

GUI::GUI()
{
    _logger.clear();
    _infoBar.clear();

    _scene = new QGraphicsScene();
}

GUI::~GUI()
{
    delete _scene;
}

QString GUI::tileFileName(QChar sign)
{
    if(sign == 'W')     return "D:\\warrior.png";
    if(sign == 'B')     return "D:\\bigben.png";
    if(sign == 'M')     return "D:\\mercenary.png";
    if(sign == 'G')     return "D:\\ground.jpg";
}
void GUI::showTiles(QVector <QVector <Tile>>* gameMap, int width, int height)
{
    QVector <QVector <Tile>> map = *gameMap;

    for(int j = 0; j < height; j++)
    {
        for(int i = 0; i < width; i++)
        {
            QPixmap tmp(32, 32);
            tmp.load(tileFileName(map[j][i].tileSymbol));
            QGraphicsPixmapItem* item = _scene->addPixmap(tmp);
            item->setPos(i * 96, j * 96);
            item->setScale(3);
        }
    }
}
void GUI::addCharakter(TilePoint pos, QChar sign)
{
    QPixmap tmp(32, 32);
    tmp.load(tileFileName(sign));
    QGraphicsPixmapItem* item = _scene->addPixmap(tmp);
    item->setPos(pos.x * 96, pos.y * 96);
    item->setScale(3);
}

QString GUI::getLogger()
{
    return _logger;
}
QString GUI::getInfoBar()
{
    return _infoBar;
}

void GUI::clearLogger()
{
    _logger.clear();
}
void GUI::clearInfoBar()
{
    _infoBar.clear();
}

void GUI::addToLogger(QString msg, bool endLine)
{
    _logger.append(msg);
    if(endLine)
    {
        _logger.append("\n");
    }
}
void GUI::addToInfoBar(QString msg, bool endLine)
{
    _infoBar.append(msg);
    if(endLine)
    {
        _infoBar.append("\n");
    }
}

QString GUI::getPosString(TilePoint tp)
{
    QString pointString;
    pointString.clear();
    pointString.append("(");
    pointString.append(QString::number(tp.x + 1));
    pointString.append(" ,");
    pointString.append(QString::number(tp.y + 1));
    pointString.append(")");
    return pointString;
}


QGraphicsScene* GUI::getScene()
{
    return _scene;
}

void GUI::clearScene()
{
    _scene->clear();
}


