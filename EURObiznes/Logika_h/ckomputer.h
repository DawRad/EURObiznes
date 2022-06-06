#ifndef CKOMPUTER_H
#define CKOMPUTER_H

#include "Logika_h/cgracz.h"




/**
 * @brief Klasa logiki.
 */
class CKomputer : public CGracz
{
public:
    CKomputer(SDnGracza _dane);
    virtual ~CKomputer();

    // <--------------------> deklaracje funkcji wirtualnych <-------------------->
    string przedstawSie();
    SWynAkcji rzucKoscmi();
    int decyduj(int stan, int kwota, int lbPol);

    // <--------------------> <--------------------> <-------------------->
};

#endif // CKOMPUTER_H
