#ifndef CPOLEEKSTRA_H
#define CPOLEEKSTRA_H

#include "Logika_h/cpolespec.h"





/**
 * @brief Klasa logiki.
 */
class CPoleEkstra : public CPoleSpec
{
public:
    CPoleEkstra();
    CPoleEkstra(SDnPoczPola dane);
    ~CPoleEkstra();

    /**
     * \brief Funkcja zwraca wartość, która pozwala określić dostępne dla tego pola akcje.
     *
     * W tym przypadku pozwala ona określić, że obiekt jest polem na którym nie można budować nieruchomości,
     * a czynsz zależy od krotności wyrzuconych oczek.
     * @param *gracz - wskaźnik do obiektu klasy gracz, który stanął na polu
     * @return wartość SWynAkcji.y1 = 2 mówiącą, że to klasa CPoleEkstra i SWynAkcji.y2 wskazującą, jaki rodzaj akcji może zostać podjęty.
     */
    SWynAkcji akcja(CGracz *gracz);

    int podajDaneInt(int opt);

    SDnPola podajDane();

    void sprzedawanie(CGracz *kupiec);

    void wpiszDane(SDnPoczPola dane);
};

#endif // CPOLEEKSTRA_H
