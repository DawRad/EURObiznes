#ifndef CPLANSZA_H
#define CPLANSZA_H

#include <iostream>
#include <ctime>

#include "Logika_h/ckomputer.h"
#include "Logika_h/cczlowiek.h"
#include "Logika_h/cpole.h"
#include "Logika_h/cpolespec.h"
#include "Logika_h/cpolestnd.h"
#include "Logika_h/cpoleekstra.h"
#include "Logika_h/cpoledowiezienia.h"
#include "Logika_h/cpolekasa.h"
#include "Logika_h/cpoleszansa.h"
#include "Logika_h/ckartakwoty.h"
#include "Logika_h/ckartaruchu.h"
#include "Logika_h/ckartawiezienia.h"
#include "Logika_h/ckartawolnosc.h"





/**
 * @brief Klasa logiki.
 */
class CPlansza
{   
private:
    /// dwukierunkowa lista kart
    deque<CKarta*> karty_;

    /// dwukierunkowa lista dla kart już wylosowanych
    deque<CKarta*> kartyUzyte_;

    /// wartość pensji pola "START"
    int pensjaStart_;

    /// dwukierunkowa lista pól
    deque<CPole*> pola_;

    /// dwukierunkowa lista nazw regionów
    deque<string> regiony_;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
    CPlansza();
    ~CPlansza();

    /**
     * @brief Tworzy pola planszy według danych pobranych z pliku.
     *
     * Dane są w postaci łańcuchów \a string. Każdy element listy \a daneZPliku
     * to z założenia 1 linijka tekstu z pliku.
     * @param daneZPliku - dwukierunkowa lista łańcuchów \a string pobranych z pliku
     */
    void wczytajDaneZPliku_pola(deque<string> &daneZPliku);

    /**
     * @brief Tworzy karty planszy według danych pobranych z pliku.
     *
     * Dane są w postaci łańcuchów \a string. Każdy element listy \a daneZPliku
     * to z założenia 1 linijka tekstu z pliku.
     * @param daneZPliku - dwukierunkowa lista łańcuchów \a string pobranych z pliku
     */
    void wczytajDaneZPliku_karty(deque<string> &daneZPliku);

    /**
     * @brief Sortuje listę pola_ rosnąco, wg pola CPole::pozycja_.
     */
    void sortujListePol();

    /**
     * @brief Zamienia pole na danej pozycji nowym obiektem.
     * @param rodz - klasa pola
     * @param dane - dane nowego pola
     */
    void dodajPole(int rodz, SDnPoczPola dane);

    void ustawPensjeStart(int pensja);

    /**
     * \brief Podmienia pole o danej pozycji polem z danymi przekazanymi jako parametr.
     *
     * Tworzy nowe pole, podmienia nim pole będące pierwotnie na podanej pozycji
     * i usuwa pole pierwotne.
     * @param dane - dane pola
     */
    void zamienNaCPoleSzansa(SDnPoczPola dane);

    /**
     * \brief Podmienia pole o danej pozycji polem z danymi przekazanymi jako parametr.
     *
     * \see zamienNaCPoleSzansa
     */
    void zamienNaCPoleSpec(SDnPoczPola dane);

    /**
     * \brief Podmienia pole o danej pozycji polem z danymi przekazanymi jako parametr.
     *
     * \see zamienNaCPoleSzansa
     */
    void zamienNaCPoleStnd(SDnPoczPola dane);

    /**
     * \brief Podmienia pole o danej pozycji polem z danymi przekazanymi jako parametr.
     *
     * \see zamienNaCPoleSzansa
     */
    void zamienNaCPoleEkstra(SDnPoczPola dane);

    /**
     * \brief Podmienia pole o danej pozycji polem z danymi przekazanymi jako parametr.
     *
     * \see zamienNaCPoleSzansa
     */
    void zamienNaCPoleKasa(SDnPoczPola dane);

    /**
     * @return Pole SWynAkcji.y1 zwracanego wyniku wskazuje na klasę obiektu pola:
     * \li = 0 -----> klasa CPoleSpec
     * \li = 1 -----> klasa CPoleStnd
     * \li = 2 -----> klasa CPoleEkstra
     * \li = 3 -----> klasa CPoleDoWiezienia
     * \li = 4 -----> klasa CPoleKasa
     * \li = 5 -----> klasa CPoleSzansa
     * \li = 6 -----> klasa CPole
     */
    SWynAkcji identPole(CGracz *gracz, int parPoz);

