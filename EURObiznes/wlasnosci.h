#ifndef WLASNOSCI_H
#define WLASNOSCI_H

#include <QMainWindow>

#include "cadministratorcrys.h"
#include "Logika_h/cgame.h"





namespace Ui {
class Wlasnosci;
}


/**
 * @brief Klasa graficzna - okno własności
 */
class Wlasnosci : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wlasnosci(CGame *wskGry, QWidget *parent = nullptr);
    ~Wlasnosci();      


private slots:
    void on_pbPoprz_clicked();

    void on_pbNast_clicked();

private:
    Ui::Wlasnosci *ui;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // wskaźniki z MainWindow

    CGame *wskGry_;

    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // pola tej klasy

    deque<SDnPola> danePolGracza_;

    deque<CRysPole *> rysunkiPol_;

    QGraphicsScene *scene_;

    // iteratory
    deque<CRysPole *>::iterator itPol_;
    deque<SDnPola>::iterator itDanychPol_;
};

#endif // WLASNOSCI_H
