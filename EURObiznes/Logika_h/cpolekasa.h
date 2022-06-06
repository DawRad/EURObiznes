#ifndef CPOLEKASA_H
#define CPOLEKASA_H

#include "Logika_h/cpole.h"





/**
 * @brief Klasa logiki.
 */
class CPoleKasa : public CPole
{
private:
    /// kwota pobierana (ujemna) przez pole od gracza albo oddawana (dodatnia) graczowi
    int kwota_;

public:
    CPoleKasa();
    CPoleKasa(SDnPoczPola dane);
    ~CPoleKasa();

    /**
     * \brief Funkcja zwraca wartość, która pozwala określić dostępne dla tego pola akcje.
     *
     * W tym przypadku pozwala ona określić, że obiekt jest polem, które dodaje lub odejmuje daną kwotę z zasobów gracza stającego.
     * @param *gracz - wskaźnik do obiektu klasy gracz, który stanął na polu
     * @return Zwraca wartość SWynAkcji.y1 = 4 mówiąca, że to klasa CPoleKasa i SWynAkcji.y2 wskazującą, ile pieniędzy gracz otrzymuje albo traci.
     */
    SWynAkcji akcja(CGracz *gracz);

    int podajDaneInt(int opt);

    SDnPola podajDane();

    void wpiszDane(SDnPoczPola dane);

    /**
     * \brief Pozwala zmienić wartość atrybutu kwota_ klasy
     *
     * Z założenia funkcja ta służy do ustawienia kwoty, jaka jest wypłacana lub pobierana od gracza, który staje na tym polu.
     * @param wartosc - wartosc, która ma zostać przypisana do atrybutu CPoleKasa::kwota_, może być zarówno dodatnia, jak i ujemna
     */
    void ustawKwote(int wartosc);
};

#endif // CPOLEKASA_H
