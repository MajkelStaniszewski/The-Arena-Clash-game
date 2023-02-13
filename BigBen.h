#ifndef BIGBEN_H
#define BIGBEN_H

#include "Charakter.h"
#include "RPGDices.h"
#include "TilePoint.h"
#include "gui.h"
#include <QVector>

/*!
 * \brief Klasa BigBen dziedzicząca po klasie Charakter.
 * \details Klasa BigBen jest pochodną klasy Charakter,także może zostać użyta do umieszczenia na mapie.
 */
class BigBen : public Charakter
{
public:
    /*!
     * \brief Konstruktor klasy BigBen
     * \param health - Poziom życia postaci.
     * \param BA - Bonus do ataku.
     * \param armor - Pancerz postaci.
     * \param dices - Wskaźnik do klasy Dice
     * \param tp -  Pozycja postaci na mapie.
     * \param gui - Wskaźnik do klasy GUI.
     */
    BigBen(int health, int BA, int armor, Dices* dices, TilePoint tp, GUI* gui):
        Charakter(health, BA, armor, dices, tp, gui)
    {
        _gui = gui;
    };

    /*!
     * \brief Metoda, która określa sposób atakowania klasy BigBen.
     * \param enemy - Wskaźnik na cel postaci.
     */
    void attack(Charakter* enemy);
    /*!
     * \brief Metoda, która określa sposób poruszania się klasy BigBen.
     * \return Pozycje, do której chce poruszyć się postać.
     */
    TilePoint move();
    /*!
     * \brief Metoda ustawiająca AI, aby mógł obliczyć swój następny ruch
     * \param enemies - QVector wszystkich przeciwników, których Ai musi pokonać.
     */
    void setAi(QVector <Charakter*> enemies);

private:
    TilePoint _Ai(QVector <Charakter*> enemies);
    int _enemyDistance(TilePoint enemyPoint, TilePoint attackerPoint);
    void _setTarget(TilePoint target);

    TilePoint _target;
    GUI* _gui;

    QVector <Charakter*> _enemies;
};

#endif // BIGBEN_H
