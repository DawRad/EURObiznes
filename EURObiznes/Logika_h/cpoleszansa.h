#ifndef CPOLESZANSA_H
#define CPOLESZANSA_H

#include "Logika_h/cpole.h"





/**
 * @brief Klasa logiki.
 */
class CPoleSzansa : public CPole
{
public:
    CPoleSzansa();
    CPoleSzansa(SDnPoczPola dane);
    ~CPoleSzansa();

    /**
     * \brief Funkcja zwraca wartość, która pozwala określić dostępne dla tego pola akcje.
     *
     * W tym przypadku pozwala ona określić, że obiekt jest polem, które pozwala zalosować kartę.
     * @param *gracz - wskaźnik do obiektu klasy gracz, który stanął na polu
     * @return Zwraca wartość SWynAkcji.y1 = SWynAkcji.y2 = 5 mówiąca, że to klasa CPoleSzansa
     */
    SWynAkcji akcja(CGracz *gracz);

    int podajDaneInt(int opt);

    SDnPola podajDane();

    void wpiszDane(SDnPoczPola dane);
};

#endif // CPOLESZANSA_H
