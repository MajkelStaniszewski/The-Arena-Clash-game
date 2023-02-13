#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "Tile.h"
#include <QVector>
/*!
 * \brief Klasa GameMap.
 * \details Klasa GameMap zwalnia pozycje na mapie oraz zawiera mapę
 */
class GameMap
{
public:
    /*!
     * \brief Metoda generująca mapę.
     */
    void generateMap();

    /*!
     * \brief Metoda zwracająca informacje dostępności danej pozycji na mapie
     * \param position - Pozycja, która zostanie sprawdzona
     * \return False - jeżeli daną pozycję nie zajmuje postać, w przeciwnym wypadku True.
     */
    bool isTileOccupied(TilePoint position);

    /*!
     * \brief Metoda określająca, że dana pozycja zostanie zwolniona.
     * \param position - Pozycja, która zostanie zwolniona z postaci.
     */
    void releaseTile(TilePoint position);

    /*!
     * \brief Metoda określająca, że dana pozycja zostanie zajętą przez postać.
     * \param position - Pozycja, która zostanie zajęta przez postać.
     */
    void occupyTile(TilePoint position);

    /*!
     * \brief Metoda zwracająca szerokość mapy.
     * \return Szerokość mapy.
     */
    int getWidth();

    /*!
     * \brief Metoda ustaljąca szerokość mapy.
     * \param width - szerokość mapy.
     */
    void setWidth(int width);

    /*!
     * \brief Metoda zwracająca wysokość mapy.
     * \return Wysokość mapy.
     */
    int getHeight();

    /*!
     * \brief Metoda ustalająca wysokość mapy.
     * \param height - wysokość mapy
     */
    void setHeight(int height);
    /*!
     * \brief Metoda drukująca testową mapę w konsoli.
     */
    void printMap();
    /*!
     * \brief Metoda udostępniająca wskaźnik na całą mapę.
     * \return Wskaźnik na całą mapę.
     */
    QVector <QVector <Tile>>* getMap();

private:
    int _width;
    int _height;
    QVector <QVector <Tile>> _gameMap;
};

#endif // GAMEMAP_H
