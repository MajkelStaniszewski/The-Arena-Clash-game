#ifndef RPGDICES_H
#define RPGDICES_H

#include <QMap>
#include <QRandomGenerator>
#include <QString>
/*!
 * \brief Klasa Dices
 * \details Klasa Dices generująca wyniki rzutów różnościennych kości.
 * Klasa zawiera standartowe kości do gier RPG: d4, d6, d8, d10, d12, d20, d100.
 */
class Dices
{
public:
    /*!
     * \brief Konstruktor klasy Dices
     */
    Dices();
    /*!
     * \brief Metoda zwracająca wynik rzutu wirtualną kością różnościenną.
     * \param Nazwa kości poprzedzonej literą 'd' od dice.
     * \return Wynik na kości.
     */
    int diceRoll(QString name);
private:
    QMap<QString, int> _dicesMap;
    QRandomGenerator _numberGenerator;
};

#endif // RPGDICES_H