    deque<SDnPola> zbierzDnPol();
    SDnPola zbierzDnPola(int poz);
    deque<SDnPola> zbierzDnPol(CGracz *gracz);
    deque<SDnPola> zbierzDnPolNiezast(CGracz *gracz);
    deque<SDnPola> zbierzDnPolZast(CGracz *gracz);
    CGracz* ktoMaPole(int parPoz);
    int podajPensje();
    int podajCenePola(int poz);

    /**
     * \brief Funkcja zwraca zsumowaną wartość cen kupna nieruchomości podanego gracza.
     *
     * Bierze pod uwagę  tylko nieruchomości NIEZASTAWIONE.     
     */
    int wartoscNieruchomosciGracza(CGracz *wlasciciel);

    /**
     * \brief Funkcja zwraca zsumowaną wartość zastawów nieruchomości podanego gracza.
     *
     * Dla danego gracza przeszukuje listę pól i sumuje wysokości ich zastawów, ale bierze pod uwagę tylko
     * niezastawione nieruchomości.
     * @param wlasciciel - wskaźnik do obiektu klasy CGracz, którego pól wyszukuje funkcja
     */
    int potencjalZastawuGracza(CGracz *wlasciciel);

    SDnKarty losowanieKarty();
    void tasowanieKart();
    void kupowaniePola(CGracz *kupiec, int parPoz);

    /**
     * \brief Podaje dane typu int konkretnego obieku klasy CPole
     *
     * W zależności od tego, jaki numer pozycji pola został podany jako parametr metody
     * zwraca określony (również w parametrach metody) atrybut klasy CPole lub pochodnej.
     * @param parPoz - numer pozycji pola
     * @param opt - mówi o tym, który atrybut ma zostać zwrócony
     */
    int daneIntPola(int parPoz, int opt);

    void zabuduj(int poz);
    int zastaw(int poz);
    void wykup(int poz);


    /**
     * \brief Na podstawie wartości aktualnej pozycji w kolejce i rozmiaru
     * analizowanej kolejki wyznacza wartość kolejnej pozycji.
     *
     */
    static int ustalKolejnaPozWKolejce(int aktPoz, int rozmKolejki);


    /**
     * \brief Funkcja zamienia rodzaj pola typu \a string na odpowiadającą mu wartość \a int
     *
     * @param rodz - napis określający rodzaj pola
     */
    static int changePoleRodz(string rodz);


    /**
     * \brief Funkcja zamienia rodzaj pola typu int na odpowiadającą mu wartość \a string
     *
     * @param rodz - liczba całkowita określająca rodzaj pola
     */
    static string poleRodzToStr(int rodz);

    /**
     * \brief Analogicznie do changePoleRodz(\a string) zamienia argument
     * na odpowiadającą mu wartość \a int
     *
     * @return Wartości wynikowe dla różnych wartości argumentu:
     * \li "CKartaKwoty" ---> 0
     * \li "CKartaRuchu" ---> 1
     * \li "CKartaWiezienia" ---> 2
     * \li "CKartaWolnosc" ---> 3
     */
    static int kartaRodzToInt(string rodzaj);


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

    /**
     * \brief Służy do zwolnienia pamięci przypisanej dynamicznie dla każdego elementu listy CPlansza::karty_.
     *
     * Wywoływana w destruktorze - ~Plansza().
     * Dopiero po ich wywołaniu kontenery zostają oczyszczone.
     */
    void usunKarty();

    /**
     * \brief Służy do zwolnienia pamięci przypisanej dynamicznie dla każdego elementu listy CPlansza::kartyUzyte_.
     *
     * \see usunKarty()
     */
    void usunKartyUzyte();

    /**
     * \brief Służy do zwolnienia pamięci przypisanej dynamicznie dla każdego elementu listy CPlansza::pola_.
     *
     * \see usunKarty()
     */
    void usunPola();

