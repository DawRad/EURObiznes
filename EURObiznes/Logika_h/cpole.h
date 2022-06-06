#ifndef CPOLE_H
#define CPOLE_H

#include <iostream>
#include "Logika_h/Struktury.h"
#include "Logika_h/cgracz.h"

using std::to_string;





/**
 * @brief Klasa logiki.
 */
class CPole
{
protected:
    /// nazwa pola
    string nazwa_;

    /// pozycja pola na planszy
    int pozycja_;

public:
    CPole();
    CPole(SDnPoczPola _dane);
    virtual ~CPole();

    // <--------------------> deklaracje metod wirtualnych <-------------------->

    /**
     * \brief Funkcja zwraca wartość, która pozwala określić dostępne dla tego pola akcje.
     *
     * W tym przypadku pozwala ona określić, że obiekt jest polem bazowym/neutralnym.
     * @param *gracz - wskaźnik do obiektu klasy gracz, który stanął na polu
     * @return Zwraca wartość SWynAkcji.y1 = 6 mówiąca, że to klasa CPole i SWynAkcji.y2 wskazującą, jaka jest pozycja tego obiektu na planszy.
     */
    virtual SWynAkcji akcja(CGracz *gracz);

    virtual void wpiszDane(SDnPoczPola _dane);

    virtual int podajDaneInt(int opt);

    virtual SDnPola podajDane();

    // <--------------------> <--------------------> <-------------------->

    string podajNazwe();





    // <--------------------> deklaracje metod statycznych <-------------------->

    /**
     * \brief Metoda zamienia kolor wyrażony w postaci typu int na typ string
     *
     */
    static string kolorToStr(int kolor);

    // <--------------------> <--------------------> <-------------------->
};

#endif // CPOLE_H
