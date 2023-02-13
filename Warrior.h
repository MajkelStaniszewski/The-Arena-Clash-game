#ifndef Warrior_H
#define Warrior_H

#include "Charakter.h"
#include "RPGDices.h"
#include "TilePoint.h"
#include "gui.h"
#include "Tile.h"
#include "GameMap.h"
#include <QVector>
/*!
 * \brief Klasa Warrior dziedzicząca po klasie Charakter.
 * \details Klasa Warrior dziedziczy po klasie Charakter, także może zostać użyta do umieszczenia na mapie.
 */
class Warrior : public Charakter
{
public:
    /*!
     * \brief Metoda określająca sposób atakowania klasy Warrior.
     * \param enemy - Wskaźnik na cel postaci.
     */
    void attack(Charakter* enemy);
    /*!
     * \brief Metoda, która określa sposób poruszania się klasy Warrior.
     * \return Pozycje, do której chce poruszyć się postać.
     */
    TilePoint move();
    /*!
     * \brief Konstruktor klasy Warrior
     * \param health - Poziom życia postaci.
     * \param BA - Bonus do ataku.
     * \param armor - Pancerz postaci.
     * \param dices - Wskaźnik do klasy Dice
     * \param tp -  Pozycja postaci na mapie.
     * \param gui - Wskaźnik do klasy GUI.
     */
    Warrior(int health, int BA, int armor, Dices* dices, TilePoint tp, GUI* gui, GameMap* map):
        Charakter(health, BA, armor, dices, tp, gui)
    {
        _gui = gui;
        _map = map;
    };

private:
    GUI* _gui;
    GameMap* _map;
    bool isInMap(TilePoint tile);
};

#endif // Warrior_H
