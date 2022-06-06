#ifndef CKARTAWIEZIENIA_H
#define CKARTAWIEZIENIA_H

#include "Logika_h/ckarta.h"




/**
 * @brief Klasa logiki.
 */
class CKartaWiezienia : public CKarta
{
public:
    CKartaWiezienia();
    CKartaWiezienia(SDnKarty dane);
    ~CKartaWiezienia();

    /**
     * \brief Funkcja zwraca dane, które reprezentuje obiekt tej klasy.
     *
     * W tym przypadku karta zawiera polecenie aresztowania gracza.
     * @return
     * \li SDnKarty.rodzaj - informacja o tym, jakiej klasy jest obiekt danej karty (w tym przypadku SDnKarty.rodzaj = 2)
     * \li SDnKarty.nr - numer karty w talii
     * \li SDnKarty.tresc - tekst, który zawiera karta
     * \li SDnKarty.wartosc - numer pola "Więzienie"
     */
    SDnKarty akcja();
};

#endif // CKARTAWIEZIENIA_H
