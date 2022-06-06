#include "Logika_h/ckartawolnosc.h"





CKartaWolnosc::CKartaWolnosc()
{

}

CKartaWolnosc::CKartaWolnosc(SDnKarty dane)
{
    nr_ = dane.nr;
    tresc_ = dane.tresc;
}

CKartaWolnosc::~CKartaWolnosc()
{

}

SDnKarty CKartaWolnosc::akcja()
{
    SDnKarty dane;

    dane.nr = nr_;
    dane.rodzaj = 3;
    dane.tresc = tresc_;
    dane.wartosc = P_ODWIEDZINY;

    return dane;
}
