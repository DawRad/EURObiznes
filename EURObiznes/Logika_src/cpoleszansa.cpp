#include "Logika_h/cpoleszansa.h"

CPoleSzansa::CPoleSzansa()
{

}

CPoleSzansa::CPoleSzansa(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
}

CPoleSzansa::~CPoleSzansa()
{

}

SWynAkcji CPoleSzansa::akcja(CGracz *gracz)
{
    SWynAkcji wynik;

    wynik.y1 = 5;
    wynik.y2 = 5;

    return wynik;
}

int CPoleSzansa::podajDaneInt(int opt)
{
    switch(opt)
    {
    case 0:
        return pozycja_;
        break;

    default:
        return pozycja_;
    }
}

SDnPola CPoleSzansa::podajDane()
{
    SDnPola wynik;

    wynik.rodz = 5;

    wynik.poz = pozycja_;

    SHeadAndData tmp;
    tmp.header = "Nazwa";
    tmp.data = nazwa_;
    wynik.atrybuty.push_back(tmp);

    return wynik;
}

void CPoleSzansa::wpiszDane(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
}
