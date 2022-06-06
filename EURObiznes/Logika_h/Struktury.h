#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream>
#include <deque>

using std::deque;
using std::string;





/**
 * \brief Struktura przechowuje właściwe dane (data) wraz z ich opisem (header).
 *
 * Podstawowe zastosowanie: atrybuty klas pól w postaci łańcuchów \a string i ich nazwy.
 */
struct SHeadAndData
{
    string header;
    string data;
};





/**
 * @brief Struktura przechowująca dane o graczu.
 */
struct SDnGracza
{
    int id;
    string rodz;
    string nick;
    int portfel;
    int lbKolorow;                      // pole wskazuje, ile jest kolorów (regionów) pól klasy CPoleStnd
    int lbKartWolnosc;
    // -----> to be continued...
};





/**
 * @brief Struktura przechowująca dane karty.
 */
struct SDnKarty
{
    int rodzaj;
    int nr;
    string tresc;
    int wartosc;
};





/**
 * @brief Struktura zawierająca dane do utworzenia pola.
 */
struct SDnPoczPola
{
    string nazwa;
    int poz;
    int kwota;
    int czynsz;

    int hipoteka;

    int cenaAp;
    int cenaHot;
    int kolor;
};

/**
 * \brief Struktura zawierająca dane pola do wypisania w GUI lub zidentyfikowania aktualnego stanu.
 *
 * Wszystkie dane podane jako typ \a string (nawet, jeśli pierwotnie są innego typu).
 */
struct SDnPola
{
    int rodz;
    int poz;
    deque<SHeadAndData> atrybuty;
};

/**
 * \brief Struktura do zwracania danych w metodzie CPole::akcja() (pierwotnie, ale jednak nie tylko w tej funkcji i poniżej wymienionej)
 * w klasie CPole (i pochodnych).
 *
 * Pole y1 z założenia zawiera informację o stanie pola planszy
 * <br>Pole y2 z założenia zawiera info uzupełniające w zależności od wartości y1
 * <br>Alternatywnie: struktura przechowująca wynik rzutu dwiema kostkami
 * <br>Pole y1 ---> kostka pierwsza
 * <br>Pole y2 ---> kostka druga
 */
struct SWynAkcji
{
    int y1;
    int y2;
};

/**
 * \brief Struktura do parsowania plików z danymi.
 *
 */
struct SParsedElem
{
    string header;
    int pocz;   
};

#endif // STRUKTURY_H
