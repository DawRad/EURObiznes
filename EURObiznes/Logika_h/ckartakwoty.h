#ifndef CKARTAKWOTY_H
#define CKARTAKWOTY_H

#include "Logika_h/ckarta.h"




/**
 * @brief Klasa logiki.
 */
class CKartaKwoty : public CKarta
{
private:
    /// kwota, którą należy dodać do zasobów gracza (może być dodatnia albo ujemna)
    int kwota_;

public:
    CKartaKwoty();
    CKartaKwoty(SDnKarty dane);
    ~CKartaKwoty();

    /**
     * \brief Funkcja zwraca dane, które definiują obiekt tej klasy.
     *
     * W tym przypadku karta zawiera informację, jaką kwotę należy dodać lub odjąć z zasobów gracza.
     * @return
     * \li SDnKarty.rodzaj - informacja o tym, jakiej klasy jest obiekt danej karty (w tym przypadku rodzaj = 0)
     * \li SDnKarty.nr - nr karty w talii
     * \li SDnKarty.tresc - tekst, który zawiera karta
     * \li SDnKarty.wartosc - ujemna lub dodatnia wartość, którą należy dodać do portfela gracza
     */
    SDnKarty akcja();
};

#endif // CKARTAKWOTY_H
