#ifndef CGRACZ_H
#define CGRACZ_H

#include <iostream>
#include <ctime>
#include "Logika_h/Stale.h"
#include "Consts.h"
#include "Logika_h/Struktury.h"




/**
 * @brief Klasa logiki.
 */
class CGracz
{
protected:
    /// numer id gracza = numer w kolejce
    int id_;

    /// nick gracza
    string nick_;

    /// zasoby gracza
    int portfel_;

    /// pozycja na planszy, na której gracz aktualnie się znajduje
    int aktPoz_;

    /// pozycja na planszy, na którą gracz ma przejść po rzucie kośćmi
    int nastPoz_;

    /// liczba pól CPoleSpec posiadanych przez gracza
    int lbPolSpec_;

    /// liczba pól CPoleStnd, które posiada gracz, wg koloru
    deque<int> lbPolKol_;               // numer elementu to nr koloru

    /// liczba pól CPoleEkstra, które posiada gracz
    int lbPolEkstra_;

    /// liczba kart "wolność" posiadanych przez gracza
    int lbKartWolnosc_;

    /// liczby oczek na pierwszej i drugiej kostce wyrzucone przez gracza
    SWynAkcji kostka_;

public:
    CGracz();
    CGracz(SDnGracza parDane);
    virtual ~CGracz();

    // <--------------------> deklaracje funkcji wirtualnych <-------------------->

    /**
     * \brief Funkcja służy do zidentyfikowania klasy obiektu.
     *
     */
    virtual string przedstawSie() = 0;

    /**
     * \brief Funkcja zwraca wartość rzutu podwójnymi kośćmi przez gracza.
     *
     * @return Zwraca wartość dla obu kości.
     */
    virtual SWynAkcji rzucKoscmi() = 0;

    /**
     * \brief Funkcja zwracająca decyzję gracza dotycząca pola, na którym stanął.
     *
     * @param stan - stan pola, na którym stanął gracz:
     * \li 0 - wolne
     * \li 1 - zajęte
     * \li 2 - zastawione
     * @param kwota - jest to, w zależności od stanu pola, koszt jego kupna, budowy nieruchomości albo wykupienia z zastawu.
     * @param lbPol - parametr podawany w przypadku pól standardowych - mówi o liczbie posiadanych przez gracza pól koloru, jaki odpowiada polu, na którym gracz aktualnie się znajduje
     * @return Zwraca zgodę na wykonanie akcji (1) albo jej brak (0).
     */
    virtual int decyduj(int stan, int kwota, int lbPol) = 0;

    // <--------------------> <--------------------> <-------------------->

    /**
     * \brief Zmienia wartość pola nastPoz_ w przypadku, gdy ruch gracza jest inicjowany w sposób inny niż rzut kostką
     *
     * @param poz Wskazuje liczbę pól, o jaką gracz ma się przemieścić (może być ujemny - ruch w tył - albo dodatni - ruch do przodu).
     */
    void ruch(int poz);        

    /**
     * zwiększa o jeden wartość atrybutu CGracz wskazującego liczbę posiadanych przez gracza pól danego rodzaju
     * @param opt wskazuje, jaki rodzaj pola ma zostać dodany:
     * \li opt.y1 == 0 ---> zwiększa wartość CGracz::lbPolSpec_
     * \li opt.y1 == 1 ---> zwiększa wartość CGracz::lbPolKol_ (opt.y2 wskazuje, który kolor)
     * \li opt.y1 == 2 ---> zwiększa wartość CGracz::lbPolEkstra_
     */
    int dodajPole(SWynAkcji opt);

    void dodajKarteWolnosc();

    // funkcja służy do podania danych gracza
    SDnGracza podajDane();

    int podajId();

    /**
     * jeśli param rodz == 1  ---> podaje CGracz::lbPolSpec_
     * <br>param rodz == 2 ---> podaje CGracz::lbPolEkstra_
     */
    int podajLbPol(int rodz);

    int podajLbPolKol(int kolor);
    int podajLbKartWolnosc();
    int podajStanKonta();
    int podajAktPoz();
    int podajNastPoz();

    int podajSumeOczekKostki();
    SWynAkcji podajKostki();

    /**
     * \brief Zwraca zarówno aktualną, jak i następną pozycję.
     *
     */
    SWynAkcji podajPoz();

    string podajNick();

    void ustawPortfel(int kwotaPocz);

    void aktualPortfel(int kwota);

    void kupPole(int rodz);

    /**
     * \brief Przypisuje polu aktPoz_ wartość pola nastPoz_.
     *
     * Wywoływana po skończeniu przez gracza tury.
     */
    void aktualPozycje();

    void uzyjWolnosc();
    void idzDoWiezienia();
    void wyjdzZWiezienia();
};

#endif // CGRACZ_H
