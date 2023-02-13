#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Team.h"
#include "GameMap.h"
#include "RPGDices.h"
#include "Charakter.h"
#include "gui.h"
#include <QVector>
#include <QObject>
#include <QGraphicsScene>
/*!
 * \brief Klasa GameManager
 * \details Klasa GameManger jest mózgiem całego programu, dziedziczy po QObject, a to umożliwia równoległe działanie z oknem aplikacji oraz komunikację za pomocą sygnałów.
 * W klasie tej zawarte są wszystkie obiekty oraz wskaźniki są przesyłane do pozostałych klas
 */
class GameManager : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor.
     */
    GameManager();
    /*!
     * \brief Destruktor.
     */
    ~GameManager();
    /*!
     * \brief Metoda złączająca grę.
     */
    void startLevel();
    /*!
     * \brief Pobranie kierunku danego przez gracza za pomocą klawiszy w oknie aplikacji.
     * \param Wektor, w którą stronę porusza się postać.
     */
    void setPlayerDirection(TilePoint direction);
    /*!
     * \brief Pobranie loggera z obiektu GUI.
     * \return Logger z GUI.
     */
    QString getGuiLogger();
    /*!
     * \brief Pobranie informatora z obiektu GUI.
     * \return Informator z GUI.
     */
    QString getGuiInfo();
    /*!
     * \brief Przekazanie gotowej sceny do wyświetlenia przez okno użytkownika.
     * \return Scene z pakietu Qt.
     */
    QGraphicsScene* showMap();

signals:
    /*!
    * \brief Sygnał, który jest przesyłany do klasy mainwindow, aby był wstanie wyświetlić scene w okienku.
    */
    void showGui();
public slots:
    /*!
     * \brief Metoda, w której Wykonuje się tura danej postaci po otrzymaniu sygnału od okna, że gracz wykonał ruch.
     */
    void turn();

private:
    void _win();
    void _lose();
    void _removeDead();
    void _showHealth();
    void _showCharakters();

    Dices _dices;
    GameMap _gameMap;
    QVector <Team> _teams;
    Player _player;
    GUI _gui;
    QVector <Charakter*> _initiativeList;
    int listIteration;
    int _width;
    int _height;
};

#endif // GAMEMANAGER_H
