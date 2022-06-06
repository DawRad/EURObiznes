#ifndef CADMINISTRATORCRYS_H
#define CADMINISTRATORCRYS_H

#include <QList>

#include "Rysunki_h/cryspoleszansa.h"
#include "Rysunki_h/cryspolespec.h"
#include "Rysunki_h/cryspolestart.h"
#include "Rysunki_h/cryspole_pplusw.h"
#include "Rysunki_h/crysrog.h"
#include "Rysunki_h/cryspionek.h"
#include "Rysunki_h/crysprzyciskimg.h"
#include "Rysunki_h/cryskostki.h"

#include "Logika_h/cgame.h"





/**
 * @brief Klasa interfejs do zarządzania obiektami graficznymi
 */
class CAdministratorCRys
{

public:
    CAdministratorCRys();


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // porządkowanie deques

    /**
     *  \brief Ustawia pole o polu poz_ == 0 na początku kolejki.
     *
     * Założenie: pozycje pól w kolejce nie są pomieszane, są tylko przesunięte względem
     * indeksu zerowego kolejki.
     */
    static void przesunPolePozZeroNaPocz(deque<CRysPole *> *pola);

    static void aktualPensjeNaStart(deque<CRysPole *> *pola, int kwota, QString waluta);


    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // chodzenie po deques

    static void dequeIntPrzod(deque<int> &kolejka);

    static void dequeIntTyl(deque<int> &kolejka);

    static void dequeCRysPionekPrzod(deque<CRysPionek *> *pionki);

    static void dequeCRysPionekTyl(deque<CRysPionek *> *pionki);

    static void dequeCRysPolePrzod(deque<CRysPole *> *pola);

    static void dequeCRysPoleTyl(deque<CRysPole *> *pola);


    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // czyszczenie deques
    static void wyczyscDequeCRysPole(deque<CRysPole *> *deqPol);


    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // tworzenie rysunków pól na podstawie danych z pola gra_

    static CRysPoleStnd *utworzRysPolaStndZDnPol(const SDnPola &dane);
    static CRysPoleSpec *utworzRysPolaSpecZDnPol(const SDnPola &dane);
    static CRysPoleSzansa *utworzRysPolaSzansaZDnPol(const SDnPola &dane);
    static CRysPoleSzansa *utworzRysPolaKasaZDnPol(const SDnPola &dane);
    static CRysPoleStart *utworzRysPolaStartZDnPol(const SDnPola &dane, QString &waluta);
    static CRysPole_PplusW *utworzRysPola_PplusW_ZDnPol(const SDnPola &dane, QString &napis2);
    static CRysRog *utworzRysPolaRogZDnPol(const SDnPola &dane);
    static CRysPoleObraz *utworzRysPolaObrazZDnPol(const SDnPola &dane);
    static CRysPoleSzansa *utworzRysPolaZErroremZDnPol(const SDnPola &dane);

    static deque<CRysPole *> utworzKolejkePol(deque<SDnPola> &danePol);


    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // zamiana rysunków pól na pola innych klas
    static void zamienNaCRysPolaStnd(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene);
    static void zamienNaCRysPolaSpec(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene);
    static void zamienNaCRysPolaEkstra(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene);
    static void zamienNaCRysPolaSzansa(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene);
    static void zamienNaCRysPolaKasa(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene);
};

#endif // CADMINISTRATORCRYS_H
