#ifndef VECTOR(PLAYER)_H
#define VECTOR(PLAYER)_H

#include "TilePoint.h"

/*!
 * \brief Klasa Player.
 * \details Klasa ta przechowuje wektor z kierunkiem, w który chciał poruszyć się gracz po wciśnięciu przycisku.
 */
class Player
{
public:
    /*!
     * \brief Metoda pobierająca wektor z kierunkiem
     * \return Wektor z kierunkiem.
     */
    TilePoint getDirection();
    /*!
     * \brief Metoda ustawiająca wektor z kierunkiem.
     * \param Wektor z kierunkiem.
     */
    void setDiretion(TilePoint newDirection);

private:
    TilePoint _direction;
};
#endif // VECTOR(PLAYER)_H
