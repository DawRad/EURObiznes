#ifndef CKARTARUCHU_H
#define CKARTARUCHU_H

#include "Logika_h/ckarta.h"




/**
 * @brief Klasa logiki.
 */
class CKartaRuchu : public CKarta
{
private:
    int nowaPoz_;

public:
    CKartaRuchu();
    CKartaRuchu(SDnKarty dane);
    ~CKartaRuchu();

    /**
     * \brief Funkcja zwraca dane, które definiują obiekt tej klasy.
     *
     * W tym przypadku karta zawiera informację, na jaką pozycję powinien przemieścić się gracz.
     * @return
     * \li SDnKarty.rodzaj - informacja o tym, jakiej klasy jest obiekt danej karty (w tym przypadku rodzaj = 1)
     * \li SDnKarty.nr - numer karty w talii
     * \li SDnKarty.tresc - tekst, który zawiera karta
     * \li SDnKarty.wartosc - numer pola, na które gracz ma się przemieścić
     */
    SDnKarty akcja();
};

#endif // CKARTARUCHU_H
