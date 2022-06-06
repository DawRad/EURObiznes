#include "Logika_h/ckartaruchu.h"

CKartaRuchu::CKartaRuchu()
{

}

CKartaRuchu::CKartaRuchu(SDnKarty dane)
{
    nr_ = dane.nr;
    tresc_ = dane.tresc;
    nowaPoz_ = dane.wartosc;
}

CKartaRuchu::~CKartaRuchu()
{

}

SDnKarty CKartaRuchu::akcja()
{
    SDnKarty dane;

    dane.rodzaj = 1;
    dane.nr = nr_;    
    dane.tresc = tresc_;
    dane.wartosc = nowaPoz_;

    return dane;
}
