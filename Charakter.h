#ifndef CHARAKTER_H
#define CHARAKTER_H
#include "RPGDices.h"
#include "Tile.h"
#include "TilePoint.h"
#include "Vector(Player).h"
#include "gui.h"
#include <QVector>

/*!
 *  \brief Bazowa klasa Charakter
 *  \details Charakter jest klasą bazową wszystkich postaci znajdujących się na mapie.
 *  W klasie znajdują się podstawowe parametry każdej postaci np. życie, pozycja na mapie, bonusy do ataku oraz obrony.
 */
class Charakter
{
public:
    /*!
     * \brief Konstruktor
     * \details Konstruktor przyjmuje wszystkie parametry dla postaci takie jak życie, pozycja na mapie, bonusy do ataku oraz obrony.
     * Także przez ten konstruktor przypisuje się wskaźniki do klasy gui oraz kości.
     * \param health - Poziom życia postaci.
     * \param BA - Bonus do ataku.
     * \param armor - Pancerz postaci.
     * \param dices - Wskaźnik do klasy Dice
     * \param tp -  Pozycja postaci na mapie.
     * \param gui - Wskaźnik do klasy GUI.
     */
    Charakter(int health, int BA, int armor, Dices* dices, TilePoint tp, GUI* gui);

    /*!
      * \brief Wirtualna metoda stosowana do atakowania pozostałych postaci.
      * \param enemy - Wskaźnik na postać, która ma być zaatakowana.
      */
    void virtual attack(Charakter* enemy)=0;
    /*!
     * \brief Wirtualna metoda określająca sposobu przemieszczania sie na mapie.
     * \return Metoda ta zwraca punkt na mapie, do którego dana postać chce przejść.
     */
    TilePoint virtual move()=0;

    /*!
     * \brief Metoda sprawdzająca, czy dana postać otrzyma obrażenia.
     * \param attackRoll - Rzut, który porównywany jest z pancerzem postaci.
     * \param dmg - obrażenia, które postać otrzyma.
     */
    void attacked(int attackRoll, int dmg);

    /*!
     * \brief Metoda sprawdzająca, czy dana postać poległa.
     * \return Metoda zwraca false gdy postać ma poniżej 0 punktóW życia, a w przeciwnym przypadku true.
     */
    bool isAlive();

    /*!
     * \brief Metoda zwracająca aktualną pozycję postaci na mapie.
     * \return Aktualna pozycja postaci.
     */
    TilePoint getPosition();

    /*!
     * \brief Metoda ustawiająca aktualną pozycję postaci na mapie.
     * \param Pozycja, na której dana postać ma się znaleźć.
     */
    void setPosition(TilePoint position);

    /*!
     * \brief Metoda zwracająca wskaźnik na klasę Player.
     * \return Wskaźnik klasy Player.
     */
    Player* getPlayer();
    /*!
     * \brief Metoda umożliwająca sterowanie postacią za pomocą wskaźnika na klasę Player.
     * \param Wskażnik klasy Player.
     */
    void setPlayer(Player* player);

    /*!
     * \brief Metoda zwracająca aktualny poziom życia postaci.
     * \return Aktualny poziom życia.
     */
    int getHealth();

protected:
    /*!
     * \brief Metoda zwracająca informacje pomyślnego zablokowania ataku.
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

#endif // CHARAKTER_H
