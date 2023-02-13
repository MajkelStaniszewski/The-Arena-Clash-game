#ifndef TEAM_H
#define TEAM_H

#include "Charakter.h"

#include <QString>
#include <QVector>
/*!
 * \brief Klasa Team.
 * \details Klasa Team przechowująca drużyny, która może się składać z wielu lub jednej postaci.
 * Drużyna przegrywa, gdy wszystkie postacie danej drużyny osiągną zerowy poziom życia.
 */
class Team
{
public:
    /*!
     * \brief Konstruktor
     * \param Nazwa drużyny.
     */
    Team(QString name);
    /*!
     * \brief Metoda odpowiedzialna za dodanie postaci do drużyny
     * \param Wskaźnik dodanej postaci.
     */
    void add(Charakter* charakter);
    /*!
     * \brief Metoda zwracają informację porażki, bądż zwycięstwa danej drużyny.
     * \return Informacja true - drużyna została pokonana, a w przeciwnym wypadku false.
     */
    bool defeat();
    /*!
     * \brief Sprawdzenie, czy dana postać znajduje się w tej drużynie.
     * \param Wskaźnik sprawdzanej postaci.
     * \return True, jeżeli należy oraz false w przeciwnym wypadku.
     */
    bool checkBelonging(Charakter* charakter);
    /*!
     * \brief Pobranie nazwy drużyny.
     * \return Nazwa drużyny.
     */
    QString getName();
    /*!
     * \brief Metoda zwracająca wskaźniki wszystkich postaci w drużynie.
     * \return QVector ze wskaźnikami wszystkich postaci w drużynie.
     */
    QVector <Charakter*> getCharakter();

private:
    QString _name;
    QVector <Charakter*> _charakters;
};

#endif // TEAM_H
