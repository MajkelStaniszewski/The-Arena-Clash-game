#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TilePoint.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _lm = new GameManager();
    _lm->moveToThread(&_lmThread);

    connect(this, &MainWindow::turn, _lm, &GameManager::turn);
    connect(_lm, &GameManager::showGui, this, &MainWindow::showGui);

    _lmThread.start();
    _lm->startLevel();
}

void MainWindow::on_upButton_clicked()
{
    TilePoint playerMove;
    playerMove.x = 0;
    playerMove.y = -1;
    _lm->setPlayerDirection(playerMove);
    emit turn();
}

void MainWindow::on_downButton_clicked()
{
    TilePoint playerMove;
    playerMove.x = 0;
    playerMove.y = 1;
    _lm->setPlayerDirection(playerMove);
    emit turn();
}

void MainWindow::on_rightButton_clicked()
{
    TilePoint playerMove;
    playerMove.x = 1;
    playerMove.y = 0;
    _lm->setPlayerDirection(playerMove);
    emit turn();
}

void MainWindow::on_leftButton_clicked()
{
    TilePoint playerMove;
    playerMove.x = -1;
    playerMove.y = 0;
    _lm->setPlayerDirection(playerMove);
    emit turn();
}

MainWindow::~MainWindow()
{
    _lmThread.quit();
    _lmThread.wait();
    delete _lm;
    delete _ui; 
}

void MainWindow::showGui()
{
    QString logger = _lm->getGuiLogger();
    QString infoBar = _lm->getGuiInfo();

    _ui->logger->clear();
    _ui->logger->append(_lm->getGuiLogger());
    _ui->charInfo->setPlainText(_lm->getGuiInfo());

    _ui->tileMap->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _ui->tileMap->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _ui->tileMap->setScene(_lm->showMap());
}
