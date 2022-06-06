#ifndef CKARTAWOLNOSC_H
#define CKARTAWOLNOSC_H

#include "Logika_h/ckarta.h"




/**
 * @brief Klasa logiki.
 */
class CKartaWolnosc : public CKarta
{
public:
    CKartaWolnosc();
    CKartaWolnosc(SDnKarty dane);
    ~CKartaWolnosc();

    /**
     * \brief Funkcja zwraca dane, które reprezentuje obiekt tej klasy.
     *
     * W tym przypadku karta daje możliwość wyjścia z więzienia.
     * @return
     * \li SDnKarty.rodzaj - informacja o tym, jakiej klasy jest obiekt danej karty (w tym przypadku SDnKarty.rodzaj = 3)
     * \li SDnKarty.nr - numer karty w talii
     * \li SDnKarty.tresc - tekst, który zawiera karta
     * \li SDnKarty.wartosc - numer pola "Odwiedziny"
     */
    SDnKarty akcja();
};

#endif // CKARTAWOLNOSC_H
