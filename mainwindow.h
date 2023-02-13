#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GameManager.h"
#include "QThread"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief Klasa MainWindow dostarczona przez aplikacje Qt.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor MainWindow
     * \param parent - Wskaźnik na rodzica, który domyślnie jest pusty.
     */
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

signals:
    /*!
     * \brief Sygnał, który uruchamia turę w GameMangerz.
     */
    void turn();

private slots:
    /*!
     * \brief Metoda ta wyświetla grafikę w okienku po otrzymaniu sygnału od GameManagera
     */
      void showGui();
      /*!
       * \brief Metoda ta po naciśnięciu przycisku "up" wysyła wektor odpowiadający za ruch postaci w górę, a takżę sygnał, że gracz wykonał turę.
       */
    void on_upButton_clicked();
    /*!
     * \brief Metoda ta po naciśnięciu przycisku "down" wysyła wektor odpowiadający za ruch postaci w dół, a takżę sygnał, że gracz wykonał turę.
     */
    void on_downButton_clicked();
    /*!
     * \brief Metoda ta po naciśnięciu przycisku "right" wysyła wektor odpowiadający za ruch postaci w prawo, a takżę sygnał, że gracz wykonał turę.
     */
    void on_rightButton_clicked();
    /*!
     * \brief Metoda ta po naciśnięciu przycisku "left" wysyła wektor odpowiadający za ruch postaci w lewo, a takżę sygnał, że gracz wykonał turę.
     */
    void on_leftButton_clicked();
private:
    Ui::MainWindow *_ui;
    GameManager *_lm;
    QThread _lmThread;
};
#endif // MAINWINDOW_H
