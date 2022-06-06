#ifndef CPOLESTND_H
#define CPOLESTND_H

#include "Logika_h/cpolespec.h"





/**
 * @brief Klasa logiki.
 */
class CPoleStnd : public CPoleSpec
{
private:
    /// kolor pola
    int kolor_;

    /// liczba apartamentów na polu
    int lbApartam_;

    /// liczba hoteli (może być tylko 0 lub 1)
    int lbHoteli_;    

    /// cena apartamentu
    int cenaApartam_;

    /// cena hotelu
    int cenaHotelu_;

public:
    CPoleStnd();
    CPoleStnd(SDnPoczPola dane);
    ~CPoleStnd();

    /**
     * \brief Funkcja zwraca wartość, która pozwala określić dostępne dla tego pola akcje.
     *
     * W tym przypadku pozwala ona określić, że obiekt jest polem o określonym kolorze i na którym można budować nieruchomości,
     * a czynsz zależy od liczby wybudowanych na polu nieruchomości.
     * @param *gracz - wskaźnik do obiektu klasy gracz, który stanął na polu
     * @return Wartości:
     * \li SWynAkcji.y1 = 1 mówiącą, że to klasa CPoleStnd
     * \li SWynAkcji.y2 wskazującą, jaki rodzaj akcji może zostać podjęty
     */
    SWynAkcji akcja(CGracz *gracz);

    int podajDaneInt(int opt);

    SDnPola podajDane();

    void sprzedawanie(CGracz *kupiec);

    void wpiszDane(SDnPoczPola dane);

    void aktualCzynsz();
    void buduj();
};

#endif // CPOLESTND_H
