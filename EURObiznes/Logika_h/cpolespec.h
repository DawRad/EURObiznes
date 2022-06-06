#ifndef CPOLESPEC_H
#define CPOLESPEC_H

#include "Logika_h/cpole.h"





/**
 * @brief Klasa logiki.
 */
class CPoleSpec : public CPole
{
protected:
    /// cena pola
    int cena_;

    /// stan pola (wolne, kupione, zastawione)
    int stan_;

    /// czynsz, który jest pobierany po stanięciu na to pole
    int czynsz_;

    /// wartość zastawienia pola
    int hipoteka_;

    /// do kogo pole należy
    CGracz *wlasciciel_;


public:
    CPoleSpec();
    CPoleSpec(SDnPoczPola _dane);
    ~CPoleSpec();

    // <--------------------> deklaracje funkcji wirtualnych <-------------------->

    /**
     * \brief Funkcja zwraca wartość, która pozwala określić dostępne dla tego pola akcje.
     *
     * W tym przypadku pozwala ona określić, że obiekt jest polem, na którym nie można budować nieruchomości,
     * a czynsz zależy od liczby posiadanych przez właściciela pól tej klasy.
     * @param *gracz - wskaźnik do obiektu klasy gracz, który stanął na polu
     * @return - wartości:
     * <ul>
     * <li>SWynAkcji.y1 = 0 mówiącą, że to klasa CPoleSpec
     * <li> i SWynAkcji.y2 wskazującą, jaki rodzaj akcji może zostać podjęty:
     *      <ul>
     *      <li>0 - pole nie ma właściciela
     *      <li>1 - pole ma właściciela, ale \a gracz nim nie jest
     *      <li>2 - właścicielem jest \a gracz
     *      <li>3 - właścicielem jest \a gracz, ale pole jest zastawione
     *      <li>4 - \a gracz nie nie jest właścicielem, ale pole jest zastawione
     *      </ul>
     * </ul>
     */
    virtual SWynAkcji akcja(CGracz *gracz);

    virtual void wpiszDane(SDnPoczPola dane);

    int podajDaneInt(int opt);

    SDnPola podajDane();

    virtual void sprzedawanie(CGracz *kupiec);

    // <--------------------> <--------------------> <-------------------->

    CGracz *podajWlasciciela();
    int zastawianie();
    void wykupowanie();

};

#endif // CPOLESPEC_H
