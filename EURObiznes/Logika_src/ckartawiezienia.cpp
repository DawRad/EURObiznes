#include "Logika_h/ckartawiezienia.h"

CKartaWiezienia::CKartaWiezienia()
{

}

CKartaWiezienia::CKartaWiezienia(SDnKarty dane)
{
    nr_ = dane.nr;
    tresc_ = dane.tresc;
}

CKartaWiezienia::~CKartaWiezienia()
{

}

SDnKarty CKartaWiezienia::akcja()
{
    SDnKarty dane;

    dane.nr = nr_;
    dane.rodzaj = 2;
    dane.tresc = tresc_;
    dane.wartosc = P_WIEZIENIE;              // w tym przypadku wartość to numer pola więzienia

    return dane;
}
