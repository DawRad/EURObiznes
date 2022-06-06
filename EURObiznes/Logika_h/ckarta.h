#ifndef CKARTA_H
#define CKARTA_H

#include <iostream>
#include "Logika_h/Stale.h"
#include "Logika_h/Struktury.h"




/**
 * @brief Klasa logiki.
 */
class CKarta
{
protected:
    /// numer porządkowy karty
    int nr_;

    /// treść karty
    string tresc_;

public:
    CKarta();
    virtual ~CKarta();

    // <--------------------> deklaracje funkcji wirtualnych <-------------------->

    /**
     * @brief Metoda identyfikująca klasę karty.
     *
     * W zależności od klasy są zwracane inne dane.
     * @return Klasę karty definiuje pole SDnKarty.rodzaj:
     * \li 0 - CKartaKwoty
     * \li 1 - CKartaRuchu
     * \li 2 - CKartaWiezienia
     * \li 3 - CKartaWolnosc
     */
    virtual SDnKarty akcja() = 0;

    // <--------------------> <--------------------> <-------------------->
};

#endif // CKARTA_H
