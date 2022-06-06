#ifndef CCZLOWIEK_H
#define CCZLOWIEK_H

#include "Logika_h/cgracz.h"




/**
 * @brief Klasa logiki.
 */
class CCzlowiek : public CGracz
{
public:
    /**
     * \brief Konstruktor klasy CCzlowiek
     *
     * Wcześniej musi być też znana liczba regionów pól klasy CPoleStnd (informacja zawarta w SDnGracza).
     */
    CCzlowiek(SDnGracza _dane);
    virtual ~CCzlowiek();

    // <--------------------> deklaracje funkcji wirtualnych <-------------------->
    string przedstawSie();
    SWynAkcji rzucKoscmi();
    int decyduj(int stan, int kwota, int lbPol);

    // <--------------------> <--------------------> <-------------------->
};

#endif // CCZLOWIEK_H
