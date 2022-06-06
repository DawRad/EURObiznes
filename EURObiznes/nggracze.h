#ifndef NGGRACZE_H
#define NGGRACZE_H

#include <QMainWindow>

#include "cadministratorcrys.h"





namespace Ui {
class NGGracze;
}

/**
 * @brief Klasa graficzna - okno graczy
 */
class NGGracze : public QMainWindow
{
    Q_OBJECT

public:
    explicit NGGracze(CGame *gra, deque<CRysPionek *> *pionki, QWidget *parent = nullptr);
    ~NGGracze();

private:
    // metody do destruktora

    /**
     * \brief Metoda "odczepia" rysunki pionków od sceny tego okna
     *
     */
    void removingItemsFromScene();

    /**
     * \brief Metoda zmienia pola topLeft_ i size_ rysunków pionków na wartości "do planszy"
     *
     */
    void zmianaRozmiaruPionkowNaOstat();

    // metody do "chodzenia" po kolejkach

    void dequeIntPrzod(deque<int> &kolejka);

    void dequeIntTyl(deque<int> &kolejka);

    void dequeCRysPionekPrzod(deque<CRysPionek *> &pionki);

    void dequeCRysPionekTyl(deque<CRysPionek *> &pionki);

    // * * * * * * * * * *
signals:
    void wstecz();
    void dalej();

    // * * * * * * * * * *
private slots:
    void on_pbOknoWstecz_clicked();

    void on_pbDodGr_clicked();

    // * * * * * * * * * *
    void on_pbDalej_clicked();

    void on_pbWstecz_clicked();

    void on_pbDalej_2_clicked();

    void on_pbWstecz_2_clicked();

    void on_pbDalej_3_clicked();

    void on_pbWstecz_3_clicked();

    void on_pbDalej_4_clicked();

private:
    Ui::NGGracze *ui;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // wskaźniki pól MainWindow

    CGame *wskGry_;

    deque<CRysPionek *> *pionki_;

    CRysPionek *wskAktPionu_;

    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // pola tylko tej klasy

    QGraphicsScene *scene_;

    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // zakodowane opcje do wyboru

    deque<int> ksztalty_;
    deque<int> symbole_;
    deque<int> koloryPionow_;
    deque<int> koloryUzyte_;

    // * * * * * * * * * *

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // flagi okna

};

#endif // NGGRACZE_H
