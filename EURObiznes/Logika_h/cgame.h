#ifndef CGAME_H
#define CGAME_H

#include <fstream>

#include "Logika_h/cgracz.h"
#include "Logika_h/cplansza.h"

using std::ifstream;





/**
 * \mainpage
 * \par Cyfrowa wersja gry planszowej \a EURObiznes
 * Program zawiera zaimplementowaną wersję na komputer podanej gry planszowej
 * \author Dawid Radłowski
 * \date 2022.02.02
 * \version 1.0
 */





/**
 * @brief Klasa logiki.
 */
class CGame
{
private:
    /// Wartość pieniędzy, jaką gracze mają na początku gry
    int *kwotaPocz_;

    /// Określa maksymalną liczbę graczy w grze
    int *lbGraczy_;

    /// Lista dwukierunkowa graczy
    deque <CGracz*> gracze_;    

    /// Obiekt planszy
    CPlansza *plansza_;

    /// Lista dwukierunkowa graczy przegranych
    deque<CGracz*> przegrani_;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
    CGame();
    ~CGame();

    /**
     * @brief Ustawia początkowe wartości pól *CGame::kwotaPocz_, *CGame::lbGraczy_ oraz CPlansza::pensjaStart_.
     * @param lbGraczy - maksymalna liczba graczy
     * @param kwotaPocz - początkowa ilość pieniędzy graczy
     * @param pensja - wartość pensji pola "START"
     */
    void utworzGre(int lbGraczy, int kwotaPocz, int pensja);

    /**
     * @brief Ustawia początkowe wartości pól *CGame::kwotaPocz_ oraz CPlansza::pensjaStart_.
     * @param kwotaPocz - początkowa ilość pieniędzy graczy
     * @param pensja - wartość pensji pola "START"
     */
    void utworzGre(int kwotaPocz, int pensja);

    void wczytajPolaZPliku(string nazPli);

    /**
     * @brief Tworzy pola planszy według danych pobranych z pliku.
     *
     * Dane są w postaci łańcuchów \a string. Każdy element listy \a daneZPliku
     * to z założenia 1 linijka tekstu z pliku.
     * @param daneZPliku - dwukierunkowa lista łańcuchów \a string pobranych z pliku
     */
    void wczytajPolaZPliku(deque<string> &daneZPliku);

    /**
     * @brief Tworzy karty planszy według danych pobranych z pliku.
     *
     * Dane są w postaci łańcuchów \a string. Każdy element listy \a daneZPliku
     * to z założenia 1 linijka tekstu z pliku.
     * @param daneZPliku - dwukierunkowa lista łańcuchów \a string pobranych z pliku
     */
    void wczytajKartyZPliku(deque<string> &daneZPliku);

    /**
     * @brief Tworzy obiekt klasy CCzlowiek.
     *
     * @param dane - dane gracza
     */
    void utworzCz(SDnGracza dane);

    /**
     * @brief Tworzy obiekt klasy CKomputer.
     * @param dane - dane gracza
     */
    void utworzKomp(SDnGracza dane);

    /**
     * \brief Metoda najpierw aktualizuje wartości kwoty początkowej i pensji, a potem uaktualnia je w planszy i u graczy.
     *
     */
    void aktualDnPocz(int kwotaPocz, int pensja);

    /**
     * @brief Losuje kolejność graczy w kolejce.
     */
    void utworzKolejke();

    /**
     * \brief Metoda sprawdza czy kolejka graczy ma odpowiednią długość.
     *
     */
    bool wypelnienieKolejkiGraczy();

    /**
     * @brief nowePole Dodaje nowe pole na podanej pozycji
     *
     * Usuwa również pole pierwotnie znajdujące się na danej pozycji.
     * @param rodz - określa klasę nowego pola:
     * \li 0 - CPoleSpec
     * \li 1 - CPoleStnd
     * \li 2 - CPoleEkstra
     * \li 3 - CPoleDoWiezienia
     * \li 4 - CPoleKasa
     * \li 5 - CPoleSzansa
     * \li 6 - CPole
     * @param dane - dane nowego pola
     */
    void nowePole(int rodz, SDnPoczPola dane);

    /**
     * @brief Przesuwa kolejkę graczy.
     *
     * Gracz, który już wykonał ruch trafia na koniec listy.
     */
    void nastepny();

    /**
     * @brief Zwraca wartość identyfikującą rodzaj gracza.
     *
     * Łańcuch \a string wskazuje czy gracz to CCzlowiek czy CKomputer.
     * Bierze pod uwagę pierwszego gracza w liście CGame::gracze_.
     * @return
     * \li "cz" dla klasy CCzlowiek
     * \li "komp" dla CKomputer
     */
    string identGracza();

    /**
     * @brief Zwraca wartość identyfikującą rodzaj gracza.
     *
     * Działa analogicznie jak metoda identGracza(), z tą różnicą, że szuka
     * gracza o podanym id.
     * @param parId - wartość pola CGracz::id_, która jest szukana
     * @return Analogicznie jak w identGracza().
     */
    string identGracza(int parId);

    /**
     * \brief Metoda sprawdza, czy w kolejce nie pozostał ostatni gracz.
     *
     * Jeśli tylko jeden gracz pozostał w grze zwraca wartość true.
     */
    bool czyOstatniGrajacy();

