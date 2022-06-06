#ifndef NGPLANSZA_H
#define NGPLANSZA_H

#include <QMainWindow>

#include "cadministratorcrys.h"





namespace Ui {
class NGPlansza;
}


/**
 * @brief Klasa graficzna - okno planszy
 */
class NGPlansza : public QMainWindow
{
    Q_OBJECT

public:
    explicit NGPlansza(CGame *wskGry, deque<CRysPole *> *pola, QWidget *parent = nullptr);
    ~NGPlansza();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

    int odczytajKolor(const QString &kolor);

    /**
     * \brief Dostosowuje elementy okna planszy do wartości w cbRodzaj
     *
     */
    void dostosujDoCBRodzaj(const QString &arg1);

    void dostosujKolor(const QString &arg1);

    /**
     * \brief Włącza wszystkie pola służące do wprowadzania danych.
     *
     */
    void setInputObjectsEnabled();

    void setInputObjectsDisabled();

    // metody do tworzenie odpowiednich rodzajów pól

    void utworzCPoleSzansa(SDnPoczPola &dane);

    void utworzCPoleKasa(SDnPoczPola &dane);

    void utworzCPoleStnd(SDnPoczPola &dane);

    void utworzCPoleSpec(SDnPoczPola &dane);

    void utworzCPoleEkstra(SDnPoczPola &dane);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // metody do destruktora

    /**
     * \brief "Odczepia" elementy ze sceny
     *
     */
    void removeItemsFromScene();


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
signals:
    void dalej();


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private slots:    

    void on_cbRodzaj_currentTextChanged(const QString &arg1);    

    void on_pbDodPole_clicked();

    void on_pbWstecz_clicked();

    void on_pbDalej_clicked();

    void on_pbGraj_clicked();

    void on_cbKolor_currentTextChanged(const QString &arg1);

private:
    Ui::NGPlansza *ui;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // wskaźniki pól MainWindow

    CGame *wskGry_;

    deque<CRysPole *> *wskDeqPol_;

    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // pola tylko tej klasy

    QGraphicsScene *scene_;
    QGraphicsScene *sceneKolor_;
    //QBrush brush;
};

#endif // NGPLANSZA_H
