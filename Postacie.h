#ifndef POSTACIE_H
#define POSTACIE_H

#include "Dices.h"
#include "Tile.h"
#include "TilePoint.h"
#include "Player.h"
#include "gui.h"

#include <QVector>


/*!
 *  \brief Bazowa klasa Postacie
 *  \details Postacie jest to bazowa klasa dla wszystkich postaci znajdujących się na planszy.
 *  W klasie znajdują się podstawowe parametry każdej postaci takie jak życie czy bonusy do ataku i obrony.
 */
class Postacie
{
public:
    /*!
     * \brief Konstruktor
     * \details Konstruktor przyjmuje wszystkie wymagane paramtery dla postaci takie jak życie, bonusy do ataku i obrony czy pozycja na mapie.
     * Również przez konstruktor przypisuje się wskaźniki do klasy z kośćmi, czy do gui.
     * \param health - Określa życie postaci.
     * \param aB - Określa bonus do ataku.
     * \param armor - Określa pancerz.
     * \param dices - Wskaźnik do klasy Dice
     * \param tp - Obecna pozycja postaci.
     * \param gui - Wskaźnik do klasy GUI.
     */
    Postacie(int health, int aB, int armor, Dices* dices, TilePoint tp, GUI* gui);

    /*!
     * \brief Wirtualna metoda dotycząca do atakowania pozostałych postaci.
     * \param enemy - Wskaźnik na postać, która ma być zaatakowana.
     */
    void virtual attack(Postacie* enemy);
    /*!
     * \brief Wirtualna metoda dotycząca do określenia sposobu poruszania sie na mapie.
     * \return Metoda zwraca punkt na mapie, do którego postać chce przejść.
     */
    TilePoint virtual move();

    /*!
     * \brief Metoda sprawdzająca, czy postać otrzyma obrażenia.
     * \param attackRoll - Rzut, który porównywany jest z pancerzem postaci.
     * \param dmg - możliwe obrażenia, które postać otrzyma.
     */
    void attacked(int attackRoll, int dmg);
    /*!
     * \brief Metoda sprawdzająca, czy postać nadal żyje.
     * \return Gdy postać ma powyżej 0 punktów życia to funkcja zwraca true, w przeciwnym wypadku false.
     */
    bool isAlive();

    /*!
     * \brief Metoda zwracająca obecną pozycję postaci.
     * \return Obecna pozycja postaci.
     */
    TilePoint getPosition();
    /*!
     * \brief Metoda ustawiająca obecną pozycję postaci.
     * \param Pozycja postaci, na której ma się znaleźć.
     */
    void setPosition(TilePoint position);

    /*!
     * \brief Metoda zwracająca wskaźnik na klasę Player.
     * \return Wskaźnik klasy Player.
     */
    Player* getPlayer();
    /*!
     * \brief Metoda ustawiająca wskaźnik na klasę Player. Dzięki czemu jest możliwe sterowanie postacią.
     * \param player - Wskażnik klasy Player.
     */
    void setPlayer(Player* player);

    /*!
     * \brief Metoda zwracająca obecną ilość życia postaci.
     * \return Obecna ilość życia.
     */
    int getHealth();

protected:
    /*!
     * \brief Metoda zwracająca informacje, czy udało się zablokować atak, czy nie.
     * \param attackRoll - wartość ataku przeciwnika.
     * \return True, jeżeli blok się udał, w przeciwnym wypadku False.
     */
    bool _block(int attackRoll);

    /*!
     * \brief Życie postaci.
     */
    int _health;
    /*!
     * \brief Bonus do ataku.
     */
    int _attackBonus;
    /*!
     * \brief Pancerz postaci.
     */
    int _armor;

    /*!
     * \brief Wskaźnik do klasy Dice.
     */
    Dices* _dices;
    /*!
     * \brief Pozycja postaci.
     */
    TilePoint _position;
    /*!
     * \brief Wskaźnik do klasy Player.
     */
    Player* _player;
    /*!
     * \brief Wskaźnik do klasy GUI.
     */
    GUI* _gui;
};

#endif // POSTACIE_H
