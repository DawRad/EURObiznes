#ifndef CPOLEDOWIEZIENIA_H
#define CPOLEDOWIEZIENIA_H

#include "Logika_h/cpole.h"





/**
 * @brief Klasa logiki.
 */
class CPoleDoWiezienia : public CPole
{
public:
    CPoleDoWiezienia();
    CPoleDoWiezienia(SDnPoczPola dane);
    ~CPoleDoWiezienia();

    /**
     * \brief Funkcja zwraca wartość, która pozwala określić dostępne dla tego pola akcje.
     *
     * W tym przypadku pozwala ona określić, że obiekt jest polem, które odsyła gracza do więzienia.
     * @param *gracz - wskaźnik do obiektu klasy gracz, który stanął na polu
     * @return Zwraca wartość SWynAkcji.y1 = SWynAkcji.y2 = 3 mówiąca, że to klasa CPoleDoWiezienia
     */
    SWynAkcji akcja(CGracz *gracz);

    int podajDaneInt(int opt);

    SDnPola podajDane();

    void wpiszDane(SDnPoczPola dane);
};

#endif // CPOLEDOWIEZIENIA_H
