#ifndef GUI_H
#define GUI_H

#include "TilePoint.h"
#include "Tile.h"
#include <QGraphicsScene>
#include <QString>
#include <QChar>
/*!
 * \brief Klasa Gui
 */
class GUI
{
public:
    /*!
     * \brief Konstruktor
     */
    GUI();
    /*!
     * \brief Destruktor
     */
    ~GUI();
    /*!
     * \brief Wyczyszczenie loggera.
     */
    void clearLogger();
    /*!
     * \brief Wyczyszczenie informatora.
     */
    void clearInfoBar();
    /*!
     * \brief Dodanie informazji do loggera.
     * \param msg - Informacja, która zostanie dodana.
     * \param endLine - Parametr określający, czy nie dodawać znaku końca linii - false albo tak - true.
     */
    void addToLogger(QString msg, bool endLine);
    /*!
     * \brief Dodanie frazy do informatora.
     * \param msg - Informacja, która zostanie dodana.
     * \param endLine - Parametr określający, czy nie dodawać znaku końca linii - false albo tak - true.
     */
    void addToInfoBar(QString msg, bool endLine);
    /*!
     * \brief Metoda tworząca mapę w okienku aplikacji.
     * \param gameMap - Wszystkie kafelki mapy.
     * \param width - Szerokość mapy.
     * \param height - Wysokość mapy.
     */
    void showTiles(QVector <QVector <Tile>>* gameMap, int width, int height);
    /*!
     * \brief Metoda dodająca postacie na mapę, która zostaje wyświetlona w okienku aplikacji.
     * \param pos - Pozycja postaci.
     * \param sign - Znak postaci określająca klasę postaci pochodnej.
     */
    void addCharakter(TilePoint pos, QChar sign);
    /*!
     * \brief Wyczyszczenie sceny w okienku aplikacji.
     */
    void clearScene();
    /*!
     * \brief Otrzymanie treści z loggera zawierającego wszystkie wydarzenia na mnapie
     * \return Treść loggera
     */
    QString getLogger();
    /*!
     * \brief Uzyskanie treści informacji o pozycji oraz życiu wszystkich postaci znajdujących się na mapie.
     * \return Treść informacji.
     */
    QString getInfoBar();
    /*!
     * \brief Uzyskanie ścieżki do grafiki reprezentujące konkretne znaki.
     * \param sign - Znak, który zostanie znaleziony w folderze z grafikami.
     * \return Ścieżka do pliku graficznego.
     */
    QString tileFileName(QChar sign);
    /*!
     * \brief Zamiana informacji pozycji na QString, która może zostać wpisana do informatora.
     * \param tp - Pozycja.
     * \return Zapis pozycji w współrzednych (x, y).
     */
    QString getPosString(TilePoint tp);
    /*!
     * \brief Metoda zwracające scene.
     * \return Qt Scena.
     */
    QGraphicsScene* getScene();



private:
    QString _logger;
    QString _infoBar;
    QGraphicsScene* _scene;
    QVector <QVector <Tile>> _gameMap;
};

#endif // GUI_H