    /**
     * \brief Sprawdza, czy gracz wykonujący aktualnie ruch, jest pierwszy w kolejce.
     *
     * Jeśli pole CGracz::id_ gracza jest równe 0 zwraca wartość true.
     */
    bool czyPierwszyZKolejki();

    /**
     * \brief Sprawdza, czy gracz jest uwięziony.
     *
     */
    bool czyUwieziony();

    /**
     *  \brief Informuje o tym, czy gracz posiada jakąś kartę "Wolność".
     *
     */
    bool czyGraczMaKartyWolnosc();

    /**
     * @brief Określa, czy grać może kupić pole.
     *
     * Sprawdzane jest pole, na które wskazuje atrybut CGracz::aktPoz_.
     * @return \a True, jeżeli gracza stać albo \a false jeżeli nie.
     */
    bool czyGraczaStacNaZakupPola();

    /**
     * @brief Określa, czy grać może zapłacić czynsz pola.
     *
     * Sprawdzane jest pole, na które wskazuje atrybut CGracz::aktPoz_.
     * @return \a True, jeżeli gracza stać albo \a false jeżeli nie.
     */
    bool czyGraczaStacNaCzynsz();

    /**
     * @brief Określa, czy grać może zapłacić podaną kwotę.
     *
     * @param kwota - wartość, którą gracz musi zapłacić
     * @return \a True, jeżeli gracza stać albo \a false jeżeli nie.
     */
    bool czyGraczaStacNaZaplate(int kwota);

    /**
     * \brief Zwraca wartość identyfikującą rodzaj i stan pola, na którym
     * staje gracz.
     *
     * Najpierw aktualizowana jest aktualna pozycja gracza (po rzucie kośćmi).
     * @return Pole SWynAkcji.y1 zwracanej struktury to rodzaj pola, a SWynAkcji.y2 to jego stan.
     * \see CPlansza::identPole(CGracz *gracz, int parPoz)
     */
    SWynAkcji graczStajeNaPolu();

    /**
     * @brief Zwraca wartość identyfikującą rodzaj i stan pola, na którym
     * staje gracz.
     *
     * Analogicznie do graczStajeNaPolu() tylko nie szuka pola odpowiadającego
     * polu CGracz::aktPoz_, ale pola o podanej pozycji.
     * @param poz - pozycja na planszy szukanego pola
     * @return Pole SWynAkcji.y1 zwracanej struktury to rodzaj pola, a SWynAkcji.y2 to jego stan.
     * \see CPlansza::identPole(CGracz *gracz, int parPoz)
     */
    SWynAkcji graczStajeNaPolu(int poz);

    /**
     * \brief Przemieszcza gracza na inne pole (poprzez zmianę następnej pozycji).
     *
     * Metoda używana w przypadku, gdy gracz zmienia pole w wyniku akcji karty ruchu.
     * W zależności od liczby kroków cofa się albo przesuwa naprzód.
     *
     * @param lbKrokow - wskazuje o ile pól zmienia się pozycja gracza (może być dodatnia - ruch do przodu - lub ujemna - ruch w tył)
     */
    void graczZmieniaPole(int lbKrokow);

    int graczDecyduje(SWynAkcji wynik, int poz, int kolor);

    /**
     * \brief Zwraca wartość mówiącą o tym, jaki jest wynik rzutu kośćmi.
     *
     * @return
     * \li SWynAkcji.y1 zwracanej struktury to kość pierwsza
     * \li SWynAkcji.y2 to kość druga
     */
    SWynAkcji graczRzuca();

    void graczKupuje();
    void graczBuduje(int poz);
    void graczZastawia(int poz);
    void graczWykupuje(int poz);
    void graczPlaciCzynsz();
    void graczZarabia(int kwota);
    void graczPobieraPensje();
    SDnKarty graczLosujeKarte();
    void graczUzywaKartyWolnosc();
    void aresztuj();
    void uwolnij();

    /**
     * \brief Sprawdza czy wartość portfela gracza na pozycji 0 w deque CGame::gracze_ nie jest ujemna.
     *
     */
    bool sprawdzPortfel();

    /**
     * \brief Sprawdza czy wartość portfela gracza na pozycji 0 w deque CGame::gracze_ jest co najmniej równa argumentowi kwota.
     *
     */
    bool sprawdzPortfel(int kwota);

    int podajKwotePocz();

    /**
     * \brief Zwraca rozmiar pola (deque) CGame::gracze_, bez pola CGame::przegrani_
     *
     */
    int podAktLbGraczy();

    string podajWlascicielaPola(int poz);
    int podajKontoGr();
    int podajLbKartWolnosc();

    /**
     * \brief Zwraca wartości aktualnej i następnej pozycji
     * gracza.
     *
     */
    SWynAkcji podajPozGracza();

    SDnGracza podajDaneGracza();
    deque<SDnPola> podajDanePol();
    deque<SDnPola> podajDanePolGracza();
    SDnPola podajDanePola(int poz);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

    /**
     * Poniższe funkcje służą do zwolnienia pamięci przypisanej dynamicznie dla każdego elementu
     * kontenerów typu deque należących do pól tej klasy.
     * Wywoływane są w destruktorze.
     * Dopiero po ich wywołaniu kontenery zostają oczyszczone.
     */
    void usunGraczy();
    void usunPrzegranych();
};

#endif // CGAME_H
