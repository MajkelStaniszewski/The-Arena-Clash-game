#ifndef TILE_H
#define TILE_H

#include "TilePoint.h"
#include <QChar>
/*!
 * \brief Struktura Tile.
 * \details Struktura przechowująca informacje o tym jaki kafelek planszy to jest, w jakim miejscu oraz czy jest zajęty przez postać, czy nie.
 */
struct Tile
{
    /*!
     * \brief Punkt na mapie.
     */
    TilePoint point;
    /*!
     * \brief Symbol kafelka.
     */
    QChar tileSymbol;
    /*!
     * \brief Informacja o dostępności danego kafelka.
     */
    bool occupied;
};

#endif // TILE_H
