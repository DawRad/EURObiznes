#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H

#include <QMainWindow>

#include "cadministratorcrys.h"
#include "Rysunki_h/cryspanelgracza.h"
#include "Rysunki_h/crysinfo.h"
#include "wlasnosci.h"





namespace Ui {
class Rozgrywka;
}


/**
 * @brief Klasa graficzna - okno rozgrywki
 *
 * Klasa ta zawiera metody potrzebne do przeprowadzenia wirtualnej rozgrywki
 */
class Rozgrywka : public QMainWindow
{
    Q_OBJECT

     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
    explicit Rozgrywka(CGame *wskGry, deque<CRysPole *> *wskDeqPol, deque<CRysPionek *> *wskPionkow, bool *wskEndGame, QWidget *parent = nullptr);
    ~Rozgrywka();

    void przygotujPolaDoRysowania();


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
    void ustawPozPol(int size);
    void ustawWymiaryPol(int size);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // akcje kart
    void akcjaKartyKwoty(SDnKarty dane);
    void akcjaKartyRuchu(SDnKarty dane);
    void akcjaKartyWiezienia();
    void akcjaKartyWolnosc();


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // metody do destruktora
    void czyszczenieDeques();


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
signals:
    void zacznijTureGracza();


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private slots:
    void on_pbNastRunda_clicked();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // moje sloty
    void actionWyjscieClicked();

    void rzutWykonany();

    void nastRuchPiona(int aktPozPola, int nastPozPola);

    void pionNaCelu();

    void turaGracza();

    void usunInfo();


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void on_pbKostki_clicked();

    void on_pbUwolnij_clicked();

    void on_pbKup_clicked();

    void on_pbWlasnosci_clicked();

private:
    Ui::Rozgrywka *ui;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // wskaźniki z MainWindow
    CGame *wskGry_;

    deque<CRysPole *> *wskDeqPol_;

    deque<CRysPionek *> *wskPionki_;

    bool *wskEndGame_;

    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // pola tej klasy

    QGraphicsScene *scenePlansza_;
    QGraphicsScene *scenePanelGracza_;

    CRysPanelGracza *panelGracza_;
    CRysInfo *info_;

    // timery
    QTimer *timerPrime_;
    QTimer *timerInfo_;

    // nadawcy
    CNadawca *wyzwalacz_;

    // kostki
    deque<CRysKostki *> *kostki_;

    // wymiary pol i planszy
    int wymiarA_;               // wymiar pola
    int wymiarB_;               // wymiar pola
    int wymiarPlanszy_;

    // aktualna karta
    SDnKarty aktKarta_;

    // okna poboczne
    Wlasnosci *oknoWlasnosci_;


};

#endif // ROZGRYWKA_H
