#include "Logika_h/ckartakwoty.h"

CKartaKwoty::CKartaKwoty()
{

}

CKartaKwoty::CKartaKwoty(SDnKarty dane)
{
    nr_ = dane.nr;
    tresc_ = dane.tresc;
    kwota_ = dane.wartosc;
}

CKartaKwoty::~CKartaKwoty()
{

}

SDnKarty CKartaKwoty::akcja()
{
    SDnKarty dane;

    dane.rodzaj = 0;
    dane.nr = nr_;
    dane.tresc = tresc_;
    dane.wartosc = kwota_;

    return dane;
}