    /**
     * @brief Tworzy CPole na podstawie danych pobranych z pliku.
     *
     * @param daneZPliku - dane pobrane z pliku
     * @param start - indeks elementu listy, od którego metoda ma zacząć pobierać dane
     * @param end - indeks ostatniego elementu listy, który ma być pobrany w metodzie
     * \see wczytajDaneZPliku_pola(deque<string> &daneZPliku)
     */
    void utworzCPoleZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CPoleSpec na podstawie danych pobranych z pliku.
     * \see utworzCPoleZPliku(deque<string> &daneZPliku, int start, int end)
     */
    void utworzCPoleSpecZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CPoleStnd na podstawie danych pobranych z pliku.
     * \see utworzCPoleZPliku(deque<string> &daneZPliku, int start, int end)
     */
    void utworzCPoleStndZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CPoleEkstra na podstawie danych pobranych z pliku.
     * \see utworzCPoleZPliku(deque<string> &daneZPliku, int start, int end)
     */
    void utworzCPoleEkstraZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CPoleKasa na podstawie danych pobranych z pliku.
     * \see utworzCPoleZPliku(deque<string> &daneZPliku, int start, int end)
     */
    void utworzCPoleKasaZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CPoleSzansa na podstawie danych pobranych z pliku.
     * \see utworzCPoleZPliku(deque<string> &daneZPliku, int start, int end)
     */
    void utworzCPoleSzansaZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CPoleDoWiezienia na podstawie danych pobranych z pliku.
     * \see utworzCPoleZPliku(deque<string> &daneZPliku, int start, int end)
     */
    void utworzCPoleDoWiezieniaZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CKartaWolnosc na podstawie danych pobranych z pliku.
     *
     * @param daneZPliku - dane pobrane z pliku
     * @param start - indeks elementu listy, od którego metoda ma zacząć pobierać dane
     * @param end - indeks ostatniego elementu listy, który ma być pobrany w metodzie
     * \see wczytajDaneZPliku_karty(deque<string> &daneZPliku)
     */
    void utworzCKartaWolnoscZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CKartaKwoty na podstawie danych pobranych z pliku.
     * \see utworzCKartaWolnoscZPliku(deque<string> &daneZPliku, int start, int end)
     */
    void utworzCKartaKwotyZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CKartaRuchu na podstawie danych pobranych z pliku.
     * \see utworzCKartaWolnoscZPliku(deque<string> &daneZPliku, int start, int end)
     */
    void utworzCKartaRuchuZPliku(deque<string> &daneZPliku, int start, int end);

    /**
     * @brief Tworzy CKartaWiezienia na podstawie danych pobranych z pliku.
     * \see utworzCKartaWolnoscZPliku(deque<string> &daneZPliku, int start, int end)
     */
    void utworzCKartaWiezieniaZPliku(deque<string> &daneZPliku, int start, int end);


    /**
     * \brief Metoda zamienia \a string na odpowiadającą mu wartość \a int
     *
     */
    int changePoleHeader(string header);    

    /**
     * \brief Analogicznie do changePoleHeader(\a string) zamienia argument
     * na odpowiadającą mu wartość \a int
     *
     * @return Wartości wynikowe dla różnych wartości argumentu:
     * \li "CKartaKwoty" ---> 0
     * \li "CKartaRuchu" ---> 1
     * \li "CKartaWolnosc" ---> 2
     * \li "CKartaWiezienia" ---> 3
     */
    int kartaHeaderToInt(string header);


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
    // <--------------------> Poniżej metody do parsowania strumienia danych pobranych z pliku <-------------------->

    /**
     * \brief Funkcja poszukuje indeksu początkowego i końcowego elementu typu string należącego do danego nagłówka.
     *
     * Przeszukuje kontener deque<string> zawierający linijki danych i określa, który element jest elementem zawierającym
     * zakończenie danego nagłówka ("/...").
     * @param trescPliku Podwójna lista składająca się z elementów typu string.
     * @param nazwaNag Zawiera informację o nazwie poszukiwanego nagłówka (nie jego końca - </...>).
     * @param start Indeks elementu listy, od którego funkcja zaczyna analizę (powinien być to indeks początku nagłówka).
     * @return Zwraca numer elementu, który jest zakończeniem nagłówka.
     */
    static int parseBound(deque<string> &trescPliku, string nazwaNag, int start);

    /**
     * \brief Zwraca właściwą zawartość nagłówka
     *
     */
    static string parseHeadCont(string strumien, int start);

    /**
     * /brief Wyszukuje w strumieniu nagłówek i indeksy początku i końca jego zawartości.
     *
     * Funkcja najpierw wyszukuje najbliższy nagłówek (<nagłówek>), a potem wyznacza indeks początkowy jego zawartości.
     * @param daneStr Strumień danych (np. pobrany z pliku).
     * @param daneStrIndex Indeks znaku w strumieniu, od którego funkcja ma zacząć poszukiwać nagłówka.
     * @return Wartość zwracana to struktura zawierająca nazwę znalezionego nagłówka i numer pierwszego indeksu zawartości (pierwszego znaku po '>' początku nagłówka)
     * oraz końca zawartości (ostatniego znaku przed '<' końca nagłówka).
     */
    static SParsedElem parseElem(string& daneStr);

    /**
     * @return Zwraca indeks szukanego znaku w strumieniu
     */
    static int znajdzZn(char parZn, int indexStart, string& strumien);
};

#endif // CPLANSZA_H
